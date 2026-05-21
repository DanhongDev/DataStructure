#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++)
    {
        q.push({priorities[i], i}); //first: 값, second: 인덱스(location)
        pq.push(priorities[i]);
    }
    while(!q.empty())
    {
        if(q.front().first != pq.top())
        {
            pair<int, int> temp = q.front();
            q.pop();
            q.push(temp);
        }
        else
        {
            if(q.front().second != location)
            {
                q.pop();
                pq.pop();
                answer++;
            }
            else
            {
                return answer;
            }
        }
    }

    return answer;
}