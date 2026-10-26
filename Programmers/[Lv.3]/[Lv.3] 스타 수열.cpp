#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> a)
{
    if(a.size()<2) return 0;

    unordered_map<int, int> cnt;
    for(int x : a) cnt[x]++;

    int answer = 0;
    for(const auto &c : cnt)
    {
        int len = 0;
        int x = c.first;
        int freq = c.second * 2;
        if(freq < answer) continue;

        for(int i=0; i<a.size()-1;)
        {
            if((a[i]==x || a[i+1]==x) && (a[i] != a[i+1]))
            {
                len += 2;
                i+=2;
            }
            else i++;
        }
        answer = max(answer, len);
    }
    return answer;
}