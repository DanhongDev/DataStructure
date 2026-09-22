#include <string>
#include <vector>
#include <queue>
using namespace std;

void toPossible(const vector<string> &storage, vector<vector<bool>> &poss) //지게차 가능 여부 갱신
{
    int n = storage.size(); int m = storage[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(storage[i][j] == ' ')
            {
                vector<pair<int,int>> coord;
                for(int k=0; k<4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                    if(storage[nx][ny] != ' ')
                    {
                        coord.push_back({nx,ny});
                    }
                }

                if(coord.size() < 4)
                {
                    for(int k=0; k<coord.size(); k++)
                    {
                        poss[coord[k].first][coord[k].second] = true;
                    }
                }
            }
        }
    }
}
int shipping(vector<string> &storage, const string &r, const vector<vector<bool>> &poss, int type)
{
    int n = storage.size(); int m = storage[0].size();

    int cnt = 0;
    char c = r[0];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(storage[i][j] == c)
            {
                if(type == 1)
                {
                    if(poss[i][j])
                    {
                        storage[i][j] = ' ';
                        cnt++;
                    }
                }
                else
                {
                    storage[i][j] = ' ';
                    cnt++;
                }
            }
        }
    }

    return cnt;
}
int solution(vector<string> storage, vector<string> requests)
{
    int n = storage.size(); int m = storage[0].size();
    int answer = n * m;

    //지게차 가능 여부 배열 생성 후 바깥 4면 true로 초기화
    vector<vector<bool>> poss(n, vector<bool>(m, false));
    for(int i=0; i<n; i++)
    {
        poss[i][0] = true;
        poss[i][m-1] = true;
    }
    for(int j=0; j<m; j++)
    {
        poss[0][j] = true;
        poss[n-1][j] = true;
    }

    // 1. 지게차 & 크레인 출고 함수 따로 만들기
    // 2. 출고 후 true로 만드는 함수 실행하기 (출고 중에 하면 안될듯?)
    for(string r : requests)
    {
        answer -= shipping(storage, r, poss, r.size());
        toPossible(storage, poss);
    }
    
    return answer;
}

int solution(vector<string> storage, vector<string> requests)
{
    int n = storage.size(), m = storage[0].size();
    int answer = n*m;

    // 1. Padding
    vector<string> grid(n+2, string(m+2, ' '));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            grid[i+1][j+1] = storage[i][j];
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(string r : requests)
    {
        char target = r[0];
        bool isCrane = (r.size() == 2);

        vector<pair<int, int>> to_remove;

        if(isCrane)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(grid[i][j] == target)
                    {
                        to_remove.push_back({i, j});
                    }
                }
            }
        }
        else
        {
            vector<vector<bool>> visited(n+2, vector<bool> (m+2, false));
            queue<pair<int,int>> q;

            q.push({0, 0});
            visited[0][0] = true;

            while(!q.empty())
            {
                int cur_x = q.front().first;
                int cur_y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++)
                {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if(nx>=0 && nx<n+2 && ny>=0 && ny<m+2)
                    {
                        if(!visited[nx][ny])
                        {
                            if(grid[nx][ny] == ' ')
                            {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                            else if(grid[nx][ny] == target)
                            {
                                visited[nx][ny] = true;
                                to_remove.push_back({nx,ny});
                            }
                        }
                    }
                }
            }
        }

        for(auto p : to_remove)
        {
            grid[p.first][p.second] = ' ';
            answer--;
        }
    }

    return answer;
}