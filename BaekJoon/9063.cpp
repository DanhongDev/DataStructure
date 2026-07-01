#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int x, y;
    int min_x = 10001, max_x = -10001, min_y = 10001, max_y = -10001;
    while(N--)
    {
        std::cin >> x >> y;
        min_x = min_x < x ? min_x : x;
        min_y = min_y < y ? min_y : y;
        max_x = max_x > x ? max_x : x;
        max_y = max_y > y ? max_y : y;
    }

    int width = max_x - min_x;
    int height = max_y - min_y;

    int s = width * height;

    std::cout << s << '\n';

    return 0;
}

//점의 위치가 음수일때의 상황을 고려안함!!