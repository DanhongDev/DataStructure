#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(const int &dist_limit, const int &split_limit, int cur_dist, long long cur_split, long long cur_leaf, int type, int &answer)
{
    //리턴 조건
    if(cur_dist > dist_limit || cur_split > split_limit)
    {
        return;
    }

    //리프 노드 최대화
        //리프노드의 개수를 세는 계산 식 유도 후
        int dist = cur_dist; //dist 개수 복사 (원본 훼손 방지)
        long long leaf_cnt = cur_leaf;
  
        //O(N) --> 시간초과
        // for(int i=0; i<cur_leaf; i++)
        // {
        //     if(dist >= dist_limit) break;

        //     leaf_cnt += type-1;
        //     if(leaf_cnt != 1) dist++;
        // }
        
        //O(1)로 수정
        if(type > 1)
        {
            //cur_leaf: 목표 횟수, dist_limit - cur_dist: 남은 횟수
            long long K = min((long long)cur_leaf, (long long)(dist_limit - cur_dist));

            leaf_cnt += K * (type - 1);
            dist += K;
        }

        //최대값 갱신
        answer = max(answer, (int)leaf_cnt);

    DFS(dist_limit, split_limit, dist, cur_split*3, leaf_cnt, 3, answer); // 3개로 확장
    DFS(dist_limit, split_limit, dist, cur_split*2, leaf_cnt, 2, answer); // 2개로 확장

    return;
}

int solution(int dist_limit, int split_limit)
{
    int answer = 0;

    DFS(dist_limit, split_limit, 0, 1, 1, 1, answer);
    
    return answer;
}