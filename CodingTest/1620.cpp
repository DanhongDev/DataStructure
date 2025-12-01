#include<iostream>
#include<vector>
#include<map>
#include<cctype>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> arr(N+1);
    std::map<std::string, int> m;
    
    for(int i=1; i<=N; i++)
    {
        std::string name;
        std::cin >> name;

        arr[i] = name;
        m.insert({name, i});
    }
    
    while(M--)
    {
        std::string str;
        std::cin >> str;

        if(isdigit(str[0]))
        {
            int num = std::stoi(str);

            std::cout << arr[num] << '\n';
        }
        else
        {
            std::cout << m[str] << '\n';
        }
    }
    
    return 0;
}