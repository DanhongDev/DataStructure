#include<iostream>
#include<vector>

const int MAX = 123456 * 2;
void Eratos(std::vector<bool>& arr)
{
     //2부터 루트 MAX까지 돌며 배수들을 지움
    for(int i=2; i*i<=MAX; i++)
    {
        if(arr[i])
        {
            //i의 배수들은 소수가 아니므로 false처리
            for(int j=i*i; j<=MAX; j+=i)
            {
                arr[j] = false;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    //N이 크면 에라토스테네스의 체를 이용해야함.
    //1. 에라토스테네스의 체로 미리 소수 판별해두기
    std::vector<bool> is_prime(MAX+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    Eratos(is_prime);

    int n;
    while(std::cin >> n)
    {
        if(n==0) break;

        int cnt=0;

        for(int i=n+1; i<=2*n; i++)
        {
            if(is_prime[i])
            {
                cnt++;
            }
        }
        std::cout << cnt << '\n';
    }

    return 0;
}