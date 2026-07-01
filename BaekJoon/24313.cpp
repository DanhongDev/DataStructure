#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a1, a0;
    int c;
    int n0;

    std::cin >> a1 >> a0;
    std::cin >> c;
    std::cin >> n0;

    //O(n) : 모든 n >= n0에 대하여 f(n) <= c * g(n) 을 만족하는 양의 상수 c와 n0가 존재한다.

    //i) f(n)구하기 f(n) = a1 * n + a0
    int n;
    int fn;

    //ii) f(n)을 통하여 g(n)구하기
    int gn;

    //iii) O(n)정의에 의하여 만족하는지 판별하기
    for(n=n0; ; n++)
    {
        fn = a1 * n + a0;
        gn = n;
        if(fn >= c * gn)
        {
            std::cout<< 0 << '\n';
            return 0;
        }
        else
        {
            std::cout<< 1 << '\n';
            return 0;
        }
    }


    return 0;
}

//Gemini
#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a1, a0;
    int c;
    int n0;

    std::cin >> a1 >> a0;
    std::cin >> c;
    std::cin >> n0;

    // f(n) <= c * n 을 만족해야 함
    
    // 조건 1: n0일 때 성립하는가?
    bool condition1 = (a1 * n0 + a0 <= c * n0);
    
    // 조건 2: f(n)의 증가율이 c*n보다 가파르지 않은가?
    bool condition2 = (a1 <= c);

    // 두 조건을 모두 만족해야 1
    if (condition1 && condition2)
    {
        std::cout << 1 << '\n';
    }
    else
    {
        std::cout << 0 << '\n';
    }

    return 0;
}