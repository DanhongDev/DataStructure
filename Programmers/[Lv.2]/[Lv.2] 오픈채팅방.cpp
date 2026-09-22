#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    unordered_map<string, string> member; //first: id, second: nickname
    vector<pair<string,string>> log; //first: id, second: type

    for(string r : record)
    {
        string type="", id="", nick="";
        stringstream ss(r);
        ss >> type >> id >> nick;

        if(type == "Enter")
        {
            member[id] = nick;
            log.push_back({id, type});
        }
        else if(type == "Leave")
        {
            log.push_back({id, type});
        }
        else //Change
        {
            member[id] = nick;
        }
    }
    
    for(int i=0; i<log.size(); i++)
    {
        string nick = member[log[i].first];
        if(log[i].second == "Enter")
        {
            answer.push_back(nick + "님이 들어왔습니다.");
        }
        else //Leave
        {
            answer.push_back(nick + "님이 나갔습니다.");
        }
    }
    return answer;
}