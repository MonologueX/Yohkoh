#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
        int len = T.size();
        vector<int> array(len + 1);
        array[0] = 1;
/*
rabbbit rabbit 
1 1 0 0 0 0 0 
1 1 1 0 0 0 0 
1 1 1 1 0 0 0 
1 1 1 2 1 0 0 
1 1 1 3 3 0 0 
1 1 1 3 3 3 0 
1 1 1 3 3 3 3 
*/
        for(int i = 1; i < S.size() + 1; i++)
        {
            for(int j = min(i, len); j>0; j--)
            {
                if(S[i-1] == T[j-1])
                    array[j] = array[j] + array[j-1];
            }
        }
        return array[len];
    }
};

int main()
{
	std::string S, T;
	while (cin >> S >> T)
	{
		Solution s;
		s.numDistinct(S, T);
	}
	return 0;
}
