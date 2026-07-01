#include<iostream>
#include<vector>
#include<algorithm>

int binary_search(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }

        else if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr (N, 0);
    std::vector<int> ori_arr(N, 0);
    for(int i=0; i<N; i++)
    {
        std::cin >> ori_arr[i];
        arr[i] = ori_arr[i];
    }

    std::sort(arr.begin(), arr.end());
    auto last = std::unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    for(int i=0; i<N; i++)
    {
        //binary_search 내장함수 == lower_bound()
        //auto iter = std::lower_bound(arr.begin(), arr.end(), ori_arr[i]);
        //std::cout << (iter - arr.begin()) << ' ';

        //lower_bound함수 직접 구현!
        std::cout << binary_search(arr, ori_arr[i]) << ' ';
    }
    return 0;
}