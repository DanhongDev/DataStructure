#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int i;
    int j;
    int time;
};

int BFS(const vector<string> &maps, const char &start, const char &end)
{
    int n = maps.size(), m = maps[0].size();
    
    //start지역 찾기
    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for(int i=0; i<n; i++) //시작 인덱스 뽑기
    {
        for(int j=0; j<m; j++)
        {
            if(maps[i][j] == start)
            {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0}; //상하
    int dy[4] = {0, 0, -1, 1}; //좌우
    
    //end지점 까지 BFS
    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if(maps[cur.i][cur.j] == end) return cur.time;

        for(int i=0; i<4; i++)
        {
            int nx = cur.i + dx[i];
            int ny = cur.j + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

            if(!visited[nx][ny] && maps[nx][ny] != 'X')
            {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.time + 1});
            }
        }
    }

    return -1;
}

int solution(vector<string> maps)
{
    int toLever = BFS(maps, 'S', 'L'); 
    if(toLever == -1) return -1;  
    int toExit = BFS(maps, 'L', 'E');
    if(toExit == -1) return -1;

    return toLever + toExit;
}