#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    int left=0, right=0;
    int start = -1, end = 1000001;
    long long sum = sequence[right];

    while(left <=right && right<sequence.size()) //iii
    {
        if(sum < k)
        {
            right++;
            //right가 size() - 1 일때 이 if문이 없으면 초과된 인덱스의 값을 더해주려 하므로 에러가 날 수 있다.
            if(right < sequence.size()) sum += sequence[right];
        }
        if(sum > k)
        {
            sum -= sequence[left];
            left++;
        }
        else if(sum == k)
        {
            if(right-left < end-start) //이전 수열보다 길이가 더 짧은 수열인지?
            {
                start = left;
                end = right;
            }

            //계속 진행
            right++;
            sum += sequence[right];
        }
    }

    return {start, end};
}

int main()
{
    vector<int> answer = solution({2,2,2,2,2}, 6);
    
    return 0;
}