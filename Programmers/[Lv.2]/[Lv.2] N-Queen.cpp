#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N;
int col[15];
int answer=0;

bool isSafe(int row, int c)
{
    for(int i=0; i<row; i++)
    {
        if(col[i] == c || abs(row-i) == abs(c - col[i]))
        {
            return false;
        }
    }
    return true;
}
void DFS(int row)
{
    if(row == N)
    {
        answer++;
        return;
    }

    for(int c=0; c<N; c++)
    {
        if(isSafe(row, c))
        {
            col[row] = c;
            DFS(row+1);
        }
    }
}
int solution(int n)
{
    N = n;
    DFS(0);
    return answer;
}


int N;
int answer=0;
int ALL_ONES; //N개의 비트가 모두 1인 마스크(N=4: 1111)

void solve(int col, int ld, int rd) //col: 열, ld: 왼쪽 대각선, rd: 오른쪽 대각선
{
    //col의 모든 비트가 1이면? N개의 퀸을 모두 찾았다
    if(col == ALL_ONES)
    {
        answer++;
        return;
    }

    // 1. 놓을 수 있는 안전한 자리들을 한 방에 구한다. (1이 켜진 곳들)
    int safe_spots = ~(col | ld | rd) & ALL_ONES;

    // 2. 안전한 자리가 남아있는 동안 반복
    while(safe_spots > 0)
    {
        //가장 오른쪽에 켜져 있는 1만 뽑아내기
        int p = safe_spots & -safe_spots;

        //p자리에 퀸을 놓고 다음 행으로 상태를 밀어서 재귀
        solve(col|p, (ld|p) << 1, (rd|p) >> 1);

        safe_spots -= p;
    }
}