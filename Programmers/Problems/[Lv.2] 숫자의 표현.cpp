#include <string>
#include <vector>

using namespace std;

int mysolution(int n) 
{
    int answer = 0;

    int sum = 0;
    for(int i=n; i>=1; i--)
    {
        sum = 0;
        int temp = i;
        while(sum < n)
        {
            sum += temp;
            temp--;
            if(temp == 0) break;
        }

        if(sum == n) answer++;
    }
    
    return answer;
}

//문제의 의도: O(N^2)처럼 보이는 문제지만 투 포인터를 활용해 O(N)으로도 풀 수 있는지?
int Gesolution(int n)
{
    int answer = 0;
    int start = 1, end = 1;
    int sum = 1;

    while(start <= n)
    {
        if(sum == n)
        {
            answer++;
            end++;
            sum += end;
        }
        else if(sum < n)
        {
            end++;
            sum += end;
        }
        else
        {
            sum -= start;
            start++;
        }
    }

    return answer;
}