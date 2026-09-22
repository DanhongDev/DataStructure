#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//소수 판별
bool isPrime(long long n)
{
    if(n<2) return false;

    for(long long i=2; i*i<=n; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

//진법 변환
string ConvertBase(int n, int k)
{
    if(n == 0) return "0";
    string result = "";

    while(n>0)
    {
        int remain = n%k;
        if(remain < 10)
        {
            result += to_string(remain);
        }
        else
        {
            result += (char)('A' - remain + 10);
        }

        n /= k;
    }

    reverse(result.begin(), result.end());
    return result;
}

int solution(int n, int k)
{
    int answer = 0;

    string whole = ConvertBase(n, k);

    string num = "";
    for(int i=0; i<whole.size(); i++)
    {
        if(whole[i] != '0')
        {
            num += whole[i];
        }

        if(whole[i] == '0' || i == whole.size()-1)
        {
            if(!num.empty())
            {
                if(isPrime(stoll(num)))
                {
                    answer++;
                }
            }
            num = "";
        }
    }
    return answer;
}