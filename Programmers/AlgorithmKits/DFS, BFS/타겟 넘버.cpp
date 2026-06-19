#include <string>
#include <vector>

using namespace std;

int cnt = 0;
void dfs(vector<int>& num, int idx, int cur_num, const int &target)
{
    if(idx == num.size() && cur_num == target)
    {
        cnt++;
        return;
    }
    else if(idx == num.size())
    {
        return;
    }
    dfs(num, idx+1, cur_num+num[idx], target);
    dfs(num, idx+1, cur_num-num[idx], target);
}
int solution(vector<int> numbers, int target) 
{
    dfs(numbers, 0, 0, target);

    return cnt;
}






//Complement
//1. 자료형을 int로 변경하여 경우의 수를 직접 반환
int dfs_com(const vector<int> &num, int idx, int cur_num, const int &target)
{
    if(idx == num.size())
    {
        //현재 계산된 cur_num이 target과 같다면 1(경우의 수 1++), 다르면 0(변화 X)을 return.
        return cur_num == target ? 1 : 0;
    }

    //현재 숫자를 더하는 경우와 빼는 경우의 경우의 수 결과를 합산하여 return.
    return dfs_com(num, idx+1, cur_num + num[idx], target) + dfs_com(num, idx+1, cur_num - num[idx], target);
}
int solution_com(vector<int> numbers, int target)
{
    return dfs_com(numbers, 0, 0, target);
}