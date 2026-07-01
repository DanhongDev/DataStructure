#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[13];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<13; i++)
    {
        arr[i] = arr[i-1] * i;
    }
    int N;
    std::cin >> N;
    std::cout << arr[N] << '\n';
    
    return 0;
}