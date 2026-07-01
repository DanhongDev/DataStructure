#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, k;
    std::cin >> N >> k;
    std::vector<int> arr(N, 0);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }
    
    std::sort(arr.begin(), arr.end());
    std::cout << arr[N-k] << '\n';

    return 0;
}