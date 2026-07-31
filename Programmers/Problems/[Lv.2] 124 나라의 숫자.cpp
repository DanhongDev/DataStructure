#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n)
{
    string answer = "";

    while(n>0)
    {
        if(n%3==0)
        {
            answer += "4";
            n = (n/3) - 1; //여기가 이문제의 핵심! 0이 없으므로 다음 몫의 1을 가져온다.
        }
        else if(n%3==1)
        {
            answer += "1";
            n /= 3;
        }
        else if(n%3==2)
        {
            answer += "2";
            n /= 3;
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}