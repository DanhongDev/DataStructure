#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<vector<int>> matrix_sizes)
{
    int n = matrix_sizes.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len=2; len<=n; len++)
    {
        for(int i=0; i<=n-len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++)
            {
                int cost = matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1];

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
            }
        }
    }

    return dp[0][n-1];
}