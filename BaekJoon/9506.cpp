#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while(1)
    {
        std::cin >> N;
        if(N == -1)
        {
            return 0;
        }
        std::vector<int> arr;
        int sum = 0;
        
        for(int i=1; i<=N/2; i++)
        {
            if(N%i == 0)
            {
                sum += i;
                arr.push_back(i);
            }
        }

        if(sum == N)
        {
            std::cout << N << " = ";
            for(int i=0; i<arr.size(); i++)
            {
                std::cout << arr[i];
                if(i != arr.size()-1)
                {
                    std::cout << " + ";
                }
            }
        }
        else
        {
            std::cout << N << " is NOT perfect.";
        }

        std::cout << '\n';
    }
    
    return 0;
}