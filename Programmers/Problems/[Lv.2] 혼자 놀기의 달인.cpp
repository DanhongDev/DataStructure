#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int &a, const int &b)
{
    return a > b;
}
int solution(vector<int> cards)
{
    vector<bool> visited(cards.size(), false);
    vector<int> arr;
    for(int i=0; i<cards.size(); i++)
    {
        if(!visited[i])
        {
            int idx = i;
            int cnt = 0;
            while(!visited[idx])
            {
                visited[idx] = true;
                cnt++;
                
                idx = cards[idx]-1;
            }
            arr.push_back(cnt);
        }
    }
    
    if(arr.size() == 1) return 0;
    
    sort(arr.begin(), arr.end(), cmp);
    return arr[0] * arr[1];
}