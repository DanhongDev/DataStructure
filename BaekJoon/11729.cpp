#include<iostream>

void Hanoi(int n, int start, int mid, int end)
{
    if(n == 1)
    {
        std::cout << start << ' ' << end << '\n';
        return;
    }

    //1. 치우기
    Hanoi(n-1, start, end, mid);

    //2. 옮기기
    std::cout << start << ' ' << end << '\n';

    //3. 합치기
    Hanoi(n-1, mid, start, end);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::cout << (1 << N)-1 << '\n';

    Hanoi(N, 1, 2, 3);
    
    return 0;
}