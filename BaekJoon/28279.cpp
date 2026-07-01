#include<iostream>
#include<queue>
#include<deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::deque<int> dq;

    int N;
    std::cin >> N;
    while(N--)
    {
        int com;
        int temp;
        std::cin >> com;
        switch(com)
        {
            case 1:
                std::cin >> temp;
                dq.push_front(temp);
                break;
            case 2:
                std::cin >> temp;
                dq.push_back(temp);
                break;
            case 3:
                if(!dq.empty())
                {
                    std::cout << dq.front() << '\n';
                    dq.pop_front();
                }
                else
                {
                    std::cout << -1 << '\n';
                }
                break;
            case 4:
                if(!dq.empty())
                {
                    std::cout << dq.back() << '\n';
                    dq.pop_back();
                }
                else
                {
                    std::cout << -1 << '\n';
                }
                break;
            case 5:
                std::cout << dq.size() << '\n';
                break;
            case 6:
                if(dq.empty()) std::cout << 1 << '\n';
                else std::cout << 0 << '\n';
                break;
            case 7:
                if(!dq.empty())
                {
                    std::cout << dq.front() << '\n';
                }
                else
                {
                    std::cout << -1 << '\n';
                }
                break;
            case 8:
                if(!dq.empty())
                {
                    std::cout << dq.back() << '\n';
                }
                else
                {
                    std::cout << -1 << '\n';
                }
                break;
        }
    }
    
    return 0;
}