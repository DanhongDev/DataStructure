#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode *AllocBinNode (void)
{
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;
    n->left = left;
    n->right = right;
}

BinNode* Search(BinNode* p, const Member* x) 
{
    int cond;
    if(p == NULL)
        return NULL;
    else if((cond = MemberNoCmp(x, &p->data)) == 0)
        return p;
    else if(cond < 0)
        Search(p->left, x);
    else
        Search(p->right, x);
}

BinNode* Add(BinNode *p, const Member *x) 
{
    int cond;

    if(p == NULL) //p가 NULL일 경우는 루트 노드가 없다는 경우이므로 루트 노드 생성.
    {
        p = AllocBinNode(); //동적으로 메모리에 할당해주고
        SetBinNode(p, x, NULL, NULL); //초기 p를 세팅해준다.
    }
    else if((cond = MemberNoCmp(x, &p->data)) == 0) //x의 no와 p의 data를 숫자 비교를 한다음 0이 나오면 (같을 경우)
    {
        printf("%d는 이미 있습니다.", x->no); //이미 있는 값이므로 출력만해주고 종료
    }
    else if(cond < 0)
    {
        p->left = Add(p->left, x); //삽입할 값 x가 p보다 낮으므로 왼쪽 자식에 Add
    }
    else
    {
        p->right = Add(p->right, x); //삽입할 값 x가 p보다 높으므로 오른쪽 자식에 Add
    }

    return p;
}

int Remove(BinNode **root, const Member *x)
{
    //필요한 재료
        //검색할 노드
        BinNode **p = root; //p의 값이 변화하면서 트리에 노드가 있는지 검색
        //임시 노드
        BinNode *next, *temp;
        //iii에서 가장 작은값이나 큰값을 검색할 때 사용할 변수
        BinNode **left;


    //먼저 삭제할 노드가 트리에 있는지 검색하는 부분을 생성해야함
    while(1)
    {
        int cond;
        if(*p == NULL)
        {
            printf("해당 노드는 트리에 없습니다.\n");
            return -1;
        }
        else if(cond = MemberNoCmp(x, &((*p)->data)) == 0) //트리에서 찾았음.
        {
            break;
        }
        else if(cond < 0)
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }

    
    //삭제 케이스

    //i)삭제하려는 노드가 자식이 없는 경우
        //부모의 (왼쪽or오른쪽)포인터를 NULL로
    //ii)삭제하려는 노드가 자식이 1개인 경우
        //부모의 포인터가 삭제하려는 노드의 자식을 가리키도록 수정
    
    //책에서는 i과 ii를 묶어서 실행될 수 있도록 구현해냈음. 이 방법에 대해 생각해낼것.
        //i이나 ii이나 일단 한쪽은 노드가 없는거잖아?? (부모의 왼쪽 자식이 NULL이거나 오른쪽 자식이 NULL이란 말)
        //그럼...
        if((*p)->left == NULL)//먼저 left가 NULL이라면
        {
            //right는 있거나 없잖아??
            //그럼 next에 right만 꽂아주면 right가 값이 있든 NULL이든 알아서 들어갈 거잖아??
            next = (*p)->right; //이렇게 하면... 알아서 제 값이 들어가거나 NULL이 자동으로 들어가잖아!
            
            //그럼 else문으로 바로 iii을 구현할 수 있겠네
        }

    //iii)삭제하려는 노드가 자식이 2개인경우
        else
        {
            //1. 삭제하려는 노드의 왼쪽 서브트리에서 가장 큰 값을 검색 (또는 오른쪽 서브트리에서 가장 낮은 값을 검색)
                //BinNode **left를 이용하자
                left = &((*p)->left);
                while((*left)->right != NULL)
                {
                    left = &(*left)->right;
                }
            //2. 검색한 노드를 삭제 위치로 이동
                next = *left;
            //3. 옮긴 노드를 삭제
                //교체자(left) 노드는 오른쪽 자식은 없지만(자기가 제일 큰 수이기 때문에) 왼쪽 자식은 있을 수도 있다.
                *left = (*left)->left; //그러므로 왼쪽 자식을 넣음으로서 트리를 정리하는 것이다.
                
                next->left = (*p)->left;
                next->right = (*p)->right;
                
            //ㄱ. 옮긴 노드에 자식이 없는 경우 i에 따라 삭제
            //ㄴ. 옮긴 노드에 자식이 1개인 경우 ii에 따라 삭제
        }
        temp = *p;
        *p = next;
        free(temp);

        //BinNode **p에 대해서 자세히 이해해볼것.
        //아직 *p, (*p)->left, ... 등에 대해서 제대로 이해한것이 아닌거 같음.
        //포인터는 "주소값을 저장하는 변수"
        //그러므로 포인터의 값을 물어보는건 어떤 주소값이 저장되어 있는지를 물어보는것
        //&: 변수에 저장되어 있는 주소값
        //*: 포인터 변수가 가리키는 곳의 값
}

void PrintTree(const BinNode * p)
{
    if(p != NULL)
    {
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
}

void FreeTree(BinNode *p) 
{
    if(p != NULL)
    {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}
