#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr(N,0);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    //1. 선택 정렬[최선: O(N^2), 평균: O(N^2), 최악: O(N^2)]
    for(int i=0; i<arr.size()-1; i++)
    {
        int min = i;
        for(int j=i+1; j<arr.size(); j++)
        {
            min = arr[j] < arr[min] ? j : min;
        }
        std::swap(arr[i], arr[min]);
    }
    
    //2. 버블 정렬[최선: O(N), 평균: O(N^2), 최악: O(N^2)]
    for(int i=arr.size()-1; i>0; i--)
    {
        bool chg = false;
        for(int j=0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                chg = true;
            }
        }

        if(!chg) break;
    }

    //3. 삽입 정렬[최선: O(N), 평균: O(N^2), 최악: O(N^2)]
    for(int i=1; i<arr.size(); i++)
    {
        int key = arr[i];
        int j;
        for(j=i; j>0 && arr[j-1] > key; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }

    //출력 부분
    for(int i=0; i<arr.size(); i++)
    {
        std::cout << arr[i] << '\n';
    }
    
    return 0;
}

//일반적으로 코딩테스트에서 std::sort를 쓰는 경우가 많다.
//std::sort는 퀵정렬로 수행을 하다가 재귀가 너무 깊어지면 힙정렬로 전환하여 수행하고
//입력 개수가 적으면 삽입정렬로 자동으로 수행하기 때문이다.

//그러나 드문 경우로 라이브러리 속 std::sort함수를 쓰지 못하게 하는 코딩테스트가 있는데,
//그 경우에는 데이터의 개수에 따라 전략을 달리 해야한다.
//i) N이 작을 때 (N <= 1,000): 선택, 버블, 삽입정렬과 같은 O(N^2)을 사용해도 된다.
//ii) N이 클 때 (N >= 100,000): 반드시 퀵, 병합, 힙정렬과 같은 O(NlogN)을 써야한다.
    //N이 클 때 Gemini추천은 "병합 정렬"이다.
        //Why?
        //퀵 정렬은 피벗을 잘못 잡으면 최악의 경우 O(N^2)이 되는 경우가 있다.
        //힙 정렬은 구현이 병합 정렬보다 조금 더 복잡할 수 있다.
        //병합 정렬은 항상 안정적으로 O(NlogN)을 보장하여 실수가 적다.

//결론: 라이브러리가 금지라면 "병합 정렬"을 외워두는게 안전하다.

//iii) N이 엄청 클 때 (N > 1,000,000): 일반적으로 std::sort로도 가능하지만, 상황에 따라
//"계수 정렬"등을 고려해야한다.

//코딩테스트에서는 최악의 경우 즉 가장 큰 N을 기준으로 코드를 구현해야 한다.