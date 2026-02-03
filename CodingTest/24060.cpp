#include<iostream>
#include<vector>

int N, K;
int cnt=0;
int res = -1;
int* temp;

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int i=left, j=mid+1, k=0;

    while(i<=mid && j<=right)
    {
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }


    i = left;
    k = 0;
    while(i <= right)
    {
        arr[i] = temp[k];
        cnt++;
        if(cnt == K)
        {
            res = arr[i];
        }
        i++;
        k++;
    }
}

void MergeSort(std::vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = (right + left)/2;
        
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        merge(arr,left, mid, right);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> K;
    std::vector<int> arr(N);
    temp = new int[N];

    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }

    MergeSort(arr, 0, N-1);

    std::cout << res << '\n';

    return 0;
}