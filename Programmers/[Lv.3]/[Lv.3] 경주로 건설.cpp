#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Coord
{
    int x;
    int y;
    int dir;
    int cost;
};
void BFS(const vector<vector<int>> &board, int start_dir, int &answer)
{
    int n = board.size();
    queue<Coord> q;

    vector<vector<vector<int>>> cost_map(n, vector<vector<int>>(n, vector<int> (4, 1e9)));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int nx = 0 + dx[start_dir];
    int ny = 0 + dy[start_dir];

    if(nx>=0 && nx<n && ny>=0 && ny<n && board[nx][ny] == 0)
    {
        q.push({nx, ny, start_dir, 100});
        cost_map[nx][ny][start_dir] = 100;
    }

    while(!q.empty())
    {
        Coord cur = q.front();
        q.pop();

        //도착
        if(cur.x == n-1 && cur.y == n-1)
        {
            answer = min(answer, cur.cost);
            continue;
        }

        for(int i=0; i<4; i++)
        {
            int nnx = cur.x + dx[i];
            int nny = cur.y + dy[i];

            if(nnx<0 || nnx>=n || nny<0 || nny>=n || board[nnx][nny] == 1) continue; //범위 초과 예외 처리

            int n_cost = cur.cost + (i == cur.dir ? 100 : 600);

            if(n_cost <= cost_map[nnx][nny][i])
            {
                cost_map[nnx][nny][i] = n_cost;
                q.push({nnx, nny, i, n_cost});
            }
        }
    }
}
int solution(vector<vector<int>> board)
{
    int answer = 1e9;

    BFS(board, 1, answer); //오른쪽 출발
    BFS(board, 3, answer); //아래쪽 출발
    
    return answer;
}