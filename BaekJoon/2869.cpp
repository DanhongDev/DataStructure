#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B, V;
    std::cin >> A >> B >> V;

    //int h = 0, d = 0;
    //while(h < V) //시간초과로 실패.
    //{
    //    d++;
    //    h += A;
    //    if(h>=V)
    //    {
    //        break;
    //    }
    //    h -= B;
    //}
    //std::cout << d << '\n';
    
    int d_day = V-A;
    int h = A-B;

    int cnt = d_day / h;
    if(d_day % h > 0)
    {
        cnt++;
    }

    //last day
    cnt++;

    std::cout << cnt << '\n';

    return 0;
}