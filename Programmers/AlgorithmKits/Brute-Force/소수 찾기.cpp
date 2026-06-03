#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

set<int> s;
vector<bool> visited;
//백트래킹
void dfs(const string &numbers, string cur)
{
    //cur가 비어있지 않다면
    if(!cur.empty())
    {
        //stoi로 정수로 변환 후
        int temp = stoi(cur);
        //소수 판별하고
        if(isPrime(temp))
        {
            //set에 추가
            s.insert(temp);
        }
    }

    //중복된 값 가지치기
    bool used[10] = {false};

    //재귀 속 for문(백트래킹의 정석)
        for(int i=0; i<numbers.length(); i++)
        {
            //문자를 정수로 변환: c - '0'
            int cur_num = numbers[i] - '0';

            //사용하고 있지 않다면 && 현재 깊이에서 사용한 숫자가 아니라면
            if(!visited[i] && !used[cur_num])
            {
                //현재 숫자 사용하고 있다고 처리
                used[cur_num] = true;

                //사용하고 있는 인덱스 true처리
                visited[i] = true;
                //재귀
                dfs(numbers, cur + numbers[i]);
                //사용한 후의 인덱스 false처리
                visited[i] = false;
            }
        }
}

int solution(string numbers) 
{
    visited.assign(numbers.size(), false);
    dfs(numbers, "");

    return s.size();

    //next_permutation 사용
    // 1. 반드시 먼저 오름차순 정렬!!!
    sort(numbers.begin(), numbers.end());

    // 2. do-while문으로 모든 순열 탐색
    do
    {
        // 3. 만들어진 전체 순열에서 길이 1부터 전체 길이까지 잘라서 숫자로 변환
        // 예시: number가 "101"이라면
        // i=1: "1", i=2: "10", i=3: "101"을 추출
        for(int i=1; i<=numbers.length(); i++)
        {
            string temp = numbers.substr(0, i);
            if(isPrime(stoi(temp)))
            {
                s.insert(stoi(temp));
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
}

