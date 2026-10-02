#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, string> er;
    unordered_map<string, int> ans;
    for(int i=0; i<enroll.size(); i++)
    {
        er[enroll[i]] = referral[i];
    }
    
    for(int i=0; i<seller.size(); i++)
    {
        string cur = seller[i];
        string next = er[cur];\

        int cost = amount[i] * 100;
        int per = cost / 10;
        cost -= per;
        ans[cur] += cost;

        while(next != "-")
        {
            cur = next;
            next = er[cur];

            int n_per = per / 10;
            if(n_per == 0)
            {
                ans[cur] += per;
                break;
            }
            ans[cur] += per - n_per;
            per = n_per;
        }
    }
    
    for(auto &a : ans)
    {
        for(int i=0; i<enroll.size(); i++)
        {
            if(enroll[i] == a.first)
            {
                answer[i] = a.second;
            }
        }
    }

    return answer;
}

// 문자열을 정수 인덱스로 치환하기
vector<int> Geanswer(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    int n = enroll.size();
    vector<int> answer(n, 0);

    // 문자열 -> 정수로 치환
    unordered_map<string, int> name_to_id;
    for(int i=0; i<n; i++)
    {
        name_to_id[enroll[i]] = i;
    }

    // 부모를 가리키는 배열
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++)
    {
        if(referral[i] != "-")
        {
            parent[i] = name_to_id[referral[i]];
        }
    }

    for(int i=0; i<seller.size(); i++)
    {
        int cur = name_to_id[seller[i]];
        int cost = amount[i] * 100;

        while(cur != -1 && cost > 0)
        {
            int per = cost / 10;
            answer[cur] += cost - per;

            cost = per;
            cur = parent[cur]; // O(1) 점프
        }
    }

    return answer;
}