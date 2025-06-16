#pragma warning(disable : 4996)
#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

int Initialize(IntStack *s, int max) 
{
    s->ptr = 0;  // 현재의 가리키고 있는 ptr을 초기화
    if (s->stk = calloc(max, sizeof(int)) == NULL)
    // calloc을 통해 동적으로 힙메모리에 할당하고 할당이 실패(NULL)하면 max값을 0으로 주어 초기화 실패
    {
        s->max = 0;
        return -1;
    }
    s->max = max;  // 초기화에 성공하면 max
    return 0;
}

int Push(IntStack *s, int x) 
{
    if (s->ptr < s->max)  // 현재의 ptr이 max값에 비해 작을때만 푸쉬할 수 있게 만들기
    {
        s->stk[s->ptr++] = x;  // ptr++를 까먹음.
        return 0;
    } else {
        return -1;
    }
}

int Pop(IntStack *s, int *x) 
{
    // x에 ptr이 stack의 top이니 ptr이 가리키고 있는 요소를 받고
    x = s->stk[s->ptr];
    //-1등의 값을 주어서 데이터 없음을 표시 후,
    s->stk[s->ptr] = -1;
    // ptr이 가리키고 있는 주소 감소해주기
    s->ptr--;
    //*x를 반환하여 pop마무리.
    return *x;

    //정답 예시
    if (s->ptr <= 0) return -1;  // ptr이 가리키고 있는곳이 정상적인 곳인지 확인하는 조건을 생각 못했음.
    *x = s->stk[s->ptr--];       // x는 포인터 형태로 이미 주소를 받기 때문에, x의 값을 지정만 해주면 알아서 값이 변환되므로
    return 0;                    // return *x를 안해도 되고, 함수형이 int*가 아니고 그냥 int이기 때문에 애초에 잘못된 접근방법.
}

int Peek(const IntStack *s, int *x) 
{
    *x = s->stk[s->ptr];  // ptr이 스택의 현재 Peek일테니 그대로 반환하여 알려주기
    return 0;
    
    //정답 예시
    if(s->ptr <= 0) return -1; //비어있으면 어떻게 할것인지 또 생각안함.
    *x = s->stk[s->ptr - 1]; 
    //왜 ptr-1일까? ==> ptr을 이미 Push에서 ++를 해주어 다음 Push를 기다리고 있는 상태이므로
    //그냥 ptr을 반환하면 쓰레기 값이 있으므로 오류가 난다.
    //그러므로 ptr - 1을 해주어 스택 현재의 Peek를 반환하게 만들어준다.
    return 0;
}

void Clear(IntStack *s) 
{
    //단순히 0부터 max까지 for문 돌려서 0으로 초기화.
    for (int i = 0; i < s->max; i++) 
    {
        s->stk[i] = 0;
    }

    //정답 예시
    s->ptr = 0; //단순히 ptr을 0으로 되돌려서 다시 쌓이게 하는건가...??
}

int Capacity(const IntStack *s) 
{
    return s->max;
}

int Size(const IntStack *s) 
{
    return s->ptr;
}

int IsEmpty(const IntStack *s) 
{
    if(s->ptr > 0)
        return 1;
    else
        return 0;
}

int IsFull(const IntStack *s) 
{
    if(s->ptr >= s-> max)
        return 1;
    else
        return 0;
}

int Search(const IntStack *s, int x) 
{
    for(int i=0; i<s->max; i++)
    {
        if(s->stk[i] == x)
            return 1;
        else
            return 0;
    }

    //정답 예시
    int i;
    for(i = s->ptr - 1; i >= 0; i--) //검색은 top에서 btm으로!
    {
        if(s->stk[i] == x)
            return i;
    }

    return -1;
}

void Print(const IntStack *s) 
{
    for(int i=0; i<s->ptr; i++)
    {
        printf("%d\n", s->stk[i]);
    }
}

void Terminate(IntStack *s) 
{
    s->ptr = 0;
    s->max = 0;
    if(s->stk != NULL)
        free(s->stk);
}

// 스택을 구현하면서 자료구조 상 깨달은점.
// 1. 조건 확인하는 습관 가지기 (NULL인지 아닌지, ptr<=0 인지 ptr>=max인지 등등...)
// 2. 포인터를 통해 구현하는것이므로 쫄지말고 들이박아볼것.

int main() {
    // IntStack s;
    // if (Initialize(&s, 64) == -1)
    // {
    // 	puts("���� ������ �����Ͽ����ϴ�.");
    // 	return 1;
    // }

    // while (1)
    // {
    // 	int menu, x;
    // 	printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
    // 	printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)���� : ");
    // 	scanf("%d", &menu);

    // 	if (menu == 0) break;
    // 	switch (menu)
    // 	{
    // 	case 1:
    // 		printf("������ : ");
    // 		scanf("%d", &x);
    // 		if (Push(&s, x) == -1)
    // 			puts("\a���� : vǪ�ÿ� �����Ͽ����ϴ�.");
    // 		break;

    // 	case 2:
    // 		if (Pop(&s, &x) == -1)
    // 			puts("\a���� : �˿� �����Ͽ����ϴ�.");
    // 		else
    // 			printf("�� �����ʹ� %d�Դϴ�.\n", x);
    // 		break;

    // 	case 3:
    // 		if (Peek(&s, &x) == -1)
    // 			puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
    // 		else
    // 			printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
    // 		break;

    // 	case 4:
    // 		Print(&s);
    // 		break;
    // 	}
    // }
    // Terminate(&s);
    printf("Hello World~  hahahaha\n");
    return 0;
}