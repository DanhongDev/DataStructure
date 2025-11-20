#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N;
    std::cin >> N;

    std::vector<int> arr;
    arr.reserve(10);

    while(N>0)
    {
        int temp = N%10;
        arr.push_back(temp);
        N /= 10;
    }
    
    std::sort(arr.begin(),arr.end());

    for(int i = arr.size()-1; i>=0; i--)
    {
        std::cout<< arr[i];
    }

    std::cout << '\n';
    return 0;
}