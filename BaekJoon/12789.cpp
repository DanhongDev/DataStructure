#include<iostream>
#include<stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::stack<int> s;
    int cnt = 1;

    while(N--)
    {
        int temp;
        std::cin >> temp;

        if(temp == cnt)
        {
            cnt++;
        }
        else
        {
            s.push(temp);
        }

        while(!s.empty() && s.top() == cnt)
        {
            s.pop();
            cnt++;
        }
    }

    if(s.empty())
    {
        std::cout << "Nice" << '\n';
    }
    else
    {
        std::cout << "Sad" << '\n';
    }
    
    return 0;
}