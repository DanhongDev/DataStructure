#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    if(n%2==1) return 0;

    vector<long long> dp(n+1 ,0);
    dp[2] = 3, dp[4] = 11;
    for(int i=6; i<=dp.size(); i++)
    {
        if(i%2==1)
        {
            continue;
        }
        dp[i] = (((dp[i-2] * 4) % 1000000007) - (dp[i-4] % 1000000007) + 1000000007) % 1000000007;
    }
    
    return dp[n];
}