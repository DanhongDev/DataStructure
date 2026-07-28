#include <string>
#include <vector>

using namespace std;

//일의 자리도 올라가는게 유리하다면 십의자리, 백의자리도 올라가는게 유리할 수 있다.
//그것을 고려하지 못헀다.

int solution(int storey)
{
    int answer = 0;
    
    while(storey > 0)
    {
        int n = storey % 10;
        storey /= 10;
        
        if(n > 5)
        {
            answer += 10-n;
            storey++;
        }
        else if(n==5)
        {
            answer += 5;
            if(storey % 10 >= 5)
            {
                storey++;
            }
        }
        else
        {
            answer += n;
        }
    }

    return answer;
}