#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    vector<int> numbers;
    long long fact = 1;

    for(int i=1; i<=n; i++)
    {
        numbers.push_back(i);
        fact *= i;
    }

    k--;
    
    while(n>0)
    {
        fact /= n;
        long long idx = k / fact;

        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx);

        k %= fact;
        n--;
    }
    
    return answer;
}