#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdbool.h>
#include "Stack.h"

//버블 정렬1
void bubble(int a[], int n)
{
    int i, j;

    for(i = 0; i < n-1; i++)
    {
        int chg = 0;
        for(j = n-1; j > i; j--)
        {
            if(a[j-1] > a[j])
            {
                swap(int, a[j-1], a[j]);
                chg++;
            }
        }
        if(chg == 0) break;
    }
}
//버블 정렬2
void bubble2(int a[], int n)
{
    int k = 0;
    while(k < n - 1)
    {
        int j;
        int last = n - 1;
        for(j = n-1; j > k; j--)
        {
            if(a[j - 1] > a[j])
            {
                swap(int, a[j-1], a[j]);
                last = j;
            }
        }
        k = last;
    }
}

//단순 선택 정렬
void Select(int a[], int n)
{
    int i,j;
    for(i = 0; i < n - 1; i++)
    {
        int min = i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[min]) //a[j]와 a[min]을 비교 후,
            {
                min = j; //조건이 맞다면 min의 인덱스를 j로 변경
            }
        }
        swap(int, a[j], a[min]);
    }
}

//단순 삽입 정렬
void Insertion(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int tmp = a[i]; //현재 옮길 요소 tmp에 저장

        for(int j=i; j>=0; j--)
        {
            if(j==0)
            //a[-1]과 a[0]을 비교할 수 없다.
            //배열의 첫 요소 즉, a[0]까지 j 루프가 왔다는건 현재 가지고 있는 tmp가
            //제일 작은 수 이므로 그냥 a[0]에 tmp를 넣어준다.
            {
                if(a[0] > tmp)
                {
                    a[j] = tmp;
                }
                break;
            }

            if(a[j-1] > tmp)
            {
                a[j] = a[j-1];
            }
            else //그 앞에 요소가 tmp보다 작다면 더이상 작업할 필요가 없음.
            {
                a[j] = tmp;
                break;
            }
        }
    }

    //정답 예시
    int i, j;
    for(i = 1; i<n; i++)
    {
        int tmp = a[i];
        for(j = i; j>0 && a[j-1] > tmp; j--)
        //내코드의 else가 a[j-1] > tmp이므로 break보다는 
        //아예 for루프가 실행이 안되는 메커니즘인거 같다. 다음에 코드짤 때 참고하도록!!
        {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

//쉘 정렬
void Shell(int a[], int n)
{
    ////4정렬
    //// n/2 횟수만큼의 정렬
    ////for(i=0 ~ n/2까지){}
    //for(int i=0; i<n/2; i++)
    //{
    //    if(a[i+(n/2)] < a[i])
    //    {
    //        swap(int ,a[i+(n/2)], a[i]);
    //    }
    //}
//
    ////2정렬
    //// '2회' 횟수만큼의 정렬
    //for(int i=2; i<n; i++)
    //{
    //    int tmp = a[i];
    //    int j;
//
    //    for(j=i; j>0 && a[j-2] > tmp; j-=2)
    //    {
    //        a[j] = a[j-2];
    //    }
    //    a[j] = tmp;
    //}
    //
//
    ////1정렬
    ////Call Insertion Func.
    //int i, j;
    //for(i = 1; i<n; i++)
    //{
    //    int tmp = a[i];
    //    for(j = i; j>0 && a[j-1] > tmp; j--)
    //    //내코드의 else가 a[j-1] > tmp이므로 break보다는 
    //    //아예 for루프가 실행이 안되는 메커니즘인거 같다. 다음에 코드짤 때 참고하도록!!
    //    {
    //        a[j] = a[j-1];
    //    }
    //    a[j] = tmp;
    //}

    //정답 예시
    int i,j,h;
    for(h=n/2; h>0; h/=2)
    {
        for(i=h; i<n; i++)
        {
            int tmp = a[i];
            for(j=i-h; j>=0 && a[j]>tmp; j-=h)
            {
                a[j+h]=a[j];
            }
            a[j+h] = tmp;
        }
    }
    //셸정렬은 정답 예시가 너무 복잡하게 보인다..
    //4정렬 2정렬 1정렬을 하나의 식으로 묶어냈다 보니까 보기가 어려움.
}

//퀵 정렬 범위 나누기
void QuickSortOneStep(int a[], int n)
{
    //One Step
    int pl = 0;
    //int x = n/2; //x를 인덱스로
    int x = a[n/2];//x를 바로 값으로
    int pr = n-1;

    while(1)
    {
        if(a[pl] < x)
        {
            pl++;
        }
        if(a[pr] > x)
        {
            pr--;
        }
        if(a[pl] >= x && a[pr] <= x)
        {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }

        if(pl > x || pr < x)
        {
            break;
        }
    }
}
//퀵 정렬 (재귀)
void Quick(int a[], int left, int right)
{
//QuickSort
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];

    int i;
    printf("a[%d] ~ a[%d]: {", left, right);
    for(i=left; i<right; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d}\n", a[right]);


    while(pl <= pr)
    {
        if(a[pl] < x)
        {
            pl++;
        }
        if(a[pr] > x)
        {
            pr--;
        }
        if(a[pl] >= x && a[pr] <= x)
        {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    }
    if(left < pr)
    {
        Quick(a, left, pr);
    }
    if(pl < right)
    {
        Quick(a, pl, right);
    }
}
//퀵 정렬 (재귀X -> 반복문 이용)
void quick (int a[], int left, int right)
{
    IntStack lstack;
    IntStack rstack;

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    while(!Isempty(&lstack))
    {
        int pl = (Pop(&lstack, &left), left);
        int pr = (Pop(&rstack, &right), right);
        int x = a[(left + right) / 2];
    }
}

static int* buff;
//병합 정렬
void _merge(int a[], int left, int right)
{
    if(left < right)
    {
        int center = (left + right) / 2;
        
    }

}
int merge(int a[], int n)
{
    if(buff = calloc(n, sizeof(int)) == NULL)
    {
        return -1;
    }
    _merge(a, 0, n-1); //배열 전체를 병합정렬 시작
    free(buff);
    return 0;
}

//힙 정렬
void heap(int a[], int n)
{
    
}


//main문
int main()
{
    int i;
    int *x;

    int nx = 9;
    x = calloc(9, sizeof(int));
    for(i=0; i<9; i++)
    {
        printf("x[%d]: ",i);
        scanf("%d", &x[i]);
    }

    //Insertion(x, 7);
    //Shell(x, 8);
    Quick(x, 0, nx - 1);

   
    return 0;
}