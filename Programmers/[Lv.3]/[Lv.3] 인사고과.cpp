#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
int solution(vector<vector<int>> scores)
{
    vector<int> wanho = scores[0];
    int wh = wanho[0] + wanho[1];

    sort(scores.begin(), scores.end(), cmp);

    int max_score = 0;
    int answer = 1;

    for(const auto &s : scores)
    {
        if(s[1] < max_score)
        {
            if(s[0] == wanho[0] && s[1] == wanho[1]) return -1;
        }
        else
        {
            max_score = max(max_score, s[1]);

            if(s[0] + s[1] > wh)
            {
                answer++;
            }
        }
    }
    
    return answer;
}

int main()
{
    int answer = solution({{2,2}, {1,4}, {3,2}, {3,2}, {2,1}});
    
    return 0;
}