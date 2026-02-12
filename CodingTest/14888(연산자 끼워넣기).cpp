#include<iostream>
#include<vector>

std::vector<int> arr;
std::vector<int> symbol(4); //0: +, 1: -, 2: *, 3: /
int min = 1000000001;
int max = -1000000001;

void func(int k, int sum) //k는 arr의 인덱스
//sum를 재귀적으로 주는 이유: return할때 굳이 +했으면 다시 -해주고, *했으면 /해주고 이런 코드를 안넣어도 되지 않을까 해서.
{
    //기저 조건
    if(k == arr.size())
    {
        //계산 후 리턴
        max = sum > max ? sum : max;
        min = sum < min ? sum : min;
        //리턴 부분이 뭔가... 부실해 보여 혹시 더 채워야 하는 것이 있을거 같음.
        return;
    }

    //symbol만 for문을 쓰는것이 좋지않을까??
    //symbol의 인덱스 값은 각 기호의 남아있는 횟수
    for(int i=0; i<symbol.size(); i++)
    {
        if(symbol[i] > 0)
        {
            symbol[i]--; //쓰고

            //기존 방식은 sum이 계속 오염되는 문제가 있다.
            int next_sum = 0;

            switch(i)
            {
                case 0:
                    next_sum = sum + arr[k];
                    break;
                case 1:
                     next_sum = sum - arr[k];
                    break;
                case 2:
                     next_sum = sum * arr[k];
                    break;
                case 3:
                     next_sum = sum / arr[k];
                    break;
            }

            func(k+1, next_sum); //갔다 와서

            symbol[i]++; //반납한다.
        }
    }

    //생각한 문제점1: symbol[i]를 어떻게 다시 ++를 해줄까?? --> 일단 i를 바깥으로 뺄까...?
    //생각한 문제점2: for문으로 0부터 돌리면... 항상 + - * / 순으로 되지 않을까??
    //결국 2의 파생되는 문제점을 해결하면 이 문제를 풀 수 있을듯 하다.
    //즉 어떻게 기호를 섞어가면서 연산을 시킬것인가 이게 키포인트인듯.

    //해결!!!: 백트래킹 기법으로 1, 2번 둘다 해결할 수 있다.
    //해결법은 for문안에서 재귀를 돌려야한다!!!!
    //모든 백트래킹은 for문 안에서 재귀를 돌려준다 라고 생각하면 된다!!!
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    arr.resize(N);

    for(int i=0; i<arr.size(); i++)
    {
        int num;
        std::cin >> num;
        arr[i] = num;
    }
    for(int i=0; i<symbol.size(); i++)
    {
        int num;
        std::cin >> num;
        symbol[i] = num;
    }

    func(1, arr[0]); //sum값은 초기값은 항상 arr[0]이기 때문에 1부터 시작.

    std::cout << max << '\n';
    std::cout << min << '\n';
    return 0;
}