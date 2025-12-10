#include<iostream>
#include<stack>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    while(1)
    {
        std::string str;
        std::getline(std::cin, str);
        if(str == ".") break;

        std::stack<char> s;
        bool is_valid = true; //문장이 올바른지 체크하는 플래그

        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            else if(str[i] == ')')
            {
                if(!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    //스택이 비었거나 짝이 안맞으면 실패이므로 더 볼 필요 없음
                    is_valid = false;
                    break;
                }
            }
            else if(str[i] == ']')
            {
                if(!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    is_valid = false;
                    break;
                }
            }
        }

        if(is_valid && s.empty())
        {
            std::cout << "yes" << '\n';
        }
        else
        {
            std::cout << "no" << '\n';
        }
    }


    return 0;
}