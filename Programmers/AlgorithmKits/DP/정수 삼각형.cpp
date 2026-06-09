#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];

    int j_0 = -1, max_val = -1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<triangle[i].size(); j++)
        {
            if(j==0) j_0 = -1;
            else j_0 = dp[i-1][j-1];
            dp[i][j] = triangle[i][j] + max(dp[i-1][j], j_0);
            
            max_val = max_val > dp[i][j] ? max_val : dp[i][j];
        }
    }

    return max_val;
}

int main()
{
    vector<vector<int>> arr = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    int answer = solution(arr);

    return 0;
}