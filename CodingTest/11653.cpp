#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    if(n == 1)
    {
        return 0;
    }

    for(int i=2; i*i<=n; i++)
    {
        //i가 약수라면 더 이상 나눠지지 않을때까지 나눠버리기
        while(n%i == 0)
        {
            //나누고 그떄그때마다 바로 출력
            std::cout << i << '\n';
            n /= i;
        }
    }

    //for문을 돌고 나왔는데도 아무것도 나눠지지 않았다면 그 숫자 자체가 소수이다.
    if(n > 1)
    {
        std::cout << n << '\n';
    }

    return 0;
}