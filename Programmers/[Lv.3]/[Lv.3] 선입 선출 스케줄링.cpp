#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores)
{
    if(n <= cores.size()) return n;
    
    int answer = 0;
    long long left = 1;
    long long right = (long long)(*max_element(cores.begin(), cores.end())) * n;
    long long time = 0;

    while(left<=right)
    {
        long long mid = (left + right) / 2;

        long long sum = cores.size();
        for(int i=0; i<cores.size(); i++)
        {
            sum += mid / cores[i];
        }

        if(sum >= n)
        {
            time = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    
    long long task = cores.size();
    for(int i=0; i<cores.size(); i++)
    {
        task += (time-1) / cores[i];
    }

    for(int i=0; i<cores.size(); i++)
    {
        if(time % cores[i] == 0)
        {
            task++;

            if(task == n)
            {
                answer = i+1;
                break;
            }
        }
    }
    return answer;
}