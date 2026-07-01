#include<iostream>

//1. 팩토리얼을 이용한 조합공식
int Facto(int n)
{
    if(n<=1) return 1;
    return n * Facto(n-1);
}

//2. 조합공식 이용 ==> 사용 금지(개념 이해로만)
// long long comb(long long n, long long k)
// {
//     if(k==0 || n==k) return 1;
//     return comb(n-1, k-1) + comb(n-1, k);
// }

//3. DP 메모이제이션
int dp[31][31]; //n과 k에 따라 크기 조정하면 됨. (여유를 위해 +1씩)
int comb(int n, int k)
{
    if(k==0 || n==k) return 1;

    if(dp[n][k] > 0) return dp[n][k];
    return dp[n][k] = comb(n-1, k-1) + comb(n-1, k);
}

//4. DP 반복문 (파스칼의 삼각형) ==> 가장 추천
void Cal()
{
    for(int i=1; i<=30; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j=1; j<i; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while(T--)
    {
        long long N, M;
        std::cin >> N >> M;

        std::cout << comb(M, N) << '\n';
    }
    
    return 0;
}