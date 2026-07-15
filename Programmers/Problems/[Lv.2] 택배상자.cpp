#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    stack<int> s;

    int cur_box = 1;
    

    for(int i=0; i<order.size(); i++)
    {
        while(cur_box <= order[i])
        {
            s.push(cur_box++);
        }

        if(!s.empty() && s.top() == order[i])
        {
            answer++;
            s.pop();
        }
        else
        {
            break;
        }
    }
    
    return answer;
}