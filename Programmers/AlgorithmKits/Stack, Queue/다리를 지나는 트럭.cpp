#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    ////다리를 건넌 트럭들의 집합
    //queue<int> finished;
    ////현재 다리를 건너고있는 트럭들의 집합
    //queue<int> bridge;
    ////bridge_length 만큼의 0을 push --> 초기값 설정 (bridge_length만큼의 queue의 size가 유지될 예정)
    //for(int i=0; i<bridge_length; i++)
    //{
    //    bridge.push(0);
    //}
    ////다리를 건너길 기다리고 있는 트럭들의 집합
    //queue<int> waiting;
    //for(int i=0; i<truck_weights.size(); i++)
    //{
    //    waiting.push(truck_weights[i]);
    //}
//
    ////시간과 현재 다리 무게 변수
    //int time = 0, present_weight = 0;
//
    //while(finished.size() != truck_weights.size())
    //{
    //    //시간 흐름
    //    time++;
//
    //    //먼저 현재 시간에 다리를 빠져나오는 트럭이 있는지 검사
    //    //0이상이면 트럭이니까 완료 목록에 push
    //    if(bridge.front() > 0)
    //    {
    //        finished.push(bridge.front());
    //    }
    //    //트럭이라면 트럭 무게만큼 빠지는거고 0라면 그대로일테니 굳이 if문안에 안넣어도 된다. 
    //    present_weight -= bridge.front();
    //    //맨 앞 트럭 빼기
    //    bridge.pop();
    //        
    //    //트럭이 다리에 올라오기 전 무게 초과 검사
    //    if(!waiting.empty() && present_weight + waiting.front() <= weight)
    //    {
    //        //다리에 올리고
    //        bridge.push(waiting.front());
    //        //다리 무게에 현재 트럭의 무게를 합산
    //        present_weight += waiting.front();
    //        //트럭 웨이팅 목록에서 제외
    //        waiting.pop();
    //    }
    //    //무게가 초과했다면 0을 push하여 bridge_length만큼 size를 유지
    //    else
    //    {
    //        bridge.push(0);
    //    }
    //}
    //return time;

    //최적화 (finished큐와 waiting큐 제거 && "마지막 트럭이 올라간 시간 + 다리 길이 == 최종 시간" 이라는 수학적 사실)
    int time = 0, cur_weight = 0, cur_idx;
    queue<int> bridge;

    //1. 다리 길이만큼 0으로 세팅
    for(int i=0; i<bridge_length; i++)
    {
        bridge.push(0);
    }

    //2. 대기열의 마지막 트럭이 올라갈 때까지만 반복
    while(cur_idx < truck_weights.size())
    {
        //시간 흐름
        time++;

        //맨 앞칸 비우기
        cur_weight -= bridge.front();
        bridge.pop();

        //다음 트럭이 올라올 수 있는지 판별
        if(cur_weight + truck_weights[cur_idx] <= weight)
        {
            bridge.push(truck_weights[cur_idx]);
            cur_weight += truck_weights[cur_idx];
            cur_idx++;
        }
        //못 올라오면 0을 push
        else
        {
            bridge.push(0);
        }
    }

    return time + bridge_length;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    cout << solution(bridge_length, weight, truck_weights) << '\n';

    return 0;
}