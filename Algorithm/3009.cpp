#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    int x4, y4;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x4 = x1 ^ x2 ^ x3;
    y4 = y1 ^ y2 ^ y3;
    
    std::cout << x4 << ' ' << y4 << '\n';

    return 0;
}