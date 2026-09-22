#include <string>
#include <vector>

using namespace std;

vector<int> check(int mid, int m, int n, int h, int w, const vector<vector<int>> &drops)
{
    // 1. 누적합 배열 생성
    vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));

    // 2. mid시간까지의 선인장 위치 표시
    for(int i=0; i<mid; i++)
    {
        int r = drops[i][0] + 1;
        int c = drops[i][1] + 1;
        prefix[r][c] = 1;
    }

    // 3. 2차원 누적 합 계산
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    // 4. h*w 크기의 구역 탐색
    for(int i=h; i<=m; i++)
    {
        for(int j=w; j<=n; j++)
        {
            int sum = prefix[i][j] - prefix[i-h][j] - prefix[i][j-w] + prefix[i-h][j-w];

            if(sum == 0)
            {
                return {i-h, j-w};
            }
        }
    }

    return {-1, -1};
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops)
{
    if(m==h && n==w) return {0,0};

    int left = 1;
    int right = drops.size();

    vector<int> answer = {0, 0};

    while(left <= right)
    {
        int mid = (left + right) / 2;

        vector<int> temp = check(mid, m, n, h, w, drops);

        if(temp[0] != -1)
        {
            answer = temp;
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}