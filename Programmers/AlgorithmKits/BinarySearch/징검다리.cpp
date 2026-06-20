#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    long long left = 0, right = distance;
    while(left<=right)
    {
        //이분 탐색
        long long mid = (left + right) / 2;
        long long prev_loc = 0, cnt = 0;
        for(int i=0; i<rocks.size(); i++)
        {
            if(rocks[i] - prev_loc < mid)
            {
                cnt++;
            }
            else
            {
                prev_loc = rocks[i];
            }
        }

        //제거한 바위 수 체크
        
        //바위를 너무 많이 제거 했다는 의미(기준 거리가 너무 길다)이므로 거리를 줄여줌
        if(cnt > n)
        {
            right = mid - 1;
        }
        //바위를 적게 제거해도 건널 수 있다는 의미(기준 거리가 짧을 수도 있다)이므로
        //일단 값을 정답에 저장하되 혹시 모르니 거리를 더 늘려서 검사해보기
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}