#include<iostream>
#include<queue>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr;
    arr.reserve(n);
    std::queue<int> q;

    for(int i=1; i<=n; i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        for(int i=0; i<k-1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int elem = q.front();
        q.pop();
        arr.push_back(elem);
    }
    
    std::cout << '<';
    for(int i=0; i<n; i++)
    {
        std::cout << arr[i];
        if(i<n-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << '>' << '\n';

    return 0;
}