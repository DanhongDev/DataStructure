#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    std::cin >> a >> b >> c;

    if(a==b && b==c && c==a)
    {
        std::cout << a+b+c << '\n';
        return 0;
    }
    
    if(a+b <= c) 
    {
        c = a+b-1;
    }
    else if(b+c <= a) 
    {
        a = b+c-1;
    }
    else if(c+a <= b) 
    {
        b = c+a-1;
    }
    std::cout << a+b+c << '\n';

    return 0;
}