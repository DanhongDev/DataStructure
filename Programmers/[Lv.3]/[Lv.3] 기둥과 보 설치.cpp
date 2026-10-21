#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a[0]==b[0] && a[1]==b[1]) return a[2] < b[2];
    if(a[0]==b[0]) return a[1] < b[1];
    return a[0]<b[0];
}
bool Check(const vector<vector<int>> &p, const vector<vector<int>> &b)
{
    for(int i=0; i<p.size(); i++)
    {
        for(int j=0; j<p.size(); j++)
        {
            if(p[i][j] == 1)
            {
                bool valid = false;

                if(i==0) valid = true; // 바닥 위
                else if(i>0 && p[i-1][j]==1) valid = true; // 다른 기둥 위
                else if(j>0 && b[i][j-1]==1) valid = true; // 보의 왼쪽 끝
                else if(b[i][j]==1) valid = true; // 보의 오른쪽 끝

                if(!valid) return false;
            }

            if(b[i][j] == 1)
            {
                bool valid = false;

                if(i>0 && p[i-1][j]==1) valid = true; // 왼쪽 끝이 기둥 위
                else if(i>0 && p[i-1][j+1]==1) valid = true; // 오른쪽 끝이 기둥 위
                else if(j>0 && b[i][j-1]==1 && b[i][j+1]==1) valid = true; // 양쪽 끝에 보

                if(!valid) return false;
            }
        }
    }

    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    // build_frame의 x,y를 배열에서의 x,y로 쓰려면 서로 스왑해야한다.
        // 즉, build_frame의 x,y는 실제로 배열에서 arr[y][x]로 쓰는게 편하다.
    vector<vector<int>> pillar(n+1, vector<int>(n+1, 0));
    vector<vector<int>> bar(n+1, vector<int>(n+1, 0));
    for(int i=0; i<build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        swap(x, y);
        
        if(b==0) //삭제
        {
            if(a==0) pillar[x][y] = 0;
            else bar[x][y] = 0;
        }
        else //설치
        {
            if(a==0) pillar[x][y] = 1; 
            else bar[x][y] = 1;
        }

        if(Check(pillar, bar))
        {
            continue;
        }
        else
        {
            if(b==0)
            {
                if(a==0) pillar[x][y] = 1;
                else bar[x][y] = 1;
            }
            else
            {
                if(a==0) pillar[x][y] = 0;
                else bar[x][y] = 0;
            }
        }
    }
    
    vector<vector<int>> answer;
    for(int i=0; i<pillar.size(); i++)
    {
        for(int j=0; j<pillar.size(); j++)
        {
            if(pillar[i][j] == 1) answer.push_back({j, i, 0});
            if(bar[i][j] == 1) answer.push_back({j, i, 1});
        }
    }
    sort(answer.begin(), answer.end(), cmp);

    return answer;
}