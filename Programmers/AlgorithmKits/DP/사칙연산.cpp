#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<string> arr)
{
    vector<int> num;
    vector<string> sym;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == "+" || arr[i] == "-")
        {
            sym.push_back(arr[i]);
        }
        else
        {
            num.push_back(stoi(arr[i]));
        }
    }
    int n = num.size();
    vector<vector<int>> dp_max(n, vector<int> (n,-1000000)), dp_min(n, vector<int> (n,10000000));
    //DP 초기값 설정
    for(int i=0; i<n; i++)
    {
        dp_max[i][i] = num[i];
        dp_min[i][i] = num[i];
    }

    //DP 채우기
    for(int step = 1; step<n; step++)
    {
        for(int i=0; i<n-step; i++)
        {
            int j = i+step;

            for(int k=i; k<j; k++)
            {
                if(sym[k] == "+")
                {
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
                }
                else if(sym[k] == "-")
                {
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] - dp_min[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] - dp_max[k+1][j]);
                }
            }
        }
    }

    return dp_max[0][n-1];
}