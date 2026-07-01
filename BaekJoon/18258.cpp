#include<iostream>
#include<queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::queue<int> q;
    while(N--)
    {
        std::string str;
        std::cin >> str;
        if(str == "push")
        {
            int temp;
            std::cin >> temp;
            q.push(temp);
        }
        else if(str == "pop")
        {
            if(q.empty()) std::cout << -1 << '\n';
            else
            {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size")
        {
            std::cout << q.size() << '\n';
        }
        else if(str == "empty")
        {
            std::cout << q.empty() ? 1 : 0;
            std::cout << '\n';
        }
        else if(str == "front")
        {
            if(q.empty()) std::cout << -1 << '\n';
            else
            {
                std::cout << q.front() << '\n';
            }
        }
        else if(str == "back")
        {
            if(q.empty()) std::cout << -1 << '\n';
            else
            {
                std::cout << q.back() << '\n';
            }
        }
    }
    
    return 0;
}