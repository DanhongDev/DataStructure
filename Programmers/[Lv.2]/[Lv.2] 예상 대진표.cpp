#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(1)
    {
        answer++;

        bool is_match = false;
        //i) a가 홀, b가 짝
        if(a%2==1 && b%2==0)
        {
            is_match = (a/2)+1 == b/2 ? 1 : 0;
        }
        //ii) a가 짝, b가 홀
        else if(a%2==0 && b%2==1)
        {
            is_match = a/2 == (b/2)+1 ? 1 : 0;
        }
        //iii) a가 홀, b가 홀
        else if(a%2==1 && b%2==1)
        {
            is_match = (a/2)+1 == (b/2)+1 ? 1 : 0;
        }
        //iv) a가 짝, b가 짝
        else if(a%2==0 && b%2==0)
        {
            is_match = a/2 == b/2 ? 1 : 0;
        }

        if(is_match) break;

        //new_a, new_b 만들기
        if(a%2) a = (a/2) + 1;
        else a /= 2;
        if(b%2) b = (b/2) + 1;
        else b /= 2;
    }

    return answer;
}

int Gesolution(int n, int a, int b)
{
    int answer = 0;

    while(a!=b)
    {
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }

    return answer;
}