#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
int answer = -1;

void adventure(int k, const vector<pair<int,int>>& dungeons, int cnt)
{
    //cnt가 최대로 갱신 되었을 시 answer를 갱신
    answer = max(answer, cnt);

    //탐험 가능할 시 소모 피로도 감소 후 방문 카운트 증가
    //백트래킹: 재귀 속 for문
    for(int i=0; i<dungeons.size(); i++)
    {
        if(!visited[i] && k >= dungeons[i].first)
        {
            visited[i] = true;
            adventure(k - dungeons[i].second, dungeons, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    visited.assign(dungeons.size(), false);
    vector<pair<int,int>> arr;
    for(const auto& dungeon : dungeons)
    {
        arr.push_back({dungeon[0], dungeon[1]});
    }
    
    adventure(k, arr, 0);


    //permutation() 사용

    //사용하기 전 정렬 필수
    sort(dungeons.begin(), dungeons.end());

    //do-while문으로 첫번째 순열도 빠짐없이 돌려주기
    do
    {
        int cur_k = k, cnt = 0;
        for(int i=0; i<dungeons.size(); i++)
        {
            if(cur_k >= dungeons[i][0])
            {
                cur_k -= dungeons[i][1];
                cnt++;
            }
        }

        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}