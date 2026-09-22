#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    //보드판 생성
    vector<vector<int>> board(rows, vector<int>(columns, 0));
    int num = 1;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            board[i][j] = num++;
        }
    }
    
    for(vector<int> q : queries)
    {
        int x1 = q[0]-1;
        int x2 = q[2]-1;
        int y1 = q[1]-1;
        int y2 = q[3]-1;

        int first = board[x1][y1];
        int min_val = first;
        //왼쪽 열 회전
        for(int i=x1; i<x2; i++) 
        {
            board[i][y1] = board[i+1][y1];
            min_val = min(min_val, board[i][y1]);
        }
        //밑 행 회전
        for(int j=y1; j<y2; j++) 
        {
            board[x2][j] = board[x2][j+1];
            min_val = min(min_val, board[x2][j]);

        }
        //오른쪽 열 회전
        for(int i=x2; i>x1; i--) 
        {
            board[i][y2] = board[i-1][y2];
            min_val = min(min_val, board[i][y2]);

        }
        //윗 행 회전
        for(int j=y2; j>y1+1; j--) 
        {
            board[x1][j] = board[x1][j-1];
            min_val = min(min_val, board[x1][j]);

        }
        //마지막 칸은 first값으로
        board[x1][y1+1] = first;

        answer.push_back(min_val);
    }
    
    return answer;
}