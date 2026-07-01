#include<iostream>

bool isPrime(long long n)
{
    if(n<2)
    {
        return false;
    }
    for(long long i=2; i*i<=n; i++)
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

    int T;
    std::cin >> T;
    while(T--)
    {
        long long n;
        std::cin >> n;
        while(1)
        {
            if(isPrime(n))
            {
                std::cout << n << '\n';
                break;
            }
            n++;
        }
    }
    
    return 0;
}