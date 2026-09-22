#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> combi;
void DFS(string &base, string cur, int idx, const int &target)
{
    if(cur.size() == target)
    {
        combi[cur]++;
        return;
    }

    for(int i=idx; i<base.size(); i++)
    {
        DFS(base, cur+base[i], i+1, target);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    combi.clear();
    vector<string> answer;
    //1. orders안에서 모든 조합을 계산해야 함
    for(string o :orders)
    {
        //"XWY"같은 입력예시 예외처리를 위해 먼저 정렬 수행
        sort(o.begin(), o.end());

        for(int len : course)
        {
            DFS(o, "", 0, len);
        }
    }
    //2. course[i]값에 해당하는 조합의 최대 빈도수만 answer에 삽입
    for(int len : course)
    {
        //최대 빈도수 값 찾기
        int max_fre = 0;
        for(auto &p : combi)
        {
            if(p.first.size() == len)
            {
                max_fre = max(max_fre, p.second);
            }
        }
        //주문 횟수가 2번 미만이면 무시
        if(max_fre < 2) continue;

        //최대 빈도수 값에 맞는 조합만 answer에 푸쉬
        for(auto &p : combi)
        {
            if(p.first.size() == len && p.second == max_fre)
            {
                answer.push_back(p.first);
            }
        }
    }
    
    //제출 전 마지막으로 정렬
    sort(answer.begin(), answer.end());
    return answer;
}