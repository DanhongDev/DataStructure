#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

template <typename T>
void clean(T& pq, unordered_map<int, int>& sync_map)
{
    while(!pq.empty() && sync_map[pq.top()] == 0)
    {
        pq.pop();
    }
}
vector<int> solution(vector<string> operations) 
{
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    unordered_map<int, int> sync_map;

    for(string op : operations)
    {
        stringstream ss(op);
        string com;
        int num;
        ss >> com >> num;

        //데이터  삽입
        if(com == "I")
        {
            max_pq.push(num);
            min_pq.push(num);
            sync_map[num]++;
        }
        //데이터 삭제
        else if(com == "D")
        {
            if(num == 1)
            {
                clean(max_pq, sync_map);

                if(!max_pq.empty())
                {
                    sync_map[max_pq.top()]--;
                    max_pq.pop();
                }
            }
            else if(num == -1)
            {
                clean(min_pq, sync_map);

                if(!min_pq.empty())
                {
                    sync_map[min_pq.top()]--;
                    min_pq.pop();
                }
            }
        }
    }

    clean(max_pq, sync_map);
    clean(min_pq, sync_map);

    if(max_pq.empty() || min_pq.empty())
    {
        return {0, 0};
    }
    else
    {
        return {max_pq.top(), min_pq.top()};
    }
}