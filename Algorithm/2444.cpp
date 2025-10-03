#include<iostream>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;

    int spaceCnt = N-1, starCnt = 1;
    for(int i=0; i<(2*N-1); i++) //전체 반복문 (2n-1)
    {
        if(i<N)
        {

            for(int j=0; j<spaceCnt; j++)
            {
                cout << ' ';
            }
            for(int k=0; k<starCnt; k++)
            {
                cout << '*';
            }
            
            if(spaceCnt > 0)
            {
                spaceCnt--;
            }
            if(starCnt < 2*N-1)
            {
                starCnt += 2;
            }
            
            cout << '\n';
        }
        else
        {
            if(spaceCnt < N-1)
            {
                spaceCnt++;
            }
            if(starCnt > 1)
            {
                starCnt -= 2;
            }
            for(int j=0; j<spaceCnt; j++)
            {
                cout << ' ';
            }
            for(int k=0; k<starCnt; k++)
            {
                cout << '*';
            }

            cout << '\n';
        }
    }

    //Gemini 개선판
    for(int i=1; i<=N; ++i)
    {
        //N-i개의 공백과 2i-1개의 별
        cout << string(N-1, ' ') << string(2*i-1, '*') << '\n';
    }
    for(int i=N-1; i>=1; --i)
    {
        cout << string(N-i, ' ') << string(2*i-1, '*') << '\n';
    }

    return 0;

    //결국 공백과 별의 개수 공식을 수식으로 못 풀어낸것이 코드가 길어진 이유였다...
    //앞으로 이런 간단한 문제라도 수식이 뭘까하면서 깊이 생각을 해봐야겠다.
}