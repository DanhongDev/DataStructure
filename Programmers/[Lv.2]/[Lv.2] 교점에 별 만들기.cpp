#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    vector<pair<long long,long long>> cood;

    long long m_x = LLONG_MAX, m_y = LLONG_MAX;
    long long p_x = LLONG_MIN, p_y = LLONG_MIN;

    bool once = true;
    for(int i=0; i<line.size()-1; i++)
    {
        for(int j=i+1; j<line.size(); j++)
        {
            long long A=line[i][0], B=line[i][1], E=line[i][2];
            long long C=line[j][0], D=line[j][1], F=line[j][2];

            long long m = A*D - B*C;
            //m==0이면 평행or일치 이므로 패스
            if(m==0) continue;
            
            long long cal_x = B*F - E*D;
            long long cal_y = E*C - A*F;

            //x나 y가 실수라면 패스
                // double을 int형으로 변환 시 소수점이 버려지는것을 이용
                // 실수라면 x - (int)x 하면 0이 나오지 않는다.
                // ex) x가 1.5라면, x - (int)x == 1.5 - 1 == 0.5. 0이 아니므로 실수이다.
            if(cal_x % m != 0 || cal_y % m != 0) continue;

            long long x = cal_x / m;
            long long y = cal_y / m;

            cood.push_back({x, y});

            m_x = min(m_x, x);
            m_y = min(m_y, y);
            p_x = max(p_x, x);
            p_y = max(p_y, y);
        }
    }

    int r_size = (int)(p_y - m_y + 1);
    int c_size = (int)(p_x - m_x + 1);

    vector<vector<char>> board(r_size, vector<char>(c_size, '.'));
    long long base_x = m_x, base_y = p_y;
    for(auto &p : cood)
    {
        board[abs(base_y - p.second)][abs(base_x - p.first)] = '*';
    }
    for(int i=0; i<board.size(); i++)
    {
        string temp = "";
        for(int j=0; j<board[i].size(); j++)
        {
            temp += board[i][j];
        }
        answer.push_back(temp);
    }
    return answer;
}