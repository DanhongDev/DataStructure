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
    
    return 0;
}
