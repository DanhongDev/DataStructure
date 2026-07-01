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

    int a,b,c,d;
    std::cin >> a >> b >> c >> d;

    int deno = b * d;
    int mole = a*d + b*c;

    int gcd = GCD(deno, mole);
    deno /= gcd;
    mole /= gcd;
    
    std::cout << mole << ' ' << deno << '\n';
    
    return 0;
}