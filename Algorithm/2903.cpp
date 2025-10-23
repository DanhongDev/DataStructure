#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N=0;
    std::cin >> N;

    int ori = 2, mul = 2, res = 0;
    int temp = 0;
    for(int i=0; i<N; i++)
    {
        if(i == 0)
        {
            temp = 1;
        }
        else
        {
            temp *= mul;
        }

        ori += temp;
    }

    res = ori * ori;

    std::cout << res << '\n';

    return 0;
}

/*
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // pow(2, N) 대신 (1 << N) 사용
    int points_on_side = (1 << N) + 1;
    int result = points_on_side * points_on_side;

    std::cout << result << '\n';

    return 0;
}
*/