#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //1: 2
    //2: 4
    //3: 8
    //4: 16
    int arr[6];
    arr[0] = 1;
    for(int i=1; i<6; i++)
    {
        arr[i] = arr[i-1] * 2;
    }
    int N;
    std::cin >> N;
    std::cout << arr[N] << '\n';

    return 0;
}