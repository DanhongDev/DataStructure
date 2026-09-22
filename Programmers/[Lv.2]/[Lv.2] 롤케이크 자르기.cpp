#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    unordered_set<int> s1; //형
    unordered_map<int, int> s2; //동생
    for(int i=0; i<topping.size(); i++)
    {
        s2[topping[i]]++;
    }

    for(int i=0; i<topping.size(); i++)
    {
        s2[topping[i]]--;
        if(s2[topping[i]] == 0)
        {
            s2.erase(topping[i]);
        }
        s1.insert(topping[i]);

        if(s1.size() == s2.size())
        {
            answer++;
        }
    }

    return answer;
}