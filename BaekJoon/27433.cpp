#include<iostream>

long long Facto(long long n)
{
    if(n<=1) return 1;
    else return Facto(n-1) * n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << Facto(n) << '\n';
    
    return 0;
}