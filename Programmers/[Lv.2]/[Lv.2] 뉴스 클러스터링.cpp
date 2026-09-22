#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int STLsolution(string str1, string str2)
{
    for(int i=0; i<str1.size(); i++) str1[i] = toupper(str1[i]);
    for(int i=0; i<str2.size(); i++) str2[i] = toupper(str2[i]);

    vector<string> set1;
    for(int i=0; i<str1.size()-1; i++)
    {
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;

        set1.push_back(str1.substr(i, 2));
    }
    vector<string> set2;
    for(int i=0; i<str2.size()-1; i++)
    {
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;

        set2.push_back(str2.substr(i, 2));
    }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    vector<string> inter_set;
    vector<string> union_set;

    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(inter_set));
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(union_set));

    if(inter_set.size() == 0 && union_set.size() == 0) return 65536;
    float j = (float)inter_set.size() / union_set.size();
    return (int)(j * 65536);
}

int solution(string str1, string str2)
{
    for(int i=0; i<str1.size(); i++) str1[i] = toupper(str1[i]);
    for(int i=0; i<str2.size(); i++) str2[i] = toupper(str2[i]);

    unordered_map<string, int> set1;
    for(int i=0; i<str1.size()-1; i++)
    {
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) 
        {
            continue;
        }
        set1[str1.substr(i, 2)]++;
    }
    unordered_map<string, int> set2;
    for(int i=0; i<str2.size()-1; i++)
    {
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) 
        {
            continue;
        }
        set2[str2.substr(i, 2)]++;
    }
    
    //교집합, 합집합 생성
    unordered_map<string, int> inter;
    unordered_map<string, int> uni;
    for(auto &e : set1) //혹은 pair<const string, int> &e (pair<string, int> &e 는 안된다.)
    {
        int set1_cnt = e.second;
        int set2_cnt = 0;
        if(set2.find(e.first) != set2.end())
        {
            set2_cnt = set2[e.first];
        }

        inter[e.first] = min(set1_cnt, set2_cnt);
        uni[e.first] = max(set1_cnt, set2_cnt);
    }
    //set2속 나머지 원소들 합집합에 추가
    for(auto &e : set2)
    {
        int cnt = e.second;
        if(set1.find(e.first) == set1.end())
        {
            uni[e.first] = cnt;
        }
    }
    int inter_size = 0;
    for(auto &e : inter)
    {
        inter_size += e.second;
    }
    int union_size = 0;
    for(auto &e : uni)
    {
        union_size += e.second;
    }

    //ii) 교집합 합집합의 map을 만들지 말고 바로 변수로 이용하기
    //int inter_size = 0;
    //int union_size = 0;
    //for(auto &e : set1)
    //{
    //    int set1_cnt = e.second;
    //    int set2_cnt = 0;
    //    if(set2.find(e.first) != set2.end())
    //    {
    //        set2_cnt = set2[e.first];
    //    }
    //    inter_size += min(set1_cnt, set2_cnt);
    //    union_size += max(set1_cnt, set2_cnt);
    //}
    //for(auto &e : set2)
    //{
    //    int set2_cnt = e.second;
    //    if(set1.find(e.first) == set1.end())
    //    {
    //        union_size += set2_cnt;
    //    }
    //}

    if(inter.size() == 0 && uni.size() == 0) return 65536;
    float j = (float)inter.size() / uni.size();
    return (int)(j * 65536);
}

