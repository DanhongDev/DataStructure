#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return a+b > b+a;
}
string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> str_numbers;
    for(int i : numbers)
    {
        str_numbers.push_back(to_string(i));
    }
    
    sort(str_numbers.begin(), str_numbers.end(), cmp);
    if(str_numbers[0] == "0")
    {
        return "0";
    }

    for(string str : str_numbers)
    {
        answer += str;
    }
    
    return answer;
}
//i) 이거 backtracking 기법 쓰면 안되려나..? --> O(N!)이 될 수 있으므로 탈락
//ii) stoi, itos는 이제 안쓰이는 기법아닐까..? --> 이게 정답이었음...