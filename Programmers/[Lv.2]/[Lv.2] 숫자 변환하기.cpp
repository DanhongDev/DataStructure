#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n)
{
    if(x==y) return 0;

    queue<pair<int,int>> q;
    vector<bool> visited(1000001, false);
    
    q.push({x,0});
    visited[x] = true;

    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        int next[3] = {cur+n, cur*2, cur*3};
        
        for(int nx : next)
        {
            if(nx == y) return cnt + 1;

            if(nx < y && !visited[nx])
            {
                visited[nx] = true;
                q.push({nx, cnt+1});
            }
        }
    }

    return -1;
}