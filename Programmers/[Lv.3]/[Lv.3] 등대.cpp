#include <string>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>> &graph, vector<bool> &onoff, vector<bool> &visited, int cur)
{
    visited[cur] = true;

    for(int next : graph[cur])
    {
        if(!visited[next])
        {
            DFS(graph, onoff, visited, next);

            if(!onoff[next])
            {
                onoff[cur] = true;
            }
        }
    }
    return;
}
int solution(int n, vector<vector<int>> lighthouse)
{
    if(n==2) return 1;

    vector<vector<int>> graph(n+1);
    for(auto &l : lighthouse)
    {
        graph[l[0]].push_back(l[1]);
        graph[l[1]].push_back(l[0]);
    }

    vector<bool> visited(n+1, false);
    vector<bool> onoff(n+1, false);
    DFS(graph, onoff, visited, 1);

    int answer = 0;
    for(int i=1; i<=onoff.size(); i++)
    {
        if(onoff[i]) answer++;
    }
    return answer;
}