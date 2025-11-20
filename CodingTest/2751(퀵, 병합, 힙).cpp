#include<iostream>
#include<vector>
#include<algorithm>

//1. 퀵정렬 (재귀)
void QuickSort(std::vector<int>& arr, int left, int right) //오류3. &가 안들어감 즉 참조가 안되어 있었다.
{
    //오류1. 재귀 종료 조건 부재
    if(left >= right) return;

    int low = left; //pl
    int high = right; //pr
    int x = arr[(left+right)/2]; //pivot

    //===MY CODE===
    // while(1)
    // {
    //     if(arr[low] < x)
    //     {
    //         low++;
    //     }
    //     if(arr[high] > x)
    //     {
    //         high--;
    //     }
    //     if(arr[low] >= x && arr[high] <= x)
    //     {
    //         std::swap(arr[low], arr[high]);
    //         low++;
    //         high--;
    //     }
    //     if(low > high)
    //     {
    //         break;
    //     }
    // }

    //오류4. if vs while
    //while로 쭉 이동하지 않고 if로 한칸씩 끊어가면 꼬일위험이 있다. ==> do-while문을 써보기.
    do
    {
        while(arr[low] < x) low++;
        while(arr[high] > x) high--;

        //교환이 일어나는건 언제나 low <= high일때의 상황이다.
        //low > high인 경우는 교차가 일어난 경우이므로 교환이 일어나면 안된다.
        if(low <= high)
        {
            std::swap(arr[low], arr[high]);
            low++;
            high--;
        }
    } while (low <= high);
    
    //===MY CODE===
    //Quick(arr, 0, high);
    //Quick(arr, low, arr.size()-1);

    //오류2. 호출 범위 오류
    //무조건 0에서부터 이거나 arr.size()-1 까지가 아닌 현재 범위의 왼쪽, 오른쪽을 기준을 잡아야함. 
    //즉 left와 right를 써야함
    if(left < high) QuickSort(arr, left, high);
    if(low < right) QuickSort(arr, low, right);
    
    return;
}

//2. 병합정렬
//쪼개진 덩어리를 합치는 일꾼 함수
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    //1. merge할 임시 배열 준비
    //크기는 right - left + 1
    std::vector<int> tempArr (right - left + 1, 0);

    //2. 포인터 3개 선언
    int i = left; //왼쪽 그룹의 현재 순서 (초기값: left)
    int j = mid+1; //오른쪽 그룹의 현재 순서 (초기값: mid+1)
    int k = 0; //임시 배열에 채워넣을 위치 (초기값: 0)

    //3. 비교하여 임시 배열에 넣기 시작
    while(i<=mid && j<=right)
    {
        tempArr[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    //4. 어느 한쪽의 배열에 숫자가 남아 있을 경우 다 털어 넣기
    while(i<=mid)
    {
        tempArr[k++] = arr[i++];
    }
    while(j<=right)
    {
        tempArr[k++] = arr[j++];
    }

    //5. 원래 배열 arr에 복사하기
    //===MY CODE===
    // int tempIdx = 0;
    // for(int i=left; i<=right; i++)
    // {
    //     arr[i] = tempArr[tempIdx++];
    // }
    //5. Gemini 버전
    for(int l=0; l<tempArr.size(); l++) //l은 tempArr의 인덱스
    {
        arr[left + l] = tempArr[l]; //left+0, left+1, ... 로 활용
    }
}
//병합정렬 (재귀)
void MergeSort(std::vector<int>& arr, int left, int right)
{
    //기저: 원소가 1개 이하면 쪼갤 수 없기에 멈춤
    //if(left >= right) return;

    //기저 최적화: 원소가 2개이면 바로 대소관계를 비교하여 Swap
    int size = right - left + 1; //right-left를 하여 지금 현재의 부분 크기를 계산
    if(size <= 1) return; //위의 기저조건과 동일
    if(size == 2)
    {
        if(arr[left] > arr[right])
        {
            std::swap(arr[left], arr[right]);
        }
        return;
    }

    int mid = (left + right) / 2;

    //1. 분할 (Divide)
    MergeSort(arr, left, mid); //왼쪽 그룹
    MergeSort(arr, mid+1, right); //오른쪽 그룹
    //2. 정복 (Conquer)
    merge(arr, left, mid, right); //병합
}

//3. 힙정렬
void Heap()
{
    
}

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

    //1. algorithm 라이브러리 내장 함수 std::sort 이용
    //std::sort(arr.begin(), arr.end());

    //2. 퀵 정렬 이용 (직접 구현)
    //QuickSort(arr, 0, arr.size()-1);

    //3. 병합 정렬 아용 (직접 구현)
    MergeSort(arr, 0, arr.size()-1);
    
    //4. 힙 정렬 이용 (직접 구현)

    //출력 부분
    for(int i : arr)
    {
        std::cout << i << '\n';
    }
    
    return 0;
}  