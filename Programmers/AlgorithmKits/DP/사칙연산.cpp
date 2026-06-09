#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
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
    for(int i=0; i<n; i++)
    {
        dp_max[i][i] = num[i];
        dp_min[i][i] = num[i];
    }

    


    return answer;
}