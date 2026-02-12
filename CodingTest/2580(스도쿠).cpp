#include<iostream>
#include<vector>

int board[9][9]; //보드판
bool row_check[9][10]; //행 체크
bool col_check[9][10]; //열 체크
bool area_check[9][10]; //구역 체크

std::vector<std::pair<int, int>> blank; //빈칸 모음

//구역 계산 함수
int cal_area(int r, int c)
{
    return (r/3) * 3 + (c/3);
}

//백트래킹 실행 함수
void func(int k)
{
    //기저 조건
    if(k == blank.size())
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                 std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }

        //답지의 경우의 수 하나만 출력하고 바로 종료.
        exit(0);
    }

    int r = blank[k].first;
    int c = blank[k].second;
    int area = cal_area(r, c);

    for(int n=1; n<=9; n++)
    {
        //행, 열, 3*3구역 셋 중 하나라도 중복된것이 있으면 패스.
        if(row_check[r][n] || col_check[c][n] || area_check[area][n])
        {
            continue;
        }

        board[r][c] = n;
        row_check[r][n] = true;
        col_check[c][n] = true;
        area_check[area][n] = true;

        func(k + 1);

         board[r][c] = 0;
        row_check[r][n] = false;
        col_check[c][n] = false;
        area_check[area][n] = false;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //보드 입력문
    for(int i=0; i<9; i++)
    {
        int value = 0;
        for(int j=0; j<9; j++)
        {
            std::cin >> value;
            board[i][j] = value;
            if(value > 0)
            {
                row_check[i][value] = true; //단순 인덱스로 하면 안되고 인덱스가 곧 그 숫자가 될테니까...
                col_check[j][value] = true;
                int area = cal_area(i, j);
                area_check[area][value] = true;
            }
            else
            {
                blank.push_back({i, j}); 
            }
        }
    }

    func(0);
    return 0;
}