#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int solution(vector<vector<int>> targets)
{
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp); //오름차순 정렬 (시작 s를 기준으로 했다. 그러나 키는 끝 e를 기준으로 정렬을 해야한다!)
    
    int pos = -1;

    for(int i=0; i<targets.size(); i++)
    {
        int s = targets[i][0];
        int e = targets[i][1];

        if(s >= pos)
        {
            answer++;
            pos = e;
        }
    }

    return answer;
}

int main()
{
    int answer = solution({{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}});

    return 0;
}