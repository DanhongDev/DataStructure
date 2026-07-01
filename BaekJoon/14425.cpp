#include<iostream>
#include<unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::unordered_set<std::string> s;
    
    for(int i=0; i<N; i++)
    {
        std::string str;
        std::cin >> str;
        s.insert(str);
    }
    
    int cnt=0;
    for(int i=0; i<M; i++)
    {
        std::string temp;
        std::cin >> temp;
        if(s.find(temp) != s.end())
        {
            cnt++;
        }
    }
    
    std::cout << cnt << '\n';
    return 0;
}