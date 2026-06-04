#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i = 0; i < lost.size(); i++)
    {
        for(int j = 0; j < reserve.size(); j++)
        {
            if(lost[i] == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < lost.size(); i++)
    {
        if(lost[i] == -1) continue; // 1단계에서 해결된 학생은 건너뜀
        
        for(int j = 0; j < reserve.size(); j++)
        {
            if(lost[i] == reserve[j]-1 || lost[i] == reserve[j]+1)
            {
                lost[i] = -1;
                reserve[j] = -1;
                break; // 체육복을 빌렸으니 안쪽 루프 즉시 종료
            }
        }
    }
    
    for(int i : lost)
    {
        if(i>0)
        {
            n--;
        }
    }
    return n;
}