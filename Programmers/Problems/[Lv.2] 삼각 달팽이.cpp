#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;

    vector<vector<int>> snail(n, vector<int> (n, 0));

    int x = -1;
    int y = 0;
    int num = 1;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(i%3==0) //하향
            {
                x++;
            }
            else if(i%3==1) //우향
            {
                y++;
            }
            else if(i%3==2) //좌상향
            {
                x--;
                y--;
            }

            snail[x][y] = num++;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            answer.push_back(snail[i][j]);
        }
    }
    return answer;
}