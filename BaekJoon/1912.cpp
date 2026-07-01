#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    int max = arr[0];
    int final_max = arr[0];
    for(int i=1; i<N; i++)
    {
        max = (max + arr[i]) > arr[i] ? max + arr[i] : arr[i];

        final_max = max > final_max ? max : final_max;
    }
    
    std::cout << final_max << '\n';

    return 0;
}