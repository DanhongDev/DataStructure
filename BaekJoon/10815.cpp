#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

int binary_search(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size()-1;

    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == target)
        {
            return 1;
        }
        
        else if(arr[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr(N, 0);
    //2. map을 이용해서 풀어보기
        //map이란?? 사전이라 생각하면 좋다.
        //map<key, value>로 이루어져 있다.
        //각 key값에 해당하는 value를 저장하여 바로바로 사용할 수 있다.
    std::map<int, bool> dict;
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
        dict[arr[i]] = true;
    }

    std::sort(arr.begin(), arr.end());

    int M;
    std::cin >> M;

    for(int i=0; i<M; i++)
    {
        int temp;
        std::cin >> temp;
        //1. 이진 탐색으로 풀어보기
        //if(binary_search(arr, temp))
        //1-1. 이진 탐색 함수를 내장함수 이용해보기
        //auto iter = std::lower_bound(arr.begin(), arr.end(), temp);
        //if(iter != arr.end() && *iter == temp)
        //{
        //    std::cout << 1 << ' ';
        //}
        //else
        //{
        //    std::cout << 0 << ' ';
        //}
        //if(dict[temp]) //살짝 오류가 날수도 있는 부분이다.
        if(dict.find(temp) != dict.end())
        {
            std::cout << 1 << ' ';
        }
        else
        {
            std::cout << 0 << ' ';
        }
    }
    return 0;
}