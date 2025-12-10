#include<iostream>
#include<vector>

const int MAX = 1000000;
void Eratos(std::vector<bool>& arr)
{
    for(int i=2; i*i<=MAX; i++)
    {
        if(arr[i])
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                arr[j] = false;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //에라토스테네스의 체를 이용하여 소수 구해놓기.
    std::vector<bool> arr(MAX+1, true);
    arr[0] = false;
    arr[1] = false;
    Eratos(arr);
    //i=0, j=0부터 i<N, j<N까지 이중 for문???
    //0.5초인데.. 1초에 1억번 검사하니까 0.5초면 5천만번 근데 N은 백만 까지니까 가능한가..?

    
    //이중 for문은 1,000,000 * 1,000,000 = 1,000,000,000,000이므로 0.5초안에 계산 못함
    //이중for문 보다는 a+b=N 이라하면 a만 알면 b는 자동으로 구할수 있음
    //즉 a와 N-a가 소수인지만 판별하면 끝.
    //최적화: 두 소수의 순서만 다른 것은 같은 파티션이라 했으므로,
    //a<=b인 경우만 구하면됨.
    //a<=N-a -> 2a<=N -> a <= N/2... 즉 a <= N/2 까지만 탐색하면 끝.
    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        int cnt=0;
        for(int i=2; i<=n/2; i++)
        {
            if(arr[i] && arr[n-i])
            {
                cnt++;
            }
        }
        std::cout << cnt << '\n';
    }
    
    return 0;
}