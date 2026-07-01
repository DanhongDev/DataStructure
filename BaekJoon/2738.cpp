#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> arr(N, std::vector<int>(M,0));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    int temp;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> temp;
            arr[i][j] += temp;
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}