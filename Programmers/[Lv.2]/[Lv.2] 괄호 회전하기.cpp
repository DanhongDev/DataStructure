#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) 
{
    int answer = 0;
    
    //(2배-1)만큼 불린 다음 s의길이로 쪼개서 각각 확인하면 끝나지 않을까??
    //ex. [](){} 이면 [](){}[](){ 로 불리는거지 그러면 큐를 굳이 안써도 될거같은데.
    int ori_size = s.size();
    s += s;

    for(int i=0; i<ori_size; i++)
    {
        stack<char> st;
        bool is_valid = true;
        for(int j=i; j<i+ori_size; j++)
        {
            //첫 시작이 닫힌 괄호면 바로 패스
            if(j==i && (s[j]==')' || s[j]=='}' || s[j]==']'))
            {
                is_valid = false;
                break;
            }

            if(!st.empty() && st.top() == '(' && s[j] == ')') st.pop();
            else if(!st.empty() && st.top() == '{' && s[j] == '}') st.pop();
            else if(!st.empty() && st.top() == '[' && s[j] == ']') st.pop();
            else st.push(s[j]);
        }

        if(is_valid && st.size() == 0) answer++;
    }

    return answer;
}

int Gesolution(string s)
{
    int answer = 0;
    int ori_size = s.size();
    //s의 길이가 홀수라면 절대 짝이 맞지 않으므로 바로 return 0
    if(ori_size %2 != 0) return 0;

    s += s;

    for(int i=0; i<ori_size; i++)
    {
        stack<char> st;
        bool is_valid = true;
        for(int j=i; j<i+ori_size; j++)
        {
            //여는 괄호이면 무조건 push
            if(s[j]=='(' || s[j]=='{' || s[j]=='[')
            {
                st.push(s[j]);
            }
            else
            //닫는 괄호이면 확인
            {
                //비어 있는데 닫는 괄호? --> 시작부터 닫는 괄호 or 짝이 안 맞음
                if(st.empty())
                {
                    is_valid = false;
                    break;
                }

                if((st.top()=='(' && s[j]==')') || 
                (st.top() == '{' && s[j] == '}') || 
                (st.top() == '[' && s[j] == ']'))
                {
                    st.pop();
                }
                else
                {
                    is_valid = false;
                    break;
                }
            }
        }
        if(is_valid && st.empty()) answer++;
    }

    return answer;
}