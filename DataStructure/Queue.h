#pragma once
#ifndef ___IntQueue
#define ___IntQueue

typedef struct
{
    int max; //큐의 최대 용량
    int num; //현재의 요소 개수
    int front;//프론ㅡ
    int rear; //리어
    int *que; //큐의 맨 앞 요소 포인터
} IntQueue;

int Initialize(IntQueue *q, int max);

int Enque(IntQueue *q, int x);

int Deque(IntQueue *q, int *x);

int Peek(const IntQueue *q, int *x);

void Clear(IntQueue *q);

int Capacity(const IntQueue *q);

int Size(const IntQueue *q);

int IsEmpty(const IntQueue *q);

int IsFull(const IntQueue *q);

#endif // ! __IntQueue
