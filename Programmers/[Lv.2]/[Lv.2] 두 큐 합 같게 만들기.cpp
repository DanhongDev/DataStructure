#include <string>
#include <vector>
#include <queue>
using namespace std;

long long Sum(const vector<int> &queue)
{
    long long sum = 0;
    for(int i=0; i<queue.size(); i++)
    {
        sum += queue[i];
    }
    return sum;
}
bool is_Same(const vector<int> &ori1, const vector<int> &ori2, const vector<int> &queue1, const vector<int> &queue2)
{
    if(ori1.size() != queue2.size() || ori2.size() != queue1.size()) return false;

    for(int i=0; i<ori1.size(); i++)
    {
        if(ori1[i] != queue2[i] || ori2[i] != queue1[i]) return false;
    }
    return true;
}
int solution(vector<int> queue1, vector<int> queue2)
{
    vector<int> ori1(queue1.begin(), queue1.end());
    vector<int> ori2(queue2.begin(), queue2.end());

    long long sum1=0, sum2=0, sum=0;
    for(int i=0; i<queue1.size(); i++)
    {
        sum += queue1[i];
        sum += queue2[i];

        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    int answer = 0;
    while(sum1 != sum2)
    {
        if(sum1 > sum2)
        {
            int num = queue1[0];
            queue1.erase(queue1.begin());
            queue2.push_back(num);
        }
        else
        {
            int num = queue2[0];
            queue2.erase(queue2.begin());
            queue1.push_back(num);
        }
        if(is_Same(ori1, ori2, queue1, queue2))
        {
            return -1;
        }
        answer++;
        sum1 = Sum(queue1);
        sum2 = Sum(queue2);
    }
    return answer;
}

int Gesolution(vector<int> queue1, vector<int> queue2)
{
    queue<int> q1, q2;
    long long sum1=0, sum2=0;

    for(int i=0; i<queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }

    int answer = 0;
    //* 두 큐가 완전히 뒤바뀌고 제자리로 돌아오는 최대 횟수
    int limit = queue1.size() * 4;

    while(sum1 != sum2)
    {
        if(answer > limit) return -1;

        if(sum1 > sum2)
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);

            //**전체 합을 다시 구하지 않고 val값만 빼주고 더해주며 업데이트
            sum1 -= val;
            sum2 += val;
        }
        else
        {
            int val = q2.front();
            q2.pop();
            q1.push(val);

            sum2 -= val;
            sum1 += val;
        }
        answer++;
    }

    return answer;
}