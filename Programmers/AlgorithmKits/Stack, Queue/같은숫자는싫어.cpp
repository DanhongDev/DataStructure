#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    q.push(arr[0]);
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i-1] != arr[i])
        {
            q.push(arr[i]);
        }
    }
    while(!q.empty())
    {
        int temp = q.front();
        answer.push_back(temp);
        q.pop();
    }
    return answer;

    //unique 이용
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}