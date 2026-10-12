#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int n = board.size(), m = board[0].size();
    vector<vector<int>> diff(n+1, vector<int>(m+1, 0));
    
    for(const auto &s : skill)
    {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];
        
        int v = (type == 1) ? -degree : degree;
        
        diff[r1][c1] += v;
        diff[r1][c2+1] -= v;
        diff[r2+1][c1] -= v;
        diff[r2+1][c2+1] += v;
    }
    
    for(int i=0; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            diff[i][j] += diff[i][j-1];
        }
    }
    for(int j=0; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            diff[i][j] += diff[i-1][j];
        }
    }
    
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] + diff[i][j] > 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}