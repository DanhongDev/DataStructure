#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    //com1) 양방향 인접 리스트 생성
    vector<vector<int>> adj(n+1);
    for(int i=0; i<edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> dist(n+1, -1);
    queue<int> q;

    //1번 노드 삽입
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        //com3) 전체 edge를 탐색 대신 현재 노드와 연결된 노드만 탐색
        for(int next : adj[cur])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                //com2) 방문하지 않은 노드일 경우만 큐에 넣는다.
                q.push(next);
            }
        }
    }

    //dist배열을 탐색하여 최댓값과 똑같은 개수 세기
    int answer = 0;
    int max_val = *(max_element(dist.begin(), dist.end()));
    for(int i=1; i<=n; i++)
    {
        if(dist[i] == max_val) answer++;
    }

    return answer;
}
















//다시 한 번 풀어보기
int reSolution(int n, vector<vector<int>> edge) 
{
    //양방향 인접 리스트 생성
    vector<vector<int>> adj(n+1);
    for(int i=0; i<edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> dist(n+1, -1);

    q.push(1);
    dist[1] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : adj[cur])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    int answer = 0;
    int max_val = *(max_element(dist.begin(), dist.end()));
    for(int i=0; i<dist.size(); i++)
    {
        if(dist[i] == max_val) answer++;
    }
    return answer;
}