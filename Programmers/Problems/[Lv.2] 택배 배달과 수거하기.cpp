#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//인덱스를 저장하지 않아 매번 n-1부터 탐색하여 TLE
//배달에서만 dist를 계산하여 오류 --> 수거에서도 dist를 계산하고 둘중 더 먼 거리의 dist를 선택헤야 함
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    int cur=0;
    long long dist=0;

    while(1)
    {
        //맨 끝집까지 가는 거리
        for(long long i=deliveries.size()-1; i>=0; i--)
        {
            //현재 집이 배달할 필요가 없으면 스킵
            if(deliveries[i] == 0) continue;

            if(cur + deliveries[i] <= cap)
            {
                cur += deliveries[i];
                deliveries[i] = 0;
                dist = max(dist, i+1);
            }
            else
            {
                long long diff = cap - cur;
                cur += diff;
                deliveries[i] -= diff;
                break;
            }
        }

        //맨 끝집까지 가는 거리
        answer += dist;
        //배달 끝
        cur = 0;

        for(long long i=pickups.size()-1; i>=0; i--)
        {
            if(pickups[i] == 0) continue;

            if(cur + pickups[i] <= cap)
            {
                cur += pickups[i];
                pickups[i] = 0;
            }
            else
            {
                long long diff = cap - cur;
                cur += diff;
                pickups[i] -= diff;
                break;
            }
        }

        //배달하고 돌아오면서 수거하기
        answer += dist;
        //수거하여 물류센터 도착
        cur = 0;

        int rem_del = *(max_element(deliveries.begin(), deliveries.end()));
        int rem_pic = *(max_element(pickups.begin(), pickups.end()));

        if(rem_del==0 && rem_pic==0) break;

        dist = 0;
    }
    
    return answer;
}

//배달과 수거를 할 집의 인덱스를 저장하면서 수행하자! -> 시간복잡도가 개선된다.
long long Gesolution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    int d_idx = n-1;
    int p_idx = n-1;

    while(d_idx >= 0 || p_idx >= 0)
    {
        while(d_idx>=0 && deliveries[d_idx]==0) d_idx--;
        while(p_idx>=0 && pickups[p_idx]==0) p_idx--;
        if(d_idx<0 && p_idx<0) break;

        long long dist = max(d_idx, p_idx)+1;
        answer += dist*2;

        int cur = cap;
        while(d_idx>=0 && cur>0)
        {
            if(deliveries[d_idx] <= cur)
            {
                cur -= deliveries[d_idx];
                deliveries[d_idx] = 0;
                d_idx--;
            }
            else
            {
                deliveries[d_idx] -= cur;
                cur = 0;
            }
        }

        cur = cap;
        while(p_idx>=0 && cur>0)
        {
            if(pickups[p_idx] <= cur)
            {
                cur -= pickups[p_idx];
                pickups[p_idx] = 0;
                p_idx--;
            }
            else
            {
                pickups[p_idx] -= cur;
                cur = 0;
            }
        }
    }

    return answer;
}

int main()
{
    //long long answer = solution(4, 5, {1,0,3,1,2}, {0,3,0,4,0});
    long long answer = solution(2, 7, {1,0,2,0,1,0,2}, {0,2,0,1,0,2,0});
    return 0;
}