#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    const int INF = 1e9;
    // dp[j] : B도둑의 흔적이 j일 때, A도둑의 최소 흔적
    vector<int> dp(m, INF);
    dp[0] = 0; // 시작점: 양쪽 도둑 모두 흔적 0
    
    for(int i = 0; i < info.size(); i++) {
        // 이번 물건을 훔치며 만들어질 새로운 우주(상태) 기록용
        vector<int> next_dp(m, INF);
        
        for(int j = 0; j < m; j++) {
            if(dp[j] == INF) continue; // 도달 불가능한 세계선은 패스
            
            // 1. A도둑이 훔치는 경우 (A 흔적 증가, B 흔적 유지)
            if(dp[j] + info[i][0] < n) {
                next_dp[j] = min(next_dp[j], dp[j] + info[i][0]);
            }
            
            // 2. B도둑이 훔치는 경우 (A 흔적 유지, B 흔적 증가)
            if(j + info[i][1] < m) {
                next_dp[j + info[i][1]] = min(next_dp[j + info[i][1]], dp[j]);
            }
        }
        // 모든 분기 탐색이 끝난 후 배열 덮어쓰기
        dp = next_dp;
    }
    
    int answer = INF;
    for(int j = 0; j < m; j++) {
        answer = min(answer, dp[j]);
    }
    
    return answer == INF ? -1 : answer;
}

int main()
{
    int answer = solution({{1,2}, {2,3}, {2,1}}, 4, 4);
    
    return 0;
}