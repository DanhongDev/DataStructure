#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr(N, 0);

    int sum = 0;
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::sort(arr.begin(), arr.end());

    int cnt=0, max_cnt=0, mode=0;
    bool second_cond = false;
    for(int i=0; i<N; i++)
    {
        if(i==0 || arr[i] == arr[i-1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        if(cnt > max_cnt)
        {
            max_cnt = cnt;
            mode=arr[i];
            second_cond = false;
        }
        else if(!second_cond && max_cnt == cnt)
        {
            //벡터가 오름차순으로 정렬되었기 때문에 바로 실행해도 문제없음.
            mode = arr[i];
            second_cond = true;
        }
    }

    std::cout << (int)round((double)sum / N) << '\n';
    std::cout << arr[N/2] << '\n';
    std::cout << mode << '\n';
    std::cout << arr.back() - arr.front() << '\n';
    
    return 0;
}