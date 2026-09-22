#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;
    int n = weights.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(weights[i] == weights[j]) answer++;
        }
    }
    sort(weights.begin(), weights.end());

    vector<int> weights_2(n,0), weights_3(n,0), weights_4(n,0);
    for(int i=0; i<n; i++)
    {
        weights_2[i] = weights[i]*2;
        weights_3[i] = weights[i]*3;
        weights_4[i] = weights[i]*4;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;
            if(weights_2[i] < weights_3[j] && weights_2[i] < weights_4[j]) break;
            if(weights_2[i] == weights_3[j] || weights_2[i] == weights_4[j])
            {
                answer++;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;
            if(weights_3[i] < weights_4[j]) break;
            if(weights_3[i] == weights_4[j]) 
            {
                answer++;
            }
        }
    }
    
    return answer;
}

long long Gesolution(vector<int> weights)
{
    long long answer = 0;

    vector<long long> count(1001, 0);
    for(int w : weights)
    {
        count[w]++;
    }

    for(int i=100; i<=1000; i++)
    {
        if(count[i] == 0) continue;

        answer += (count[i] * (count[i] -1)) / 2;

        if(i%2==0 && (i*3/2) <= 1000)
        {
            answer += count[i] * count[i*3/2];
        }

        if(i*2 <= 1000)
        {
            answer += count[i] * count[i*2];
        }

        if(i%3==0 && (i*4/3) <= 1000)
        {
            answer += count[i] * count[i*4/3];
        }
    }

    return answer++;
}