// #include <string>
// #include <vector>

// using namespace std;

// void Hanoi(int n, int from, int by, int to, vector<vector<int>> &answer)
// {
//     if(n==1)
//     {
//         answer.push_back({from, to});
//         return;
//     }

//     //i) n-1개의 원판을 경유지(by)로 치워둔다. 이때 목적지는 by, 경유지는 to가 된다.
//     Hanoi(n-1, from, to, by, answer);

//     //ii) 맨 밑에 남은 1개의 가장 큰 원판을 목적지(to)로 옮긴다.
//     answer.push_back({from, to});

//     //iii) 경유지(by)에 치워두었던 n-1개의 원판을 다시 목적지(to)로 옮긴다.
//     Hanoi(n-1, by, from, to, answer);
// }

// vector<vector<int>> solution(int n)
// {
//     vector<vector<int>> answer;
//     Hanoi(n, 1, 2, 3, answer);
//     return answer;
// }

#include <iostream>

using namespace std;

// from: 출발지, by: 경유지, to: 목적지
void hanoi(int n, int from, int by, int to) {
    if (n == 1) {
        cout << from << "번 기둥에 있는 [원판 1]을(를) " << to << "번 기둥으로 이동\n";
        return;
    }
    
    // 1단계: n-1개의 원판을 2번(by) 기둥으로 치우기
    hanoi(n - 1, from, to, by);
    
    // 2단계: 맨 밑의 가장 큰 원판을 3번(to) 기둥으로 옮기기
    cout << from << "번 기둥에 있는 [원판 " << n << "]을(를) " << to << "번 기둥으로 이동\n";
    
    // 3단계: 치워뒀던 n-1개의 원판을 다시 3번(to) 기둥으로 덮기
    hanoi(n - 1, by, from, to);
}

int main() {
    int n = 3; // 원판의 개수를 3개로 설정
    cout << "=== 원판 " << n << "개 하노이의 탑 이동 순서 ===\n";
    
    // 1번 기둥에서 2번 기둥을 거쳐 3번 기둥으로 옮긴다.
    hanoi(n, 1, 2, 3); 
    
    return 0;
}