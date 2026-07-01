#include<iostream>
#include<vector>

void Blank(std::vector<std::vector<char>>& arr, int r_left, int c_left, int len)
{
    int split_len = len / 3;

    for(int i=r_left + split_len; i<r_left + split_len * 2; i++)
    {
        for(int j=c_left + split_len; j<c_left + split_len * 2; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    if(split_len == 1)
    {
        return;
    }
    else
    {
        for(int i=0; i<len; i+=split_len)
        {
            for(int j=0; j<len; j+=split_len)
            {
                if(i==split_len && j==split_len)
                {
                    continue;
                }
                Blank(arr, r_left+i, c_left+j, split_len);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::vector<char>> arr(N, std::vector<char> (N, '*'));
    Blank(arr, 0, 0, N);
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}