#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> relation)
{
    int row = relation.size();
    int col = relation[0].size();

    vector<int> ans_keys;

    for(int i=1; i<(1<<col); i++) //1<<col: 1부터 2^col-1 까지의 모든 부분집합 탐색
    {

        // 2. 최소성 검사 (유일성 검사 전에 미리 걸러서 효율성 올리기)
        bool is_min = true;
        for(int key : ans_keys)
        {
            //현재 조합(i) 안에 기존에 찾은 후보키(key)가 온전히 들어있나?
            if((i&key) == key)
            {
                is_min = false;
                break;
            }
        }
        if(!is_min) continue;

        // 3. 유일성 검사
        unordered_set<string> s;
        for(int r=0; r<row; r++)
        {
            string temp = "";

            for(int c=0; c<col; c++)
            {
                if(i & (1 << c))
                {
                    temp += relation[r][c] + ",";
                }
            }
            s.insert(temp);
        }

        // 4. 후보키 등록
        if(s.size() == row)
        {
            ans_keys.push_back(i);
        }
    }
    
    return ans_keys.size();
}