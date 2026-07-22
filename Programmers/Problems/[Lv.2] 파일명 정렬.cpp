#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool cmp(const vector<string> &a, const vector<string> &b)
{
    //정렬할때 대소문자 통일 후 비교하기
    string a_head = "", b_head = "";
    for(char c : a[0]) a_head += tolower(c);
    for(char c : b[0]) b_head += tolower(c);
    
    //num을 정수형으로 변환
    int a_num = stoi(a[1]);
    int b_num = stoi(b[1]);

    //head순으로 정렬
    if(a_head != b_head)
    {
        return a_head < b_head;
    }
    //num순으로 정렬
    return a_num < b_num;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<vector<string>> dict; //[0]: head, [1]: num, [2]: tail

    for(string f : files)
    {
        string head = "", num = "", tail = "";
        bool end_head = false, end_num = false;

        for(int i=0; i<f.size(); i++)
        {
            if(!end_head && !isdigit(f[i]))
            {
                head += f[i];
            }
            else if(!end_num && isdigit(f[i]) && num.size() < 5)
            {
                end_head = true;
                num += f[i];
            }
            else
            {
                end_num = true;
                tail += f[i];
            }
        }

        dict.push_back({head, num, tail});
    }
    
    //문제의 조건에 맞게 정렬
    stable_sort(dict.begin(), dict.end(), cmp);

    for(int i=0; i<dict.size(); i++)
    {
        answer.push_back(dict[i][0] + dict[i][1] + dict[i][2]);
    }

    return answer;
}