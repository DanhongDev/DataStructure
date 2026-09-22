#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    priority_queue<int> pq;
    for(int i=0; i<enemy.size(); i++)
    {
        n -= enemy[i]; //일단 싸워
        pq.push(enemy[i]); //싸운 적의 수를 저장

        if(n<0) //싸우고 난 후 병사가 모자를 때
        {
            if(k>0) //무적기가 남아있을 때
            {
                n += pq.top(); //싸운 병사 롤백
                pq.pop(); //싸움을 무효화
                k--; //무적기 사용
            }
            else //무적기까지 없을땐 종료
            {
                return i;
            }
        }
    }

    return enemy.size();
}