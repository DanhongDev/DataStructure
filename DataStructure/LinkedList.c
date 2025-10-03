#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Member.h"

static Node* AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

static void SetNode(Node *n, const Member *x, Node *next)
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
        if(compare(&p->data, x) == 0) //혹은 compare(&p->data, x->no)
        {
            list->crnt = p;
            return p;
        }
        p = p->next;
    }

    return NULL;
}
//LinkedList에서는 이전 노드 포인터 방식. 즉 p와 pre 포인터 변수를 생성해서 조정
//ChainHash에서는 이전 노드 포인터 방식을 이중포인터 방식으로 발전시켰음

//즉, 이전 노드 포인터 방식 == 이중 포인터 방식
//나에겐 이전 노드 포인터 방식이 익숙하고 이해하고 쉬웠겠지만, 이중포인터를 잘쓰기만 하면
//사기적인 기술이 되므로 이중 포인터 방식을 계속해서 연습해보자.

//함수를 호출하여 head 포인터 자체를 바꾸면서 Insert나 Remove를 진행해야 하는데,
//일반적으로 InsertFront(List *list, ...) 형식으로 보내면 결국 list의 복사본만 넘겨줄뿐 헤드 포인터 자체를 수정못한다.
//그래서 head 포인터 자체를 수정할 수 있게 이중 포인터 방식으로 쓰면 된다.
void InsertFront(List *list, const Member *x) 
{
    //1. 삽입 전의 머리노드 A에 관한 정보를 p에 대입
    Node *p = list->head;

    //2. 삽입할 노드 G를 AllocNode 함수로 만들고 만든 노드 G를 가리키도록 list->head를 업데이트
    list->head = AllocNode();
    list->crnt = list->head;

    //3. SetNode 함수를 호출하여 값을 설정, 머리노드의 next변수는 p로 업데이트
    SetNode(list->head, x, p);
}

//그럼 당장 여기(LinkedList)에서 쓰인 이전 노드 포인터 방식을 이중 포인터로 바꿔보는 연습을 해보자!!
//이중 포인터 방식
void InsertNodeFront(Node **head, Node **crnt, const Member *x) 
{
    //매개변수 Node **head로 받는것이 Node *p = list->head; 와 동일하다.

    //새 노드 생성: list->head = AllocNode()와 동일.
    Node *p = AllocNode();
    //새 노드의 next변수가 원래의 헤드를 가리키도록 설정
    SetNode(p, x, *head);
    //해드의 주소를 새 노드로 재 설정
    *head = p;
    *crnt = p;
}

void InsertRear(List *list, const Member *x) 
{
    if(list->head == NULL) //헤드가 비어있다면
    {
        InsertFront(list, x); //아무것도 없으므로 InsertFront함수 호출
    }
    else
    {
        Node *p = list->head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = list->crnt = AllocNode();

        SetNode(p->next, x, NULL);
    }
}
//이중 포인터 방식
void InsertNodeRear(Node **head, Node **crnt, const Member *x) 
{
    Node **pp = head;
    while(*pp != NULL)
    {
        //p = p->next;
        //pp = &p->next;

        //한줄로 변경
        pp = &((*pp)->next);
        //*pp == pp가 가리키는 곳의 값, 즉 노드의 next필드 자체
        //(*pp)->next == pp가 가리키는 노드의 주소로 가서(*연산자) 그 노드의 next필드(->next)
    }

    Node *G = AllocNode();
    SetNode(G, x, NULL);

    *pp = G;
    *crnt = G;
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
//이중 포인터 방식
void RemoveNodeFront(Node **head, Node **crnt) 
{
    if(*head != NULL)
    {
        /* == My Code ==
        Node **pp = head;
        *head = &((*pp)->next);
        free(*pp);*/
        
        //Ex.
        Node *p = *head;
        *head = (*head)->next;
        *crnt = *head;
        free(p);
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
//이중 포인터 방식
void RemoveNodeRear(Node **head, Node **crnt) 
{
    //Node **pp = head;
    //while((*pp)->next != NULL)
    //{
    //    pp = &((*pp)->next);
    //}
    //Node *p = *pp;
    //*pp = NULL;
    //free(p);

    //Ex.
    if(*head != NULL)
    {
        Node **pp = head;
        Node *pre = NULL; //마지막에서 두 번째 노드를 저장할 포인터
        while((*pp)->next != NULL)
        {
            pre = *pp; //지금의 노드를 pre에 저장해두고
            pp = &((*pp)->next); //다음 노드로 이동
        }

        Node *p = *pp;
        *pp = NULL;
        free(p);

        *crnt = pre;
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
        printf("노드가 없습니다.\n");
    }
}

void Terminate(List *list) 
{
    Clear(list);
}