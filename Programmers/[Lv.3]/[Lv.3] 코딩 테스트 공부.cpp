#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int max_al=0, max_co=0;
    for(auto &p : problems)
    {
        max_al = max(max_al, p[0]);
        max_co = max(max_co, p[1]);
    }

    alp = min(alp, max_al);
    cop = min(cop, max_co);

    //dp[i][j] = 알고력 i점과 코딩력 j점에 도달하기 위한 최단 시간
    vector<vector<int>> dp(max_al+1, vector<int>(max_co+1, 1e9));
    dp[alp][cop] = 0;

    for(int i=alp; i<=max_al; i++)
    {
        for(int j=cop; j<=max_co; j++)
        {
            if(i+1 <= max_al) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if(j+1 <= max_co) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);

            // 현재 스탯으로 풀 수 있는 문제 풀기 삽입
            for(auto &p : problems)
            {
                int alp_req = p[0], cop_req = p[1], alp_rwd = p[2], cop_rwd = p[3], cost = p[4];

                if(i >= alp_req && j >= cop_req)
                {
                    int next_alp = min(max_al, i + alp_rwd);
                    int next_cop = min(max_co, j + cop_rwd);
                    
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    return dp[max_al][max_co];
}

int main()
{
    int answer = solution(0, 0,	{{0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2}});
    
    return 0;
}