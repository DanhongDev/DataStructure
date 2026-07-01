#include <iostream>
#include <string>

//My. 이중 for문을 이용하여 하나하나 탐색하는 방법 O(N^2)
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(NULL);
//
//
//    int T;
//    std::cin >> T;
//    std::string str;
//    int cnt = 0;
//
//    while(T--)
//    {
//        std::cin >> str;
//        int len = str.length();
//        bool group = true;
//
//        for(int i=0; i<len; i++)
//        {
//            for(int j=i+1; j<len; j++)
//            {
//                if(str[i] != str[j] && str[i] == str[j+1])
//                {
//                    group = false;
//                }
//            }
//        }
//
//        if(group) 
//        {
//            cnt++;
//        }
//    }
//
//    std::cout << cnt << '\n';
//    return 0;
//}

//Gemini. O(N)
//현재 탐색하고 있는 문자가 이미 탐색했던 문자였는지에 대한 정보를 저장하는 배열을 이용
//이 배열이 true라면 그 문자는 이전에 탐색했던 적이 있으면 그룹문자가 아니므로 return false.

//현재 탐색하고 있는 문자와 그 이전의 문자가 같은지 다른지에 대해 조사
//다를 경우 현재 문자가 이전에 탐색됐던 적이 있는지에 대해 조사

bool isGroup(const std::string& str)
{
    //현재 문자가 이미 탐색했던 문자인지에 대한 정보가 저장되어 있는 배열
    bool chkArr[26] = {false, };

    //각 단어의 첫 문자는 항상 그룹 단어를 만족
    chkArr[str[0] - 'a'] = true;

    for(int i=1; i<str.length(); i++)
    {
        if(str[i] != str[i-1]) //현재문자와 이전문자가 다를경우
        {
            if(chkArr[str[i] - 'a']) //현재 문자가 이미 탐색되었을 경우 false
            {
                return false;
            }
            else
            {
                //아니라면 현재문자를 탐색했으므로 해당 인덱스 true로 변경
                chkArr[str[i] - 'a'] = true;
            }
        }
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, cnt = 0;
    std::cin >> T;
    while(T--)
    {
        std::string str;
        std::cin >> str;

        if(isGroup(str))
        {
            cnt++;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}