#include <string>
#include <vector>

using namespace std;

int gld(int a, int b)
{
    int n = a+b;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i == 0 && (n/i - 2) * (i-2) == b) 
        {
            return n/i;
        }
    }
    return 1;
}

vector<int> solution(int brown, int yellow) 
{
    int answer = gld(brown, yellow);
    return {answer, (brown+yellow)/answer};
}