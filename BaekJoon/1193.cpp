#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //각 분수의 분자는 행 분모는 열로 치환하여 생각가능
    int N;
    std::cin >> N;

    //N이 몇번째 그룹에 속하는지 찾기 (k번째)
    int step=1, k=0;
    while(N>0)
    {
        k++;
        N -= step;
        if(N<=0)
        {
            N+=step;
            break;
        }
        step++;
    }
    //N이 k번 그룹에 몇번째 인지 찾기 (pos값)
    
    //지금 내 코드에선 N이 pos값이 됨.
    
    //k번째 그룹의 분자+분모는 k+1.
    int pos = N, i, j;
    if(k%2 == 1)
    {
        //(k+1)-pos로 분자값(i)찾기
        i = (k+1) - pos;
        //홀수일경우 j는 pos그대로
        j = pos;
    }
    else
    {
        //짝수일경우 i는 pos그대로
        i = pos;
        //(k+1)-i로 분모값(j) 찾기
        j = (k+1) - pos;
    }

    //분자 분모 출력.
    std::cout << i << '/' << j << '\n';

    return 0;
}