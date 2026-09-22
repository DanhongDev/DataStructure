#include <string>
#include <vector>

using namespace std;

int max_regi=0, max_sell=0;
void DFS(const vector<vector<int>> &users, vector<vector<int>> &dis_emo, vector<bool> &visited, vector<int> &purchase, int depth)
{
    //리턴 조건
    if(depth == dis_emo.size())
    {
        int regi=0, sell=0;
        //최댓값 갱신
        for(int i=0; i<users.size(); i++)
        {
            if(purchase[i] >= users[i][1])
            {
                regi++;
            }
            else
            {
                sell += purchase[i];
            }
        }

        if(regi > max_regi)
        {
            max_regi = regi;
            max_sell = sell;
        }
        else if(regi == max_regi)
        {
            max_sell = max(max_sell, sell);
        }

        return;
    }

    for(int j=0; j<4; j++)
    {
        if(!visited[depth])
        {
            visited[depth] = true;
            //현재 할인율이 고객이 원하는 할인율인지 확인하여 배열에 추가
            for(int i=0; i<purchase.size(); i++)
            {
                if((j+1)*10 >= users[i][0])
                {
                    purchase[i] += dis_emo[depth][j];
                }
            }
            DFS(users, dis_emo, visited, purchase, depth+1);
            //현재 할인율에 따른 고객의 구매 복원 (백트래킹)
            for(int i=0; i<purchase.size(); i++)
            {
                if((j+1)*10 >= users[i][0])
                {
                    purchase[i] -= dis_emo[depth][j];
                }
            }
            visited[depth] = false;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    //10% ~ 40% 할인된 금액 한번에 저장
    vector<vector<int>> dis_emo(emoticons.size());
    for(int i=0; i<emoticons.size(); i++)
    {
        int dis = emoticons[i] / 10;
        for(int j=0; j<4; j++)
        {
            dis_emo[i].push_back(emoticons[i] - (dis*(j+1)));
        }
    }

    vector<bool> visited(emoticons.size(), false);
    vector<int> purchase(users.size(), 0);
    DFS(users, dis_emo, visited, purchase, 0);

    return {max_regi, max_sell};
}

int dis_rates[4] = {10, 20, 30 ,40};
void GeDFS(const vector<vector<int>> &users, const vector<int> &emoticons, vector<int> &rates, int depth)
{
    if(depth == emoticons.size())
    {
        int regi=0, sell=0;

        for(const auto &u : users)
        {
            int purchase = 0;
            for(int i=0; i<emoticons.size(); i++)
            {
                if(rates[i] >= u[0])
                {
                    purchase += emoticons[i] * ((100-rates[i])/100);
                }
            }

            if(purchase >= u[1]) regi++;
            else sell += purchase;
        }

        if(regi > max_regi)
        {
            max_regi = regi;
            max_sell = sell;
        }
        else if(regi == max_regi)
        {
            max_sell = max(max_sell, sell);
        }
        return;
    }

    for(int j=0; j<4; j++)
    {
        rates.push_back(dis_rates[j]);
        GeDFS(users, emoticons, rates, depth+1);
        rates.pop_back();
    }
}
vector<int> Gesolution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> rates;
    GeDFS(users, emoticons, rates, 0);
    return {max_regi, max_sell};
}