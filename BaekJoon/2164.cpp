#include<iostream>
#include<queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::queue<int> q;
    for(int i=1; i<=N; i++)
    {
        q.push(i);
    }

    while(q.size() != 1)
    {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    std::cout << q.front() << '\n';
    
    return 0;
}