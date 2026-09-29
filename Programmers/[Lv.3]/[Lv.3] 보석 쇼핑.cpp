#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems)
{
    //보석 종류 세기
    unordered_set<string> g(gems.begin(), gems.end());
    int num_gems = g.size();

    unordered_map<string, int> m;
    int left=0, right=0; //투 포인터 선언

    int min_len = 1e9;
    int min_left=0, min_right=0;
    
    while(right < gems.size())
    {
        //구간 늘리기
        m[gems[right]]++;
        right++;

        while(m.size() == num_gems)
        {
            //최소 구간 갱신
            if(right - left < min_len)
            {
                min_len = right - left;
                min_left = left;
                min_right = right;
            }

            //구간 줄이기
            m[gems[left]]--;
            if(m[gems[left]] == 0)
            {
                m.erase(gems[left]);
            }
            left++;
        }
    }

    return {min_left + 1, min_right};
}