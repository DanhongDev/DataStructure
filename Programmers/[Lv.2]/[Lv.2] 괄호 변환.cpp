#include <string>
#include <vector>

using namespace std;
//올바른 괄호 문자열인지 판단
bool is_right(const string &p)
{
    int cnt = 0;
    for(char c : p)
    {
        if(c == '(') cnt++;
        else cnt--;

        if(cnt < 0) return false;
    }
    return cnt == 0;
}
//균형잡힌 괄호 문자열로 분리
int Separate(const string &p)
{
    int cnt = 0;
    for(int i=0; i<p.size(); i++)
    {
        if(p[i]=='(') cnt++;
        else cnt--;

        if(cnt == 0) return i;
    }
}
string solution(string p)
{
    //처음부터 올바른 괄호라면 그대로 반환
    if(is_right(p)) return p;
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if(p.empty()) return "";
    
    //2. 문자열 p를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    int sep_idx = Separate(p);
    string u = p.substr(0, sep_idx+1);
    string v = p.substr(sep_idx+1);
    
    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if(is_right(u))
    {
        //3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        return u + solution(v);
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
    else
    {
        //4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        string temp = "(";
        //4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        temp += solution(v);
        //4-3. ')'를 다시 붙입니다. 
        temp += ')';
        //4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        u = u.substr(1, u.size()-2); //앞뒤 제거
        for(char &c : u)
        {
            if(c == '(') c = ')';
            else c = '(';
        }
        temp += u;
        //4-5. 생성된 문자열을 반환합니다.
        return temp;
    }
}