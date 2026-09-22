#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    unordered_map<string, string> park; //입출차 명부 (first: 번호, second: 시각)
    map<string, int> accum; //누적 시간 명부 (first: 번호, second: 누적시간)

    for(string record : records)
    {
        stringstream ss(record);
        string time, num, type;
        ss >> time >> num >> type;

        if(type == "IN") //입차
        {
            park[num] = time;
        }
        else //출차
        {
            //입차 계산
            string in_time = park[num];
            int hour = stoi(in_time.substr(0, 2));
            int min = stoi(in_time.substr(3));
            int in_total = 60*hour + min;

            //출차 계산
            hour = stoi(time.substr(0,2));
            min = stoi(time.substr(3));
            int out_total = 60*hour + min;

            //해당 출차의 주차 시간 계산
            int total = out_total - in_total;

            if(accum.find(num) != accum.end()) //이미 명단에 있으면
            {
                accum[num] += total;
            }
            else //새로 명단에 추가해야 한다면
            {
                accum[num] = total;
            }

            park.erase(num);
        }
    }

    // 1. 입차만 있고 출차가 없을때의 예외처리
    if(!park.empty())
    {
        for(auto &p : park)
        {
            string in_time = p.second;
            int hour = stoi(in_time.substr(0, 2));
            int min = stoi(in_time.substr(3));
            int in_total = 60*hour + min;
            int out_total = 60*23 + 59;
            int total = out_total - in_total;
            if(accum.find(p.first) != accum.end())
            {
                accum[p.first] += total;
            }
            else
            {
                accum[p.first] = total;
            }
        }
    }

    // 2. accum을 순회하며 주차요금계산
    for(auto &a : accum)
    {
        //기본 시간 초과 확인
        if(a.second > fees[0])
        {
            float total_fee = fees[1] + (ceil((a.second - fees[0]) / (float)fees[2]) * fees[3]);
            //ceil()없이 올림하기: A를 B로 나눌 때, (A+B-1) / B
            //int over_time = a.second - fees[0];
            //int unit_time = fees[2];
            //int over_fee = ((over_time + unit_time - 1) / unit_time) * fees[3];
            //int total_fee = fees[1] + over_fee;
            answer.push_back(total_fee);
        }
        else
        {
            answer.push_back(fees[1]);
        }
    }
    
    return answer;
}