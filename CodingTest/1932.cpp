#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> arr(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            if(j==0)
            {
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
            }
        }
    }
    
    int ans = -1;
    for(int i=0; i<N; i++)
    {
        ans = ans > dp[N-1][i] ? ans : dp[N-1][i];
    }
    std::cout << ans << '\n';
    
    return 0;
}