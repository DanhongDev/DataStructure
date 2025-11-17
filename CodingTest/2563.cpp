#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[100][100] = {0, };
    int T;
    std::cin >> T;
    
    int res = 0;
    while(T--)
    {
        int x, y;
        std::cin >> x >> y;
        for(int i=x-1; i<x+9; i++)
        {
            for(int j=y-1; j<y+9; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[i][j] = 1;
                    res++;
                }
            }
        }
    }

    std::cout << res;
    return 0;
}