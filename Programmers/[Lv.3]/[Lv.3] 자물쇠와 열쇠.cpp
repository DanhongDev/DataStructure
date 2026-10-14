#include <string>
#include <vector>

using namespace std;

void Spin_Matrix(vector<vector<int>> &board)
{
    int m = board.size();
    //y=-x 대칭
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            swap(board[i][j], board[j][i]);
        }
    }
    //좌우 반전
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m/2; j++)
        {
            swap(board[i][j], board[i][m-1-j]);
        }
    }
}
bool Check(const vector<vector<int>> &grid, int m, int n)
{
    for(int i=m-1; i<(m-1)+n; i++)
    {
        for(int j=m-1; j<(m-1)+n; j++)
        {
            if(grid[i][j] != 1) return false;
        }
    }

    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int m = key.size(), n = lock.size();
    vector<vector<int>> Trans = key;
    
    //패딩 행렬 생성
    int padding = n + 2*(m-1);
    vector<vector<int>> grid(padding, vector<int>(padding, 0));
    for(int i=m-1; i<(m-1)+n; i++)
    {
        for(int j=m-1; j<(m-1)+n; j++)
        {
            grid[i][j] = lock[i-(m-1)][j-(m-1)];
        }
    }

    int cnt=4;
    while(cnt--)
    {
        for(int i=0; i<=grid.size()-m; i++)
        {
            for(int j=0; j<=grid.size()-m; j++)
            {
                for(int x=0; x<m; x++)
                {
                    for(int y=0; y<m; y++)
                    {
                        grid[i+x][j+y] += Trans[x][y];
                    }
                }

                if(Check(grid, m, n)) return true;

                for(int x=0; x<m; x++)
                {
                    for(int y=0; y<m; y++)
                    {
                        grid[i+x][j+y] -= Trans[x][y];
                    }
                }
            }
        }

        //90도 회전
        Spin_Matrix(Trans);
    }
    
    return false;
}