#include <string>
#include <vector>
#include <queue>
using namespace std;

int getTime(string t)
{
    string hour = t.substr(0,2);
    string min = t.substr(3,2);

    return stoi(hour)*60 + stoi(min);
}
string getStr(int time)
{
    string hour = to_string(time / 60);
    string min = to_string(time % 60);

    if(hour.size() == 1) hour = "0" + hour;
    if(min.size() == 1) min = "0" + min;

    return hour + ":" + min;
}
string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";

    priority_queue<int, vector<int>, greater<int>> wait; //vector 대신 priority_queue도 좋을듯??
    for(int i=0; i<timetable.size(); i++)
    {
        wait.push(getTime(timetable[i]));
    }
    
    int suttle = 60 * 9; // 09:00
    int my_time = 0;
    //핵심은 내가 탈 차가 막차이면서 내가 타야될 자리가 남는가?
    for(int i=0; i<n; i++)
    {
        int cnt_m = 0;
        int last = 0;

        while(!wait.empty() && wait.top() <= suttle && cnt_m<m)
        {
            last = wait.top();
            wait.pop();
            cnt_m++;
        }
        
        if(i==n-1)
        {
            if(cnt_m < m)
            {
                my_time = suttle;
            }
            else
            {
                my_time = last - 1;
            }
        }
        suttle += t;
    }

    return getStr(my_time);
}