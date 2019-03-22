/***********************************
 * 文件名称: util.hpp
 * 文件描述: 准备
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#pragma once 
#include <iostream>
#include <unistd.h>
#include <string>
#include <stdint.h>
#include <fstream>
#include <sys/time.h>


///////////////////////////////////////////////
//  时间戳
///////////////////////////////////////////////

class TimeUtil
{
    public:
        // 获取当前时间戳
        static int64_t TimeStamp()
        {
            struct timeval tv;
            ::gettimeofday(&tv, NULL);
            return tv.tv_sec;
        }

        static int64_t TimeStampMS()
        {
            struct timeval tv;
            ::gettimeofday(&tv, NULL);
            return tv.tv_sec * 1000 + tv.tv_usec / 1000;
        }
    private:
};

///////////////////////////////////////////////
//  日志
///////////////////////////////////////////////

enum Level 
{
    INFO,
    WARING,
    ERROR,
    FATAL,
};

inline std::ostream& Log(Level level, const std::string& file_name, int line_num)
{
    std::string prefix = "[";
    if (level == INFO)
    {
        prefix += "I";
    }
    else if (level == WARING)
    {
        prefix += "W";
    }
    else if (level == ERROR)
    {
        prefix += "E";
    }
    else if (level == FATAL)
    {
        prefix += "F";
    }
    prefix += std::to_string(TimeUtil::TimeStamp());
    prefix += " ";
    prefix += file_name;
    prefix += ":";
    prefix += std::to_string(line_num);
    prefix += "]";
    std::cout << prefix;
    return std::cout;
}

#define LOG(level) Log(level, __FILE__, __LINE__)

///////////////////////////////////////////////
//  文件
///////////////////////////////////////////////

class FileUtil
{
    public:
        static bool Read(const std::string& file_path, std::string* content)
        {
            content->clear();
            std::ifstream file(file_path.c_str());
            if (!file.is_open())
            {
                return false;
            }
            std::string line;
            while (std::getline(file, line))
            {
                *content += line + '\n';
            }
            file.close();
            return true;
        }
        static bool Write(const std::string& file_path, const std::string& content)
        {
            std::ofstream file(file_path.c_str());
            if (!file.is_open())
            {
                return false;
            }
            file.write(content.c_str(), content.size());
            file.close();
            return true;
        }
    private:
};

