#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_matched(const vector<int> &cur_arr, const vector<vector<int>> &q, const vector<int> &ans)
{
    for(int i=0; i<q.size(); i++)
    {
        int cnt = 0;
        for(int num : q[i])
        {
            if(find(cur_arr.begin(), cur_arr.end(), num) != cur_arr.end())
            {
                cnt++;
                if(cnt > ans[i]) return false; //가지치기 (이미 cnt가 넘었다면 이번 숫자는 아님)
            }
        }
        if(cnt != ans[i]) return false; //ans[i]와 같지 않으면 이번 숫자는 아님
    }

    //모든 ans와 일치할 경우
    return true;
}
void DFS(const int &n, const vector<vector<int>> &q, const vector<int> &ans, vector<int> cur_arr, int num, int &answer)
{
    if(cur_arr.size() == 5)
    {
        if(is_matched(cur_arr, q, ans))
        {
            answer++;
        }
        return;
    }

    // 1. 12345 ~ (n-4)(n-3)(n-2)(n-1)n까지의 조합 만들기
    for(int i=num; i<=n; i++)
    {
        cur_arr.push_back(i);
        DFS(n, q, ans, cur_arr, i+1, answer);
        cur_arr.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    int answer = 0; 
    DFS(n, q, ans, {}, 1, answer);
    return answer;
}