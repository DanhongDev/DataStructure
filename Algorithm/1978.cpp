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

    int T;
    std::cin >> T;

    int n, cnt = 0;
    while(T--)
    {
        std::cin >> n;
        if(isPrime(n))
        {
            cnt++;
        }

    }

    std::cout << cnt << '\n';
    return 0;
}