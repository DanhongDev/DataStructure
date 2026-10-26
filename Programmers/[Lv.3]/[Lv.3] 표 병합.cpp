#include <string>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

struct Con
{
    string val; // 현재 값
    vector<pair<int,int>> m; // merge를 끊어줘야 하므로 vector.erase대신 unordered_set.erase를 사용해보자.
};

Con grid[51][51];
bool visited[51][51];

void Update(int cur_r, int cur_c, const string &value)
{
    visited[cur_r][cur_c] = true;
    grid[cur_r][cur_c].val = value;

    for(auto &l : grid[cur_r][cur_c].m)
    {
        if(!visited[l.first][l.second])
        {
            Update(l.first, l.second, value);
        }
    }

    return;
}
void Group(int cur_r, int cur_c, vector<pair<int,int>> &group)
{
    visited[cur_r][cur_c] = true;
    group.push_back({cur_r, cur_c});

    for(auto &l : grid[cur_r][cur_c].m)
    {
        if(!visited[l.first][l.second])
        {
            Group(l.first, l.second, group);
        }
    }
}
vector<string> solution(vector<string> commands)
{
    vector<string> answer;
    // vector<vector<Con>> grid(51, vector<Con>(51));
    for(int i=1; i<=50; i++)
    {
        for(int j=1; j<=50; j++)
        {
            grid[i][j].val = "EMPTY";
            grid[i][j].m.clear();
        }
    }

    for(string c : commands)
    {
        stringstream ss(c);
        vector<string> tokens;
        string token;
        while(ss >> token) tokens.push_back(token);

        if(tokens[0] == "UPDATE")
        {
            if(tokens.size() == 4) // UPDATE r1 c1 value
            {
                int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]);
                memset(visited, false, sizeof(visited));
                Update(r1, c1, tokens[3]); // DFS
            }
            else // UPDATE value1 value2
            {
                for(int i=1; i<=50; i++)
                {
                    for(int j=1; j<=50; j++)
                    {
                        if(grid[i][j].val == tokens[1]) grid[i][j].val = tokens[2];
                    }
                }
            }
        }
        else if(tokens[0] == "MERGE") // MERGE r1 c1 r2 c2
        {
            int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]), r2 = stoi(tokens[3]), c2 = stoi(tokens[4]);

            // 이미 연결된 그룹인지 확인
            memset(visited, false, sizeof(visited));
            vector<pair<int,int>> group;
            Group(r1, c1, group);

            bool already_merged = false;
            for(auto &p : group)
            {
                if(p.first == r2 && p.second == c2) already_merged = true;
            }
            if(already_merged) continue;

            // 새로운 값 결정
            string new_val = grid[r1][c1].val;
            if(new_val == "EMPTY" && grid[r2][c2].val != "EMPTY") new_val = grid[r2][c2].val;

            // 그룹 연결
            grid[r1][c1].m.push_back({r2, c2});
            grid[r2][c2].m.push_back({r1, c1});

            memset(visited, false, sizeof(visited));
            Update(r1, c1, new_val);
        }
        else if(tokens[0] == "UNMERGE") // UNMERGE r1 c1
        {
            int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]);
            string ori_val = grid[r1][c1].val;

            memset(visited, false, sizeof(visited));
            vector<pair<int,int>> group;
            Group(r1, c1, group);

            for(auto &p : group)
            {
                grid[p.first][p.second].m.clear();
                grid[p.first][p.second].val = "EMPTY";
            }

            grid[r1][c1].val = ori_val;
        }
        else if(tokens[0] == "PRINT") // PRINT r1 c1
        {
            int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]);
            answer.push_back(grid[r1][c1].val);
        }
    }
    
    return answer;
}