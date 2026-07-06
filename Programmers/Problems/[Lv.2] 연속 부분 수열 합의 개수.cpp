#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int mysolution(vector<int> elements) 
{
    //중복없이 부분 합들을 담을 컨테이너 set
    unordered_set<int> s;

    //1000*1000*1000 = 1e9 라서 삼중for문 해도 될듯??
    //cnt: 더한 횟수
    int sum = 0, cnt = 0;
    //길이 k인 연속 부분 수열
    for(int k=1; k<=elements.size(); k++)
    {
        //기준이 되는 첫 인덱스 i
        for(int i=0; i<elements.size(); i++)
        {
            sum = 0;
            cnt = 0;
            //길이 k만큼 탐색할 인덱스 j
            for(int j=i; j<i+k; j++)
            {
                if(j>=elements.size())
                {
                    j=0;
                }
                sum += elements[j];
                cnt++;
                if(cnt == k) 
                {
                    break;
                }
                //com1: 모듈러 연산(%) 이용하기 --> 필수 스킬이므로 기억해두기
                sum += elements[j % elements.size()];
            }
            s.insert(sum);
        }
    }

    return s.size();
}

int Gesolution(vector<int> elements)
{
    unordered_set<int> s;
    //n: 원본 배열(elements)의 크기 2배한 배열(twice_elements)의 크기가 아니다.
    int n = elements.size();
    
    //2배 배열 만들기
    vector<int> twice_elements(elements);
    //.insert(어디에 넣는지, 무엇을 넣는지(시작점), 무엇을 넣는지(끝점))순이다.
    twice_elements.insert(twice_elements.end(), twice_elements.begin(), twice_elements.end());

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<i+n; j++)
        {
            sum += twice_elements[j];
            s.insert(sum);
        }
    }

    return s.size();
}