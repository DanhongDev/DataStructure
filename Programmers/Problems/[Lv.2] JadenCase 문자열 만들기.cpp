#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

string solution(string s)
{
    string answer = "";
    bool is_first = true;

    for(char &c : s)
    {
        if(c == ' ')
        {
            answer += c;
            is_first = true;
        }
        else if(is_first)
        {
            answer += toupper(c);
            is_first = false;
        }
        else
        {
            answer += tolower(c);
        }
    }

    return answer;
}