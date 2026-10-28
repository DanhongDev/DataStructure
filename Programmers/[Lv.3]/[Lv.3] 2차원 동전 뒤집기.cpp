#include <string>
#include <vector>

using namespace std;
bool Check(const vector<vector<int>> &b, const vector<vector<int>> &t)
{
    for(int i=0; i<b.size(); i++)
    {
        for(int j=0; j<b[0].size(); j++)
        {
            if(b[i][j] != t[i][j]) return false;
        }
    }

    return true;
}
void Reverse(vector<vector<int>> &b, const int row,const int col, int type)
{
    if(type==0) //행 뒤집기
    {
        for(int j=0; j<b[row].size(); j++) b[row][j] = (b[row][j]==0) ? 1 : 0;
    }
    else if(type==1)//열 뒤집기
    {
        for(int i=0; i<b.size(); i++) b[i][col] = (b[i][col]==0) ? 1 : 0;
    }

    return;
}
void colDFS(int depth, vector<vector<int>> &b, const vector<vector<int>> &t, int cnt, int &answer)
{
    int m = b[0].size();

    if(depth == m)
    {
        if(Check(b, t)) answer = min(answer, cnt);
        return;
    }

    colDFS(depth+1, b, t, cnt, answer);

    Reverse(b, 0, depth, 1);
    colDFS(depth+1, b, t, cnt+1, answer);
    Reverse(b, 0, depth, 1);
}
void rowDFS(int depth, vector<vector<int>> &b, const vector<vector<int>> &t, int cnt, int &answer)
{
    int n = b.size();
    
    if(depth == n)
    {
        colDFS(0, b, t, cnt, answer);
        return;
    }

    rowDFS(depth+1, b, t, cnt, answer);

    Reverse(b, depth, 0 ,0);
    rowDFS(depth+1, b, t, cnt+1, answer);
    Reverse(b, depth, 0, 0);
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    int answer = 1e9;
    rowDFS(0, beginning, target, 0, answer);
    return (answer == 1e9) ? -1 : answer;
}

int main()
{
    // int answer = solution({{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}}, {{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}});
    // int answer = solution({{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}}, {{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}});
    int answer = solution({{0, 1}, {1, 0}, {0, 1}, {1, 0}, {0, 1}}, {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0,0}});

    return 0;
}