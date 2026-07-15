#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> dict;

    // 1. 길이가 1인 모든 단어 사전 초기화 AtoZ
    int idx = 1;
    for(char c='A'; c<='Z'; c++)
    {
        dict[string(1, c)] = idx++;
    }

    // 2. 메시지 탐색
    int i = 0;
    while(i<msg.size())
    {
        string word = "";
        word += msg[i];

        // 3. 다음 글자를 붙인 조합(word + msg[j])이 사전에 있을 동안 계속 word를 확장
        int j = i+1;
        while(j<msg.size() && dict.find(word + msg[j]) != dict.end())
        {
            word += msg[j];
            j++;
        }

        // 4. 사전에 있는 가장 긴 단어 w의 색인 번호를 출력
        answer.push_back(dict[word]);

        // 5. 다음 글자가 남아있다면 새로운 단어(word + msg[j])를 사전에 등록
        if(j<msg.size())
        {
            dict[word + msg[j]] = idx++;
        }

        // 6. 처리한 문자열 길이만큼 i를 j만큼 점프
        i = j;
    }
    
    return answer;
}