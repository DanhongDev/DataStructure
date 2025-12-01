#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> hear(N);
    std::vector<std::string> see(M);
    std::vector<std::string> hear_see;

    //N^2 형태의 탐색법을 쓰면 N과 M이 500,000가지이므로 시간초과가 날것이다.
    //고로 logN형태의 탐색법을 써야한다.

    for(int i=0; i<N; i++)
    {
        std::cin >> hear[i];
    }
    std::sort(hear.begin(), hear.end());
    //N+2째 줄 이라는 말은... N이 3이니까 3+2 라서 5번째 줄부터이고
    //결국 obama부터이라는 말인데.. 그냥 hear입력이 끝나면 바로 0부터 M까지의 입력을
    //그대로 이어서 받으면 되는거 아닌가...?
    for(int i=0; i<M; i++)
    {
        std::cin >> see[i];
    }

    int cnt=0;
    for(int i=0; i<M; i++)
    {
        //찾았다면 듣도보도 못한 사람임!
        if(std::binary_search(hear.begin(), hear.end(), see[i]))
        {
            hear_see.push_back(see[i]);
            cnt++;
        }
    }
    
    std::sort(hear_see.begin(), hear_see.end());
    std::cout << cnt << '\n';
    for(auto i : hear_see)
    {
        std::cout << i << '\n';
    }
    return 0;
}