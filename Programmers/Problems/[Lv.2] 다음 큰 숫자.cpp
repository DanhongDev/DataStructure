#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//com: 세기만 하기
int Cnt_1(int n)
{
    int cnt = 0;
    while(n>0)
    {
        if(n%2 == 1) cnt++;
        n /= 2;
    }

    return cnt;
}

int solution(int n) 
{
    int cnt_ori = __builtin_popcount(n);

    int answer = n+1;
    while(1)
    {
        if(cnt_ori == __builtin_popcount(answer)) break;
        answer++;
    }

    return answer;
}