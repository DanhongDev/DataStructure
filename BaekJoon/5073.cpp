#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;

    while(1)
    {
        std::cin >> a >> b >>c;

        if(a==0 && b==0 && c==0)
        {
            break;
        }
        
        if(a+b<=c || b+c<=a || c+a<=b)
        {
            std::cout << "Invalid" << '\n';
        }
        
        else
        {
            if(a==b && b==c && c==a)
            {
                std::cout << "Equilateral" << '\n';
            }
            
            else if(a==b || b==c || c==a)
            {
                std::cout << "Isosceles" << '\n';
            }
            
            else
            {
                std::cout << "Scalene" << '\n';
            }
        }
        
    }
        return 0;
}