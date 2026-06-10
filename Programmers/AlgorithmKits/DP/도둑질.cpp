#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) 
{
    //My.
    ////dp[i]: i번째 집까지 훔쳤을때의 최대값
    ////true: 0번 집 도둑질 했음, false: 0번 집 도둑질 안함
    //vector<pair<int,bool>> dp(money.size());
    //
    //dp[0].first = money[0], dp[0].second = true;
    //dp[1].first = money[1], dp[1].second = false;
    //int max_money = max(dp[0].first, dp[1].first);
    //
    //for(int i=2; i<money.size(); i++)
    //{
    //    if(i==2) 
    //    {
    //        dp[i].first = dp[i-2].first + money[2];
    //        dp[i].second = true;
    //    }
    //    
    //    else
    //    {
    //        pair<int, bool> temp = dp[i-2].first > dp[i-3].first ? dp[i-2] : dp[i-3];
    //        dp[i].first = money[i] + temp.first;
    //        dp[i].second = temp.second;
    //    }
    //    
    //    //마지막 인덱스를 구했는데 이전dp가 true라면 0번 집을 턴 경우이므로
    //    if(i==money.size()-1 && dp[i].second == true)
    //    {
    //        dp[i].first -= money[0];
    //    }   
    //    max_money = max_money > dp[i].first ? max_money : dp[i].first;
    //}
    //return max_money;

    //Complement.
    //i) 0번 집을 훔치는 경우
    vector<int> dp_com(money.size());
    dp_com[0] = money[0], dp_com[1] = dp_com[0];
    //i<money.size()-1 이므로 마지막 인덱스 자동 배제
    for(int i=2; i<money.size()-1; i++)
    {
        //dp_com[i-1]: 이번 집(i)을 안 털고 이전 집(i-1)까지의 최대 이익을 유지할 것인가?
        //dp_com[i-2] + money[i]: 전전 집(i-2)의 이익에 이번 집(i)을 더할 것인가?
        dp_com[i] = max(dp_com[i-1], dp_com[i-2] + money[i]);
    }

    //ii) 0번 집을 훔치지 않는 경우
    vector<int> dp_com2(money.size());
    dp_com2[0] = 0, dp_com2[1] = money[1];
    for(int i=2; i<money.size(); i++)
    {
        dp_com2[i] = max(dp_com2[i-1], dp_com2[i-2] + money[i]);
    }
    
    return max(dp_com[money.size()-2], dp_com2[money.size()-1]);
}

int main()
{
    vector<int> money = {1, 2, 3};
    solution(money);

    return 0;
}