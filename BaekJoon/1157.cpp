#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    //대소문자로 된 단어가 주어지면 단어에서 가장 많이 사용된 알파벳은?? (단, 대문자 구분 X) ==> 출력은 대문자로.

    //문자열 입력 받기
    std::string str;
    std::cin >> str;
    
    //각 문자마다 개수를 저장하는 배열을 만든후 (인덱스는 n - 'a' 을 이용하여 생성) 카운팅.
    int cntArr[26] = {0, };

    //문자열을 다시 단어 하나하나로 쪼갤 수 있는 방법 생각해내기
    for(int i=0; i<str.length(); i++)
    {
        char c = str[i];
        
        //c가 대문자인 경우
        if(c >= 'A' && c <= 'Z')
        {
            int idx = c - 'A';
            cntArr[idx]++;
        }
        //c가 소문자인 경우
        else if(c >= 'a' && c <= 'z')
        {
            int idx = c - 'a';

            cntArr[idx]++;
        }
    }

    //배열을 순차적으로 탐색하여 가장 높은 인덱스를 뽑아내고 출력
    //int maxVal = -1, maxIdx = 0;
    //for(int i=0; i<26; i++)
    //{
    //    if(maxVal > 0 && cntArr[i] > 0 && cntArr[i] == maxVal)
    //    {
    //        std::cout << '?' << '\n';
    //        return 0;
    //    }
    //    if(cntArr[i] > maxVal)
    //    {
    //        maxVal = cntArr[i];
    //        maxIdx = i;
    //    }
    //}
    //std::cout << char(maxIdx + 'A') << '\n';
    
    //Gemini 개선
    int maxVal = -1;
    char result = '?';
    for(int i = 0; i < 26; i++)
    {
        if(cntArr[i] > maxVal)
        {
            maxVal = cntArr[i];
            result = i + 'A';
        }
        else if(cntArr[i] == maxVal && maxVal != -1)
        {
            result = '?';
        }
    }

    std::cout << result << '\n';
    
    
    return 0;
}


/*
1) OutofBounds가 뜬 이유.
24, 30 라인에 &&가 아닌 ||이기 때문이다.
c가 만약 'a'라 해도 || 때문에 c >= 'A'에 참이므로 if문으로 들어가게 된다.

2) 내코드가 틀린 이유.
더 큰 최대값이 나올수도 있는데도 바로 성급하게 return(45줄)을 해버려서 그렇다.

예를들어 bbaaccc 일경우 탐색을 할때, B가 2==2이므로 바로 ?을 출력하고 종료.
허나 c는 3번까지 나왔으므로 탐색을 더 진행해야 한다.

따라서,
1. 최댓값 찾기
2. 최댓값의 개수 세기
로 진행을 해야한다.
*/