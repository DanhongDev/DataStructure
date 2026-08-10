#include <string>
#include <vector>
#include <algorithm> //std::max
#include <cctype> //isdigit
#include <cmath> //abs()
using namespace std;

long long max_val = 0;
void DFS(vector<long long> numbers, vector<char> symbols, string &order, vector<bool> &visited)
{
    //종료 조건: 계산이 완료됐다면 max값 갱신후 return;
    if(symbols.empty())
    {
        //4. DFS속에서 최댓값 계속 갱신해주기.
        max_val = max(max_val, abs(numbers[0]));
        return;
    }

    for(int i=0; i<order.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;

            //원본을 건드려선 안된다.
            vector<long long> temp_nums = numbers;
            vector<char> temp_syms = symbols;

            int j=0;
            while(j< temp_syms.size())
            {
                if(temp_syms[j] == order[i])
                {
                    if(order[i] == '+') temp_nums[j] += temp_nums[j+1];
                    else if(order[i] == '-') temp_nums[j] -= temp_nums[j+1];
                    else if(order[i] == '*') temp_nums[j] *= temp_nums[j+1];

                    temp_nums.erase(temp_nums.begin()+j+1);
                    temp_syms.erase(temp_syms.begin()+j);
                }
                else
                {
                    j++;
                }
            }
            DFS(temp_nums, temp_syms, order, visited);
            visited[i] = false;
        }
    }

}
long long solution(string expression)
{
    //1. 숫자와 수식 기호를 각각 분리하여 배열에 저장
    //2. expression에 나오는 수식 기호들 정리(중복이 안되게)
    vector<long long> numbers;
    vector<char> symbols;
    string order = "";

    string s = "";
    for(char c : expression)
    {
        if(isdigit(c))
        {
            //숫자 만들기
            s += c;
        }
        else //기호라면
        {
            //이어 붙이던 숫자를 numbers에 추가
            numbers.push_back(stoll(s));
            //초기화
            s = "";
            //연산자 배열에 추가
            symbols.push_back(c);
            //연산자 우선순위 배열에 추가
                //find를 쓸까..? 어차피 많아봐야 3개인데
                //음.. 굳이 find해서 expression속 수식 기호가 뭐가 있는지 검사 안해도 될거 같기도 하고..?
                    //어차피 + - * 로 정해져 있으니까 고정값(3) 줘도 되지 않을까?? DFS에서 알아서 거를거 같기도 하고...
            if(order.find(c) == string::npos)
            {
                order += c;
            }
        }
    }
    //마지막 숫자 넣기
    numbers.push_back(stoll(s));

    //3. visted 배열 + DFS로 경우의 수 다 계산하기.
    vector<bool> visited(order.size() ,false);
    DFS(numbers, symbols, order, visited);

    return max_val;
}