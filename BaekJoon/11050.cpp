#include<iostream>

int Facto(int n)
{
    if(n<=1) return 1;
    return n * Facto(n-1);
}

//N이 커질경우.
int Comb(int n, int k)
{
    if(k==0 || n==k) return 1;

    return Comb(n-1,k-1) + Comb(n-1, k);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    std::cin >> N >> K;

    std::cout << Facto(N) / (Facto(K) * Facto(N-K)) << '\n';
    
    return 0;
}