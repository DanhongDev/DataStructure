#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
    int x;
    int y;
    int dist;
};

int BFS(vector<string> &places, int x, int y)
{
    queue<Node> q;
    q.push({x, y, 0});
    
    int dx[4] = {-1, 1, 0 ,0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[x][y] = true;

    while(!q.empty())
    {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_dist = q.front().dist;
        q.pop();

        if(cur_dist == 2) continue;

        for(int i=0; i<4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx<0 || nx>=5 || ny<0 || ny>=5 || places[nx][ny] == 'X') continue;

            if(!visited[nx][ny])
            {
                if(places[nx][ny] == 'P')
                {
                    return 0;
                }
                q.push({nx, ny, cur_dist + 1});
                visited[nx][ny] = true;
            }
        }
    }

    return 1;
}
int Check(vector<string> &p)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(p[i][j] == 'P')
            {
                if(!BFS(p, i, j))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for(vector<string> p : places)
    {
        answer.push_back(Check(p));
    }

    return answer;
}