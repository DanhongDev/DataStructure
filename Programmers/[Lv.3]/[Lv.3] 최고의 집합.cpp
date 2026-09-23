#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s)
{
    if(s/n == 0) return {-1};
    
    int num = s / n;
    int rem = s % n;

    vector<int> answer(n, num);
    
    for(int i=0; i<rem; i++)
    {
        answer[n-1 -i]++;
    }
    
    return answer;
}