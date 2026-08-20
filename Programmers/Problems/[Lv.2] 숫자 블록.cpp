#include <string>
#include <vector>

using namespace std;

long long getMaxDiv(long long n)
{
    if(n==1) return 0;

    long long max_div = 1;

    for(long long i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(n/i <= 10000000)
            {
                return n/i;
            }

            max_div = i;
        }
    }

    return max_div;
}
vector<int> solution(long long begin, long long end)
{
    vector<int> answer;

    for(long long i=begin; i<=end; i++)
    {
        answer.push_back(getMaxDiv(i));
    }
    
    return answer;
}

int main()
{
    vector<int> answer =solution(1000000014, 1000000015);
    
    return 0;
}