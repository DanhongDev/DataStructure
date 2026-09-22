#include <string>
#include <vector>
#include <sstream> //stringstream
#include <cctype> //isdigit
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> m_info;

void DFS(int depth, string key, const vector<string> &tokens, int score)
{
    if(depth == 4)
    {
        m_info[key].push_back(score);
        return;
    }

    DFS(depth+1, key + tokens[depth], tokens, score);

    DFS(depth+1, key + "-", tokens, score);
}
vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    // 50,000 x 100,000 = 5,000,000,000이라서 시간초과 날것이다.

    for(string i : info)
    {
        stringstream ss(i);
        vector<string> token(4);
        int score = 0;
        
        ss >> token[0] >> token[1] >> token[2] >> token[3] >> score;

        //바로 추가하는 것이 아닌 해당 문자열을 바탕으로 DFS돌려서 모든 - 가 들어가는 경우를 바로 만들어내자.
        DFS(0, "",token, score);
    }

    for(string q : query)
    {
        stringstream ss(q);
        string str;
        string cond;
        int score = 0;
        while(ss >> str)
        {
            if(str == "and") continue;

            if(isdigit(str[0])) score = stoi(str);
            else cond += str;
        }

        int cnt = 0;
        for(int s : m_info[cond])
        {
            if(s >= score) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}