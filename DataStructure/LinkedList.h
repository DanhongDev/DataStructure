#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node
{
    Member data;
    struct __node *next;
} Node;

typedef struct
{
    Node *head;
    Node *crnt;
} List;

//링크드리스트 초기화
void Initialize(List *list);

//compare함수로 x와 같은 노드를 검색
Node* Search(List *list, const Member *x, int compare(const Member *x, const Member *y));

//머리에 노드를 삽입
void InsertFront(List *list, const Member *x);
//이중 포인터 방식
void InsertNodeFront(Node **head, Node **crnt, const Member *x);

//꼬리에 노드를 삽입
void InsertRear(List *list, const Member *x);
//이중 포인터 방식
void InsertNodeRear(Node **head, Node **crnt, const Member *x);

//머리 노드를 삭제
void RemoveFront(List *list);
//이중 포인터 방식
void RemoveNodeFront(Node **head, Node **crnt);

//꼬리 노드를 삭제
void RemoveRear(List *list);
//이중 포인터 방식
void RemoveNodeRear(Node **head, Node **crnt);

//선택한 노드를 삭제
void RemoveCurrent(List *list);

//모든 노드를 삭제
void Clear(List* list);

//선택한 노드의 데이터를 출력
void PrintCurrent(const List *list);

//선택한 노드의 데이터를 출력 (줄바꿈)
void PrintLnCurrent(const List *list);

//모든 노드의 데이터를 리스트 순서대로 출력
void Print(const List *list);

//링크드리스트 종료
void Terminate(List *list);

#endif