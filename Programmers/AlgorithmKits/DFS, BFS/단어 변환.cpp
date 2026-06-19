#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isConvert(const string &a, const string &b)
{
    int cnt = 0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i]) cnt++;
    }

    return cnt == 1 ? true : false;
}

int solution(string begin, string target, vector<string> words) 
{
    //words안에 target이 없다면 무조건 return 0;
    int cnt = 0;
    for(const auto& word : words)
    {
        if(target == word) cnt++;
    }
    if(cnt == 0) return 0;
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    vector<bool> visited(words.size(), false);
    
    //1. 배열 내에서 한글자만 다른 애들을 큐에 넣는 방법을 찾기
    //단순하게 for문안에서 인덱스 별로 비교하고 != 일때 cnt++해주어 cnt==1일때만 변환 가능하다고 여김
    //2. 큐에서 하나씩 뽑으면서 현재 단어와 1에 부합하는 단어들 또 큐에 넣기
    //3. 2를 반복하며 target을 찾았을때 그때의 값을 리턴하기
    //3-1. 값을 어떻게 저장할 것인지 생각하기 
    //pair를 쓴다음 cnt++해주기??
    //map을 써서??
    
    int answer = 0;
    while(!q.empty())
    {
        string cur = q.front().first;
        answer = q.front().second;
        if(cur == target)
        {
            return answer;
        }
        q.pop();

        for(int i=0; i<words.size(); i++)
        {
            if(!visited[i] && isConvert(cur, words[i]))
            {
                q.push({words[i], answer+1});
                visited[i] = true;
            }
        }
    }

    return 0;
}