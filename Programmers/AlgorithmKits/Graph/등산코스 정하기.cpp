#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int INF = 1e9;
vector<int> Dijkstra(int n, const vector<int> &gates, const unordered_set<int> &sum, const vector<vector<pair<int,int>>> &adj)
{
    vector<int> intensity(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    //초기값 세팅
    //com3: 다중 출발점 다익스트라를 적용하면 된다. 모든 출발점을 pq에 push해놓고 다익스트라 출발.
    for(int i=0; i<gates.size(); i++)
    {
        pq.push({0, gates[i]});
        intensity[gates[i]] = 0;
    }
    
    //BFS 탐색
    while(!pq.empty())
    {
        //cur_dist: 해당 노드에 저장되어 있는 최대 intensity
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        //꿀팁: 지금 꺼낸 dist가 이미 저장되어 있는 값보다 크다면 바로 패스
        if(cur_dist > intensity[cur_node]) continue;

        //큐에서 꺼낸 노드가 산봉우리라면 패스
        if(sum.find(cur_node) != sum.end()) continue;

        //해당 노드 번호와 이어져있는 노드들을 전부 탐색
        for(int i=0; i<adj[cur_node].size(); i++)
        {
            //next_dist: 다음 노드까지의 걸리는 시간
            //com1: pair가 뒤집어 졌었디. first와 second를 변수에 잘 짝지어 넣어주기
            int next_node = adj[cur_node][i].first;
            int next_dist = adj[cur_node][i].second;

            //해당 노드까지 최댓값으로 갱신되었던 cur_dist와 다음 노드까지의 거리 next_dist를 비교하여 최댓값 갱신하기.
            int new_intensity = max(cur_dist, next_dist);
            
            //next_node에 있는 기존 intensity와 새로운 intensity를 비교하여 더 적은쪽으로 갱신
            if(new_intensity < intensity[next_node])
            {
                //com2: std::min쓰고 갱신하려면 과거의 값과 비교하므로 무조건 false가 되어버리므로 수정
                intensity[next_node] = new_intensity;
                pq.push({intensity[next_node], next_node});
            }
        }
    }

    return intensity;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    //등산코스의 경우의 수를 어떻게 고려할건지
    
    //양방향 인접 리스트
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<paths.size(); i++)
    {
        int u = paths[i][0];
        int v = paths[i][1];
        int cost = paths[i][2];

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    //com4: 산봉우리용 unordered_set 만들기
    unordered_set<int> sum(summits.begin(), summits.end());

    //모든 출입구 각각의 다익스트라 생성 --> com3: 다중 출발점 다익스트라 구현으로 해결
    //com3: 다중 출발점 다익스트라
    vector<int> intensity_arr = Dijkstra(n, gates, sum, adj);

    sort(summits.begin(), summits.end());
    int min_intensity = INF;
    int best_summit = -1;

    for(int s : summits)
    {
        if(intensity_arr[s] < min_intensity)
        {
            min_intensity = intensity_arr[s];
            best_summit = s;
        }
    }

    return {best_summit, min_intensity};
}