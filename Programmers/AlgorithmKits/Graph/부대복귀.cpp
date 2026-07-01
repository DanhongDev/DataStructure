#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<int> Dijkstra(int n, const vector<vector<int>> &adj, vector<int> &sources, int &destination)
{
    vector<int> dist(n+1, INF);
    dist[destination] = 0;
    //간선의 가중치가 모두 1이므로 일반 큐(BFS)로 진행
    queue<pair<int,int>> q;
    //일반 큐 이나, sources가 여러개 이므로 다중 출발점 다익스트라 수행 --> 역발상: destination을 출발지로!!
    q.push({destination, 0});

    //BFS
    while(!q.empty())
    {
        int cur_node = q.front().first;
        int cur_dist = q.front().second;
        q.pop();

        //현재 거리가 이미 저장되어 있는 거리보다 넘었으면 패스 --> 추가로 생략할 수 있는 조건이 있을까하고 떠올려 본 것
        if(cur_dist > dist[cur_node]) continue;

        for(int i=0; i<adj[cur_node].size(); i++)
        {
            int next_node = adj[cur_node][i];
            
            int new_dist = cur_dist + 1;

            if(new_dist < dist[next_node])
            {
                dist[next_node] = new_dist;
                q.push({next_node, new_dist});
            }
        }
    }

    vector<int> answer;
    for(int i : sources)
    {
        if(dist[i] == INF) dist[i] = -1;
        answer.push_back(dist[i]);
    }
    return answer;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    //양방향 인접 리스트 생성
    vector<vector<int>> adj(n+1);
    for(int i=0; i<roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //이 문제도 다익스트라를 sources크기 만큼 여러번 돌리는게 아니고 한꺼번에 큐에 넣어서 다중 출발점 다익스트라로 풀어보자.
    vector<int> answer = Dijkstra(n, adj, sources, destination);
    return answer;
}