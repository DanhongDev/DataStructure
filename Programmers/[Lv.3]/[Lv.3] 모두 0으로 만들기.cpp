#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// void DFS(vector<int> &a, const vector<vector<long long>> &graph, vector<bool> &visited, const int &dest_node, int cur_node, int cnt, const int &start_node, long long &answer)
// {
//     if(cur_node == dest_node)
//     {
//         answer += cnt * a[start_node]; // 행동 횟수 추가
//         a[dest_node] += a[start_node];
//         a[start_node] -= a[start_node];
//         return;
//     }

//     for(int i=0; i<graph[cur_node].size(); i++)
//     {
//         int next_node = graph[cur_node][i];
//         if(!visited[next_node])
//         {
//             visited[next_node] = true;
//             DFS(a, graph, visited, dest_node, next_node, cnt+1, start_node, answer);
//         }
//     }
//     return;
// }
// long long solution(vector<int> a, vector<vector<int>> edges)
// {
//     // 모든 원소 값이 0이라면 return 0;
//     long long min_val = *min_element(a.begin(), a.end());
//     long long max_val = *max_element(a.begin(), a.end());
//     if(min_val==0 && max_val==0) return 0;

//     // 모든 원소들의 합이 0으로 유지가 안된다면 애초에 불가능 return -1;
//     long long sum = 0;
//     for(int x : a) sum += x;
//     if(sum != 0) return -1;

//     // 연결 리스트 만들기
//     vector<vector<long long>> graph(a.size());
//     for(int i=0; i<edges.size(); i++)
//     {
//         long long u = edges[i][0];
//         long long v = edges[i][1];

//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     // 1. 절대값이 가장 큰 값을 가진 노드를 찾기 (목적지 노드)
//     int dest_node = -1;
//     int abs_max = abs(max_val) >= abs(min_val) ? max_val : min_val;
//     for(int i=0; i<a.size(); i++)
//     {
//         if(abs_max == a[i]) 
//         {
//             dest_node = i;
//             break;
//         }
//     }
//     // 2. 목적지 노드를 향해 모든 노드가 DFS탐색을 하며 값을 옮기면...?
//     long long answer = 0;
//     for(int i=0; i<graph.size(); i++)
//     {
//         if(i == dest_node) continue; // 현재 노드가 이미 도착지 노드라면 continue;

//         vector<bool> visited(a.size(), false);
//         visited[i] = true;
//         DFS(a, graph, visited, dest_node, i, 0, i, answer);
//     }
    
//     return answer;
// }

void DFS(int cur_node, vector<long long> &arr, const vector<vector<int>> &graph, vector<bool> &visited, long long &answer)
{
    visited[cur_node] = true;

    for(int next_node : graph[cur_node])
    {
        if(!visited[next_node])
        {
            // 자식 노드 끝까지 파고 내려가기
            DFS(next_node, arr, graph, visited, answer);

            // 자식 값을 부모에게 전송
            arr[cur_node] += arr[next_node];

            // 자식의 절대값만큼 행동 횟수 증가
            answer += abs(arr[next_node]);
        }
    }
}
long long solution(vector<int> a, vector<vector<int>> edges)
{
    long long sum = 0;
    vector<long long> arr(a.size());
    for(int i=0; i<a.size(); i++)
    {
        arr[i] = a[i];
        sum += a[i];
    }
    if(sum != 0) return -1;

    vector<vector<int>> graph(a.size());
    for(auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> visited(a.size(), false);
    long long answer = 0;
    
    DFS(0, arr, graph, visited, answer);

    return answer;
}