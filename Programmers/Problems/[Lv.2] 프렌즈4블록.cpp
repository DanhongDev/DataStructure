#include <string>
#include <vector>
#include <queue>
using namespace std;

//BFS쓸 필요 없다!
int solution(int m, int n, vector<string> board)
{
    bool isEnd = false;

    while(!isEnd)
    {
        isEnd = true;

        vector<vector<bool>> check(m, vector<bool>(n, false));

        for(int i=0; i<m-1; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                if(board[i][j] == ' ') continue;

                char c = board[i][j];

                if (c == board[i+1][j] && c == board[i][j+1] && c == board[i+1][j+1])
                {
                    check[i][j] = true;
                    check[i+1][j] = true;
                    check[i][j+1] = true;
                    check[i+1][j+1] = true;
                    isEnd = false;
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(check[i][j]) board[i][j] = ' ';
            }
        }

        for(int j=0; j<n; j++)
        {
            for(int i=m-1; i>=0; i--)
            {
                if(board[i][j] == ' ')
                {
                    for(int k=i-1; k>=0; k--)
                    {
                        if(board[k][j] != ' ')
                        {
                            swap(board[i][j], board[k][j]);
                            break;
                        }
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j] == ' ') answer++;
        }
    }
    return answer;
}


//void bfs(vector<string> &board, int i, int j)
//{
//    board[i][j] = ' '; //기준 블록은 일단 제거 항목에 추가
//
//    //bfs탐색
//    queue<pair<int,int>> q;
//    q.push({i, j+1});
//    q.push({i+1, j});
//    q.push({i+1, j+1});
//
//    while(!q.empty())
//    {
//        int cur_i = q.front().first;
//        int cur_j = q.front().second;
//        q.pop();
//
//        char c = board[cur_i][cur_j];
//
//        if(c == board[cur_i+1][cur_j] && c == board[cur_i][cur_j+1] && c == board[cur_i+1][cur_j+1]) //2x2 탐색
//        {
//            q.push({cur_i, cur_j+1});
//            q.push({cur_i+1, cur_j});
//            q.push({cur_i+1, cur_j+1});
//        } //중복되는 인덱스가 push되는 경우가 있다. 해결방법은??
//
//        board[cur_i][cur_j] = ' ';
//    }
//}
//
//void block(int m, int n, vector<string> &board, bool &isEnd)
//{
//    //이중 for문으로 돌다가 2x2를 만나면 bfs돌려서 삭제할 칸의 인덱스를 전부 저장
//    for(int i=0; i<m-1; i++)
//    {
//        for(int j=0; j<n-1; j++)
//        {
//            if(board[i][j] == ' ') continue;
//            
//            char c = board[i][j]; //기준 블록
//            if(c == board[i+1][j] && c == board[i][j+1] && c == board[i+1][j+1]) //2x2 탐색
//            {
//                isEnd = false;
//                bfs(board, i, j);
//            }
//        }
//    }
//}
//
//void down(int m, int n, vector<string> &board)
//{
//    for(int i=0; i<m-1; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(board[i+1][j] == ' ')
//            {
//                swap(board[i][j], board[i+1][j]);
//            }
//        }
//    }
//}
//
//int solution(int m, int n, vector<string> board)
//{
//    bool isEnd = false;
//    while(!isEnd)
//    {
//        isEnd = true;
//        //2x2 블록 탐색
//        block(m, n, board, isEnd);
//        //끌어내리기
//        down(m, n, board);
//    }
//    
//    int answer = 0;
//    for(int i=0; i<m; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(board[i][j] == ' ') answer++;
//        }
//    }
//    return answer;
//}
