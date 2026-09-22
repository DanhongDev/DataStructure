#include <string>
#include <vector>

using namespace std;

void DFS(int idx, int n, const vector<int> &info, vector<int> &temp, int &max_diff, vector<int> &answer)
{
    if(idx == 11 || n == 0)
    {
        temp[10] += n;

        int ryan=0, apeach=0;
        for(int i=0; i<11; i++)
        {
            if(info[i]<temp[i]) ryan += (10-i);
            else if(info[i]>0) apeach += (10-i);
        }

        int diff = ryan - apeach;

        if(diff>0 && diff>=max_diff)
        {
            if(diff > max_diff)
            {
                max_diff = diff;
                answer = temp;
            }
            else if(diff == max_diff)
            {
                for(int i=10; i>=0; i--)
                {
                    if(temp[i] > answer[i])
                    {
                        max_diff = diff;
                        answer = temp;
                        break;
                    }
                    else if(temp[i] < answer[i])
                    {
                        break;
                    }
                }
            }
        }

        temp[10] -= n;
        return; 
    }

        if(n > info[idx])
        {
            temp[idx] = info[idx] + 1;
            DFS(idx+1, n-temp[idx], info, temp, max_diff, answer);
            temp[idx] = 0;
        }

        DFS(idx+1, n, info, temp, max_diff, answer);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> temp(11, 0);
    vector<int> answer(11, -1);
    int max_diff = 0;

    DFS(0, n, info, temp, max_diff, answer);

    if(max_diff == 0) return {-1};

    return answer;
}