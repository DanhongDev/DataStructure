#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    //이것도 투포인터 아닐까?
    int cur = 1;
    int s = 0;

    while(cur <= n)
    {
        if(s < stations.size())
        {
            if(cur < stations[s] - w)
            {
                answer++;
                cur += w * 2;
            }
            else
            {
                cur = max(cur, stations[s] + w);
                s++;
            }
        }
        else
        {
            answer++;
            cur += w * 2;
        }
        
        //다음 아파트 탐색
        cur++;
    }
    
    return answer;
}