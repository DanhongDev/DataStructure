#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> arr(N, std::vector<int>(3, 0));
    std::vector<std::vector<int>> dp(N, std::vector<int>(3, 0));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i=1; i<N; i++)
    {
        dp[i][0] = std::min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = std::min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = std::min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }

    int res = std::min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    std::cout << res << '\n';

    return 0;
}