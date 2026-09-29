#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int mid, const vector<int> &stones, int k)
{
    int cnt_0 = 0;
    for(int i=0; i<stones.size(); i++)
    {
        if(stones[i] - mid < 0)
        {
            cnt_0++;
            if(cnt_0 >= k) return false;
        }
        else 
        {
            cnt_0 = 0;
        }
    }
    return true;
}
int solution(vector<int> stones, int k)
{
    int answer = 0;
    int left=1, right=2e8;

    while(left<=right)
    {
        int mid = (left + right) / 2;

        if(check(mid, stones, k))
        {
            answer = mid;
            left = mid+1;
        }
        else 
        {
            right = mid-1;
        }   
    }

    return answer;
}