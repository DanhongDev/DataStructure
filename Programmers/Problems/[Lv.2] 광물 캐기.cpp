#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int> picks, const vector<string> &minerals, int idx, int stam, int &answer, int cnt)
{
    if(stam >= answer) return; //가지치기 (이미 최소를 넘겼으면 패스)

    if(cnt==0 || idx >= minerals.size()) //채광 완료 시
    {
        answer = min(answer, stam);
        return;
    }

    for(int i=0; i<picks.size(); i++)
    {
        if(picks[i] > 0)
        {
            picks[i]--;
            cnt--;

            int nx_stam = stam;

            for(int j=idx; j<idx+5 && j<minerals.size(); j++)
            {
                if(i==0) //다이아 곡괭이
                {
                    nx_stam += 1;
                }
                else if(i==1) //철 곡괭이
                {
                    if(minerals[j] == "diamond") nx_stam += 5;
                    else nx_stam += 1;
                }
                else
                {
                    if(minerals[j] == "diamond") nx_stam += 25;
                    else if(minerals[j] == "iron") nx_stam += 5;
                    else nx_stam += 1;
                }
            }

            DFS(picks, minerals, idx+5, nx_stam, answer, cnt);

            picks[i]++;
            cnt++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 1e9;
    int cnt = 0;
    for(int p : picks) cnt += p;

    DFS(picks, minerals, 0, 0, answer, cnt);
    
    return answer;
}