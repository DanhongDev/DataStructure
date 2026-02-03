#include<iostream>

int N, M;
int arr[10];
bool is_used[10];

void func(int depth)
{
    if(depth == M)
    {
        for(int i=0; i<M; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++)
    {
        if(!is_used[i])
        {
            arr[depth] = i;
            is_used[i] = true;

            func(depth + 1);

            is_used[i] = false;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;

    func(0);
    
    return 0;
}