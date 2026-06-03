#include <iostream>
#include <string>
#include <vector>
using namespace std;

string dict = "AEIOU";
bool dfs(const string& word, string cur, int &cnt)
{
    if(cur == word)
    {
        return true;
    }
    
    if(cur.size() == dict.size())
    {
        return false;
    }
    
    for(int i=0; i<dict.size(); i++)
    {
        cnt++;
        if(dfs(word, cur+dict[i], cnt))
        {
            return true;
        }
    }

    return false;
}

int solution(string word) 
{
    //A E I O U의 순열이 아니고 중복되는 조합이다. --> permutation 사용X
    //방문 취소하고 다음 경우의 수를 찾는다. --> 백트래킹
    int cnt = 0;
    dfs(word, "", cnt);
    return cnt;
}