#include<iostream>
#include<stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::stack<int> s;
    
    while(N--)
    {
        int input;
        std::cin >> input;
        switch (input)
        {
        case 1:
            int num;
            std::cin >> num;
            s.push(num);
            break;
        case 2:
            if(s.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << s.top() << '\n';
                s.pop();
            }
            break;
        case 3:
            std::cout << s.size() << '\n';
            break;
        case 4:
            if(s.empty())
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 0 << '\n';
            }
            break;
        case 5:
            if(s.empty())
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << s.top() << '\n';
            }
            break;
        default:
            break;
        }
    }

    return 0;
}