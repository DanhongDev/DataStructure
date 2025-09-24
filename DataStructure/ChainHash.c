#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"
//해시테이블의 크기는 소수가 좋다고 알려져 있다.
//키 값이 정수가 아닌 경우 다른 방법(실수 키 값에 대한 비트연산, 문자열 키 값에 대한 각 문자 코드에 곱셈과 덧셈 등등)을 이용

//hash값을 구하고 리턴
static int hash(int key, int size)
{
    return key % size;
}

//노드의 값을 Member값으로 설정해주는 세팅함수
static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;
    n->next = next;
}

int Initialize(ChainHash* h, int size) 
{
    //h->table을 Node*사이즈로 calloc해주고 반환값이 NULL이라면 0으로 설정후 리턴
    if((h->table = calloc(size, sizeof(Node*))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    
    //size만큼 해쉬 테이블의 버킷들을 NULL로 초기화 하여 Initialize진행
    int i;
    h->size = size;
    for(i=0; i<size; i++)
    {
        h->table[i] = NULL;
    }
    
    return 1;
}

Node *Search(const ChainHash *h, const Member *x) 
{
    //1. hash함수가 키 값을 해시 값으로 변환
    int key = hash(x->no, h->size);
    //2. 해시 값을 인덱스로 하는 버킷을 선택
    Node *p = h->table[key];
    //3. 선택한 버킷의 연결 리스트를 처음부터 순서대로 검색. 키 값과 같은 값을 찾으면 검색 성공. 아니면 실패.
    while(p != NULL)
    {
        if(p->data.no == x->no)
        {
            return p; //검색 성공
        }

        //next로 이동
        p = p->next;
    }
    return NULL;
}

int Add(ChainHash *h, const Member *x) 
{
    //1. hash함수가 키 값을 해시 값으로 변경
    int key = hash(x->no, h->size);

    //2. 해시 값을 인덱스로 하는 버킷을 선택
    Node *p = h->table[key];

    //3. NULL이 나올때까지 탐색
    while(p != NULL)
    {
        if(p->data.no == x->no) //이미 같은 값이 있는지에 대한 유무를 판별안함.
        {
            return 1;
        }
        p = p->next;
    }

    //4. NULL이 나왔다는 것은 해당 버킷의 끝 주소이므로 노드를 생성후 삽입
    //SetNode(p, x, p->next);
    //Ex4
    Node *temp;
    if((temp = calloc(1, sizeof(Node))) == NULL)
    {
        return 2;
    }
    SetNode(temp, x, h->table[key]);
    h->table[key] = temp;
    return 0;

    //4번이 달랐던 이유.
    //나는 리스트 맨 뒤에 삽입하는 것인줄 알았으나 리스트 맨 앞에 삽입을 하는것이었다.
    //그러므로 먼저 임시 노드 변수인 temp를 생성후 calloc을 통해 동적으로 메모리에 자리를 마련해주고,
    //SetNode함수를 통해 이 노드에 실질적인 값을 넣어서 노드 자체를 생성한다.
    //실질적인 값을 넣을때에 next자리는 현재의 h->table[key]의 주소를 넣어준다. (책에서의 20을 저장한 노드)
    //다시 h->table[key]자리에 temp를 지정해줌으로써 버킷의 맨 처음에 temp가 오도록 설정해준다.

    //1. hash 함수가 키 값을 해시 값으로 변경
    //2. 해시 값을 인덱스로 하는 버킷을 선택
    //3. 버킷에 저장된 포인터가 가리키는 연결 리스트를 처음부터 순서대로 검색. 키 값과 같은 값을 찾으면 이미 있으므로
    //  삽입 실패, 찾지 못하면 리스트의 맨 앞 위치에 노드를 삽입.
}

int Remove(ChainHash *h, const Member *x) 
{
    //1. hash 함수가 키 값을 해시 값으로 변경
    int key = hash(x->no, h->size);
    //2. 해시 값을 인덱스로 하는 버킷을 선택
    Node *p = h->table[key];
    //3. 버킷에 저장된 포인터가 가리키는 연결 리스트를 처음부터 순서대로 검색. 키 값과 같은 값을 찾으면 삭제.
    //  찾지 못하면 종료.
    while(p != NULL)
    {
        if(p->data.no == x->no)//삭제할 노드를 발견함.ㄴ
        {
            h->table[key] = p->next;
            break;
        }
        p = p->next;
    }
    return 0;

    //Ex3.
    Node **pp = &h->table[key];
    while(p != NULL)
    {
        if(p->data.no == x->no)
        {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }

    return 1;
}

void Dump(const ChainHash *h)//해시테이블의 모든 요소(우선은 숫자만)를 출력하는 함수
{
    int i;
    for(i=0; i<h->size; i++)
    {
        Node *p = h->table[i];
        printf("%d ", i);
        while(p != NULL)
        {
            printf("-> %d ", p->data.no);
            p = p->next;
        }
        printf("\n");
    }

    return 0;
}

void Clear(ChainHash *h)//해시테이블의 모든 요소를 삭제하는 함수
{
    //1. 배열표의 모든 요소를 순서대로 검사
    int i;
    for(i=0; i<h->size; i++)
    {
        Node *p = h->table[i];
        //2. 요소가 NULL이 아니면 값이 있다는 뜻이므로 맨 앞부터 검사하면서 메모리해제
        while(p != NULL)
        {
            //next값을 미리 백업시켜 놔야함.
            //백업 시키지 않고 free를 해버리면 next값을 잃어버리므로.
            Node* next = p->next;
            free(p);
            p = next;
        }
        //3. 마지막으로 검사 중인 배열 요소에 NULL을 대입
        h->table[i] = NULL;
    }
}

void Terminate(ChainHash *h) 
{
    //1. Clear함수로 해시에 등록한 모든 데이터 삭제
    Clear(h);
    //2. Init 함수로 메모리에 확보한 해시 테이블 해제
    free(h->table);
    //3. 해시테이블 멤버 size를 0으로 초기화
    h->size = 0;
}


//포인터와 이중포인터는 되게되게 중요하고, 되게되게 존나 헷갈린다 씨발... 할때마다 헷갈려
 