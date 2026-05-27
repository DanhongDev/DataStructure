#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp_pq
{
    bool operator() (const vector<int>& a, const vector<int>& b)
    {
        //1순위: 소요시간
        if(a[2] != b[2])
        {
            return a[2] > b[2];
        }
        //2순위: 요청시간
        if(a[1] != b[1])
        {
            return a[1] > b[1];
        }
        //3순위: 번호
        return a[0] > b[0];
    }
};

int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    //원본 jobs 정렬 (요청시간 순으로)
    sort(jobs.begin(), jobs.end());
    //대기 큐 (구조체 cmp의 연산자 operator에 맞게 정렬)
    priority_queue<vector<int>, vector<vector<int>>, cmp_pq> pq;
    int idx=0, time=0, com_jobs=0;
    //작업 시작.
    while(com_jobs < jobs.size())
    {
        //1. 현재 시간(time)보다 작거나 같은 시점에 요청된 작업을 모두 큐에 push
        //이때, 이미 큐 선언의 cmp에 맞게 우선순위가 자동으로 정렬이 된다.
        while(idx < jobs.size() && jobs[idx][0] <= time)
        {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        //2. 큐가 비어있지 않다면?? (처리할 작업이 있음)
        if(!pq.empty())
        {
            //1. 소요 시간만큼 time을 증가 -> time은 작업 종료 시간이 된다.
            time += pq.top()[2];
            
            //2. 총 대기시간 = 종료 시간(time) - 요청 시간
            answer += time - pq.top()[1];

            //3. 완료된 작업 큐에서 제거
            pq.pop();

            //4. 완료된 작업 수 증가
            com_jobs++;
        }
        //3. 큐가 비어있다면?? (현재 시간까지 도착한 작업이 없음)
        else
        {
            //idx가 가리키는 다음 작업의 요청 시간으로 time 워프
            time = jobs[idx][0];
        }
    }

    return answer / jobs.size();
}