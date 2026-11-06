#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int max_alp=0, max_cop=0;
    for(auto &p : problems)
    {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    // 만약 초기에 주어진 alp, cop이 max_alp,cop를 이미 넘었다면?? -> 보정
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);

    // dp[i][j]: 알고 i점과 코딩 j점에 도달하기 위한 최소 시간
    vector<vector<int>> dp(max_alp+1, vector<int>(max_cop+1, 1e9));
    dp[alp][cop] = 0;

    for(int i=alp; i<=max_alp; i++)
    {
        for(int j=cop; j<=max_cop; j++)
        {
            if(i+1 <= max_alp) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1); // 알고 공부 1점
            if(j+1 <= max_cop) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1); // 코딩 공부 1점
            // 풀 수 있는 문제들을 풀기
            for(auto &p : problems)
            {
                int req_alp = p[0], req_cop = p[1], rwd_alp = p[2], rwd_cop = p[3], cost = p[4];

                if(i >= req_alp && j >= req_cop)
                {
                    int get_alp = min(max_alp, i + rwd_alp);
                    int get_cop = min(max_cop, j + rwd_cop);

                    dp[get_alp][get_cop] = min(dp[get_alp][get_cop], dp[i][j] + cost);
                }
            }
        }
    }

    return dp[max_alp][max_cop];
}