#include<iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int M, N;
    std::cin >> M >> N;
    
    std::vector<std::vector<char>> board(M, std::vector<char>(N, 0));
    
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> board[i][j];
        }
    }
    
    int min = 10001;

    //r과 c는 보드에서 시작하는 맨 왼쪽 위 인덱스들.
    for(int r=0; r<=M-8; r++)
    {
        for(int c=0; c<=N-8; c++)
        {
            int cnt_W=0, cnt_B=0;
            //i와 j는 시작 인덱스를 기준으로 8*8로 탐색하는 변수
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    //cur_R과 cur_C는 현재 인덱스가 전체 보드판으로 치면 어떤 인덱스인가? 를 계산한 값.
                    int cur_R = r + i;
                    int cur_C = c + j;
                    //따라서 r + c가 홀짝임에따라 cur_R + cur_C가 홀인지 짝인지 계산을하여
                    //그때마다 board[cur_R][cur_C]가 B인지 W인지 검사하고 cnt++하기
                    // if(board[r][c] == 'W')
                    // {
                    //     if((r+c) % 2 == 0)
                    //     {
                    //         if((cur_R+cur_C)%2==0 && board[cur_R][cur_C] == 'B')
                    //         {
                    //             cnt++;
                    //         }
                    //         else if((cur_R+cur_C)%2==1 && board[cur_R][cur_C] == 'W')
                    //         {
                    //             cnt++;
                    //         }
                    //     }
                    //     else
                    //     {
                    //         if((cur_R+cur_C)%2==0 && board[cur_R][cur_C] == 'W')
                    //         {
                    //             cnt++;
                    //         }
                    //         else if((cur_R+cur_C)%2==1 && board[cur_R][cur_C] == 'B')
                    //         {
                    //             cnt++;
                    //         }
                    //     }
                    // }
                    // else //시작인덱스가 B인 경우
                    //      //여기 부분이 Gemini에서 B시작 64-cnt_W 그 공식 부분인거 같음.
                    // {
                    //     if((r+c) % 2 == 0)
                    //     {
                    //         if((cur_R+cur_C)%2==0 && board[cur_R][cur_C] == 'W')
                    //         {
                    //             cnt++;
                    //         }
                    //         else if((cur_R+cur_C)%2==1 && board[cur_R][cur_C] == 'B')
                    //         {
                    //             cnt++;
                    //         }
                    //     }
                    //     else
                    //     {
                    //         if((cur_R+cur_C)%2==0 && board[cur_R][cur_C] == 'B')
                    //         {
                    //             cnt++;
                    //         }
                    //         else if((cur_R+cur_C)%2==1 && board[cur_R][cur_C] == 'W')
                    //         {
                    //             cnt++;
                    //         }
                    //     }
                    // }

                //입력예시가 W라고 W패턴만 검사하는 것이 아니다.
                //문제에서 요구하는건 8*8보드 안에서의 최소만 요구하고 있으므로
                //어느 8*8범위라 할지라도 W시작패턴과 B시작패턴의 비용을 계산하고
                //최소를 비교해야한다!!!

                // (i+j)의 홀짝성으로 W-시작 패턴을 검사
                if((i+j) % 2 == 0) // W가 와야 할 짝수 칸
                {
                    if(board[cur_R][cur_C] != 'W') cnt_W++;
                    if(board[cur_R][cur_C] != 'B') cnt_B++;
                }
                else // B가 와야 할 홀수 칸
                {
                    if(board[cur_R][cur_C] != 'B') cnt_W++;
                    if(board[cur_R][cur_C] != 'W') cnt_B++;
                }
                }
            }
            int cur_min = cnt_W < cnt_B ? cnt_W : cnt_B;

            min = cur_min < min ? cur_min : min;
        }
    }

    std::cout << min << '\n';
    return 0;
}


//Gemini버전: cnt_W와 cnt_B를 따로 계산하는것이 아닌 전체 비용은 64(8*8이기 때문)이므로
//cnt_W만 구해놓으면 B시작패턴 비용(cnt_B)는 64-cnt_W로 구할수 있기 때문이다.
/*
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int M, N;
    std::cin >> M >> N;
    
    std::vector<std::vector<char>> board(M, std::vector<char>(N, 0));
    
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> board[i][j];
        }
    }
    
    int min = 64;
    
    for(int r=0; r<=M-8; r++)
    {
        for(int c=0; c<=N-8; c++)
        {
            int cnt_W = 0;
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    int cur_R = r + i;
                    int cur_C = c + j;
                    if((i+j)%2 == 0)
                    {
                        if(board[cur_R][cur_C] != 'W')
                        {
                            cnt_W++;
                        }
                    }
                    else
                    {
                        if(board[cur_R][cur_C] != 'B')
                        {
                            cnt_W++;
                        }
                    }
                }
            }
            
            int cnt_B = 64 - cnt_W;
            int cur_min = cnt_W < cnt_B ? cnt_W : cnt_B;
            
            min = cur_min < min ? cur_min : min;
        }
    }
    
    
    std::cout << min << '\n';
    
    return 0;
}
*/