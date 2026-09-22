#include <string>
#include <vector>
#include <queue>
using namespace std;

bool Search(const vector<string> &board, int x, int y, const char &c)
{
    //상하좌우 우상좌상우하좌하 (대각선까지 고려)
    int dx[] = {-1, 1, 0 ,0, -1, -1, 1, 1}; 
    int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

    for(int i=0; i<8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=3 || ny<0 || ny>=3) continue;

        int cnt = 1;
        while(0<=nx && nx<3 && 0<=ny && ny<3)
        {
            if(board[nx][ny] != c)
            {
                break;
            }
            nx += dx[i];
            ny += dy[i];
            cnt++;
        }
        if(cnt == 3)
        {
            return true;
        }
    }

    return false;
}
bool is_Win(const vector<string> &board, char c)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == c)
            {
                if(Search(board, i, j, c))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
int solution(vector<string> board)
{
    int cnt_O=0, cnt_X=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == 'O') cnt_O++;
            else if(board[i][j] == 'X') cnt_X++;
        }
    }
    
    //1. X가 O보다 많은 경우
    //2. O가 X보다 2개이상 많은 경우
    if(cnt_X > cnt_O || cnt_O - cnt_X > 1) return 0; 
   
    bool win_O = is_Win(board, 'O');
    bool win_X = is_Win(board, 'X');

    if(win_O && win_X) return 0; //3. 둘 다 승리한 경우
    if(win_O && cnt_O != cnt_X + 1) return 0; //4. O가 승리한 경우
    if(win_X && cnt_O != cnt_X) return 0; //5. X가 승리한 경우

    return 1;
}