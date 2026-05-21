#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    //배열 이용
    //while(!progresses.empty())
    //{
    //    for(int i=0; i<progresses.size(); i++)
    //    {
    //        progresses[i] += speeds[i];
    //    }
    //    int cnt = 0;
    //    for(int i=0; i<progresses.size(); i++)
    //    {
    //        if(progresses[i] >= 100)
    //        {
    //            cnt++;
    //        }
    //        else
    //        {
    //            break;
    //        }
    //    }
    //    if(cnt > 0)
    //    {
    //        answer.push_back(cnt);
    //        progresses.erase(progresses.begin(), progresses.begin()+cnt);
    //        speeds.erase(speeds.begin(), speeds.begin()+cnt);
    //    }
//
    //}

    //큐 이용
    queue<int> q;
    for(int i=0; i<progresses.size(); i++)
    {
        int temp = (100 - progresses[i]) % speeds[i];
        int dueDate = (100 - progresses[i]) / speeds[i];
        if(temp == 0)
        {
            q.push(dueDate);
        }
        else
        {
            q.push(dueDate+1);
        }
    }

    while(!q.empty())
    {
        int cnt = 0;
        int temp = q.front();
        q.pop();
        cnt++;

        while(temp >= q.front() && !q.empty())
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);  
    }

    return answer;
}