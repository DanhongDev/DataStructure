#include <string>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<string>> &places, int &x, int &y)
{
    queue<pair<int,int>> q;
    q.push({x, y});

    while(!q.empty())
    {
        
    }
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(places[i][j] == "P")
            {
                answer.push_back(BFS(places, i, j));
            }
        }
    }

    return answer;
}