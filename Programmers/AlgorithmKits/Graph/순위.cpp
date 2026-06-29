#include <string>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, int n, const vector<vector<int>> &graph)
{
    vector<bool> visited(n+1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    int cnt = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : graph[cur])
        {
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    //승자 큐, 패자 큐를 만들어 BFS돌리면.. 알 수 있을까...?

    //결국 "정확하게 순위가 매길 수 있는"이라는 기준을 명확하게 알아내야 한다.
        //1. 치른 경기가 (n-1)번인 선수
        //2. 1번 결과의 선수가 2위 혹은 (n-1)위 라면, 그 선수와의 승패
    //--> (X가 확실하게 이긴 선수의 수) + (X를 확실하게 이긴 선수의 수) = n-1
    
    vector<vector<int>> win(n+1);
    vector<vector<int>> lose(n+1);
    for(int i=0; i<results.size(); i++)
    {
        int u = results[i][0];
        int v = results[i][1];
        win[u].push_back(v);
        lose[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++)
    {
        int win_cnt = bfs(i, n, win);
        int lose_cnt = bfs(i, n, lose);

        if(win_cnt + lose_cnt == n-1)
        {
            answer++;
        }
    }
         
    return answer;
}

int Floyd_Warshall(int n, vector<vector<int>> results)
{
    int answer = 0;
    //2차원 배열 준비: graph[i][j]를 만들어 i가 j를 이겼다면 true
    //거쳐 가는 노드 중심 탐색: 노드 k를 거쳐 갈 때 승패가 연결되는지 확인
    //점화식: graph[i][k]가 true이고 graph[k][j]가 true라면 graph[i][j]도 true

    //배열 초기화
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));

    //1. 직접적인 경기 결과 반영 (results 탐색)
    for(int i=0; i<results.size(); i++)
    {
        int win = results[i][0];
        int lose = results[i][1];
        graph[win][lose] = true;
    }

    //2. 플로이드-워셜 (간접 승패 관계 업데이트)
    //반드시 거쳐가는 노드가 가장 바깥쪽 루프여야 한다.
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(graph[i][k] && graph[k][j])
                {
                    graph[i][k] = true;
                }
            }
        }
    }

    //3. 정확하게 순위를 매길 수 있는 선수 카운트
    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            if(graph[i][j] || graph[j][i])
            {
                cnt++;
            }
        }

        if(cnt == n-1)
        {
            answer++;
        }
    }

    return answer;
}