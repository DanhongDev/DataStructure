#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Member.h"

static Node* AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;
    n->next = next;
}

void Initialize(List *list) 
{
    list->head = NULL;
    list->crnt = NULL;
}

//링크드리스트가 비어있는지? list->head == NULL
//노드가 1개인지? list->head->next == NULL
//노드가 2개인지? list->head->next->next == NULL
//머리 노드인지? p == list->head (p는 Node* 자료형)
//꼬리 노드인지? p->next == NULL (p는 Node* 자료형)

Node* Search(List *list, const Member *x, int compare(const Member *x, const Member *y)) 
{
    Node *p = list->head;
    while(p != NULL)
    {
        if(compare(p->data.no, x->no)) //혹은 compare(&p->data, x->no)
        {
            list->crnt = p;
            return p;
        }
        p = p->next;
    }

    return NULL;
}

void InsertFront(List *list, const Member *x) 
{
    //1. 삽입 전의 머리노드 A에 관한 정보를 p에 대입
    Node *p = list->head;

    //2. 삽입할 노드 G를 AllocNode 함수로 만들고 만든 노드 G를 가리키도록 list->head를 업데이트
    list->head = AllocNode();
    list->crnt = AllocNode();

    //3. SetNode 함수를 호출하여 값을 설정, 머리노드의 next변수는 p로 업데이트
    SetNode(list->head, x, p);
}

void InsertRear(List *list, const Member *x) 
{
    if(list->head == NULL)
    {
        InsertFront(list, x);
    }
    else
    {
        Node *p = list->head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = AllocNode();
        list->crnt = AllocNode();

        SetNode(p->next, x, NULL);
    }
}

void RemoveFront(List *list) 
{
    if(list->head != NULL)
    {
        Node *ptr = list->head->next;
        free(list->head);
        list->head = ptr;
        list->crnt = ptr;
    }
}

void RemoveRear(List *list) 
{
    if(list->head != NULL)
    {
        if((list->head)->next == NULL)
        {
            RemoveFront(list);
        }
        else
        {
            Node *p = list->head;
            Node *pre;
            while(p->next != NULL)
            {
                pre = p;
                p = p->next;
            }
            pre->next = NULL;
            free(p);
            list->crnt = pre;
        }
    }
}

void RemoveCurrent(List *list) 
{
    if(list->head != NULL)
    {
        RemoveFront(list);
    }
    else
    {
        Node *p = list->head;
        while(p->next != list->crnt)
        {
            p = p->next;
        }
        p->next = list->crnt->next;
        free(list->crnt);
    }
}

void Clear(List *list) 
{
    while(list->head != NULL)
    {
        RemoveFront(list);
    }

    list->crnt = NULL;
}

void PrintCurrent(const List *list) 
{
    if(list->crnt != NULL)
    {
        PrintMember(&list->crnt->data);
    }
    else
    {
        printf("선택한 노드가 없습니다.");
    }
}

void PrintLnCurrent(const List *list) 
{
    PrintCurrent(list);
    printf("\n");
}

void Print(const List *list) 
{
    if(list->head != NULL)
    {
        Node *p = list->head;
        while(p != NULL)
        {
            PrintLnMember(&p->data);
            p = p->next;
        }
    }
    else
    {
        pritnf("노드가 없습니다.\n");
    }
}

void Terminate(List *list) 
{
    Clear(list);
}
