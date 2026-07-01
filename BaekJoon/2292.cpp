#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //long long N, temp = 1, times = 1, cnt = 1;
    //std::cin >> N;
    ////temp의 값은 각 벌집 둘레에서 가장 큰 숫자 즉, 끝 숫자
    ////N이 temp보다 작게되면 그 둘레에 포함되어 있다는거니 그때의 cnt를 출력하면 완성
    //while(temp < N)
    //{
    //    cnt++;
    //    temp += 6 * times;
    //    times++;
    //}
//
    //std::cout << cnt << '\n';
//
    //return 0;

    //Gemini의 개선버전
    //times 변수가 필요 없다. 메모리 공간 덜씀
    long long N;
    std::cin >> N;

    if(N == 1)
    {
        std::cout << 1 << '\n';
        return 0;
    }

    long long size = 1, step = 6;
    int cnt = 1; //1은 이미 처리했으므로.

    while(size < N)
    {
        size += step;
        step += 6;
        cnt++;
    }

    std::cout << cnt << '\n';

    return 0;
}

