#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool Check(const string &cur_id, const string &banned_id)
{
    if(cur_id.size() != banned_id.size()) return false;
    for(int i=0; i<cur_id.size(); i++)
    {
        if(banned_id[i] == '*') continue;
        else if(cur_id[i] != banned_id[i]) return false;
    }
    return true;
}
void DFS(int depth, const vector<string> &user_id, const vector<string> &banned_id, vector<bool> visited, unordered_set<int> &answer)
{
    if(depth == banned_id.size())
    {
        // 1. 비트마스킹 방법
        int bit = 0;
        for(int i=0; i<user_id.size(); i++)
        {
            if(visited[i])
            {
                bit |= (1 << i);
            }
        }
        answer.insert(bit);

        // 2. 정석
        // vector<string> temp;
        // for(int i=0; i<user_id.size(); i++)
        // {
        //     if(visited[i]) temp.push_back(user_id[i]);
        // }
        // sort(temp.begin(), temp.end());
        // string t;
        // for(int i=0; i<temp.size(); i++) t += temp[i];
        // //unoredered_set<string> ans를 매개변수에 생성 후
        //     //ans.insert(t);

        return;
    }

    for(int i=0; i<user_id.size(); i++)
    {
        if(!visited[i] && Check(user_id[i], banned_id[depth]))
        {
            visited[i] = true;
            DFS(depth+1, user_id, banned_id, visited, answer);
            visited[i] = false;
        }
    }
    
    return;
}
int solution(vector<string> user_id, vector<string> banned_id)
{
    vector<bool> visited(user_id.size(), false);
    unordered_set<int> answer;
    DFS(0, user_id, banned_id, visited, answer);

    return answer.size();
}

int main()
{
    int answer = solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"});
    
    return 0;
}