#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//조각들의 집합에서 각각의 위치를 정규화하는 함수
void normalize(vector<pair<int,int>> &shape)
{
    int min_x = 50, min_y = 50;
    
    for(int i=0; i<shape.size(); i++)
    {
        min_x = min(min_x, shape[i].first);
        min_y = min(min_y, shape[i].second);
    }
    
    for(int i=0; i<shape.size(); i++)
    {
        shape[i].first -= min_x;
        shape[i].second -= min_y;
    }
    
    sort(shape.begin(), shape.end());
}
void rotate(vector<pair<int,int>> &shape)
{
    for(int i=0; i<shape.size(); i++)
    {
        //swap(shape[i].second, shape[i].first);
        //shape[i].second *= -1;

        int x = shape[i].first;
        int y = shape[i].second;

        shape[i] = {y, -x};
    }

    normalize(shape);
}

//각각의 모양을 탐색하여 삽입하는 함수(BFS함수)
void find_shape(vector<vector<int>> &grid, int x, int y, vector<pair<int,int>> &cur, int num)
{
    //상하좌우 탐색시 사용할 이동기
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    //퍼즐 조각은 1x1 조각이 최소 1개라도 있다고 했으므로 우선 cur에 push해도 될 것같다.
    cur.push_back({x, y});
    //해당 칸을 퍼즐조각으로 사용했으므로 반대 처리
    grid[x][y] = !num;

    //상하좌우에 조각이 또 있는지 검색
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid.size() && grid[nx][ny] == num)
        {
            find_shape(grid, nx, ny, cur, num);
        }
    }
}

//각각의 모양의 집합을 만드는 함수
vector<vector<pair<int,int>>> extract_shape(vector<vector<int>> &grid, int num)
{
    vector<vector<pair<int,int>>> shape_set;

    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid.size(); j++)
        {
            if(grid[i][j] == num)
            {
                vector<pair<int,int>> cur_shape;

                find_shape(grid, i, j, cur_shape, num);

                shape_set.push_back(cur_shape);
            }
        }
    }

    return shape_set;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    vector<vector<pair<int,int>>> board_shape_set = extract_shape(game_board, 0);
    vector<vector<pair<int,int>>> table_shape_set = extract_shape(table, 1);
    
    for(int i=0; i<board_shape_set.size(); i++)
    {
        normalize(board_shape_set[i]);
    }
    for(int i=0; i<table_shape_set.size(); i++)
    {
        normalize(table_shape_set[i]);
    }
    
    int answer = 0;
    vector<bool> visited(table_shape_set.size(), false);

    for(int i=0; i<board_shape_set.size(); i++)
    {
        bool is_match = false;

        for(int j=0; j<table_shape_set.size(); j++)
        {
            if(visited[j]) continue;

            //회전 계산
            for(int r=0; r<4; r++)
            {
                if(board_shape_set[i] == table_shape_set[j])
                {
                    is_match = true;
                    break;
                }

                rotate(table_shape_set[j]);
            }

            if(is_match)
            {
                visited[j] = true;
                answer += table_shape_set[j].size();
                break;
            }
        }
    }
    
    return answer;
}