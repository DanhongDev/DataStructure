#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;

    int R = grid.size();
    int C = grid[0].size();
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    vector<vector<vector<int>>> visited(R, vector<vector<int>>(C, vector<int>(4, 0)));
    
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            for(int k=0; k<4; k++)
            {
                if(visited[i][j][k]) continue;

                int x=i, y=j, d=k;
                int len = 0;
                
                while(!visited[x][y][d])
                {
                    visited[x][y][d] = 1;
                    len++;
                    
                    // 방향 전환
                    if(grid[x][y] == 'L') d = (d+3) % 4; //왼쪽 90도 회전
                    else if(grid[x][y] == 'R') d = (d+1) % 4; //오른쪽 90도 회전

                    x = (x + dx[d] + R) % R;
                    y = (y + dy[d] + C) % C;
                }

                answer.push_back(len);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}