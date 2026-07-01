#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int sum=0;
    for(int i=1; i<N; i++)
    {
        sum += i;
        int temp = i;
        while(temp>0)
        {
            int sep = temp % 10;
            sum += sep;
            temp /= 10;
        }

        if(sum == N)
        {
            std::cout << i << '\n';
            return 0;
        }
        else
        {
            sum = 0;
        }
    }
    
    std::cout << 0 << '\n';
    return 0;
}