#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Extend(const string &s, int left, int right)
{
    while(left>=0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return right - left - 1;
}
int solution(string s)
{
    if(s.size() == 1) return 1;

    int answer=0;
    
    for(int i=0; i<s.size(); i++)
    {
        int len1 = Extend(s, i, i);

        int len2 = Extend(s, i, i+1);

        answer = max({answer, len1, len2});
    }

    return answer;
}