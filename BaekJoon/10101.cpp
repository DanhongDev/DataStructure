#include<iostream>

int main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;

    std::cin >> a >> b >> c;

    if(a==60 && b==60 && c==60)
    {
        std::cout << "Equilateral" << '\n';
        return 0;
    }

    if(a+b+c == 180)
    {
        if(a==b || b==c || c==a)
        {
            std::cout << "Isosceles" << '\n';
            return 0;
        }
        else
        {
            std::cout << "Scalene" << '\n';
            return 0;
        }
    }
    else
    {
        std::cout << "Error" << '\n';
    }
    
    return 0;
}