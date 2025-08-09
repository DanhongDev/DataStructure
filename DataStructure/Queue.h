#pragma once
#ifndef ___IntQueue
#define ___IntQueue
#include <stdio.h>

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

void Clear(IntQueue *q); //모든 데이터 삭제

int Capacity(const IntQueue *q); //최대 용량

int Size(const IntQueue *q); //현재 용량

int IsEmpty(const IntQueue *q);

int IsFull(const IntQueue *q);

int Search(const IntQueue *q, int x);

void Print(const IntQueue *q);

void Terminate(IntQueue *q);

#endif // ! __IntQueue
