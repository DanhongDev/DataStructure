#include <string>
#include <vector>

using namespace std;

void DFS(int depth, const vector<vector<int>> &cost, const vector<vector<int>> &hint, vector<int> h, int price, int &answer)
{
    if(depth == cost.size())
    {
        //최솟값 갱신
        answer = min(answer, price);
        return;
    }

    //힌트권 미구매 경우
    DFS(depth+1, cost, hint, h, price+cost[depth][h[depth]], answer);

    //힌트권 구매 경우
    vector<int> cur_h(h.begin(), h.end());
    for(int i=1; i<hint[depth-1].size(); i++)
    {
        cur_h[hint[depth-1][i]-1]++;
        //힌트권이 최대 개수를 초과하면 보정해줘야 함.
        if(cur_h[hint[depth-1][i]-1] >= cost[depth].size())
        {
            cur_h[hint[depth-1][i]-1] = cost[depth].size()-1;
        }
    }
    int pur_h = hint[depth-1][0]; //힌트 요금
    int cost_h = cost[depth][cur_h[depth]]; //힌트 구매에 의해 할인된 비용
    DFS(depth+1, cost, hint, cur_h, price+pur_h+cost_h, answer);
}
int solution(vector<vector<int>> cost, vector<vector<int>> hint)
{
    int answer = 1e9;

    //각 스테이지별 힌트권 개수 저장할 벡터 -> h[i]: i+1번 스테이지의 힌트권 개수
    vector<int> h(cost.size(), 0); 
    DFS(1, cost, hint, h, cost[0][0], answer);

    return answer;
}