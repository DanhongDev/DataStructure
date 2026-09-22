#include <string>
#include <vector>

using namespace std;

int getCnt(int T)
{
    int sm = T * 59 / 3600;
    int sh = T * 719 / 43200;

    int cross = (T>=43200) ? 1 : 0;

    return sm + sh - cross;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int dep_time = h1*3600 + m1*60 + s1;
    int arr_time = h2*3600 + m2*60 + s2;
    
    int answer = getCnt(arr_time) - getCnt(dep_time);

    if(dep_time * 59 % 3600 == 0 || dep_time * 719 % 43200 == 0)
    {
        answer++;
    }

    return answer;
}