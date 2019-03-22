#include <jsoncpp/json/json.h>
#include "util.hpp"
#include "compiler.hpp"

int main()
{
    Json::Value req;
    req["code"] = "#include <stdio.h> \n int main() {printf(\"hehe\");retuen 0;}";
    req["stdin"] = "";
    Json::Value resp;
    Compiler::CompilerAndRun(req, &resp);
    Json::FastWriter writer;
    LOG(INFO) << writer.write(resp)  << std::endl;
    return 0;
}
