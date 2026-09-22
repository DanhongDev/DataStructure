#include <iostream>
#include <string>
#include <stack>
using namespace std;

int mysolution(string s)
{
    stack<char> st;
    st.push(s[0]);

    for(int i=1; i<s.size(); i++)
    {
        if(!st.empty())
        {
            if(st.top() == s[i])
            {
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }

    if(st.empty()) return 1;
    else return 0;
}

//string을 스택처럼 활용하기
int Gesolution(string s)
{
    string answer = "";

    answer.reserve(s.size());

    for(char c : s)
    {
        if(!answer.empty() && answer.back() == c) answer.pop_back();
        else answer.push_back(c);
    }

    return answer.empty() ? 1 : 0;
}

//추가 메모리를 쓰지 않는 방법
int Gesolution_2(string s)
{
    int top = -1;

    for(int i=0; i<s.size(); i++)
    {
        if(top >= 0 && s[top] == s[i])
        {
            top--;
        }
        else
        {
            top++;
            s[top] = s[i];
        }
    }

    return top == -1 ? 1 : 0;
}

// 효율성 성공한 버전(타인)
//#include <bits/stdc++.h>
//using namespace std;
//
//int solution(string str)
//{ // str을 push대상 겸 가상의 stack으로 동시에 활용
//    size_t str_len = str.length(); // str 사이즈 저장
//    if(str_len & 1) return false;  // 조기 종료 조건: str이 홀수인 경우
//    auto *st = &str[0];            // 시작 포인터
//    auto *ed = &str[0] + str_len;  // 종료 포인터
//    size_t top = 0; // 가상의 stack size (==.end()의 index)
//    for(auto *p = st; p<ed; p++){ // 포인터 p를 증가시키면서 순회
//        if(top && *p == str[top-1]) --top; // top이 비어있거나, push 대상과 가상의 stack.top()이 동일하면: stack.pop()
//        else str[top++] = *p;              // 그렇지 않은 경우, stack.push(*p) 후, 가상의 stack size 증가
//    } // stack size (=top) == stack.top()의 index이므로 base[top]이 아닌 base[top-1]을 비교 (top이 일종의 .end() 역할)
//    return !top; // top이 비어있으면 TRUE, 그렇지 않으면(제거되지 않은 문자 존재) FALSE 반환
//}