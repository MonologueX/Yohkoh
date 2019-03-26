#pragma once 
#include <ctemplate/template.h>
#include "oj_model.hpp"
class OjView
{
public:
    static void RenderAllQuestions(const std::vector<Question>& all_questions, std::string* html)
    {
        ctemplate::TemplateDictionary dict("all_questions");
        for (const auto& question : all_questions)
        {
            ctemplate::TemplateDictionary* table_dict = dict.AddSectionDictionary("question");
            table_dict->SetValue("id", question.id);
            table_dict->SetValue("name", question.name);
            table_dict->SetValue("star", question.star);
        }

        ctemplate::Template* tpl;
        tpl = ctemplate::Template::GetTemplate("./wwwroot/all_questions.html", ctemplate::DO_NOT_STRIP);
        tpl->Expand(html, &dict);
    }

    static void RenderQuestion(const Question& question, std::string* html)
    {
        ctemplate::TemplateDictionary dict("question");

        dict.SetValue("id", question.id);
        dict.SetValue("name", question.name);
        dict.SetValue("star", question.star);
        dict.SetValue("desc", question.desc);
        dict.SetValue("header", question.header_cpp);

        ctemplate::Template* tpl;
        tpl = ctemplate::Template::GetTemplate("./wwwroot/question.html", ctemplate::DO_NOT_STRIP);
        tpl->Expand(html, &dict);
    }
    static void RenderResult(const std::string& str_stdout, const std::string& reason, std::string* html)
    {
        ctemplate::TemplateDictionary dict("result");

        dict.SetValue("stdout", str_stdout);
        dict.SetValue("reason", reason);

        ctemplate::Template* tpl;
        tpl = ctemplate::Template::GetTemplate("./wwwroot/result.html", ctemplate::DO_NOT_STRIP);
        tpl->Expand(html, &dict);
    }
};

