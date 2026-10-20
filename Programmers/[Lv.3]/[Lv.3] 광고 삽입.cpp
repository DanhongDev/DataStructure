#include <string>
#include <vector>

using namespace std;

int timetoInt(string s)
{
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3, 2));
    int second = stoi(s.substr(6, 2));

    return hour*3600 + min*60 + second;
}
string timetoString(int t)
{
    int h = t/3600;
    int m = (t%3600) / 60;
    int s = (t%3600) % 60;

    string hour = to_string(h);
    if(hour.size()==1) hour = "0" + hour;
    string min = to_string(m);
    if(min.size()==1) min = "0" + min;
    string second = to_string(s);
    if(second.size()==1) second = "0" + second;

    string time = hour + ":" + min + ":" + second;
    return time;
}
string solution(string play_time, string adv_time, vector<string> logs)
{
    // 가지치기: 애초에 서로 시간이 같다면 00:00:00을 바로 리턴
    if(play_time == adv_time) return "00:00:00";

    int play = timetoInt(play_time);
    int adv = timetoInt(adv_time);

    vector<int> viewer(360000, 0);
    for(string l : logs)
    {
        int start = timetoInt(l.substr(0, 8));
        int end = timetoInt(l.substr(9));

        viewer[start]++;
        viewer[end]--;
    }
    for(int i=1; i<viewer.size(); i++)
    {
        viewer[i] += viewer[i-1];
    }
    
    long long max_cum = 0;
    for(int i=0; i<adv; i++)
    {
        max_cum += viewer[i];
    }

    int left = 0, right = adv;
    long long cur = max_cum;
    int res = 0;
    while(right < play)
    {
        cur -= viewer[left];
        cur += viewer[right];
        left++;
        right++;
        
        if(cur > max_cum)
        {
            max_cum = cur;
            res = left;
        }
    }

    string answer = timetoString(res);
    return answer;
}