#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS_Target(int depth, const vector<vector<int>> &t_dice, int &cur, vector<int> &targets)
{
    if(depth == t_dice.size())
    {
        targets.push_back(cur);
        return;
    }

    for(int j=0; j<t_dice[depth].size(); j++)
    {
        cur += t_dice[depth][j];
        DFS_Target(depth+1, t_dice, cur, targets);
        cur -= t_dice[depth][j];
    }
}
void DFS(int depth, const vector<vector<int>> &dice, vector<int> &choice, int &max_cnt, vector<int> &answer)
{
    // 조합이 끝났으면
    if(choice.size() == dice.size()/2)
    {
        // 주사위 만들고
        vector<vector<int>> a_dice, b_dice;
        int idx=0;
        for(int i=0; i<dice.size(); i++)
        {
            if(idx<choice.size() && choice[idx] == i)
            {
                a_dice.push_back(dice[i]);
                idx++;
            }
            else b_dice.push_back(dice[i]);
        }

        int cur = 0;
        vector<int> a_score, b_score;
        DFS_Target(0, a_dice, cur, a_score);
        cur = 0;
        DFS_Target(0, b_dice, cur, b_score);
        
        sort(b_score.begin(), b_score.end());
        int cnt = 0;
        for(int i=0; i<a_score.size(); i++)
        {
            auto it = lower_bound(b_score.begin(), b_score.end(), a_score[i]);
            cnt += it - b_score.begin();
        }

        if(cnt > max_cnt)
        {
            max_cnt = cnt;

            int idx = 0;
            for(auto &c : choice) answer[idx++] = c+1;
        }
        return;
    }

    // 주사위 조합을 고르는 경우의 수
    for(int i=depth; i<dice.size(); i++)
    {
        choice.push_back(i);
        DFS(i+1, dice, choice, max_cnt, answer);
        choice.pop_back(i);
    }

    return;
}
vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer(dice.size()/2, 0);
    vector<int> choice;
    int max_cnt = 0;
    DFS(0, dice, choice, max_cnt, answer);

    sort(answer.begin(), answer.end());
    return answer;
}