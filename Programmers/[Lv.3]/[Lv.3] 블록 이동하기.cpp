#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

pair<pair<int,int>, pair<int,int>> MakeState(pair<int,int> p1, pair<int,int> p2)
{
    if(p1 > p2) swap(p1, p2);
    return {p1, p2};
}

// 현재 좌표에서 이동or회전 가능한 모든 경우의 수를 반환하는 함수
vector<pair<pair<int,int>, pair<int,int>>> GetAllCoord(const vector<vector<int>> &board, pair<int,int> p1, pair<int,int> p2)
{
    vector<pair<pair<int,int>, pair<int,int>>> next_states;

    int n = board.size();
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i=0; i<4; i++)
    {
        int nx1 = p1.first + dx[i] , ny1 = p1.second + dy[i];
        int nx2 = p2.first + dx[i] , ny2 = p2.second + dy[i];

        if(nx1>=0 && nx1<n && ny1>=0 && ny1<n && nx2>=0 && nx2<n && ny2>=0 && ny2<n) // board 범위 초과 체크
        {
            if(board[nx1][ny1] == 0 && board[nx2][ny2] == 0)
            {
                next_states.push_back(MakeState({nx1, ny1}, {nx2, ny2}));
            }
        }
    }

    if(p1.first == p2.first) // 가로
    {
        for(int i=-1; i<2; i+=2) // for(int i : {-1, 1})로 대체 가능
        {
            if(p1.first + i >= 0 && p1.first + i < n) // board 범위 초과 체크
            {
                if(board[p1.first + i][p1.second] == 0 && board[p2.first + i][p2.second] == 0)
                {
                    next_states.push_back(MakeState(p1, {p1.first + i, p1.second})); // p1 축
                    next_states.push_back(MakeState(p2, {p2.first + i, p2.second})); // p2 축
                }
            }
        }
    }
    else if(p1.second == p2.second) // 세로
    {
        for(int i=-1; i<2; i+=2)
        { // -1은 왼쪽, 1은 오른쪽
            if (p1.second + i >= 0 && p1.second + i < n)
            {
                if (board[p1.first][p1.second + i] == 0 && board[p2.first][p2.second + i] == 0)
                {
                    next_states.push_back(MakeState(p1, {p1.first, p1.second + i})); // p1 축
                    next_states.push_back(MakeState(p2, {p2.first, p2.second + i})); // p2 축
                }
            }
        }
    }

    return next_states;
}

int solution(vector<vector<int>> board)
{
    int n = board.size();

    queue<pair<pair<pair<int,int>, pair<int,int>>, int>> q; // {(p1, p2), cnt}
    set<pair<pair<int,int>, pair<int,int>>> visited;

    auto start_state = MakeState({0,0}, {0,1});
    q.push({start_state, 0});
    visited.insert(start_state);

    while (!q.empty()) 
    {
        auto cur_state = q.front().first;
        int cost = q.front().second;
        q.pop();

        pair<int,int> p1 = cur_state.first;
        pair<int,int> p2 = cur_state.second;

        if ((p1.first == n-1 && p1.second == n-1) || (p2.first == n-1 && p2.second == n-1))
        {
            return cost; // BFS 특성상 가장 먼저 도달한 cost가 무조건 최솟값
        }

        for (auto next_state : GetAllCoord(board, p1, p2))
        {
            if (visited.find(next_state) == visited.end())
            {
                visited.insert(next_state);
                q.push({next_state, cost + 1});
            }
        }
    }

    return 0;
}