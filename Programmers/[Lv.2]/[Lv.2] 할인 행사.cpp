#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    //장바구니 만들기
    vector<pair<string,int>> cart;
    for(int i=0; i<want.size(); i++)
    {
        cart.push_back({want[i], number[i]});
    }
    
    for(int i=0; i<discount.size(); i++)
    {
        //할인 목록
        unordered_map<string, int> dis;
        for(int j=i; j<i+10 && i+10<=discount.size(); j++)
        {
            dis[discount[j]]++;
        }

        bool is_matched = true;
        for(int i=0; i<cart.size(); i++)
        {
            //한 품목이라도 일치하지 않으면
            
            if(dis[cart[i].first] != cart[i].second)
            {
                //변수 조정 후
                is_matched = false;
                //중단
                break;
            }
        }
        if(is_matched)
        {
            answer++;
        }
    }
    
    return answer;
}

int Gesolution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> cart;

    //첫 10일 설정
    for(int i=0; i<10; i++)
    {
        cart[discount[i]]++;
    }
    //첫 10일 일치 여부 확인
    bool is_matched = true;
    for(int i=0; i<want.size(); i++)
    {
        if(cart[want[i]] != number[i])
        {
            is_matched = false;
            break;
        }
    }
    if(is_matched) answer++;

    //투포인터 시작
    for(int i=10; i<discount.size(); i++)
    {
        //빠지는 맨 앞 날짜 품목 삭제
        cart[discount[i-10]]--;
        //새로 들어오는 맨 뒤 날짜 품목 추가
        cart[discount[i]]++;

        is_matched = true;
        for(int i=0; i<want.size(); i++)
        {
            if(cart[want[i]] != number[i])
            {
                is_matched = false;
                break;
            }
        }
        if(is_matched) answer++;
    }

    return answer;
}