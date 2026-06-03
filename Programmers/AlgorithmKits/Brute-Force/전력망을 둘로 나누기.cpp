#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int dfs(int v, vector<vector<int>>& tt, vector<bool>& visited)
{
    int cnt=1;
    visited[v] = true;

    for(int i=0; i<tt[v].size(); i++)
    {
        int next = tt[v][i];
        if(!visited[next])
        {
            cnt += dfs(next, tt, visited);
        }
    }

    return cnt;
}
int solution(int n, vector<vector<int>> wires) 
{
    int answer = 9999;
    
    //인덱스 1부터 맞추기 위해
    vector<vector<int>> tt(n+1);
    //2차원 벡터로 그래프(인접 리스트) 만들기
    for(int i=0; i<wires.size(); i++)
    {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        tt[v1].push_back(v2);
        tt[v2].push_back(v1);
    }

    //하나씩 끊어보기
    for(int i=0; i<wires.size(); i++)
    {
        int v1 = wires[i][0];
        int v2 = wires[i][1];

        //1. 매번 새로운 visited 배열 생성
        vector<bool> visited(n+1, false);

        //2. v2는 이미 갔다고 하여 선 끊는 효과 내기
        visited[v2] = true;

        //3. v1에서 dfs출발하여 연결된 탑 개수 세기
        int cnt = dfs(v1, tt, visited);

        //4. 두 전력망의 차이를 구한 후 최솟값을 갱신
        int diff = abs(cnt - (n-cnt));
        answer = min(answer, diff);
    }


    return answer;
}