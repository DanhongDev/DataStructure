#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    //std::cout << 1 << '\n' << 0 << '\n'; //24262
    //std::cout << n << '\n' << 1 << '\n'; //24263
    //std::cout << n*n << '\n' << 2 << '\n'; //24264
    
    /* //24265
    long long sum = 0;
    for(int i=1; i<n; i++)
    {
        sum += i;
    }
    std::cout << sum << '\n' << 2 << '\n';
    */

    //std::cout << n*n*n << '\n' << 3 << '\n'; //24266

    long long cnt = (n * (n-1) * (n-2)) / 6;
    std::cout << cnt << '\n' << 3 << '\n';
    
    return 0;
}