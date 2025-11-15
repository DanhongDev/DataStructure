#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    int res=0, temp=0;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                temp = arr[i] + arr[j] + arr[k];
                if(temp <= M && temp > res)
                {
                    res = temp;
                }
            }
        }
    }
    
    std::cout << res << '\n';
    return 0;
}