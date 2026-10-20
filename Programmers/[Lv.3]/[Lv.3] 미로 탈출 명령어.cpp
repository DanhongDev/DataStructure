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

int main()
{
    string answer = solution(3, 4, 2, 3, 3, 1, 5);
    // string answer = solution(3, 3, 1, 2, 3, 3, 4);
    
    return 0;
}

//struct Cood
//{
//    int x;
//    int y;
//    int len;
//    string dirt; // 현재까지 온 방향 표시할 변수
//};
//void BFS(const vector<vector<char>> &board, int x, int y, int k, string &answer)
//{
//    int n = board.size(), m = board[0].size();
//    queue<Cood> q;
//    q.push({x, y, 0, ""});
//
//    vector<string> route; // 경로들을 담을 벡터
//    
//    int dx[] = {-1, 1, 0, 0};
//    int dy[] = {0, 0, -1, 1};
//
//    while(!q.empty())
//    {
//        Cood cur = q.front();
//        q.pop();
//
//        if(cur.len > k) continue;
//
//        if(cur.len == k && board[cur.x][cur.y] == 'E') 
//        {
//            //0=u, 1=d, 2=l, 3=r
//            for(int i=0; i<k; i++)
//            {
//                if(cur.dirt[i] == '0') cur.dirt[i] = 'u';
//                else if(cur.dirt[i] == '1') cur.dirt[i] = 'd';
//                else if(cur.dirt[i] == '2') cur.dirt[i] = 'l';
//                else if(cur.dirt[i] == '3') cur.dirt[i] = 'r';
//            }
//            route.push_back(cur.dirt);
//            continue;
//        }
//
//        for(int i=0; i<4; i++)
//        {
//            int nx = cur.x + dx[i];
//            int ny = cur.y + dy[i];
//            if(nx<=0 || nx>=n || ny<=0 || ny>=m) continue;
//
//            string temp = cur.dirt + to_string(i);
//            
//            q.push({nx, ny, cur.len+1, temp});
//        }
//    }
//    sort(route.begin(), route.end());
//    answer = (route.size()==0) ? "impossible" : route[0];
//    return;
//}