#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    answer.reserve(commands.size());

    //for(int l=0; l<commands.size(); l++)
    for(const auto& cmd : commands) //범위 기반 for문 사용하기
    {
        //가독성을 위해 변수로 지정
        int i = cmd[0], j = cmd[1], k = cmd[2];
        //temp배열 선언하는 과정에서 자르기
        vector<int> temp(array.begin() + i-1, array.begin() + j);
        
        sort(temp.begin(), temp.end());
        //전체 정렬 대신 K번째 원소만 찾는 알고리즘 최적화
        nth_element(temp.begin(), temp.begin() + k-1, temp.end());

        answer.push_back(temp[k-1]);
    }
    
    return answer;
}

int main()
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };
    solution(array, commands);

    return 0;
}