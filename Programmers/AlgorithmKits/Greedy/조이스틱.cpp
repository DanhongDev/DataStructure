#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int n = name.length();
    int up_down = 0;
    int left_right = n-1;

    for(int i=0; i<n; i++)
    {
        //ASCII코드값 이용
        up_down += min(name[i] - 'A', 'Z' - name[i] + 1);

        //A가 아닌 문자가 나오는 다음 인덱스
        int next_idx = i+1;
        while(next_idx < n && name[next_idx] == 'A')
        {
            next_idx++;
        }

        left_right = min({left_right, (i*2) + (n-next_idx), (n-next_idx)*2 + i});
    }
    
    return up_down+left_right;
}