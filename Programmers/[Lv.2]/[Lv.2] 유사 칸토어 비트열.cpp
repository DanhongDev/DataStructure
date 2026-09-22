#include <string>
#include <vector>

using namespace std;

long long get_pow(long long base, int exp)
{
    long long result = 1;
    for(int i=0; i<exp; i++)
    {
        result *= base;
    }
    return result;
}

long long DC(int n, long long k)
{
    if(k==0) return 0;
    if(n==0) return 1;
    
    long long pre_len = get_pow(5, n-1);
    long long pre_ones = get_pow(4, n-1);

    long long chunk = k / pre_len;

    long long rem = k % pre_len;

    if(chunk == 0) return DC(n-1, rem);
    else if(chunk == 1) return pre_ones + DC(n-1, rem);
    else if(chunk == 2) return pre_ones * 2;
    else if(chunk == 3) return pre_ones * 2 + DC(n-1, rem);
    else if(chunk == 4) return pre_ones * 3 + DC(n-1, rem);
    else return pre_ones * 4;
}
int solution(int n, long long l, long long r)
{
    int answer = 0;

    return DC(n, r) - DC(n, l-1);
    
    return answer;
}