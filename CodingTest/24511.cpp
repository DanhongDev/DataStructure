#include<iostream>
#include<deque>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    
    std::vector<int> arr(N, 0);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }
    
    std::deque<int> dq;
    for(int i=0; i<N; i++)
    {
        int val;
        std::cin >> val;
        if(arr[i] == 0)
        {
            dq.push_back(val);
        }
    }

    int M;
    std::cin >> M;
    while(M--)
    {
        int temp;
        std::cin >> temp;
        dq.push_front(temp);
        std::cout << dq.back() << ' ';
        dq.pop_back();
    }
    return 0;
}