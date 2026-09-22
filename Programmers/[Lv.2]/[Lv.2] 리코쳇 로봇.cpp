#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Coord
{
    int x;
    int y;
    int cnt;
};

int solution(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    
    int start_i, start_j;
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == 'R')
            {
                start_i = i;
                start_j = j;
            }
        }
    }

    int dx[4] = {-1, 1, 0 ,0};
    int dy[4] = {0, 0, -1, 1};

    queue<Coord> q;
    q.push({start_i, start_j, 0});
    visited[start_i][start_j] = true;

    while(!q.empty())
    {
        Coord cur = q.front();
        q.pop();
       
        if(board[cur.x][cur.y] == 'G')
        {
            return cur.cnt;
        }

        for(int i=0; i<4; i++)
        {
            int nx = cur.x;
            int ny = cur.y;

            //벽에 부딪힐 때까지 전진하기
            while(1)
            {
                int nnx = nx + dx[i];
                int nny = ny + dy[i];

                if(nnx<0 || nnx>=n || nny<0 || nny>=m || board[nnx][nny] == 'D')
                {
                    break;
                }

                nx = nnx;
                ny = nny;
            }

            if(!visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.cnt+1});
            }
        }
    }

    return -1;
}