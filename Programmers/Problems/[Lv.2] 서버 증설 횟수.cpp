#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k)
{
    int answer = 0;

    //우선순위 큐를 이용해보는건 어떨까??
        //앞쪽은 무조건 서버 시간이 짧은애가 나올거야.
        //증설되었을때의 시각을 저장해두면 나중에 현재시각-증설된시각 == k 라면 pop하는 형식은 어떨까??
    //아니다 어차피 시각이 흘러가면서 차례대로 들어갈테니 그냥 큐 써도 상관없을듯??
    
    int cur = 0; //현재 서버 수
    queue<pair<int,int>> expanded;

    for(int i=0; i<24; i++)
    {
        if(!expanded.empty() && expanded.front().first == i)
        {
            cur -= expanded.front().second;
            expanded.pop();
        }
        
        int required_exp = players[i] / m;
        
        if(required_exp > cur)
        {
            int exp = required_exp = - cur;
            expanded.push({i+k, exp});
            cur += exp;
            answer += exp;
        }
    
    }

    return answer;
}