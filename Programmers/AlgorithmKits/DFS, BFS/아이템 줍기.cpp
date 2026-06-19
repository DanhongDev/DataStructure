#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    int answer = 0;

    //i) (minX, minY) ~ (maxX, maxY)영역 범위 구하기
    //int minX=100, minY=100, maxX=0, maxY=0;
    //for(const auto& rect : rectangle)
    //{
    //    minX = minX < rect[0] ? minX : rect[0];
    //    minY = minY < rect[1] ? minY : rect[1];
    //    maxX = maxX > rect[2] ? maxX : rect[2];
    //    maxY = maxY > rect[3] ? maxY : rect[3];
    //}
    //int X = maxX - minX;
    //int Y = maxY - minY;
    ////i을 2배로 스케일 업하기. ii)0으로 초기화하여 일단 모두 외부 벽으로 만들기
    //vector<vector<int>> map(X*2, vector<int>(Y*2, 0));

    //Com: 좌표 최댓값이 50까지 이므로 애초에 100으로 고정크기 설정하기.
    vector<vector<int>> map(102, vector<int>(102, 0));

    //ii) 내부 공간 절대벽 세우기
    int n = map.size();
    for(const auto& rect : rectangle)
    {
        int x1 = rect[0]*2;
        int y1 = rect[1]*2;
        int x2 = rect[2]*2;
        int y2 = rect[3]*2;
        
        for(int i=x1; i<=x2; i++)
        {
            for(int j=y1; j<=y2; j++)
            {
                if(x1<i && i<x2 && y1<j && j<y2) map[i][j] = 2;
                else
                {
                    if(map[i][j] != 2) map[i][j] = 1;
                }
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1 ,1};
    
    vector<vector<int>> dist(102, vector<int>(102, -1));
    dist[characterX*2][characterY*2] = 0;
    queue<pair<int,int>> q;
    q.push({characterX*2, characterY*2});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == itemX*2 && y == itemY*2)
        {
            return dist[x][y] / 2;
        }

        //길찾기
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(map[nx][ny] != 1) continue;
            if(dist[nx][ny] != -1) continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }


    return 0;
}