#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    //find를 쓰기 위해 set생성
    unordered_set<char> set;
    for(int i=0; i<skill.size(); i++)
    {
        set.insert(skill[i]);
    }

    vector<queue<char>> trees;
    for(string tree : skill_trees)
    {
        queue<char> q;
        for(int i=0; i<tree.size(); i++)
        {   
            //set에 있는 스킬들을 find하여 해당하는 스킬이면 큐에 푸시
            if(set.find(tree[i]) != set.end())
            {
                q.push(tree[i]);
            }
        }
        trees.push_back(q);
    }

    for(queue<char> route : trees)
    {
        int idx = 0; //skill을 탐색하기 위한 인덱스
        bool unorder = false;
        while(!route.empty())
        {
            if(route.front() != skill[idx])
            {
                unorder = true;
                break;
            }
            route.pop();
            idx++;
        }

        if(!unorder)
        {
            answer++;
        }
    }

    return answer;
}

//i) tree[i] = ' '; --> 효과적이지 못함
//ii) tree.erase(tree.begin()+i, tree.begin()+i+1); --> 인덱스가 꼬여버림
//iii) queue로 이동 후 front()끼리 비교

int Gesolution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for(string tree : skill_trees)
    {
        int idx = 0;
        bool possible = true;

        for(char c : tree)
        {
            if(skill.find(c) != string::npos)
            {
                if(c == skill[idx])
                {
                    idx++;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
        }

        if(possible)
        {
            answer++;
        }
    }
}