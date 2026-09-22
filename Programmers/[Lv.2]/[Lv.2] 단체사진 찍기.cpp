#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(const string &fri, vector<bool> &visited, string cur, const vector<string> &data, int &answer)
{
    if(cur.size() == fri.size())
    {
        //조건 판별
            //조건에서의 각 글자를 바로 인덱스로 뽑아내는 방법이 없을까?
        for(string d : data)
        {
            //간격 재기
            int loc_1 = cur.find(d[0]);
            int loc_2 = cur.find(d[2]);
            int interval = (max(loc_1, loc_2) - min(loc_1, loc_2)) - 1;

            int num = d[4] - '0';
            if(d[3] == '=' && interval != num) return;
            else if(d[3] == '>' && interval <= num) return;
            else if(d[3] == '<' && interval >= num) return;
        }
        answer++;
        return;
    }

    for(int i=0; i<fri.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            DFS(fri, visited, cur+fri[i], data, answer);
            visited[i] = false;
        }
    }
}

int solution(int n, vector<string> data)
{
    int answer = 0;

    string friends = "ACFJMNRT";
    vector<bool> visited(friends.size(), false);
    DFS(friends, visited, "", data, answer);
    
    return answer;
}