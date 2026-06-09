#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(const auto& puddle : puddles)
    {
        dp[puddle[1] -1 ][puddle[0] -1 ] = -1;
    }

    //[0,0]은 집이므로 초기값 1
    dp[0][0] = 1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //시작 칸(집) 건너뛰기
            if(i==0 && j==0) continue;
            //물웅덩이를 만나면 경우의 수를 0으로
            if(dp[i][j] == -1) 
            {
                dp[i][j] = 0;
            }
            else
            {
                //i와 j가 0보다 클 때만 dp값을 더해주는걸로. (i=0, j=0인 행과열 예외처리 코드)
                int from_up = i > 0 ? dp[i-1][j] : 0;
                int from_left = j > 0 ? dp[i][j-1] : 0;

                dp[i][j] = (from_up + from_left) % 1000000007;
            }
        }
    }

    return dp[n-1][m-1];
}