#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> arr;
    int n;
    while(std::cin >> n)
    {
        arr.push_back(n);
    }
    
    //평균값 부분
    int sum = 0;
    for(int i=0; i<arr.size(); i++)
    {
        sum += arr[i];
    }
    std::cout << sum / arr.size() << '\n';

    //정렬부분 std::sort 사용
    std::sort(arr.begin(),arr.end());
    std::cout << arr[arr.size()/2] << '\n';


    return 0;
}