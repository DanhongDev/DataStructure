#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Union-Find의 Find함수
int findParent(vector<int> &parent, int x)
{
    //1. 만약 보스가 자기 자신이라면, 자기 자신을 return
    if(parent[x] == x) return x;
    //2. 아니라면, 보스(parent[x])를 재귀적으로 쫓아가서 최종 보스를 찾는다.
    return parent[x] = findParent(parent, parent[x]);
}

//Union-Find의 Union함수
void unionParent(vector<int> &parent, int a, int b)
{
    //1. findParent함수를 이용해 a, b 보스를 찾기
    int boss_a = findParent(parent, a);
    int boss_b = findParent(parent, b);
    //2. 두 보스를 비교하여 번호가 작은 보스 선택
    boss_a < boss_b ? parent[boss_b] = boss_a : parent[boss_a] = boss_b;
}

//Cruscal 비교 함수(건설 비용이 적은 순으로)
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    
    //1. parent배열 초기화: 자기 자신을 가리키도록
    vector<int> parent(n);
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    //2. sort하기
    sort(costs.begin(), costs.end(), cmp);

    //3. 다리 건설하기
    for(int i=0; i<costs.size(); i++)
    {
        //1. 두 노드의 번호와 코스트를 담아내는 변수 생성
        int a = costs[i][0], b = costs[i][1], cur_cost = costs[i][2];
        //2. 두 섬의 보스가 다르다면
        if(findParent(parent, a) != findParent(parent, b))
        {
            //unionParent함수를 호출하여 두 노드를 한 그룹으로 묶어줌
            unionParent(parent, a, b);
            //총 비용(answer)에 현재의 비용을 더해줌
            answer += cur_cost;
        }
    }
    return answer;
}

int main()
{
    int n=4;
    vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
    solution(n, costs);

    return 0;
}