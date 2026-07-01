// #include<iostream>

// int N;
// int cnt = 0;

// bool is_used1[40];
// bool is_used2[40];
// bool is_used3[40];

// void func(int row)
// {
//     if(row == N)
//     {
//         cnt++;
//         return;
//     }

//     for(int col=0; col<N; col++)
//     {
//         if(is_used1[col] || is_used2[row+col] || is_used3[row - col + N - 1])
//         {
//             continue;
//         }

//         is_used1[col] = true;
//         is_used2[row+col] = true;
//         is_used3[row - col + N - 1] = true;

//         func(row + 1);

//         is_used1[col] = false;
//         is_used2[row+col] = false;
//         is_used3[row - col + N - 1] = false;
//     }
// }



// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     std::cin >> N;

//     func(0);
//     std::cout << cnt << '\n';
    
//     return 0;
// }


//비트마스크 방법.
#include<iostream>

int N, ans;

void solve(int row, int ld, int rd, int col)
{
    if(row == N)
    {
        ans++;
        return;
    }
    
    int safe_spots = ~(ld | rd | col) & ((1 << N) - 1);

    while(safe_spots > 0)
    {
        int bit = safe_spots & -safe_spots;

        solve(row+1, (ld | bit) << 1, (rd | bit) >> 1, col | bit);

        safe_spots -= bit;
    }
}

int main()
{
    std::cin >> N;
    solve(0, 0, 0, 0);
    std::cout << ans;
    return 0;
}