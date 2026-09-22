#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    vector<vector<int>> dp(land.size(), vector<int> (land[0].size(), 0));
    for(int i=0; i<4; i++)
    {
        dp[0][i] = land[0][i];
    }
    
    
    for(int i=1; i<land.size(); i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<4; k++)
            {
                if(k!=j)
                {
                    dp[i][j] = max(dp[i][j], land[i][j] + dp[i-1][k]);
                }
            }
        }
    }
    
    //land.size()-1 대신 land.back() 사용가능
    int answer = *(max_element(dp[land.size()-1].begin(), dp[land.size()-1].end()));

    return answer;
}