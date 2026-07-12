#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<int> s;
    for(int i=0; i<numbers.size(); i++)
    {
        while(!s.empty() && numbers[i] > numbers[s.top()])
        {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    
    return answer;
}