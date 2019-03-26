#include "httplib.h"
#include <jsoncpp/json/json.h>
#include "util.hpp"
#include "oj_model.hpp"
#include "oj_view.hpp"
#include "compiler.hpp"

int main()
{
    OjModel model;
    model.Load();

    using namespace httplib;
    Server server;
    server.Get("/all_questions", [&model](const Request& req, Response& resp)
    {
        (void)req;
        std::vector<Question> all_questions;
        model.GetAllQuestion(&all_questions);
        std::string html;
        OjView::RenderAllQuestions(all_questions, &html);
        resp.set_content(html, "text/html");
    });
    
    server.Get(R"(/question/(\d+))", [&model](const Request& req, Response& resp)
    {
        Question question;
        model.GetQuestion(req.matches[1].str(), &question);
        //LOG(INFO) << "desc:" << question.desc << std::endl;
        std::string html;
        OjView::RenderQuestion(question, &html);
        resp.set_content(html, "text/html");
    });

    server.Post(R"(/compile/(\d+))", [&model](const Request& req, Response& resp)
    {
        Question question;
        model.GetQuestion(req.matches[1].str(), &question);
        
        std::unordered_map<std::string, std::string> body_kv;
        UrlUtil::ParseBody(req.body, &body_kv);
        const std::string& user_code = body_kv["code"];

        Json::Value req_json;
        req_json["code"] = user_code + question.tail_cpp;

        Json::Value resp_json;
        Compiler::CompilerAndRun(req_json, &resp_json);
        // 根据具体的场景，根据请求，计算出响应结果
        
        std::string html;
        OjView::RenderResult(resp_json["stdout"].asString(), resp_json["reason"].asString(), &html);
        resp.set_content(html, "text/html");
    });
    server.set_base_dir("./wwwroot");
    server.listen("0.0.0.0", 9001);
    return 0;
}
