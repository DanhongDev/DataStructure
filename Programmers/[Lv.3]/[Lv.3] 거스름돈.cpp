#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> money)
{
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    sort(money.begin(), money.end());
    
    for(int m : money)
    {
        for(int i=0; i<=dp.size(); i++)
        {
            if(i-m >= 0)
            {
                dp[i] += dp[i-m];
            }
        }
    }
    
    return dp[n];
}

int main()
{
    int answer = solution(12, {3, 5, 6});
    return 0;
}