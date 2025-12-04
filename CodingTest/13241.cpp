#include<iostream>

int GCD(long long a, long long b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    std::cin >> a >> b;

    long long gcd = GCD(a, b);

    std::cout << (a*b) / gcd << '\n';
    
    return 0;
}