#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//sort의 cmp함수 인자는 2개만 있어야 하나 col까지 있어 3개가  있다. --> 고로 람다식을 이용한 cmp를 만들어줘야한다.
//bool cmp(const vector<int> &a, const vector<int> &b, int col)
//{
//    if(a[col] == b[col])
//    {
//        return a[0] > b[0];
//    }
//    return a[col] < b[col];
//}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    sort(data.begin(), data.end(), [col](const vector<int> &a, const vector<int> &b){
        if(a[col-1] == b[col-1])
        {
            return a[0] > b[0];
        }
        return a[col-1] < b[col-1];
    });
    
    vector<int> S_i;
    for(int i=row_begin; i<=row_end; i++)
    {
        int sum = 0;
        for(int x : data[i-1])
        {
            sum += x%i;
        }
        S_i.push_back(sum);
    }
    
    int answer = S_i[0];
    for(int i=1; i<S_i.size(); i++)
    {
        answer = answer ^ S_i[i];
    }
    return answer;
}