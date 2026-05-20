#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    //옷 종류의 수를 저장할 map
    unordered_map<string, int> list;
    //map에 삽입
    for(int i=0; i<clothes.size(); i++)
    {
        list[clothes[i][1]]++;
    }

    //경우의 수 구하기
    for(const auto& [clothes, cnt] : list)
    {
        answer *= (cnt + 1);
    }
    answer -= 1;

    return answer;
}