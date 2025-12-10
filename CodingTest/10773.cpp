#include<iostream>
#include<stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int K;
    std::cin >> K;

    std::stack<int> s;
    while(K--)
    {
        int temp;
        std::cin >> temp;

        if(temp != 0)
        {
            s.push(temp);
        }
        else
        {
            s.pop();
        }
    }

    int sum = 0;
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    std::cout << sum << '\n';
    return 0;
}