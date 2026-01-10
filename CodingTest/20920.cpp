#include<iostream>
#include<map>
#include<algorithm>

bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string ,int>& b)
{
    //1. 자주 나오는 단어일수록
    if(a.second != b.second)
    {
        return a.second > b.second;
    }
    //2. 단어의 길이가 길수록
    if(a.first.length() != b.first.length())
    {
        return a.first.length() > b.first.length();
    }
    //3. 사전 순으로 앞에 있는 단어일수록
    return a.first < b.first;
        
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);


    //i) 흐음.. sort의 조건을 직접 만들어야 하나...? ==> 정답
    //   
    int N, M;
    std::cin >> N >> M;
    
    //1. Map으로 빈도수 카운팅
    std::map<std::string, int> word_map;
    std::string word;
    for(int i=0; i<N; i++)
    {
        std::cin >> word;
        if(word.length() >= M)
        {
            word_map[word]++;
        }
    }

    //2. 정렬을 위해 Vector로 이식
    std::vector<std::pair<std::string, int>> arr;
    for(auto& iter : word_map)
    {
        arr.push_back(iter);
    }

    //3. 사용자 설정 cmp 함수를 통한 sort 진행
    std::sort(arr.begin(), arr.end(), cmp);
    
    //4. 출력
    for(auto& iter : arr)
    {
        std::cout << iter.first << '\n';
    }

    return 0;
}