#pragma once 
#include <string>
#include <atomic>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <jsoncpp/json/json.h>
#include "util.hpp"

///////////////////////////////////////////////
//  Compiler 类
///////////////////////////////////////////////

class Compiler
{
    public:
        // 使用文件使用进程间通信
        // 1. 源代码文件
        // name:请求与请求之间名字不同
        static std::string SrcPath(const std::string& name)
        {
            return "./temp_files/" + name + ".cpp";
        }
        // 2. 编译错误文件
        static std::string CompilerErrorPath(const std::string& name)
        {
            return "./temp_files/" + name + ".compiler_error";
        }
        // 3. 可执行程序文件
        static std::string ExePath(const std::string& name)
        {
            return "./temp_files/" + name + ".exe";
        }
        
        // 4. 标准输入文件
        static std::string StdinPath(const std::string& name)
        {
            return "./temp_files/" + name + ".stdin";
        }
        // 5. 标准输出文件
        static std::string StdoutPath(const std::string& name)
        {
            return "./temp_files/" + name + ".stdout";
        }
        // 6. 标准错误文件
        static std::string StderrPath(const std::string& name)
        {
            return "./temp_files/" + name + ".stderr";
        }

        static bool CompilerAndRun(const Json::Value& req, Json::Value* resp)
        {
            // 1. 生成源代码文件
            if (req["code"].empty())
            {
                (*resp)["error"] = 3;
                (*resp)["reason"] = "code empty";
                LOG(ERROR) << "code empty" << std::endl;
                return false;
            }
            const std::string& code = req["code"].asString();
            //std::string code = req["code"].asString();
            std::string file_name = WriteTmpFile(code, req["stdin"].asString());
            
            // 2. 调用 g++ 进行编译
            //    生成可执行从程序，编译错误，重定向到文件中
            bool ret = Compile(file_name);
            if (!ret)
            {
                // 错误处理
                (*resp)["error"] = 1;
                std::string reason;
                FileUtil::Read(CompilerErrorPath(file_name), &reason);
                (*resp)["reason"] = reason; 
                LOG(INFO) << "Compiler failed" << std::endl;
                return false;
            }
            // 3. 调用可执行程序，把标准输入记录到文件中
            //    把文件中的内容重定向给可执行程序
            //    把可执行程序中的标准输出和标准错误重定向到文件中
            int sig  = Run(file_name);
            if (sig != 0)
            {
                (*resp)["error"] = 2;
                (*resp)["reason"] = "Program exit by signo : " + std::to_string(sig);
                LOG(INFO) << "Program exit by signo:" <<std::to_string(sig) << std::endl;
                return false;
            }
            // 4. 返回程序结果，构造 resp 对象
            (*resp)["error"] = 0;
            (*resp)["reason"] = "";
            std::string str_stdout;
            FileUtil::Read(StdoutPath(file_name), &str_stdout);
            (*resp)["stdout"] = str_stdout;
            std::string str_stderr;
            FileUtil::Read(StderrPath(file_name), &str_stderr);
            (*resp)["stderr"] = str_stderr;
            LOG(INFO) << "Program" << file_name << " Done" << std::endl;
            return true;
        }
    private:
        static std::string WriteTmpFile(const std::string& code, const std::string& str_stdin)
        {
            static std::atomic_int id(0);
            ++id;
            std::string file_name = "tmp_" + std::to_string(TimeUtil::TimeStamp()) + "." + std::to_string(id);
            FileUtil::Write(SrcPath(file_name), code);
            FileUtil::Write(StdinPath(file_name), str_stdin);
            return file_name;
        }
        static bool Compile(const std::string& file_name)
        {
            // 1.构造编译指令
            char* command[20] = {0};
            char buff[20][50] = {{0}};
            for (int i = 0; i < 20; i++)
            {
                command[i] = buff[i];
            }
            sprintf(command[0], "%s", "g++");
            sprintf(command[1], "%s", SrcPath(file_name).c_str());
            sprintf(command[2], "%s", "-o");
            sprintf(command[3], "%s", ExePath(file_name).c_str());
            sprintf(command[4], "%s", "-std=c++11");
            command[5] = NULL;
            // 2.创建子进程
            int ret = fork();
            if (ret > 0)
            {
                // 3.父进程进行进程等待
                waitpid(ret, NULL, 0);
            }
            else 
            {
                // 4.子进程进行程序替换
                int fd = open(CompilerErrorPath(file_name).c_str(), O_WRONLY | O_CREAT, 0666);
                if (fd < 0)
                {
                    LOG(ERROR) << "open Compile file error" << std::endl;
                    exit(1);
                }
                dup2(fd, 2);
                execvp(command[0], command);
                exit(0);
            }
            struct stat st;
            ret = stat(ExePath(file_name).c_str(), &st);
            if (ret < 0)
            {
                LOG(INFO) << "Compile filed! " << file_name << std::endl;
                return false;
            }
            LOG(INFO) << "Compile " << file_name << " OK!" << std::endl;
            return true;
        }
        static int Run(const std::string& file_name)
        {
            // 1.创建子进程
            int ret = fork();
            if (ret > 0)
            {
                // 2.父进程进行等待
                int status = 0;
                waitpid(ret, &status, 0);
                return status & 0x7f;
            }
            else 
            {
                // 3.进行重定向
                int fd_stdin = open(StdinPath(file_name).c_str(), O_RDONLY);
                dup2(fd_stdin, 0);
                int fd_stdout = open(StdoutPath(file_name).c_str(), O_WRONLY | O_CREAT, 0666);
                dup2(fd_stdout, 1);
                int fd_stderr = open(StderrPath(file_name).c_str(), O_WRONLY | O_CREAT, 0666);
                dup2(fd_stderr, 2);
                // 4.子进程进行程序替换
                execl(ExePath(file_name).c_str(), ExePath(file_name).c_str(), NULL);
                exit(0);
            }
        }
};















