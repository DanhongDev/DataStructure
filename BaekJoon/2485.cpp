#include<iostream>
#include<vector>

int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> arr(N, 0);
    for(int i=0; i<N; i++)
    {
        std::cin>> arr[i];
    }

    // int a = arr[1] - arr[0];
    // int b = arr[2] - arr[1];

    // int gcd = GCD(a, b);
    // int cnt = 0;

    // int temp = arr[0] + gcd;
    // int idx = 1;
    // while(1)
    // {
    //     if(temp >= arr[N-1])
    //     {
    //         break;
    //     }
    //     if(arr[idx] < temp)
    //     {
    //         idx++;
    //     }
    //     if(temp != arr[idx])
    //     {
    //         cnt++;
    //     }
        
    //     temp += gcd;
    // }
    
    //Gemini
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i];
    }
    int gcd = arr[1] - arr[0];
    for(int i=2; i<N; i++)
    {
        int gap = arr[i] - arr[i-1];
        gcd = GCD(gcd, gap);
    }

    int dist = arr[N-1] - arr[0];
    int cnt = (dist / gcd) - (N-1);

    std::cout << cnt << '\n';


    
    return 0;
}