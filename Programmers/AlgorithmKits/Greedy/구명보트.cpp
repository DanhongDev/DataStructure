#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer=0, cnt_p=0, cur_w=0;
    sort(people.begin(), people.end());

    //left: 가벼운 사람, right: 무거운 사람
    int left=0, right=people.size()-1;
    while(left<=right)
    {
        if(people[left] + people[right] <= limit)
        {
            left++;
            right--;
        }
        else
        {
            right--;
        }
        answer++;
    }
    return answer;
    //이 방법은 가벼운 사람을 먼저 태워버리는 알고리즘이다.
    //이러면 나중에 무거운 사람 태우는데 보트 1개씩 써버린다.
    //정답 알고리즘은 무거운사람+가벼운사람으로 보트 수를 최소화하는 것이다.
    //for(int i=0; i<people.size(); i++)
    //{
    //    //현재 보트가 꽉찼는지와 현재 사람을 태우면 무게제한을 넘는지 체크
    //    if(cnt_p == 2 || cur_w+people[i] > limit)
    //    {
    //        cnt_p=0;
    //        cur_w=0;
    //        answer++;
    //    }
    //    //현재사람을 아직 태울 수 있으면 태우기
    //    if(cur_w+people[i] <= limit && cnt_p<2)
    //    {
    //        cur_w += people[i];
    //        cnt_p++;
    //    }
    //    //마지막 사람은 무조건 태울 수 있으니 예외
    //    if(i == people.size()-1)
    //    {
    //        answer++;
    //    }
    //}
}