#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N;

    //1. map 방식
    // std::map<int, int> m;
    // for(int i=0; i<N; i++)
    // {
    //     int temp;
    //     std::cin >> temp;
    //     m[temp]++;
    // }
    // std::cin >> M;
    // while(M--)
    // {
    //     int query;
    //     std::cin >> query;
    //     std::cout << m[query] << ' ';
    // }


    //2. upper_bound & lower_bound 방식 (정석)
    std::vector<int> arr(N,0);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    std::cin >> M;
    while(M--)
    {
        int target;
        std::cin >> target;

        std::cout << std::upper_bound(arr.begin(), arr.end(), target) - std::lower_bound(arr.begin(), arr.end(), target) << ' ';
    }
    return 0;
}