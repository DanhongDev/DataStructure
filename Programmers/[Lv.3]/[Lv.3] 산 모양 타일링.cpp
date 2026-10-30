#include <string>
#include <vector>

using namespace std;

void DFS(int depth, const vector<int> &dp, const vector<int> &tops, vector<int> &idx, const int &max_len, int cnt, int &answer)
{
    if(cnt == max_len)
    {
        int noc = 1;
        int cur = 0, diff = 0;
        int last = tops.size();
        for(int i=idx.size()-1; i>=0; i--)
        {
            diff = (last - idx[i]) -1; // -1 은 윗변의 개수를 보정
            last = idx[i];
            noc *= dp[2*diff + 1];
            noc %= 10007;
        }

        // 앞에서 부터 탐색 --> 실패: 인덱스에 따른 값들이 자꾸 꼬임
        // for(int i=0; i<idx.size(); i++)
        // {
        //     diff = idx[i] - cur;
        //     cur = idx[i];
        //     noc *= dp[2*diff + 1];
        // }
        // noc *= dp[2*((tops.size()-1)-cur) + 1];

        noc *= dp[2*last + 1];  // 0~last까지의 삼각형 개수에 따른 경우의 수를 한번 더 계산
        answer += noc;
        answer %= 10007;
        return;
    }

    for(int i=depth; i<tops.size(); i++)
    {
        if(tops[i] == 0) continue;

        idx.push_back(i);
        DFS(i+1, dp, tops, idx, max_len, cnt+1, answer);
        idx.pop_back();
    }

    return;
}
int solution(int n, vector<int> tops)
{
    // 사다리꼴 부분 삼각형 갯수에 따른 경우의 수 정리
    vector<int> dp((2*n+1)+1, 0);
    dp[1] = 1, dp[2] = 2;
    for(int i=3; i<dp.size(); i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }

    int answer = 0;

    int max_len = 0;
    for(int x : tops)
    {
        if(x == 1) max_len++;
    }

    // 마름모 1개~N개 까지의 경우의 수
    vector<int> idx;
    for(int len=1; len<=max_len; len++)
    {
        DFS(0, dp, tops, idx, len, 0, answer);
    }
    
    //마지막 마름모 0개의 경우의 수 더하고 리턴
    answer += dp[2*n + 1];
    answer %= 10007;
    return answer;
}

int solution(int n, vector<int> tops)
{
    vector<int> a(n+1, 0), b(n+1, 0);
    a[0]=1, b[0]=0;

    for(int i=1; i<=n; i++)
    {
        if(tops[i-1]==1)
        {
            a[i] = (a[i-1]*3 + b[i-1]*2) % 10007;
            b[i] = (a[i-1] + b[i-1]) % 10007;
        }
        else
        {
            a[i] = (a[i-1]*2 + b[i-1]) % 10007;
            b[i] = (a[i-1] + b[i-1]) % 10007;
        }
    }

    return (a[n] + b[n]) % 10007;
}