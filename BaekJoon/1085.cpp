#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    int disX = w-x < x ? w-x : x;
    int disY = h-y < y ? h-y : y;

    if(disX < disY)
    {
        std::cout << disX << '\n';
    }
    else
    {
        std::cout << disY << '\n';
    }
    
    return 0;
}