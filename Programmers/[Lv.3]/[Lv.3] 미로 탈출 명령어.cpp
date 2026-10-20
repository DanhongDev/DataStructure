#include <string>
#include <vector>
#include <cmath>
using namespace std;

void DFS(const int &n, const int &m, const int &r, const int &c, const int &k, int cx, int cy, int cnt, string path, string &answer)
{
    if(answer != "") return;

    int dist = abs(r - cx) + abs(c - cy);
    if(k - cnt < dist) return;
    if((k - cnt - dist) % 2 != 0) return;

    if(cnt == k && cx == r && cy == c)
    {
        answer = path;
        return;
    }

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'d', 'l', 'r', 'u'};

    for(int i=0; i<4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if(nx<=0 || nx>n || ny<=0 || ny>m) continue;

        path.push_back(dir[i]);
        DFS(n, m, r, c, k, nx, ny, cnt+1, path, answer);
        path.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";
    DFS(n, m, r, c, k, x, y, 0, "", answer);
    
    return (answer.size()==0) ? "impossible" : answer;
}