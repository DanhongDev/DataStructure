#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    //이길 수 없는 경우 가지치기 --> 기존 max, min_element는 어차피 O(N)의 시간이 필요했다.
    if(A.front() >= B.back()) return 0;

    int answer=0, a=0, b=0;
    while(b<B.size())
    {
        if(A[a] < B[b])
        {
            a++;
            b++;
            answer++;
        }
        else
        {
            b++;
        }
    }
    
    return answer;
}