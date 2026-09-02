#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0); //{정점, 도넛, 막대, 8자}
    
    int max_node = 0;
    for(vector<int> &e : edges)
    {
        max_node = max(max_node, e[0]);
        max_node = max(max_node, e[1]);
    }
    
    vector<int> in(max_node+1, 0);
    vector<int> out(max_node+1, 0);
    for(vector<int> &e : edges)
    {
        int u = e[0];
        int v = e[1];

        in[v]++;
        out[u]++;
    }

    int total = 0;
    for(int i=1; i<=max_node; i++)
    {
        if(in[i] == 0 && out[i] >= 2)
        {
            answer[0] = i;
            total = out[i];
        }
        else if(in[i] > 0 && out[i] == 0)
        {
            answer[2]++;
        }
        else if(in[i]>=2 && out[i]==2)
        {
            answer[3]++;
        }
    }
    answer[1] = total - answer[2] - answer[3];

    return answer;
}