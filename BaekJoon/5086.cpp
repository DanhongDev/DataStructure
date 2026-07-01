#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //1. 첫 번째 숫자가 두 번째 숫자의 약수이다.
    //2. 첫 번째 숫자가 두 번째 숫자의 배수이다.
    //3. 첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다.

    int a, b;

    while(1)
    {
        std::cin>>a>>b;
        if(a == 0 && b == 0)
        {
            break;
        }
        if(b % a == 0)
        {
            std::cout << "factor" << '\n';
        }
        else if(a % b == 0)
        {
            std::cout << "multiple" << '\n';
        }
        else
        {
            std::cout << "neither" << '\n';
        }
    }

    return 0;
}