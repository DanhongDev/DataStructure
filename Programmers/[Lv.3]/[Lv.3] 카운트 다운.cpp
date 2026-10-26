#include <string>
#include <vector>

using namespace std;

pair<int, int> dp[100001];

vector<int> solution(int target)
{
    //다트 점수판 세팅
    vector<pair<int,int>> dart;
    for(int i=1; i<=20; i++)
    {
        dart.push_back({i, 1});
        dart.push_back({i*2, 0});
        dart.push_back({i*3, 0});
    }
    dart.push_back({50, 1}); //Bull

    dp[0] = {0,0};
    for(int i=1; i<=target; i++) dp[i] = {1e9, 0};

    for(int i=1; i<=target; i++)
    {
        for(pair<int, int> &d : dart)
        {
            int score = d.first;
            int bs_cnt = d.second;

            // 점수가 score보다 높아야만 맞출 수 있다.
            if(i >= score)
            {
                // 과거(dp[i-score])를 가져와서
                int new_cnt = dp[i-score].first + 1;
                int new_bs = dp[i-score].second + bs_cnt;

                if(new_cnt < dp[i].first)
                {
                    dp[i].first = new_cnt;
                    dp[i].second = new_bs;
                }
                else if(new_cnt == dp[i].first && new_bs > dp[i].second)
                {
                    dp[i].second = new_bs;
                }
            }
        }
    }

    return {dp[target].first, dp[target].second};
}