#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>> &picture, int type, int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    picture[x][y] = -1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int area = 1;
    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<0 || nx>=picture.size() || ny<0 || ny>=picture[0].size() || picture[nx][ny] == 0) continue;

            if(picture[nx][ny] != -1 && picture[nx][ny] == type)
            {
                area++;
                picture[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
    }

    return area;
}
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int cnt = 0, area = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(picture[i][j] > 0)
            {
                cnt++;
                area = max(area, BFS(picture, picture[i][j], i, j));
            }
        }
    }

    return {cnt, area};
}