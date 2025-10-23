#include<iostream>

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }

    for(int i=2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N;
    std::cin >> M >> N;

    int min = 10001, sum = 0;
    for(int i=M; i<=N; i++)
    {
        if(isPrime(i))
        {
            sum += i;
            min = i < min ? i : min;
        }
    }

    if(sum == 0)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << sum << '\n';
        std::cout << min << '\n';
    }

    return 0;
}