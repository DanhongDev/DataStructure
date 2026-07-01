#include<iostream>
#include<vector>

int min = 2147483647;
int N;
std::vector<std::vector<int>> board;
std::vector<bool> is_used;
int score_start, score_link;

void func(int k, int cnt) //k는 기준이 되는 첫번째 사람.
{
    //기저 조건
        //cnt == N/2 일때
        //start팀과 link팀의 점수를 구하고 차이 절대값을 계산
        //min값 갱신
        //리턴
    if(cnt == N/2)
    {
        //is_used에서 true이면 start팀으로 간주. false이면 link팀으로 간주
        //근데... 이게 인덱스 놀이를 가능한건가???
        //N이 커질수록 [0, 1] [0, 1, 3] 등등 하나하나 참고하기엔 경우의 수가 너무 많아지는데
        score_start = 0;
        score_link = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(is_used[i] && is_used[j]) //start팀
                {
                    score_start += board[i][j];
                }
                else if(!is_used[i] && !is_used[j])
                {
                    score_link += board[i][j];
                }
            }
        }

        int temp = std::abs(score_start - score_link);

        min = temp < min ? temp : min;
        return;
    }

    //for문
        //is_used[k] = true; cnt++; 이 코드를 for문 안에서 할지 위에서 할지는 한번 더 고민
        //is_used[i] = true; cnt++;
        //func(k+1);
        //is_used[k] = false;
        //is_used[i] = false;
    for(int i=k; i<N; i++)
    {
        is_used[i] = true;
        func(i+1, cnt+1);
        is_used[i] = false;
    }
        
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //처음에는 행과 열로 생각해서 재귀와 for를 구현하려 했으나, 생각해보니
    //그냥 인덱스 놀이이므로 그때의 팀 조합 인덱스가 만들어지면 board에서 따오기만 하면 됨.
    //즉 1차원 배열안에서 재귀와 for를 돌려도 무방함.
    std::cin >> N;
    board.assign(N, std::vector<int>(N, 0)); //N*N 크기의 보드판 새로 작성
    is_used.assign(N, false);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> board[i][j];
        }
    }
    
    func(0, 0);
    std::cout << min << '\n';

    return 0;
}