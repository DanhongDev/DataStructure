#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    
    //연립방정식 공식으로 말고 전수조사로 푸는것이 핵심이었음.

    for(int x=-999; x<=999; x++)
    {
        for(int y=-999; y<=999; y++)
        {
            if((a*x+b*y == c) && (d*x + e*y == f))
            {
                std::cout << x << ' ' << y << '\n';
                return 0;
            }
        }
    }
    return 0;
}