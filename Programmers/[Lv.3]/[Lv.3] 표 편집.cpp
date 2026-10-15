#include <string>
#include <vector>
#include <stack>
using namespace std;

// string mysolution(int n, int k, vector<string> cmd)
// {
//     map <int, bool> graph;
//     for(int i=0; i<n; i++) graph.insert({i, true});
//     stack<int> del; // 삭제한 행의 인덱스 보관
//
//     int cur = k;
//
//     for(string c : cmd)
//     {
//         if(c[0] == 'U') cur -= (c[2]-'0');
//         else if(c[0] == 'D') cur += (c[2]-'0');
//         else if(c[0] == 'C')
//         {
//             auto it = next(graph.begin(), cur)->first;
//             graph.erase(it);
//             del.push(it);
//          
//             if(cur == graph.size()) cur--;
//         }
//         else if(c[0] == 'Z')
//         {
//             int undo = del.top();
//             graph.insert({undo, true});
//             del.pop();
//
//             if(undo <= cur) cur++;
//         }
//     }
//    
//     //undo("Z")되지 못한 애들은 삭제된 애들이므로 false로 삽입
//     while(!del.empty())
//     {
//         int last = del.top();
//         graph.insert({last, false});
//         del.pop();
//     }
//
//     //graph 순회하면서 answer완성
//     string answer = "";
//     for(const auto &g : graph)
//     {
//         if(g.second == true) answer += "O";
//         else answer += "X";
//     }
//     return answer;
// }

string solution(int n, int k, vector<string> cmd)
{
    vector<int> pre(n), next(n);
    for(int i=0; i<n; i++)
    {
        pre[i] = i-1;
        next[i] = i+1;
    }
    stack<int> del;
    int cur = k;

    for(string c : cmd)
    {
        if(c[0] == 'U')
        {
            int x = stoi(c.substr(2));
            while(x--) cur = pre[cur];
        }
        else if(c[0] == 'D')
        {
            int x = stoi(c.substr(2));
            while(x--) cur = next[cur];
        }
        else if(c[0] == 'C')
        {
            del.push(cur);

            if(next[cur] != n) pre[next[cur]] = pre[cur]; // 내 뒷사람의 앞사람을 내 앞사람으로 연결
            if(pre[cur] != -1) next[pre[cur]] = next[cur]; // 내 앞사람의 뒷사람을 내 뒷사람으로 연결

            if(next[cur] == n) cur = pre[cur];
            else cur = next[cur];
        }
        else if(c[0] == 'Z')
        {
            int undo = del.top();
            del.pop();

            if(next[undo] != n) pre[next[undo]] = undo; //내 뒷사람의 앞사람을 다시 '나'로 연결
            if(pre[undo] != -1) next[pre[undo]] = undo; //내 앞사람의 뒷사람을 다시 '나'로 연결
        }
    }

    string answer(n, 'O');
    while(!del.empty())
    {
        answer[del.top()] = 'X';
        del.pop();
    }
    return answer;
}

int main()
{
    // string answer = solution(8, 2, {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"});
    string answer = solution(8, 2, {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"});

    return 0;
}