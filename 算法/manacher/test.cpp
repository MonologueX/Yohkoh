#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <time.h>
using namespace std;

class Manacher
{
public:
    int Num(std::string s)
    {
        std::string str = ManacherInit(s);
        PrintManacherInit(str);
        int num = CalManacher(str) - 1;
        return num;
    }
private:
    int CalManacher(std::string s)
    {
        int question = 0;
        std::vector<int> len;
        len.resize(s.size(), 0);
        int max = 0;
        int mid = 0;
        int size = s.size();
        for (int i = 1; i < size; i++)
        {
            if (i < max)
                len[i] = Min(max-i, len[2*mid-i]);
            else 
                len[i] = 1;

            while (s[i+len[i]] == s[i-len[i]])
                len[i]++;

            if (len[i]+i > max)
            {
                max = len[i] + i;
                mid = i;
            }

            if (question < len[i])
                question = len[i];
            PrintLen(len, s, i);
            cout << endl;
            sleep(1);
        }
        return question;
    }
    std::string ManacherInit(std::string s)
    {
        std::string str;
        str += "$#";
        for (size_t i = 0; i < s.size(); i++)
        {
            str += s[i];
            str += '#';
        }
        return str;
    }
    void PrintManacherInit(std::string s)
    {
        cout << "初始化Manacher: ";
        cout << s << endl;
    }
    void PrintLen(std::vector<int> len, std::string s, int num)
    {
        system("clear");
        for (size_t i = 1; i < len.size(); i++)
            cout << s[i] << '\t';
        cout << endl;
        for (size_t i = 1; i <= num; i++)
            cout << len[i] << '\t';
        cout << endl;
    }
    int Min(int num1, int num2)
    {
        if (num1 > num2)
            return num2;
        return num1;
    }
};


int main()
{
    std::string str;
    str += "acbaabab";
    Manacher m;
    cout << m.Num(str) << endl;
    return 0;
}
