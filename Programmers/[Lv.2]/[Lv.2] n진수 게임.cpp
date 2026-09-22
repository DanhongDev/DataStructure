#include <string>
#include <vector>

using namespace std;

//진법 변환
string ConvertBase(int n, int base)
{
    if(n == 0) return "0";
    string res = "";

    while(n>0)
    {
        int rem = n % base;

        if(rem < 10)
        {
            res += to_string(rem);
        }
        else
        {
            //계산식에 맞는 문자를 ASCII로 구한 후 char형으로 캐스팅
            res += (char)('A' + rem - 10);
        }
        n /= base;
    }

    reverse(res.begin(), res.end());

    return res;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    
    //문자열의 길이 모두 구해놓기
    string whole = "";

    int cur_num = 0;
    while(whole.size() < t*m)
    {
        whole += ConvertBase(cur_num, n);
        cur_num++;
    }

    for(int i=p-1; i<whole.size(); i+=m)
    {
        answer += whole[i];

        if(answer.size() == t)
        {
            break;
        }
    }

    return answer;
}