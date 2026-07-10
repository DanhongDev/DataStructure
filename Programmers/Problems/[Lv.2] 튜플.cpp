#include <string>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp1(const unordered_set<int> &a, const unordered_set<int> &b)
{
    return a.size() < b.size();
}
vector<int> solution(string s)
{
    vector<int> answer;

    //각 집합을 set에 담아서 정리하기
    vector<unordered_set<int>> tuple;
    unordered_set<int> u;
    string num = "";
    for(int i=1; i<s.size()-1; i++)
    {
        //해당 코드는 1의자리의 숫자만 처리 가능 함.
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            num += s[i];
            //u.insert(s[i]-'0');
        }

        if(s[i] == ',')
        {
            if(num.size() != 0)
            {
                u.insert(stoi(num));
                num = "";
            }
        }
        else if(s[i] == '}')
        {
            if(!num.empty())
            {
                u.insert(stoi(num));
                num = "";
            }
            tuple.push_back(u);
            u.clear();
        }
    }
    
    //set의 크기별로 먼저 정렬
    sort(tuple.begin(), tuple.end(), cmp1);
    //이미 넣은 숫자인지 판별
    unordered_set<int> visited;

    //크기가 1인 set부터 중복된 숫자 거르면서 answer에 push_back해주기.
    for(unordered_set<int> &cur_set : tuple)
    {
        for(int number : cur_set)
        {
            if(visited.find(number) == visited.end())
            {
                answer.push_back(number);
                visited.insert(number);
            }
        }
    }
    return answer;
}


//map으로 빈도수 체크
//빈도수가 높은순으로 적은 자릿수 이므로 차례대로 push_back만 하면 끝
bool cmp2(pair<int,int> &a, pair<int,int> &b)
{
    return a.second > b.second;
}
vector<int> Gesolution(string s)
{
    vector<int> answer;

    unordered_map<int, int> m;
    string num = "";

    for(int i=0; i<s.size(); i++)
    {
        if(0<=s[i]-'0' && s[i]-'0'<=9)
        {
            num += s[i];
        }
        else
        {
            if(!num.empty())
            {
                m[stoi(num)]++;
                num = "";
            }
        }
    }

    vector<pair<int,int>> fre(m.begin(), m.end());
    sort(fre.begin(), fre.end(), cmp2);

    for(int i=0; i<fre.size(); i++)
    {
        answer.push_back(fre[i].first);
    }

    return answer;
}