#include<iostream>
#include<cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    
    std::cout << (int)sqrt(N) << '\n';

    return 0;
}