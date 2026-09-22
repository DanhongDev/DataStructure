#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> Lothar(int k)
{
    vector<int> seq;
    while(k != 1)
    {
        seq.push_back(k);
        
        if(k%2==0) k /= 2;
        else k = k*3 + 1;
    }
    seq.push_back(k);

    return seq;
}
vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<int> seq = Lothar(k); //로타르 계산
    int n = seq.size() - 1; //계산 횟수
    vector<double> pre_sum(n+1, 0.0); //누적 합 구하기 (a~b구간은 b-a로 구할 수 있다.)
    
    for(int i=0; i<n; i++)
    {
        double cur = min(seq[i],seq[i+1]) + abs(seq[i] - seq[i+1]) / 2.0;
        pre_sum[i+1] = pre_sum[i] + cur;
    }
    
    vector<double> answer;
    for(vector<int> r : ranges)
    {
        int a = r[0], b = r[1];
        b += n; //끝점 수정

        //시작점이 끝점보다 클 경우 유효하지 않은 구간
        if(a > b)
        {
            answer.push_back(-1.0);
            continue;
        }

        //반복문 없이 누적합 배열 이용
        answer.push_back(pre_sum[b] - pre_sum[a]);
    }
    return answer;
}