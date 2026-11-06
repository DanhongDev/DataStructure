#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts)
{
    vector<int> div(e+1, 0);
    for(int i=1; i<=e; i++)
    {
        for(int j=i; j<=e; j+=i)
        {
            div[j]++;
        }
    }
    
    //dp[i]: i부터 e까지 구간의 최대 등장 횟수를 가진 숫자 저장
    vector<int> dp(e+1, 0);
    dp[e] = e;
    
    for(int i=e-1; i>=1; i--)
    {
        if(div[i] >= div[dp[i+1]]) 
        {
            dp[i] = i;
        }
        else 
        {
            dp[i] = dp[i+1];
        }
    }
    
    vector<int> answer;
    for(int s : starts)
    {
        answer.push_back(dp[s]);
    }
    return answer;
}