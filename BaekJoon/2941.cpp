#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    //int cnt = 0;
    //for(int i=0; i<str.length(); i++)
    //{
    //    if(str[i] == 'c')
    //    {
    //        if(str[i+1] == '=' || str[i+1] == '-')
    //        {
    //            cnt++;
    //            i++;
    //        }
    //    }
    //    else if(str[i] == 'd')
    //    {
    //        if(str[i+1] == '-')
    //        {
    //            cnt++;
    //            i++;
    //        }
    //        else if(str[i+1] == 'z' && str[i+2] == '=')
    //        {
    //            cnt++;
    //            i+=2;
    //        }
    //        else
    //        {
    //            cnt++;
    //        }
    //    }
    //    else if(str[i] == 'l' && str[i+1] == 'j')
    //    {
    //        cnt++;
    //        i++;
    //    }
    //    else if(str[i] == 'n' && str[i+1] == 'j')
    //    {
    //        cnt++;
    //        i++;
    //    }
    //    else if(str[i] == 's' && str[i+1] == '=')
    //    {
    //        cnt++;
    //        i++;
    //    }
    //    else if(str[i] == 'z' && str[i+1] == '=')
    //    {
    //        cnt++;
    //        i++;
    //    }
    //    else
    //    {
    //        cnt++;
    //    }
    //}
    
    //Gemini 개선
    int cnt = 0;
    int len = str.length(); // 길이를 미리 저장해두면 더 깔끔
    
    for(int i = 0; i < len; i++)
    {
        cnt++; // 일단 글자 수를 하나 센다고 가정하고 시작
        
        if(i + 1 < len) // i+1 접근 전 확인
        {
            if(str[i] == 'c' && (str[i+1] == '=' || str[i+1] == '-')) i++;
            else if(str[i] == 'd' && str[i+1] == '-') i++;
            else if(i + 2 < len && str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') i += 2; // i+2 접근 전 확인
            else if(str[i] == 'l' && str[i+1] == 'j') i++;
            else if(str[i] == 'n' && str[i+1] == 'j') i++;
            else if(str[i] == 's' && str[i+1] == '=') i++;
            else if(str[i] == 'z' && str[i+1] == '=') i++;
        }
    }
    
    
    std::cout << cnt << '\n';
    return 0;
}

/*
틀린이유
1. d에서의 if문처럼 일반 l, n, s, z가 들어왔을때의 경우를 생각을 못했다.
gemini처럼 맨 처음의 cnt++처럼 먼저 수를 하나 센다고 하고 if문에서는 i++만 사용하는 거처럼
생각해도 좋은 방법일듯!!

tip) 배열의 인덱스 탐색에서 i+1, i+2와 같은 방법을 쓸때에는 i+1, i+2, ...가 배열의 끝을
탐색하는지 아닌지에 대해 접근 전에 확인이 필요하다. 쓰레기값을 탐색할 경우 범위초과 오류가
날 수 있기 때문이다.



*/