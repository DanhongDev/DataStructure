#include <string>
#include <vector>
#include <algorithm>
#include <cctype> //toupper()사용
#include <list>
#include <unordered_map>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if(cacheSize == 0)
    {
        return cities.size() * 5;
    }

    int answer = 0;

    //cache 생성 (0번부터 LRU)
    vector<string> cache;
    cache.reserve(30);
    
    for(int i=0; i<cities.size(); i++)
    {
        //대소문자 통일
        for(char& c : cities[i])
        {
            c = toupper(c);
        }

        //도시가 이미 있는 경우(cache_hit)
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if(it != cache.end())
        {
            answer += 1;
            cache.erase(it);
            cache.push_back(cities[i]);
        }
        //도시가 없는 경우(cache_miss)
        else
        {
            answer += 5;
            if(cache.size() == cacheSize)
            {
                //0번(LRU) 삭제
                cache.erase(cache.begin(), cache.begin()+1);
            }
            cache.push_back(cities[i]);
        }
    }
    
    return answer;
}

//std::list 사용해보기
void List()
{
    list<string> cache;

    // 1. 데이터 추가 (맨 앞, 맨 뒤)
    cache.push_front("Seoul");
    cache.push_back("Jeju");

    // 2. 데이터 확인 (맨 앞, 맨 뒤의 '값'만 읽어옴)
    string mru = cache.front(); //Seoul
    string lru = cache.back(); //Jeju

    // 3. 데이터 삭제 (맨 앞, 맨 뒤)
    cache.pop_front();
    cache.pop_back();
}
//list와 unordered_map 섞기
void Mix()
{
    list<string> cache;
    //Key: 도시 이름
    //Value: 그 도시가 List에서 어디에 있는지 가리키는 포인터(iterator)
    unordered_map<string, list<string>::iterator> map;

    //중간 데이터 삭제 및 이동
        //i) 지우고 다시 넣기(erase & push_front): 맨 앞이 MRU
        auto it = map["Seoul"];

        cache.erase(it);
        cache.push_front("Seoul");
        map["Seoul"] = cache.begin();

        //ii) list 안의 splice 사용
        //cache.splie(어디로 옮기는지, 어느 리스트에서, 어떤 노드를)
        cache.splice(cache.begin(), cache, it);
}

//리스트를 이용한 솔루션
int Listsolution(int cacheSize, vector<string> cities)
{
    if(cacheSize == 0)
    {
        return cities.size() * 5;
    }
    
    list<string> cache;
    unordered_map<string, list<string>::iterator> map;
    int answer = 0;

    for(int i=0; i<cities.size(); i++)
    {
        //대소문자 통일
        for(char &c : cities[i])
        {
            c = toupper(c);
        }

        //Cache_Hit
        if(map.find(cities[i]) != map.end())
        {
            answer += 1;
            //it: map에 저장되어 있는 list의 iterator
            auto it = map[cities[i]];
            cache.splice(cache.begin(), cache, it);
        }
        //Cache_Miss
        else
        {
            answer += 5;
            if(cache.size() == cacheSize)
            {
                //맨 뒤(LRU) 도시 이름 가져오기
                string lru = cache.back();

                //맨 뒤에서 삭제
                cache.pop_back();
                map.erase(lru);
            }

            //맨 앞에 다시 push후 주소값 갱신
            cache.push_front(cities[i]);
            map[cities[i]] = cache.begin();
        }
    }

    return answer;
}