#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<string> &maps, int &x, int &y)
{
    int n = maps.size(), m = maps[0].size();
    queue<pair<int,int>> q;

    q.push({x,y});
    int sum = maps[x][y] - '0';
    maps[x][y] = '0';

    int dx[4] = {-1, 1, 0 ,0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

            if(maps[nx][ny] != 'X' && maps[nx][ny] != '0')
            {
                sum += maps[nx][ny] - '0';
                maps[nx][ny] = '0';
                
                q.push({nx,ny});
            }
        }
    }

    return sum;
}
vector<int> solution(vector<string> maps)
{
    int n = maps.size(), m = maps[0].size();
    vector<int> answer;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(maps[i][j] != 'X' && maps[i][j] != '0')
            {
                answer.push_back(bfs(maps, i, j));
            }
        }
    }

    if(answer.size() == 0) return {-1};

    sort(answer.begin(), answer.end());
    return answer;
}