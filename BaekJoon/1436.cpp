#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int cnt = 0, num = 665;

    while(cnt<N)
    {
        num++;

        int cnt_666 = 0;
        int temp = num;
        bool found  = false;
        
        while(temp > 0)
        {
            if(temp % 10 == 6)
            {
                cnt_666++;
            }
            else
            {
                cnt_666 = 0;
            }

            if(cnt_666 >= 3)
            {
                found = true;
                break;
            }

            temp /= 10;
        }

        if(found)
        {
            cnt++;
        }

    }
    
    std::cout << num << '\n';
    return 0;
}