/***********************************
 * 文件名称: test.cpp
 * 文件描述: 测试
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream> 
#include <sstream> 
#include <memory> 
#include <string> 
#include <json/json.h> 

using namespace std;

void ParseJson(std::string &s) 
{ 
    JSONCPP_STRING errs; 
    Json::Value root; 
    Json::CharReaderBuilder readerBuilder; 
    std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader()); 
    bool res = jsonReader->parse(s.data(), s.data()+s.size(), &root, &errs); 
    if(!res || !errs.empty())
    { 
        std::cerr << "json parse error: " << errs << std::endl; 
        return; 
    }
    std::cout << "Name: " << root["Name"].asString() << std::endl; 
    std::cout << "Age: " << root["Age"].asInt() << std::endl; 
    std::cout << "Lang: " << root["Lang"].asString() << std::endl; 
}


int main() 
{ 
    std::string s = "{\"Age\" : 26,\"Lang\" : \"c++\",\"Name\" : \"zhangsan\"}"; 
    std::cout << s << std::endl; 
    ParseJson(s); 
    return 0; 
    //Json::Value root; 
    //Json::StreamWriterBuilder wb; 
    //std::ostringstream os; 
    //root["Name"] = "zhangsan"; 
    //root["Age"] = 26; 
    //root["Lang"] = "c++"; 
    //std::unique_ptr<Json::StreamWriter> jsonWriter(wb.newStreamWriter()); 
    //jsonWriter->write(root, &os); 
    //std::string s = os.str(); 
    //std::cout << s << std::endl; 
    //return 0; 
}
