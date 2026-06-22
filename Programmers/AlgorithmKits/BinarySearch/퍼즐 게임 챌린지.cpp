#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    int answer = 0;

    int left = 1;
    //com2) right = max_element 사용
    int right = *(max_element(diffs.begin(), diffs.end()));
    
    while(left<=right)
    {
        long long total_time = 0;
        int mid = (left + right) / 2;
        for(int i=0; i<diffs.size(); i++)
        {
            //난이도 대비 레벨 격차 계산
            long long cur_lev = diffs[i] - mid;
            //이전 퍼즐 소요시간 저장
            int prev_time = 0;
            if(i != 0)
            {
                prev_time = times[i-1];
            }
            //cur_lev이 음수이면 너무 쉬운 퍼즐을 풀고 있다는 뜻
            if(cur_lev <= 0)
            {
                cur_lev = 0;
            }
            
            //현재 퍼즐 푸는데 걸리는 최종 시간
            //com1) int -> long long
            long long cur_time = (prev_time + times[i]) * cur_lev + times[i];
            
            total_time += cur_time;
            //com3) Early Exit
            if(total_time > limit)
            {
                break;
            }
        }
        //최종 시간이 limit안이면 아직 여유로운 것이므로 숙련도 낮춰보기
        if(total_time <= limit)
        {
            //숙련도 낮추기
            right = mid - 1;
            //일단 정답일 수 있으므로 저장
            answer = mid;
        }
        //그렇지 않으면 숙련도가 미달이므로 숙련도 올려주기
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}