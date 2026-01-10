#include<iostream>

int Fibo(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibo(n-1) + Fibo(n-2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cout << Fibo(n) << '\n';
    
    return 0;
}