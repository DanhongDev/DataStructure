#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int r1, int r2)
{
    long long answer = 0;
    
    for(int x=1; x<=r2; x++)
    {
        long long max_y = floor(sqrt((long long)r2 * r2 - x * x));

        long long min_y = 0;
        if(x < r1)
        {
            min_y = ceil(sqrt((long long)r1 * r1 - x * x));
        }

        answer += (max_y - min_y + 1); 
    }

    return answer * 4;
}