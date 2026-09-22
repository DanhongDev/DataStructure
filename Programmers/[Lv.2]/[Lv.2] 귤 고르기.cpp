#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(int &a, int &b)
{
    return a > b;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;

    //카운트정렬
    //vector<int> arr(10000000, 0);
    //for(int t : tangerine)
    //{
    //    arr[t]++;
    //}
    ////내림차순 정렬
    //sort(arr.begin(), arr.end(), cmp);
    //for(int i=0; i<arr.size(); i++)
    //{
    //    k -= arr[i];
    //    answer++;
    //    if(k <= 0) break;
    //}
    
    //map이용
    unordered_map<int,int> m;
    for(int i=0; i<tangerine.size(); i++)
    {
        m[tangerine[i]]++;
    }

    vector<int> freq;
    for(auto &p : m)
    {
        freq.push_back(p.second);
    }

    //greater<int>() 를 쓰면 cmp함수 만들 필요가 없다.
    sort(freq.begin(), freq.end(), greater<int>());

    for(int i=0; i<freq.size(); i++)
    {
        k -= freq[i];
        answer++;
        if(k <= 0) break;
    }

    return answer;
}