#include <string>
using namespace std;

int solution(string dirs)
{
    int answer = 0;

    bool visited[11][11][11][11] = {false, };
    int x = 5, y = 5;

    for(int i=0; i<dirs.size(); i++)
    {
        int nx = x;
        int ny = y;

        if(dirs[i] == 'U') nx--;
        else if(dirs[i] == 'D') nx++;
        else if(dirs[i] == 'R') ny++;
        else if(dirs[i] == 'L') ny--;

        if(nx<0 || nx>10 || ny<0 || ny>10) continue;

        if(!visited[x][y][nx][ny])
        {
            visited[x][y][nx][ny] = true;
            visited[nx][ny][x][y] = true;
            answer++;
        }

        //이동
        x = nx;
        y = ny;
    }

    return answer;
}