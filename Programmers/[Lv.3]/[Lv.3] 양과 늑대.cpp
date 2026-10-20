#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int> &info, const vector<vector<int>> &graph, int cur, vector<int> next, int sheep, int wolf, int &answer)
{
    if(sheep <= wolf) return;

    answer = max(answer, sheep);

    for(int c : graph[cur])
    {
        next.push_back(c);
    }

    for(int i=0; i<next.size(); i++)
    {
        vector<int> temp = next;
        temp.erase(temp.begin()+i);

        if(info[next[i]] == 0) DFS(info, graph, next[i], temp, sheep+1, wolf, answer);
        else DFS(info, graph, next[i], temp, sheep, wolf+1, answer);
    }
}
int solution(vector<int> info, vector<vector<int>> edges)
{
    //그래프 생성
    vector<vector<int>> graph(info.size());
    for(const auto &e : edges)
    {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
    }

    int answer = 0;
    vector<int> next;
    //DFS 1회
    DFS(info, graph, 0, next, 1, 0, answer);

    return answer;
}