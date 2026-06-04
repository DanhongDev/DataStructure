#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) 
{
    int answer = 0;

    //sudo-code
        //1. 진입 시점 기준으로 오름차순으로 정렬 --> 진출 시점을 기준으로 오름차순 해야함!!
            //sort(routes.begin(), routes.end(), cmp);
        //2. sort한 배열을 큐에 저장
            //for(i 0 to routes.size()) {
                //q.push(routes[i]); }
        //2-1. 혹은 배열 그대로 사용
        //3. 현재 i번째 차량의 진입, 진출 시점을 변수로 저장
            //while(!q.empty()) {
                //int start = q.top()[0], end = q.top()[1];
                //4. 순회하면서 변수와 교차하는 차량은 싹다 배열에서 빼면서 카운트
                //while(end < q.top()[0]) {
                    //q.pop();
                    //answer++; }
                //}

    //1. 진출 시점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);

    //2. 카메라의 현재 위치를 제일 작은 초기값으로 설정
    int cam = -30001;

    //3. 큐를 사용하지 말고 배열을 순회한다.
    for(int i=0; i<routes.size(); i++)
    {
        if(routes[i][0] > cam)
        {
            cam = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}