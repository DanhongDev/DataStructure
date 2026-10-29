#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ChangetoString(long long n)
{
    string s = "";
    while(n>0)
    {
        long long remain = n % 26;
        if(remain == 0)
        {
            s.push_back('z');
            n = (n/26) - 1;
        }
        else
        {
            s.push_back('a' + (remain - 1));
            n /= 26;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
long long ChangetoInt(string s)
{
    long long order = 0;
    
    long long mul = 1;
    while(s.size() > 0)
    {
        char c = s.back();
        s.pop_back();

        order += mul * ((c - 'a') + 1);
        mul *= 26;
    }
    return order;
}
string solution(long long n, vector<string> bans)
{
   // bans의 문자열들을 정수형으로 치환
    vector<long long> orders;
    orders.reserve(bans.size());
    for(string b : bans) orders.push_back(ChangetoInt(b));
    sort(orders.begin(), orders.end());

    // int front_cnt = 0, back_cnt = 0;
    // bool is_end = false;
    // for(long long x : orders)
    // {
    //     if(is_end) break;

    //     if(x <= n) front_cnt++;
    //     else
    //     {
    //         long long new_order = x - front_cnt - back_cnt;
    //         if(new_order <= n)
    //         {
    //             back_cnt++;
    //         }
    //         else is_end = true;
    //     }
    // }
    // long long new_n = n + front_cnt + back_cnt;

    // 개선: 실시간으로 한칸씩 밀어내기
    long long new_n = n;
    for(long long x : orders)
    {
        if(x <= new_n) new_n++;
        else break;
    }
    
    return ChangetoString(new_n);
}