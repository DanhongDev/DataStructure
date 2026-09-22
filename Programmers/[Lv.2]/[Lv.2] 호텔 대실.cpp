#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time)
{
    //체크인 시간 오름차순으로 정렬
    sort(book_time.begin(), book_time.end());
    vector<pair<string, string>> rooms;
    
    for(vector<string> time : book_time) //time[0]: 입실, time[1]: 퇴실
    {
        bool is_checkin = false;
        int cur_checkin_hour = stoi(time[0].substr(0,2)), cur_checkin_min = stoi(time[0].substr(3,2));
        int cur_checkin_time = cur_checkin_hour*60 + cur_checkin_min;

        for(int i=0; i<rooms.size(); i++) //현재 있는 방에 입실할 수 있는지 체크
        {
            //substr말고 나누는 다른 방법 알아보기
            int pre_checkout_hour = stoi(rooms[i].second.substr(0,2));
            int pre_checkout_min = stoi(rooms[i].second.substr(3,2));
            int pre_checkout_time = pre_checkout_hour*60 + pre_checkout_min + 10;

            if(cur_checkin_time >= pre_checkout_time)
            {
                rooms[i].first = time[0];
                rooms[i].second = time[1];
                is_checkin = true;
                break;
            }
        }
        
        if(!is_checkin)
        {
            //모든 방에 입실할 수 없다면 새로운 방을 만들어야함
            rooms.push_back({time[0], time[1]});
        }
    }
    
    return rooms.size();
}

#include <queue>
#include <sstream>
int TimeToInt(string time)
{
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour*60 + min;

    //stringstream과 getline 방법
    stringstream ss(time);
    string ss_hour, ss_min;
    getline(ss, ss_hour, ':'); //':'를 만날 때까지 읽어서 ss_hour에 저장
    getline(ss, ss_min); //남은 문자열을 끝까지 읽어서 ss_min에 저장
    return stoi(ss_hour)*60 + stoi(ss_min);
}
//우선순위 큐 이용
int Gesolution(vector<vector<string>> book_time)
{
    sort(book_time.begin(), book_time.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for(vector<string> time : book_time)
    {
        int checkin = TimeToInt(time[0]);
        int checkout = TimeToInt(time[1]) + 10;

        if(!pq.empty() && checkin >= pq.top())
        {
            pq.pop();
        }

        pq.push(checkout);
    }

    return pq.size();
}