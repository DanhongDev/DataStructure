#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;
    for(string str : s)
    {
        // 가지치기: 애초에 크기가 3이하면 그대로 반환
        if(str.size() <= 3) 
        {
            answer.push_back(str);
            continue;
        }

        // 1단계: 110 제거
        string cut = ""; // 110을 제거 후 정렬되어 있는 문자열
        int cnt = 0;
        for(int i=0; i<str.size(); i++)
        {
            cut += str[i];
            if(cut.size() >= 3)
            {
                int n = cut.size();
                if(cut[n-3]=='1' && cut[n-2]=='1' && cut[n-1]=='0')
                {
                    for(int i=0; i<3; i++) cut.pop_back();
                    cnt++;
                }
            }
        }
        string oneonezero = "";
        while(cnt--) oneonezero += "110";
        
        // 2단계: 110 재삽입
        int idx = 0;
        for(int i=cut.size()-1; i>=0; i--)
        {
            if(cut[i] == '0')
            {
                idx = i + 1;
                break;
            }
        }
        cut.insert(idx, oneonezero);
        answer.push_back(cut);
    }
    
    return answer;
}