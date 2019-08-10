#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        std::vector<bool> v(len+1,false);
        v[0] = true;
        for(int i = 1; i <= len; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(v[j] && dict.find(s.substr(j,i-j)) != dict.end())
                {
                    v[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i <= len; i++)
        {
            cout << v[i] << " ";
            // 1 0 0 0 0 1 0 0 0 1
            // 前i个字符能否根据词典中的词被成功分词
        }
        cout << endl;
        return v[len];
    }
};


int main()
{
    string str("helloword");
    unordered_set<string> dict{"hello", "word", "haha"};
    Solution s;
    s.wordBreak(str, dict);
    return 0;
}
