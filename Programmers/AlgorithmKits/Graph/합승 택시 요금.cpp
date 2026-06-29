#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 0;
    //1. 합승인지 아닌지를 어떻게 구별할까
    //2. A의 플루이드, B의 플루이드 각각 구해야 하는것일까?
    
    //i) 양방향 인접리스트를 만들어야 할 것같다.
    vector<vector<int>> adj(n+1, vector<int>(n+1, 40000000));
    for(int i=0; i<=n; i++)
    {
        adj[i][i] = 0;
    }
    for(int i=0; i<fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int fare = fares[i][2];

        adj[start][end] = fare;
        adj[end][start] = fare;
    }

    //ii) 만든 양방향 인접리스트를 참고하여 플루이드-워셜 돌리기
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            if(adj[i][k] >= 40000000) continue;
            
            for(int j=1; j<=n; j++)
            {
                //지금은 동승을 안했을때의 상황만 구했다.
                //즉 그냥 단순히 혼자서 k를 거쳐서 목적지(j)까지 가는 가장 최소의 요금만 구했다.
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
  
                //adj[s][k]+adj[k][a]+adj[k][b]와 adj[s][a]+adj[s][b]를 비교
                //더 작은값을 answer에 대입
                //--> 우선 adj를 다 완성시키고 나서 해야함.
            }
        }
    }
    
    //adj완성 후에 정답 비교
    answer = adj[s][a] + adj[s][b];
    for(int i=1; i<=n; i++)
    {
        answer = min(answer, adj[s][i]+adj[i][a]+adj[i][b]);
    }

    return answer;
}

//다시 한 번 풀어보기
//이번엔 다익스트라 방법으로
const int INF = 1000000000;
vector<int> Dijkstra(int s, int n, const vector<vector<pair<int,int>>> &adj)
{
    //거리 만들기
    vector<int> dist(n+1, INF);
    //시작 노드는 0으로 설정
    dist[s] = 0;
    //거리 오름차순 우선순위 큐
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        //현재의 거리보다 이미 작은 값이 들어가있다면 스킵
        if(dist[cur_node] < cur_dist) continue;

        //탐색
        for(int i=0; i<adj[cur_node].size(); i++)
        {
            //현재 노드와 이어져 있는 노드, 거리 뽑아내기
            int next_node = adj[cur_node][i].first;
            int next_cost = adj[cur_node][i].second;
            
            //현재 노드에 저장되어 있는 거리(cur_dist)와 다음 노드로 가는 거리(next_cost)를 더하기
            int new_dist = cur_dist + next_cost;

            //더한 값이 이전에 기록되어 있던 거리보다 작으면 갱신 후 큐에 푸쉬
            if(new_dist < dist[next_node])
            {
                dist[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }

    return dist;
}
int reSolution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    //양방향 인접 리스트 만들기
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<fares.size(); i++)
    {
        int u = fares[i][0];
        int v = fares[i][1];
        int cost = fares[i][2];

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    vector<int> dist_s = Dijkstra(s, n, adj);
    vector<int> dist_a = Dijkstra(a, n, adj);
    vector<int> dist_b = Dijkstra(b, n, adj);

    int answer = INF;
    for(int i=1; i<=n; i++)
    {
        if(dist_s[i] != INF && dist_a[i] != INF && dist_b[i] != INF)
        {
            answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
        }
    }

    return answer;
}