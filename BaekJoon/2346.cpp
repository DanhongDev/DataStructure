#include<iostream>
#include<deque>
//#include<vector>
#include<cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    //std::deque<int> dq;
    //vector를 사용하는 방법은 비효율적이다.
    //std::vector<int> arr(N, 0);

    //deque의 자료형을 단순 int가 아닌 pair로 바꿔보자
    std::deque<std::pair<int,int>> dq;
    for(int i=0; i<N; i++)
    {
        int input_val;
        std::cin >> input_val;
        dq.push_back({input_val, i+1});
        //arr[i] = input_val;
    }

    while(!dq.empty())
    {
        int val = dq.front().first;
        std::cout << dq.front().second << ' ';
        //val에 해당하는 요소의 인덱스에 순서를 메겨줘야함.
            //1. 원본 배열에서 search한다음 순서 배열에 메겨주기.
        // for(int i=0; i<N; i++)
        // {
        //     if(arr[i] == val)
        //     {
        //         std::cout << i+1 << ' ';
        //         break;
        //     }
        // }
        dq.pop_front();
        if(dq.empty()) break; //pop을 한 후에 바로 empty면 밑에 코드 실행할 필요 없음.

        if(val > 0)
        {
            for(int i=0; i<val-1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for(int i=0; i<std::abs(val); i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}