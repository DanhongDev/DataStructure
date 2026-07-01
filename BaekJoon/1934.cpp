#include<iostream>

int GCD(int a, int b)
{
    if(b==0) return a;
    
    return GCD(b, a%b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while(T--)
    {
        int a,b;
        std::cin >> a >> b;

        int gcd = GCD(a, b);

        std::cout << (a*b) / gcd << '\n';
    }
    // while(T--)
    // {
    //     int a, b;
    //     std::cin >> a >> b;

    //     int max = a > b ? a : b;

    //     int gcd = 0;
    //     for(int i=max; i>=1; i--)
    //     {
    //         if(a%i == 0 && b%i == 0)
    //         {
    //             gcd = i;
    //             break;
    //         }
    //     }

    //     std::cout << gcd * (a/gcd) * (b/gcd) << '\n';
    // }
    
    return 0;
}