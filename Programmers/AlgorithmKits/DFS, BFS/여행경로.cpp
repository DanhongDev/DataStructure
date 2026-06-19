#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<vector<string>> &tickets, vector<string> &answer, vector<bool> &visited, string cur_port)
{
    //오름차순으로 sort를 했기 때문에 첫 완성 경로가 정답이 된다. 따라서 경로를 모두 찾았으면 즉시 종료
    if(answer.size() == tickets.size() + 1) return true;

    //도착지에 경유하여 출발하는 티켓이 있는지 확인
    for(int i=0; i<tickets.size(); i++)
    {
        if(!visited[i] && tickets[i][0] == cur_port)
        {
            visited[i] = true;
            answer.push_back(tickets[i][1]);

            if(dfs(tickets, answer, visited, tickets[i][1])) return true;

            visited[i] = false;
            answer.pop_back();
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());

    answer.push_back("ICN");

    dfs(tickets, answer, visited, "ICN");

    return answer;
}