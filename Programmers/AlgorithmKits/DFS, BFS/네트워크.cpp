#include <string>
#include <vector>

using namespace std;

//각각의 컴퓨터 방문하는 목적
void dfs(const vector<vector<int>>& computers, vector<bool> &checked, int idx)
{
    int n = computers.size();
    //i) 일일히 이중 for문 돌리면서 탐색할 필요가 있을까?? --> (O)
    //Why? solution함수에서 이미 각 행을 탐색하는 for문이 있으므로 dfs함수 에서는 열만 탐색하면 되어서 단일 for문을 쓰는것이 정석
    for(int j=0; j<n; j++)
    {
        //자기 자신은 패스
        if(idx == j) continue;

        if(computers[idx][j] == 1 && !checked[j])
        {
            checked[j] = true;
            dfs(computers, checked, j);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

    vector<bool> checked(n, false);
    for(int i=0; i<n; i++)
    {
        if(!checked[i])
        {
            checked[i] = true;
            answer++;
            //이미 위에서 처리를 했기 때문에 dfs를 돌려봐야 바로 빠져나올테니
            //i == n-1이라면 바로 종료하는 예외처리를 추가하면 어떨까?? --> (X)
            //Why? 바로 빠져나온다해도 dfs함수가 알아서 걸러주니. 오히려 if문 붙이는게 깔끔해 보이지 않음.
            dfs(computers, checked, i);
        }
    }

    return answer;
}