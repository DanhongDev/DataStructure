#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int x;
    int y;
    vector<pair<int, int>> route;
};
void BFS(vector<vector<pair<int,int>>> &paths, int &idx, pair<int,int> start, pair<int, int> end)
{
    queue<Node> q;
    q.push({start.first, start.second, {{start.first, start.second}}});
    bool visited[101][101] = {false, };
    visited[start.first][start.second] = true;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if(cur.x == end.first && cur.y == end.second)
        {
            // paths[idx] = (cur.route);
            for(pair<int,int> &p : cur.route)
            {
                if(!paths[idx].empty() && paths[idx].back() == p) continue;
                paths[idx].push_back(p);
            }
            return;
        }
        for(int i=0; i<4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx<=0 || nx>100 || ny<=0 || ny>100) continue;
            
            if(!visited[nx][ny])
            {
                visited[nx][ny] = true;

                vector<pair<int, int>> temp = cur.route;
                temp.push_back({nx, ny});
                
                q.push({nx, ny, temp});
            }
        }
    }
}
void MakePath(vector<vector<pair<int,int>>> &paths, int idx, pair<int,int> start, pair<int,int> end)
{
    int r = start.first;
    int c = start.second;

    if(paths[idx].empty() || paths[idx].back() != make_pair(r, c))
    {
        paths[idx].push_back({r, c});
    }

    while(r != end.first)
    {
        if(r < end.first) r++;
        else r--;
        paths[idx].push_back({r,c});
    }
    while(c != end.second)
    {
        if(c < end.second) c++;
        else c--;
        paths[idx].push_back({r,c});
    }
}
int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;

    vector<vector<pair<int, int>>> paths(routes.size());

    //각 로봇의 진짜 경로 정리
    int idx = 0;
    for(vector<int> r : routes)
    {
        //현재 로봇이 목적지가 1개인 경우만 고려했다.
        //예제 3번처럼 routes가 [2,3,4,5]식으로 주어지면 2번이 3,4,5번을 거치는 경로를 따와야하는데
        //나는 2번에서 3번만 가는 경로만 저장해서 보고있다.
        for(int i=0; i<r.size()-1; i++)
        {
            //  BFS(paths, idx, {points[r[i]-1][0], points[r[i]-1][1]}, {points[r[i+1]-1][0], points[r[i+1]-1][1]});
             MakePath(paths, idx, {points[r[i]-1][0], points[r[i]-1][1]}, {points[r[i+1]-1][0], points[r[i+1]-1][1]});
        }
        // BFS(paths, idx, {points[r[0]-1][0] , points[r[0]-1][1]}, {points[r[1]-1][0], points[r[1]-1][1]});
        idx++;
    }

    int max_time = 0;
    for(int i=0; i<paths.size(); i++)
    {
        max_time = max(max_time, (int)paths[i].size());
    }

    for(int time=0; time<max_time; time++)
    {
        bool is_crashed[101][101] = {false, };
        for(int i=0; i<paths.size()-1; i++)
        {
            if(paths[i].size() == 0 || time >= paths[i].size()) continue;
            for(int j=i+1; j<paths.size(); j++)
            {
                if(paths[j].size() == 0 || time >= paths[j].size()) continue;

                int f_x = paths[i][time].first;
                int f_y = paths[i][time].second;
                int s_x = paths[j][time].first;
                int s_y = paths[j][time].second;

                if(!is_crashed[f_x][f_y] && (f_x == s_x && f_y == s_y))
                    {
                        is_crashed[f_x][f_y] = true;
                        answer++;
                    }
            }
        }
    }
    return answer;
}

int main()
{
    // int answer = solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {2, 4}});
    int answer = solution({{2, 2}, {2, 3}, {2, 7}, {6, 6}, {5, 2}}, {{2, 3, 4, 5}, {1, 3, 4, 5}});

    return 0;
}