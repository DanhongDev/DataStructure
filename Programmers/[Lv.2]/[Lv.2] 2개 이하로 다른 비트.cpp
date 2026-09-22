#include <string>
#include <vector>

using namespace std;

//규칙이 있었던 문제였다
vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for(long long num : numbers)
    {
        if(num % 2 == 0)
        {
            answer.push_back(num+1);
            continue;
        }
        
        long long bit = 1;
        while((num&bit) != 0)
        {
            bit <<= 1;
        }

        long long next_num = (num | bit) & ~(bit >> 1);

        answer.push_back(next_num);
    }

    return answer;
}


//__builtin_popcount(n); 를 이용할 수 있는 방법이 있지 않을까??
string ChangeBinary(long long n)
{
    string bin = "";
    while(n>0)
    {
        bin += to_string(n%2);
        n /= 2;
    }
    //reverse(bin.begin(), bin.end()); //자리별로 다른지만 비교하기 때문에 reverse할 필요 없을듯??

    return bin;
}
vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for(long long num : numbers)
    {
        string num_bin = ChangeBinary(num);
        long long bigger = num + 1;

        //시간초과가 난다...
            //num이 long long을 인 만큼 문제에서 최대값인 10^15가 들어간다면
            //그만큼 num_bin의 길이도 길테고 그걸 하나하나 인덱스 비교하고 있으니 시간초과가 날 것이다.

        //i) 이분탐색은 어떨까?
            //절반으로 나눈 후 한쪽 반이 다른게 3개이상이면 이미 아니므로 continue하는 식으로?
            //근데 어차피 절반에서 다른게 몇개 있나 탐색할때도 결국은 인덱스끼리 비교하면서 탐색하는거 아냐??
            //그럼 그냥 O(N/2)가 되는거일뿐 일텐데...? --> 그래도 반만 탐색할테니 효율이 더 나올거 같기도??
            //i결과) 테스트케이스 부터 시간초과 난다.
        while(1)
        {
            string big_bin = ChangeBinary(bigger);
            int cnt = 0;

            //num_bin과 big_bin의 size()가 다르다면 통일시켜줘야하나..?
                //for(int i=0; i<big_bin.size()-num_bin.size(); i++)
                //{
                //  num_bin += '0';
                //}
            //이렇게 안해줘도 되려남 흠...

            for(int i=0; i<big_bin.size(); i++) //reverse를 안했으므로 0번인덱스가 맨 뒤 자리(2^0)이다.
            {
                if(num_bin[i] != big_bin[i]) 
                {
                    cnt++;
                    if(cnt > 3) break;
                }
            }
            if(cnt==1 || cnt==2)
            {
                answer.push_back(bigger);
                break;
            }
            

            bigger++;
        }
    }

    return answer;
}