#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    //중복 체크 컨테이너 set
    unordered_set<string> s;
    s.reserve(words.size());

    //첫번째 순서는 넣기만 하고 패스
    s.insert(words[0]);
    char prev = words[0][words[0].size()-1];

    //num: 탈락한 사람의 번호, cnt_cycle: 차례 카운트
    int num = 0, cnt_cycle = 1;

    for(int i=1; i<words.size(); i++)
    {
        //사이클 수 체크
        if(i%n == 0)
        {
            cnt_cycle++;
        }
        char c = words[i][0];
        //3번 끝말잇기가 안되었을 때: c != prev
        //4번 중복된 단어를 말했을 때: s.find(words[i]) != s.end()
        //5번 말한 단어가 한 글자일 때: words[i].size() == 1
        if(c != prev || s.find(words[i]) != s.end() || words[i].size() == 1)
        {
            num = (i%n) + 1;
            break;
        }
        else
        {
            s.insert(words[i]);
        }
        prev = words[i][words[i].size()-1];
    }

    if(num == 0) cnt_cycle = 0;

    return {num, cnt_cycle};
}

int main()
{
    vector<string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    vector<int> answer = solution(2, words);

    return 0;
}

vector<int> Gesolution(int n, vector<string> words)
{
    unordered_set<string> s;
    s.reserve(words.size());
    
    s.insert(words[0]);
    //com1: .back() 사용
    char prev = words[0].back();

    //com2: num = (i%n)+1, cnt_cycle = (i/n)+1로 각각 수식으로 대체 가능.

    for(int i=1; i<words.size(); i++)
    {
        char c = words[i].front();

        if(c != prev || s.find(words[i]) != s.end() || words[i].size() == 1)
        {
            return {(i%n)+1, (i/n)+1};
        }

        s.insert(words[i]);
        prev = words[i].back();
    }

    //루프를 통과했다면 탈락자가 없으므로 0, 0 리턴
    return {0, 0};
}