#ifndef ___IntStack
#define ___IntStack

typedef struct
{
	int max; //Stack Capacity
	int ptr; //Stack Pointer
	int* stk; //Stack Pointer to initial element
}IntStack;

int Initialize(IntStack* s, int max); //초기화 함수

int Push(IntStack* s, int x); //Push 함수

int Pop(IntStack* s, int* x); //Pop 함수

int Peek(const IntStack* s, int* x); //Top 요소를 값 참조

void Clear(IntStack* s); //스택 비우기

int Capacity(const IntStack* s); //스택의 최대 용량

int Size(const IntStack* s); //스택의 현재 크기

int IsEmpty(const IntStack* s); //스택이 비어있는지 확인

int IsFull(const IntStack* s); //스택이 가득찼는지 확인

int Search(const IntStack* s, int x); //스택에 x가 있는지 검색

void Print(const IntStack* s); //스택 전체 출력

void Terminate(IntStack* s); //스택 종료


#endif