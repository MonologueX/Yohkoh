#include <iostream>
#include <string.h>
using namespace std;
int BF(string S,string T)
{
    int index=0;
    int i=0;
    int j=0;
    while(S[i]!='\0'&&T[j]!='\0')
    {
        if(S[i]==T[j])
        {
            i++;
            j++;
        }
        else
        {
            index++;
            i=index;
            j=0;
        }
    }
    if(T[j]=='\0') return index+1;
    else return 0;
}
int main()
{
    string A;
    cin>>A;
    string B;
    cin>>B;
    cout<<"匹配的开始位置是:"<<BF(A,B)<<endl;
    return 0;
}
