#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int order;
    std::cin >> order;

    int idx = 0;
    for(int i=1; i<=N; i++)
    {
        if(N % i == 0)
        {
            idx++;
        }
        if(idx == order)
        {
            std::cout << i << '\n';
            return 0;
        }
    }

    std::cout << 0 << '\n';

    return 0;
}