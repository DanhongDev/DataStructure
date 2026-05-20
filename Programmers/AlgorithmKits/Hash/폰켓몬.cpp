#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> list;
    for(int n : nums)
    {
        list.insert(n);
    }
    if(list.size() > nums.size()/2)
    {
        answer = nums.size()/2;
    }
    else
    {
        answer = list.size();
    }
    return answer;

    //더 간단한 방법
    //vector를 begin과 end 이터레이터를 이용하여 넘겨주면 한번에 set에 중복 제거하여 삽입도 가능하다.
    unordered_set<int> ponketmon(nums.begin(), nums.end());
    //if-else문 보다는 min문이 더 간결하긴 하다.
    return min(ponketmon.size(), nums.size()/2);
}