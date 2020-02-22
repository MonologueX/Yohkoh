#pragma once

///////////////////////////////////////////////////////
// 每一个 OJ 题目对应一个目录(放在 oj_data 下)
// 目录中包含了三个文件
// 1) header.cpp: .cpp 文件的上半部分, 主要是头文件包含 + 代码模板 + 用户要实现的代码主体
// 2) tail.cpp: .cpp 文件的末尾, 包含了测试用例代码和测试用例的执行过程(用例如何组织,
//    以及通过/失败的输出日志需要满足一定的约定)
// 3) desc.txt: 题目要求的详细描述.
//
// 另外还有一个总的配置文件, 是一个 行文本文件, 记录了每个题目的id, 标题, 路径, 难度信息
// (这个文件放到内存中).
//
// 该文件需要实现一个 OjModel 类, 提供以下接口:
// 1. 获取所有题目列表
// 2. 获取某个题目的题面信息(也就是只包含 oj1.header部分的信息)
// 3. 获取某个题目的完整信息(也就是 header + tail 拼接成的完整 cpp)
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// tail.cpp 文件编写约定(此处可以考虑接入 gtest)
// 1. 每个用例是一个函数, 函数构造输入并获取校验输出.
// 2. 每个用例从标准输出输出一行日志
// 3. 如果用例通过, 统一打印 [TestName] ok!
// 4. 如果用例不通过, 统一打印 [TestName] failed! 并且给出合适的提示.
// 这样风格来设计, 可能对后期的多语言扩展不利. 但是不用引入额外的标准输入输出的配置文件,
// 实现风格更简洁好理解.
///////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>

#include "util.hpp"

// 定义一个结构体描述题目信息
struct Question {
  std::string id;       // 题目的 id
  std::string title;    // 题目的标题
  std::string star;     // 题目难度
  std::string desc;     // 题目描述
  std::string header_cpp; // 题目代码框架
  std::string tail_cpp; // 题目测试代码
};

class OjModel {
private:
  // key 为题目 id, value 为题目结构体
  std::unordered_map<std::string, Question> model_;

public:
  OjModel () {
    assert(Load("./oj_data/oj_config.cfg"));
  }

  bool Load(const std::string& config_path) {
    std::ifstream file(config_path.c_str());
    if (!file.is_open()) {
      return false;     
    }
    std::string line;
    while (std::getline(file, line)) {
      // 针对 line 进行切分, 字段用 \t 切分
      std::vector<std::string> tokens;
      StringUtil::Split(line, "\t", &tokens);
      // 跳过出错的行
      if (tokens.size() != 4) {
        continue;
      }
      Question question;
      question.id = tokens[0];
      question.title = tokens[1];
      question.star = tokens[2];
      const std::string dir = tokens[3];
      FileUtil::ReadFile(dir + "/desc.txt", &question.desc);
      FileUtil::ReadFile(dir + "/header.cpp", &question.header_cpp);
      FileUtil::ReadFile(dir + "/tail.cpp", &question.tail_cpp);
      model_[question.id] = question;
    }
    file.close();
    LOG(INFO) << "Load " << model_.size() << " questions!\n";
    return true;
  }

  bool GetAllQuestions(std::vector<Question>* questions) const {
    for (const auto& kv : model_) {
      questions->push_back(kv.second);
    }
    // 再来个排序吧, 按照 id 升序. 如果是想按照其他顺序排序
    // 只要调整 lambda 的实现细节即可.
    std::sort(questions->begin(), questions->end(),
        [](const Question& l, const Question& r) {
          return std::stoi(l.id) < std::stoi(r.id);
        });
    return true;
  }

  bool GetQuestion(const std::string& id, Question* question) const {
    // 1. 根据 id 找到题目的具体信息
    auto it = model_.find(id);
    if (it == model_.end()) {
      // 该 id 对应的题目不存在
      LOG(ERROR) << "Question not found! id=" << id << "\n";
      return false;
    }
    *question = it->second;
    return true;
  }
};
