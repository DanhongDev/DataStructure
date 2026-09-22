#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    vector<vector<int>> dp(n, vector<int> (n,0));
    //첫 행과 첫 열 설정
    for(int i=0; i<n; i++)
    {
        dp[0][i] = i+1;
        dp[i][0] = i+1;
    }
    //나머지 칸 값 대입
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> arr(n*n, 0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[(n*i)+j] = dp[i][j];
        }
    }

    for(int i=left; i<=right; i++)
    {
        answer.push_back(arr[i]);
    }
    //ii)arr.erase()를 이용해보는건 어떨까??
    //arr.erase(arr.begin(), arr.begin()+left);
    //arr.erase(arr.begin()+right, arr.end());

    return answer;
}

vector<int> Gesolution(int n, long long left, long long right)
{
    vector<int> answer;
    for(long long i=left; i<=right; i++)
    {
        answer.push_back((int)(max(i/n, i%n) + 1));
    }
    return answer;
}