#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    //예외 처리: 문자열의 처음이 )이고 끝이 (라면 가차없이 리턴 false
    if(s[0] == ')' || s[s.size()-1] == '(')
    {
        answer = false;
        return answer;
    }

    st.push(s[0]);
    for(int i=1; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            //스택이 비어있는 상태에서 )를 넣으면 처음 예외 처리와 똑같은 상황이므로 리턴 false
            if(st.empty())
            {
                return false;
            }
            st.pop();
        }
    }

    if(st.empty())
    {
        answer = true;
    }
    else
    {
        answer = false;
    }

    return answer;
}