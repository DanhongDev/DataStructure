#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    long long left = 1;
    long long right = *(max_element(times.begin(), times.end())) * (long long)n;
    //최적해 넣기
    long long answer = right;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long poss = 0;

        for(int i=0; i<times.size(); i++)
        {
            poss += (mid / times[i]);
        }
        if(poss >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}