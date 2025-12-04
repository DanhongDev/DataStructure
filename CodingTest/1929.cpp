#include<iostream>

bool isPrime(int n)
{
    if(n<2) return false;

    for(int i=2; i*i <= n; i++)
    {
        if(n%i == 0) return false;
    }

    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N;
    std::cin >> M >> N;
    for(int i=M; i<=N; i++)
    {
        if(isPrime(i))
        {
            std::cout << i << '\n';
        }
    }
    
    return 0;
}