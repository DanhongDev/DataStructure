#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int BFS(vector<vector<int>> &land, int x, int y, set<int> &cols)
{
    int n=land.size(), m=land[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    land[x][y] = 0;
    cols.insert(y);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int sum = 1;
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

            if(land[nx][ny] == 1)
            {
                sum++;
                cols.insert(ny);
                q.push({nx, ny});
                land[nx][ny] = 0;
            }
        }
    }

    return sum;
}

int solution(vector<vector<int>> land)
{
    int n=land.size(), m=land[0].size();
    
    vector<int> col_oil(m, 0);
    
    int answer = 0;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(land[i][j] == 1)
            {
                set<int> cols;
                int oil_size = BFS(land, i, j, cols);

                for(int c : cols)
                {
                    col_oil[c] += oil_size;
                }
            }

        }
    }
    
    return *max_element(col_oil.begin(), col_oil.end());
}