#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int getTime(string s)
{
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3));

    return hour * 60 + min;
}

bool cmp(const vector<string> &a, const vector<string> &b)
{
    return a[1] < b[1];
}
vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);

    stack<pair<string, int>> wait;

    for(int i=0; i<plans.size()-1; i++)
    {
        string cur_name = plans[i][0];
        int cur_start = getTime(plans[i][1]);
        int cur_remain = stoi(plans[i][2]);

        int nx_start = getTime(plans[i+1][1]);

        if(nx_start < cur_start + cur_remain)
        {
            wait.push({cur_name, cur_remain - (nx_start - cur_start)});
        }
        else
        {
            answer.push_back(cur_name);
            int cur_time = cur_start + cur_remain;

            while(!wait.empty())
            {
                pair<string, int> top = wait.top();
                wait.pop();

                //짬짜미 시간 안에 스택 과제를 다 끝낼 수 있다면??
                if(cur_time + top.second <= nx_start)
                {
                    answer.push_back(top.first);
                    cur_time += top.second; //스택 과제 남은 시간만큼 현재시간 갱신
                }
                else
                {
                    //짬난 시간만큼 과제를 진행하고 다시 스택에 넣기
                    top.second -= (nx_start - cur_time);
                    wait.push(top);
                    break;
                }
            }
        }
    }
    //루프가 끝나면 가장 마지막 과제는 방해받지 않으므로 바로 끝냄.
    answer.push_back(plans.back()[0]);
    
    //과제 순회가 끝나면 스택안의 남은 과제 털기
    while(!wait.empty())
    {
        answer.push_back(wait.top().first);
        wait.pop();
    }

    return answer;
}