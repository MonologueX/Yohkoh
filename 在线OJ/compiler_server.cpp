#include <unordered_map>
#include "httplib.h"
#include "compiler.hpp"
#include <jsoncpp/json/json.h>

int main()
{
    // 命名空间写在里面
    // 不要写在头文件里
    using namespace httplib;
    Server server;
    // 注册了一个回调函数，这个函数调用时机
    // 处理 Get 方法的时候
    // lambda 表达式
    server.Post("/compile", [](const Request& req, Response& resp)
    {
        (void)req;
        std::unordered_map<std::string, std::string> body_kv;
        UrlUtil::ParseBody(req.body, &body_kv);
        Json::Value req_json;
        for (auto p : body_kv)
        {
        req_json[p.first] = p.second;
        }
        // 调用 CompileAndRun
        Json::Value resp_json;
        Compiler::CompilerAndRun(req_json, &resp_json);
        // 根据具体的场景，根据请求，计算出响应结果
        Json::FastWriter writer;
        resp.set_content(writer.write(resp_json), "text/plain");
    });
    server.set_base_dir("./wwwroot");
    server.listen("0.0.0.0", 9001);
    return 0;
}
