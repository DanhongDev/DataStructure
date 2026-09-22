#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

void DFS_Infect(int cur_node, const vector<vector<int>> &adj, unordered_set<int> &cur_infe)
{
    for(int nx_node : adj[cur_node])
    {
        if(cur_infe.find(nx_node) == cur_infe.end())
        {
            cur_infe.insert(nx_node);
            DFS_Infect(nx_node, adj, cur_infe);
        }
    }
}

void CheckInfe(const vector<vector<int>> &adj, unordered_set<int> &cur_infe, int &answer)
{
    vector<int> start_nodes(cur_infe.begin(), cur_infe.end());
    
    for(int node : start_nodes)
    {
        DFS_Infect(node, adj, cur_infe);
    }
    
    answer = max(answer, (int)cur_infe.size()); 
}

void OpenPipe(const unordered_map<int, vector<vector<int>>> &graph, const vector<int> &types, unordered_set<int> infe, int k, int cnt, int prev_type, int &answer)
{
    if(cnt == k) return;

    for(int type : types)
    {
        if(type == prev_type) continue;
        
        unordered_set<int> cur_infe(infe.begin(), infe.end());
        
        if(graph.find(type) != graph.end())
        {
            CheckInfe(graph.at(type), cur_infe, answer);
        }
        
        OpenPipe(graph, types, cur_infe, k, cnt + 1, type, answer);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k)
{
    int answer = 1;

    unordered_map<int, vector<vector<int>>> graph;
    unordered_set<int> type_set; 
    
    for(const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int type = edge[2];
        
        if(graph.find(type) == graph.end())
        {
            graph[type] = vector<vector<int>>(n + 1);
        }
        
        // 양방향 연결
        graph[type][u].push_back(v);
        graph[type][v].push_back(u);
        
        type_set.insert(type);
    }
    
    vector<int> types(type_set.begin(), type_set.end());
    
    unordered_set<int> infe;
    infe.insert(infection);

    OpenPipe(graph, types, infe, k, 0, -1, answer);

    return answer;
}