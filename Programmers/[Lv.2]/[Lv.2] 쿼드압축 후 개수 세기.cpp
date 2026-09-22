#include <string>
#include <vector>

using namespace std;

void quadcomp(int row_x, int row_y, int col_x, int col_y, vector<vector<int>> &board, int &cnt_0, int &cnt_1, vector<vector<bool>> &comp)
{
    int size = row_y - row_x;
    if(size <= 1) return;

    int row_mid = (row_x+row_y) / 2;
    int col_mid = (col_x+col_y) / 2;

    int base = board[row_x][col_x];
    bool diff = false;
    for(int i=row_x; i<row_y; i++)
    {
        if(diff) break;
        for(int j=col_x; j<col_y; j++)
        {
            if(board[i][j] != base) 
            {
                diff = true;
                break;
            }
        }
    }

    if(!diff)
    {
        //압축했다는것을 저장하는 부분
        for(int i=row_x; i<row_y; i++)
        {
            for(int j=col_x; j<col_y; j++)
            {
                comp[i][j] = true;
            }
        }
        if(base) cnt_1++;
        else cnt_0++;
    }
    else
    {
        quadcomp(row_x, row_mid, col_x, col_mid, board, cnt_0, cnt_1, comp); //좌상
        quadcomp(row_x, row_mid, col_mid, col_y, board, cnt_0, cnt_1, comp); //우상
        quadcomp(row_mid, row_y, col_x, col_mid, board, cnt_0, cnt_1, comp); //좌하
        quadcomp(row_mid, row_y, col_mid, col_y, board, cnt_0, cnt_1, comp); //우하
    }

    return;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<vector<bool>> comp(arr.size(), vector<bool> (arr.size(), false));

    int cnt_0=0, cnt_1=0;
    quadcomp(0, arr.size(), 0, arr.size(), arr, cnt_0, cnt_1, comp);

    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr.size(); j++)
        {
            if(!comp[i][j])
            {
                if(arr[i][j] == 0) cnt_0++;
                else cnt_1++;
            }
        }
    }

    return {cnt_0, cnt_1};
}

//comp없이 size==1일때도 바로 cnt++되게 할 수 있다. (분할정복을 믿는다.)
void Gequadcomp(int row, int col, int size, const vector<vector<int>> &board, int &cnt_0, int &cnt_1)
{
    int base = board[row][col];
    bool diff = false;

    for(int i=row; i<row+size; i++)
    {
        for(int j=col; j<col+size; j++)
        {
            if(board[i][j] != base)
            {
                diff = true;
                break;
            }
        }
        if(diff) break;
    }

    if(!diff)
    {
        if(base == 0) cnt_0++;
        else cnt_1++;
    }
    else
    {
        int half = size / 2;
        Gequadcomp(row, col, half, board, cnt_0, cnt_1);
        Gequadcomp(row, col+half, half, board, cnt_0, cnt_1);
        Gequadcomp(row+half, col, half, board, cnt_0, cnt_1);
        Gequadcomp(row+half, col+half, half, board, cnt_0, cnt_1);
    }
}
vector<int> Gesolution(vector<vector<int>> arr)
{
    int cnt_0=0, cnt_1=0;

    Gequadcomp(0, 0, arr.size(), arr, cnt_0, cnt_1);

    return {cnt_0, cnt_1};
}