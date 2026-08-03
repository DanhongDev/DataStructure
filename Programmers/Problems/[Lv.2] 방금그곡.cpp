#include <string>
#include <vector>
#include <sstream>
using namespace std;

int getPlay(string start, string finish)
{
    int s_hour = stoi(start.substr(0,2));
    int s_min = stoi(start.substr(3,2));
    int s_time = s_hour * 60 + s_min;

    int f_hour = stoi(finish.substr(0,2));
    int f_min = stoi(finish.substr(3,2));
    int f_time = f_hour * 60 + f_min;

    return f_time - s_time;
}

string replaceNotes(string s)
{
    string result = "(None)";
    for(int i=0; i<s.size(); i++)
    {
        if(i+1<s.size() && s[i+1]=='#')
        {
            result += tolower(s[i]);
            i++;
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}
string solution(string m, vector<string> musicinfos)
{
    string answer = "";

    int max_play = -1;
    m = replaceNotes(m);
    for(string music: musicinfos)
    {
        stringstream ss(music);
        
        string start, finish, name, pitchs;
        getline(ss, start, ',');
        getline(ss, finish, ',');
        getline(ss, name, ',');
        getline(ss, pitchs);

        int play_time = getPlay(start, finish);

        pitchs = replaceNotes(pitchs);
        string new_notes = "";
        for(int i=0; i<play_time; i++)
        {
            new_notes += pitchs[i % pitchs.size()];
        }
       
        if(new_notes.find(m) != string::npos)
        {
            if(play_time > max_play)
            {
                max_play = play_time;
                answer = name;
            }
        }
    }

    return answer;
}