#pragma once 
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "util.hpp"

struct Question 
{
    std::string id;
    std::string name;
    std::string dir;
    std::string star;
    std::string desc;
    std::string header_cpp;
    std::string tail_cpp;
};

class OjModel
{
public:
    bool Load()
    {
        // 打开文件
        std::ifstream file("./oj_data/oj_config.cfg");
        if (!file.is_open())
        {
            return false;
        }
        // 按行读取，解析
        std::string line;
        while (std::getline(file, line))
        {
            std::vector<std::string> tokens;
            StringUtil::Spilt(line, "\t", &tokens);
            if (tokens.size() != 4)
            {
                LOG(ERROR) << "config file format error!\n";
                continue;
            }
            // 把结构体加入到 hash 表中
            Question q;
            q.id = tokens[0];
            q.name = tokens[1];
            q.star = tokens[2];
            q.dir = tokens[3];
            FileUtil::Read(q.dir + "/desc.txt", &q.desc);
            FileUtil::Read(q.dir + "/header.cpp", &q.header_cpp);
            FileUtil::Read(q.dir + "/tail.cpp", &q.tail_cpp);
            model_[q.id] = q;
        }
        file.close();
        LOG(INFO) << "Load " << model_.size() << "question" << std::endl;
        return true;
    }

    bool GetAllQuestion(std::vector<Question>* question)
    {
        question->clear();
        for (const auto & kv : model_)
        {
            question->push_back(kv.second);
        }
        return true;
    }

    bool GetQuestion(const std::string& id, Question *q) const
    {
        std::map<std::string, Question>::const_iterator pos = model_.find(id);
        if (model_.end() == pos)
        {
            return false;
        }
        *q = pos->second;
        return true;
    }
private:
    std::map<std::string, Question> model_;
};
