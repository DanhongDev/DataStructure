#include<iostream>

int N, M;
int arr[10];

void func(int depth, int before)
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

    for(int i=before+1; i<=N; i++)
    {
        arr[depth] = i;
        func(depth + 1, i); //여기다가 i를 변수로 넘겨줘서 오름차순으로 되게 만들면...??
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;

    func(0, 0);
    
    return 0;
}