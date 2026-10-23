#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string toBinary(long long &n) // 십진수를 이진수로 변환
{
    string str = "";
    while(n>0)
    {
        str += to_string(n%2);
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
void supple(string &str) // 더미 데이터(0)으로 자릿 수 맞추기
{
    long long len = str.size();
    long long n = 0;
    int h=0;
    while(len > n)
    {
        n = pow(2, h) - 1;
        h++;
    }

    int diff = n-len;
    string temp = "";
    for(int i=0; i<diff; i++)
    {
        temp += "0";
    }

    str = temp + str;
}
void DV(const string &bin, int left, int right, bool &is_poss)
{
    if(left == right) return; // 가지치기: 1칸일 경우 보지말고 바로 리턴

    int mid = (left + right) / 2; // 해당 분할에서의 부모 노드

    // 해당 분할이 마지막 분할 즉 길이가 3이라면 파악.
        // --> 길이가 3일때만 해당하는 것이 아닌 모든 분할에서의 부모 자식노드를 살펴봐야 함.
    int l_c = (left + (mid-1) ) / 2;
    int r_c = ((mid+1) + right) / 2;
    if(bin[mid]=='0' && (bin[l_c]=='1' || bin[r_c]=='1'))
    {
        is_poss = false;
        return;
    }

    if(is_poss && left<right)
    {    
        DV(bin, left, mid-1, is_poss);
        DV(bin, mid+1, right, is_poss);
    }
}
vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for(long long n : numbers)
    {
        // 가지치기
        if(n<=3) 
        {
            answer.push_back(1);
            continue;
        }

        string bin = toBinary(n);
        supple(bin);

        // 분할 정복
        bool is_poss = true;
        DV(bin, 0, bin.size()-1, is_poss);

        if(is_poss) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}