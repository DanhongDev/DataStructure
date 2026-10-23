#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int len = weak.size();
    for(int i=0; i<len; i++)
    {
        weak.push_back(weak[i] + n);
    }

    int answer = dist.size() + 1;

    sort(dist.begin(), dist.end());
    do
    {
        for(int i=0; i<len; i++)
        {
            int idx = 0;

            int limit = weak[i] + dist[idx];
            bool is_poss = true;

            for(int j=i; j<i+len; j++)
            {
                if(weak[j] > limit)
                {
                    idx++;
                    if(idx >= dist.size())
                    {
                        is_poss = false;
                        break;
                    }

                    limit = weak[j] + dist[idx];
                }
            }

            if(is_poss) answer = min(answer, idx+1);
        }
    } while (next_permutation(dist.begin(), dist.end()));
    
    return answer > dist.size() ? -1 : answer;
}