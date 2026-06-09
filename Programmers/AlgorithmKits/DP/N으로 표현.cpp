#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number)
{
    //dp를 접근하는 관점이 틀렸었다.
    //dp[목표 숫자] = 사용한 횟수 가 아니라
    //dp[사용한 횟수] = 만들 수 있는 숫자들의 집합 으로 dp를 설정했어야 했다.

    if(N==number) return 1;
    vector<unordered_set<int>> dp(9);
    dp[1].insert(N);
    
    //N, NN, NNN 등의 숫자를 이어 붙이기 위한 변수
    int seqN = 0;

    //k: N을 사용한 횟수 최소값 8을 넘으면 -1 이므로 1부터 8까지
    for(int k=1; k<=8; k++)
    {
        //1. N, NN, NNN을 초기화
        seqN = seqN * 10 + N;
        dp[k].insert(seqN);

        //2. 사칙연산 조합 구하기
        for(int i=0; i<k; i++)
        {
            for(int a : dp[i])
            {
                for(int b : dp[k-i])
                {
                    dp[k].insert(a+b);
                    dp[k].insert(a-b);
                    dp[k].insert(a*b);
                    if(b!=0) dp[k].insert(a/b);
                }
            }
        }

        //3. 목표 숫자 확인
        if(dp[k].find(number) != dp[k].end())
        {
            return k;
        }
    }

    return -1;
}


int getExponentLoop(int target, int N) 
{
    int count = 0;
    while (target > 1) {
        if (target % N != 0) {
            return -1; // N의 거듭제곱으로 딱 떨어지지 않는 경우 예외 처리
        }
        target /= N;
        count++;
    }
    return count;
}
//현재 숫자가 기준 숫자의 제곱인지를 확인하는 함수나 STL이 있을까...??
bool is_Square(int N, int i) //N: 기준 숫자, i: 현재 검사하려는 숫자
{
    int based = N;
    while(N<i)
    {
        N *= based;
        if(N==i) return true;
    }
    return false;
}
int solution(int N, int number) 
{
    //dp[i]: 자연수 i를 만드는데 사용한 N의 최소 개수
        //1. i가 NN/N 꼴로 표현이 가능한 경우.
            //11, 111, 1111, ... 이 이에 해당한다. (11 = NN/N, 111 = NNN/N, 1111 = NNNN/N, ...)
            //그럼 11, 111, 1111, ... 은 어떻게 수식을 만들 수 있을까??
            //DP를 순회하기전에 미리 값을 넣어주면 될거 같은데...
                //32000이하라 했으니 11, 111, 1111, 11111 이렇게 4개밖에 없네.
                //그럼 항상 11: 3개, 111: 4개, 1111: 5개, 11111: 6개 이겠다.
                //그러므로 N이 몇이든 dp[11] = 3, dp[111] = 4, dp[1111] = 5, dp[11111] = 6으로 해주면 되겠네.
        //2. i가 N의 제곱, 세제곱, 네제곱, ... 인 경우.
        //3. 1과 2가 아닌 경우. 즉, 현재 i보다 작은 제곱의 숫자부터 다음 제곱의 숫자까지는 3번에 해당함.
        //4. i < N인 경우. (내 생각엔 여기가 핵심!!!)
            //4-1. i가 1인 경우. --> 항상 2이다. (N/N)
            //4-2. i가 2인 경우. --> 항상 3이다. ((N+N)/N)
            //4-3. i가 3 ~ N-1인 경우.
                //4-3-1. N-1인 경우. --> 3이다.(N-(N/N))
                //4-3-2. 3 < i < N-1 인 경우. --> N - [ {N*(N-i)} / N ]이 수식이므로 개수 공식으로 풀어쓰면 dp[i] = 2+(N-i)이다.
        //5. i == N인 경우. --> 항상 1이다. (N 그 자체 이므로)

    //내가 유도한 점화식을 정리하자면
        //1) i==1인 경우: dp[1]=2 (N/N)
        //2) i==2인 경우: dp[2]=3 ((N+N)/N)
        //3) 2<i<(N-1)인 경우: dp[i] = 2+(N-i)  (N-[{N*(N-i)} / N]이 i를 구하는 수식)
        //4) i==(N-1)인 경우: dp[N-1]=3 (N-(N/N))
        //5) i==N인 경우: 항상 dp[N]=1 (N 그 자체)
        //6) i==11, 111, 1111, 11111인 경우: dp[11]=3, dp[111]=4, dp[1111]=5, dp[11111]=6
        //7) i>N 인 경우 dp[i] = dp[s] + dp[i-s] (s는 i보다 작은 N의 제곱)
    vector<int> dp(number+1);
    for(int i=3; i<dp.size(); i++) dp[i] = 99999999;
    int s = pow(N,1);

    for(int i=1; i<dp.size(); i++)
    {
        //특수한 경우
        if(i==1 && N!=1) dp[i]=2;
        else if(i==2 && N!=2) dp[i]=3;
        else if(i<N-1)
        {
            dp[i] = 2+(N-i);
        }
        else if(i==N-1) dp[i]=3;
        else if(i==N) dp[i]=1;
        else if(i==11||i==111||i==1111||i==11111)
        {
            switch(i)
            {
                case 11:
                    dp[i]=3;
                    break;
                case 111:
                    dp[i]=4;
                    break;
                case 1111:
                    dp[i]=5;
                    break;
                case 11111:
                    dp[i]=6;
                    break;
            }
        }
        
        //그 외에 경우 (i>N인 경우)
        else
        {
            if(is_Square(N, i))
            {
                s = i;
                //3제곱근을 넣어야함.
                dp[i] = getExponentLoop(i, N);
            }
            dp[i] = min(dp[i], dp[s] + dp[i-s]);
        }
    }
    
    return dp[number-1];
}
