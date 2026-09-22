#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    for(vector<int> &b : balls)
    {
        int endX = b[0];
        int endY = b[1];
        int min_dist = 1e9;

        // x=0 대칭
        if(!(startY == endY && startX > endX))
        {
            int dist = pow(startX - (-endX), 2) + pow(startY - endY, 2);
            min_dist = min(min_dist, dist);
        }
        // x=m 대칭
        if(!(startY == endY && startX < endX))
        {
            int dist = pow(startX - (m + (m - endX)), 2) + pow(startY - endY, 2);
            min_dist = min(min_dist, dist);
        }
        // y=0 대칭
        if(!(startX == endX && startY > endY))
        {
            int dist = pow(startX - endX, 2) + pow(startY - (-endY), 2);
            min_dist = min(min_dist, dist);
        }
        // y=n 대칭
        if(!(startX == endX && startY < endY))
        {
            int dist = pow(startX - endX, 2) + pow(startY - (n + (n - endY)), 2);
            min_dist = min(min_dist, dist);
        }

        answer.push_back(min_dist);
    }
    
    return answer;
}