#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;

    // 0과 size() 인덱스는 통과 용으로 쓰기.
    vector<string> board(grid.size()+2);
    
    int dx=1, dy=1;
    // 방향 전환
    if(board[dx][dy] == 'L')
    {
        if(dx==0 && dy==1)
        {
            dx=-1;
            dy=0;
        }
        else if(dx==0 && dy==-1)
        {
            dx=1;
            dy=0;
        }
        else if(dx==1 && dy==0)
        {
            dx=0;
            dy=1;
        }
        else if(dx==-11 && dy==0)
        {
            dx=0;
            dy=-1;
        }
    }
    else if(board[dx][dy] == 'R')
    {
        if(dx==0 && dy==1)
        {
            dx=1;
            dy=0;
        }
        else if(dx==0 && dy==-1)
        {
            dx=-1;
            dy=0;
        }
        else if(dx==1 && dy==0)
        {
            dx=0;
            dy=-1;
        }
        else if(dx==-11 && dy==0)
        {
            dx=0;
            dy=1;
        }
    }

    
    return answer;
}

int main()
{
    vector<int> answer = solution({"SL", "LR"});
    
    return 0;
}