#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s)
{
    if(s.size() == 1) return 1;
    
    int answer = 1e9;
    for(int unit=1; unit<=s.size(); unit++)
    {
        //단위별로 잘라서 그룹화 하기
        vector<string> sub;
        for(int i=0; i<s.size(); i+=unit) //올바르게 잘라지지 않음 --> 해결할 방법???
        {
            sub.push_back(s.substr(i, unit));
        }
        sub.push_back("");

        //압축 시작
        string comp_str = "";
        int cnt = 1;
        for(int i=0; i<sub.size(); i++)
        {
            if(sub[i] != sub[i+1])
            {
                if(cnt>1)
                {
                    comp_str += to_string(cnt);
                    cnt = 1;
                }
                comp_str += sub[i];
            }
            else
            {
                cnt++;
            }
        }
        answer = min(answer, (int)comp_str.size());
    }

    return answer;
}