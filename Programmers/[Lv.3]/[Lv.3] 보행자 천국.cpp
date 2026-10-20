#include <vector>
#include <queue>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map)
{
    if(m==1 && n==1) return 1;
    
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int i=1; i<m; i++)
    {
        if(city_map[i][0] == 1) break;
        dp[i][0][0] = 1;
    }
    for(int j=1; j<n; j++)
    {
        if(city_map[0][j] == 1) break;
        dp[0][j][1] = 1;
    }

    // dp 채우기
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(city_map[i][j] == 1) continue;

            if(city_map[i-1][j] == 0) dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            else if(city_map[i-1][j] == 2) dp[i][j][0] = dp[i-1][j][0] % MOD;
            
            if(city_map[i][j-1] == 0) dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
            else if(city_map[i][j-1] == 2) dp[i][j][1] = dp[i][j-1][1] % MOD;
        }
    }
    
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
}