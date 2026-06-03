#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) 
{ 
    //먼저 떠오른 방법: 큐
    //queue<int> q1(deque<int>{1,2,3,4,5});
    //...
    
    //추천: 배열 이용 --> %연산자 사용
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2,1,2,3,2,4,2,5};
    vector<int> arr3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> score(3, 0);
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == arr1[i % arr1.size()]) score[0]++;
        if(answers[i] == arr2[i % arr2.size()]) score[1]++;
        if(answers[i] == arr3[i % arr3.size()]) score[2]++;
    }
    
    vector<int> answer;
    //초안: 첫for문에서 최댓값 찾기 --> 다음for문에서 최댓값과 똑같으면 추가
    //대안: 한번만 순회하면서 최댓값(최솟값)찾기
    //i) max_element
    int max_score1 = *(max_element(score.begin(), score.end()));
    for(int i=0; i<3; i++)
    {
        if(score[i] == max_score1)
        {
            answer.push_back(i+1);
        }
    }
    return answer;
    //ii) clear()
    int max_score2 = -1;
    for(int i=0; i<3; i++)
    {
        if(score[i] > max_score2)
        {
            max_score2 = score[i];
            answer.clear();
            answer.push_back(i+1);
        }
        else if(score[i] == max_score2)
        {
            answer.push_back(i+1);
        }
    }
    return answer;
}