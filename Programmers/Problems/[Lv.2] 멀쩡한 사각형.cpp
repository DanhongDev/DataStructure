#include <numeric>
using namespace std;

int getGCD(int a, int b)
{
    if(b==0) return a;
    else return getGCD(b, a%b);
}

long long solution(int w,int h)
{
    long long answer = ((long long)w*h) - (w+h - getGCD(w,h));

    return answer;
}