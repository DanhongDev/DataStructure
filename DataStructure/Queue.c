#include "Queue.h"

int Initialize(IntQueue* q, int max) 
{
    if(q->que = calloc(max, sizeof(int))) //힙 메모리에 max값만큼 저장
    {
        return -1;
    }
    q->max = max; //사이즈는 max로 저장.
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    return 0;
}

int Enque(IntQueue* q, int x) 
{
    //내 생각
    if(q->front != q->rear) //front와 rear가 같지 않을때만 인큐가능
    {
        q->que[q->rear] = x;
        q->rear++;

        return 0;
    }
    else
    {
        return -1;
    }

    //정답 예시
    if(q->num >= q->max) //num >= max라면 '이미' 큐가 가득 찬것이므로 return -1
    {
        return -1;
    }
    q->num++;
    q->que[q->rear] = x;
    q->rear++;
    if(q->rear >= q->max)
    //인큐를 계속 하다보면, 큐가 가득 찼을때는 (rear >= max인 경우)
    //이럴 경우 범위 초과가 되는 오류가 발생하므로 다시 rear를 0으로 세팅해준다.
    {
        q->rear = 0;
    }

    return 0;
}

int Deque(IntQueue* q, int* x) 
{
    if(q->num <= 0) //num이 0이하라면 큐가 비었으므로 디큐를 못함.
    {
        return -1;
    }
    q->num--; //나갔으므로 해제
    *x = q->que[q->front];
    q->front++;
    if(q->front >= q->max)
    {
        q->front = 0;
    }
    
    return 0;

    //정답 예시와 동일하다!!
}

int Peek(const IntQueue* q, int* x) 
{
    *x = q->que[q->rear - 1];

    return 0;
}

void Clear(IntQueue* q) 
{
    q->num = 0;
    q->front = 0;
    q->rear = 0;
}
