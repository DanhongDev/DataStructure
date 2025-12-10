#include<iostream>
#include<stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    
    while(T--)
    {
        std::stack<char> s;
        std::string str;
        std::cin >> str;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '(')
            {
                s.push(str[i]);
            }
            else if(str[i] == ')')
            {
                if(s.size() > 0 && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(str[i]);
                }
            }
        }

        if(s.size() == 0)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}