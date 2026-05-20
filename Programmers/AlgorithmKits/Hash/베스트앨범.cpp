#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    //genres와 plays를 옮겨 담을 map을 생성.
        unordered_map<string, vector<pair<int, int>>> album;
        for(int i=0; i<genres.size(); i++)
        {
            album[genres[i]].push_back({i,plays[i]});
        }

    //1번 조건 (속한 노래가 많이 재생된 장르를 먼저 수록)
        //먼저 각 장르별로 재생횟수를 합친 컨테이너(sum_plays) 생성
        unordered_map<string, int> sum_plays;
        for(int i=0; i<genres.size(); i++)
        {
            sum_plays[genres[i]] += plays[i];
        }
        //재생 횟수가 많은 순으로 장르를 정렬하고 담을 벡터(cond_1) 생성
        vector<pair<string, int>> cond_1(sum_plays.begin(), sum_plays.end());
        //정렬
        sort(cond_1.begin(), cond_1.end(), [](const pair<string, int>& a, const pair<string, int>& b) {return a.second > b.second;});

    //2번 조건 (장르 내에서 많이 재생된 노래를 먼저 수록)
    //3번 조건 (장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록)
        //앞에서 만든 cond_1를 이용하여 2, 3번 조건에 맞춰 정렬
        for(int i=0; i<cond_1.size(); i++)
        {
            //cond_1에서 장르 가져오기
            string name = cond_1[i].first;

            //정렬
            sort(album[name].begin(), album[name].end(), [](const pair<int, int>& a, const pair<int, int>& b)
            {
                //3번 조건
                if(a.second == b.second)
                {
                    return a.first < b.first;
                }
                //2번 조건
                return a.second > b.second;
            });

            //베스트 앨범에 2개씩 넣기 (answer에 앞에 2개씩 인덱스 넣기)
                //i
                    for(int j=0; j<2 && j<album[name].size(); j++)
                    {
                        answer.push_back(album[name][j].first);
                    }
                //ii
                    //int size = min(2, (int)album[name].size());
                    //for(int j=0; j<size; j++)
                    //{
                    //    answer.push_back(album[name][j].first);
                    //}
        }
    
    return answer;
}