#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    int N;

    long long arr[100];
    arr[0] = arr[1] = arr[2] = 1;

    for(int i=3; i<100; i++)
    {
        arr[i] = arr[i-2] + arr[i-3];
    }

    while(T--)
    {
        std::cin >> N;

        std::cout << arr[N-1] << '\n';
    }
    
    return 0;
}