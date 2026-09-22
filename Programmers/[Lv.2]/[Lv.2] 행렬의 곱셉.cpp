#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    int m = arr1.size(); //행
    int n = arr2.size(); //공통
    int r = arr2[0].size(); //열
    vector<vector<int>> answer(m, vector<int>(r, 0));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<r; j++)
        {
            for(int k=0; k<n; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}