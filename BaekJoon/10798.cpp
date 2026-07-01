#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string arr[5];
    for(int i=0; i<5; i++)
    {
        std::getline(std::cin,arr[i]);
    }

    for(int j=0; j<15; j++)
    {
        for(int i=0; i<5; i++)
        {
            if(j < arr[i].length())
            {
                std::cout << arr[i][j];
            }
        }
    }

    return 0;
}