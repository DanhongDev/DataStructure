#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works)
{
    priority_queue<int> pq(works.begin(), works.end());

    while(n>0)
    {
        if(pq.top() == 0) break;

        int temp = pq.top();
        pq.pop();
        pq.push(temp-1);
        n--;
    }

    long long answer = 0;
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}