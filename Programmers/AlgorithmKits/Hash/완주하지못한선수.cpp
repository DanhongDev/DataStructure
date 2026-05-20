#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main() 
{
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    
    string result = solution(participant, completion);
    cout << "완주하지 못한 선수: " << result << "\n";

    return 0;
}

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    
    unordered_map<string, int> list;
    //해당 참가자의 값을 목록에서 상승
    for(string name : participant)
    {
        list[name]++;
    }
    //해당 완주자의 값을 목록에서 조정.
    for(string name : completion)
    {
        list[name]--;
    }
    //목록에 값이 1이상인 사람이 리타이어.
    for(const auto& [name, cnt] : list )
    {
        if(cnt > 0)
        {
            answer = name;
            break;
        }
    }
    
    return answer;
}