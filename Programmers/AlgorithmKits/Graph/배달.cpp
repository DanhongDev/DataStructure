#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

//다익스트라 알고리즘
int Dijkstra(int N, int K, int start, const vector<vector<int>> &road)
{
    int answer = 0;
    //저장 형태: {도착마을, 도로길이} 인덱스(i) 자체가 마을이 된다.
    vector<vector<pair<int,int>>> adj_arr(N+1);
    vector<int> dist(N+1, INF);
    
    dist[start] = 0;

    //양방향 인접 리스트 생성
    for(int i=0; i<road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int cost = road[i][2];

        adj_arr[a].push_back({b, cost});
        adj_arr[b].push_back({a, cost});
    }

    //저장 형태: {현재까지의 최단 거리, 노드 번호}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    //큐가 빌 때까지 탐색 반복
    while(!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        //이미 처리된 적이 있는 노드면 무시
        if(dist[cur_node] < cur_dist) continue;

        //현재 노드와 연결된 이웃 노드들을 모두 확인
        for(int i=0; i<adj_arr[cur_node].size(); i++)
        {
            int next = adj_arr[cur_node][i].first;
            int cost = adj_arr[cur_node][i].second;

            //현재 노드를 거쳐서 이웃 노드로 가는 새로운 거리 계산
            int new_dist = cur_dist + cost;

            //새로운 거리가 기존의 거리보다 짧으면 변경
            if(new_dist < dist[next])
            {
                dist[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        if(dist[i] <= K) answer++;
    }
    
    return answer;
}

//플루이드-워셜 알고리즘
int Floyd_Warshall(int N, int K, const vector<vector<int>> &road)
{
    int answer = 0;
    //1. 양방향 인접 행렬 만들기
    vector<vector<int>> adj(N+1, vector<int>(N+1, INF)); //1e9 == 10억
    for(int i=0; i<adj.size(); i++)
    {
        adj[i][i] = 0;
    }
    for(int i=0; i<road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int dist = road[i][2];
        //두 마을 a, b를 연결하는 도로는 여러개 있다고 했으므로 그중 제일 짧게 걸리는 것만 남기기
        adj[a][b] = min(adj[a][b], dist);
        adj[b][a] = min(adj[b][a], dist);
    }
    
    //2. 플루이드-워셜
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            //com1: 플루이드-워셜 최적화
            if(adj[i][k] == INF) continue;
            for(int j=1; j<=N; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        if(adj[1][i] <= K) answer++;
    }

    return answer;
}

int solution(int N, vector<vector<int> > road, int K) 
{
    //다익스트라
    int result = Dijkstra(N, K, 1, road);
    //플로이드-워셜
    //int result = Floyd_Warshall(N, K, road);
    
    return result;
}