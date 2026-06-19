#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    //현재 좌표의 dist값이 -1이라면 아직 방문하지 않은 경우이다.
    vector<vector<int>> dist(n, vector<int> (m, -1));
    //시작점은 무조건 방문하므로.
    dist[0][0] = 1;
    
    queue<pair<int,int>> q;
    q.push({0, 0});


    //반복문: 큐가 empty할때 까지??
    while(!q.empty())
    {
        //현재 좌표 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //동서남북 둘러본 후 해당 좌표가
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
            
                ////i) 맵을 벗어나지 않았을 경우
                //if(0<=nx && nx<n && 0<=ny && ny<m)
                //{
                //    //ii) 아직 방문하지 않았을 경우
                //    if(dist[nx][ny] == -1)
                //    {
                //        //iii) 벽이 아닌 경우
                //        if(maps[nx][ny] == 1)
                //        {
                //            //해당 좌표들을 큐에 push
                //            q.push({nx,ny});
                //            //dist[nx][ny]의 값을 수정해주어 방문했다고 표기
                //            dist[nx][ny] = dist[x][y] + 1;
                //        }
                //    }
                //}

                //가독성 패치: 안되는 조건을 먼저 찾아서 continue로 빠르게 내쳐버리기 (Early Return/Continue)방식
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(dist[nx][ny] != -1 || maps[nx][ny] == 0) continue;
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
                
    }
    //반복문 종료 후
        //dist[n-1][m-1]의 값이 -1이라면 도착 못했으므로 return -1 양수라면 도착했으므로 그때의 값을 return
        //dist를 전부 -1로 초기화를 했으므로 도착하지 못했을 경우 -1이 자동으로 return이 됨
    return dist[n-1][m-1];
}