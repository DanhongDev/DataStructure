#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[9][9], max = -1, x, y, temp;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            std::cin >> temp;
            if(temp > max)
            {
                max = temp;
                x = i;
                y = j;
            }
        }
    }

    std::cout << max << '\n' << x+1 << " " << y+1 << '\n';

    return 0;
}