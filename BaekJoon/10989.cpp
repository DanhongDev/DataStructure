#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> arr(10001, 0);
    while(N--)
    {
        int temp;
        std::cin >> temp;
        arr[temp]++;
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > 0)
        {
            for(int j=0; j<arr[i]; j++)
            {
                std::cout << i << '\n';
            }
        }
    }
    
    return 0;
}