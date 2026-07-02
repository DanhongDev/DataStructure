#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    if(n>1) dp[2] = 2;
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }

    return dp[n];
}

//O(N)을 O(1)로 만들어버리기: 변수로만 이용하기
long long Gesolution(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;

    long long prev2 = 1;
    long long prev1 = 2;
    long long cur = 0;

    for(int i=3; i<=n; i++)
    {
        cur = (prev2+prev1) % 1234567;
        prev2=prev1;
        prev1=cur;
    }

    return cur;
}