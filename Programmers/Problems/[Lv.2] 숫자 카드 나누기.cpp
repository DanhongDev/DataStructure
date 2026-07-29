#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int cd(const vector<int> &arrayA, const vector<int> &arrayB, int maxVal)
{
    int num = maxVal;
    while(num > 0)
    {
        bool is_matched = true;
        for(int i=0; i<arrayA.size(); i++)
        {
            if(arrayA[i] % num != 0)
            {
                is_matched = false;
                break;
            }
        }
        if(!is_matched) 
        {
            num--;
            continue;
        }

        for(int i=0; i<arrayB.size(); i++)
        {
            if(arrayB[i] % num == 0)
            {
                is_matched = false;
                break;
            }
        }

        if(is_matched)
        {
            return num;
        }

        num--;
    }
    
    return 0;
}
int solution(vector<int> arrayA, vector<int> arrayB)
{
    int max_A = *(max_element(arrayA.begin(), arrayA.end()));
    int max_B = *(max_element(arrayB.begin(), arrayB.end()));
    int maxVal = max(max_A, max_B);

    int AB = cd(arrayA, arrayB, maxVal);
    int BA = cd(arrayB, arrayA, maxVal);

    return max(AB, BA);
}

int getGCD(const vector<int> &array)
{
    int GCD = array[0];
    for(int i=1; i<array.size(); i++)
    {
        GCD = gcd(GCD, array[i]);
    }
}
int solution(vector<int> arrayA, vector<int> arrayB)
{
    int gcd_A = getGCD(arrayA);
    int gcd_B = getGCD(arrayB);

    bool canA = true;
    for(int b : arrayB)
    {
        if(b%gcd_A == 0)
        {
            canA=false;
            break;
        }
    }

    bool canB = true;
    for(int a : arrayA)
    {
        if(a%gcd_B == 0)
        {
            canB = false;
            break;
        }
    }

    int candA = canA ? gcd_A : 0;
    int candB = canB ? gcd_B : 0;

    return max(candA, candB);
}