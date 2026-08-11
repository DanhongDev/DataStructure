#include <iostream>
#include<vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    if(n==1 || m==1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==1) return 1;
            }
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(board[i][j] == 1)
            {
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;

                answer = max(answer, board[i][j]);
            }
        }
    }
    
    return answer * answer;
}