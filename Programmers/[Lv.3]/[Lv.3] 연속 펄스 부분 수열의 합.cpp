#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence)
{
    if(sequence.size() == 1)
    {
        return max(sequence[0], -sequence[0]);
    }
    long long answer = 0;

    vector<long long> s1(sequence.size(), 0);
    vector<long long> s2(sequence.size(), 0);
    
    int pulse = 1;
    for(int i=0; i<s1.size(); i++)
    {
        s1[i] = pulse * sequence[i];
        pulse *= -1;
        s2[i] = pulse * sequence[i];
    }

    vector<long long> dp1(s1.size(), 0);
    vector<long long> dp2(s2.size(), 0);
    dp1[0] = s1[0], dp2[0] = s2[0];

    for(int i=1; i<s1.size(); i++)
    {
        dp1[i] = max(s1[i], dp1[i-1] + s1[i]);
        dp2[i] = max(s2[i], dp2[i-1] + s2[i]);

        long long max_val = max(dp1[i], dp2[i]);
        answer = max(answer, max_val);
    }
    
    return answer;
}