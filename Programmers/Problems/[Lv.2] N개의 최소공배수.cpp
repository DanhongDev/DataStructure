#include <string>
#include <vector>
using namespace std;

int getGCD(int a, int b)
{
    if(b==0) return a;
    return getGCD(b, a%b);
}
int getLCM(int a, int b)
{
    //(a*b) / gcd(a,b)를 하면 오버플로우가 날 수 있다.
    return (a / getGCD(a,b)) * b;
}
int solution(vector<int> arr) 
{
    //AxB = GCD(A, B) * LCM(A, B)
    if(arr.size() == 1) return arr[0];
    
    int LCM = arr[0];
    
    for(int i=1; i<arr.size(); i++)
    {
        LCM = getLCM(LCM, arr[i]);
    }
    
    return LCM;
}

//STL 이용 (C++ 17이상)
//#include <numeric>
//int Gesolution(vector<int> arr)
//{
//    if(arr.size() == 1) return arr[0];
//
//    int LCM = arr[0];
//
//    for(int i=1; i<arr.size(); i++)
//    {
//        LCM = lcm(LCM, arr[i]);
//    }
//}