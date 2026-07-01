#include<iostream>
#include<set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::set<std::string, std::greater<std::string>> s;

    while(N--)
    {
        std::string name, status;
        std::cin >> name >> status;
        if(status == "enter")
        {
            s.insert(name);
        }
        else if(status == "leave")
        {
            s.erase(name);
        }
    }

    //기본 오름차순 set일때.
    // for(auto iter = s.rbegin(); iter != s.rend(); iter++)
    // {
    //     std::cout << *iter << '\n';
    // }

    //내림차순 set으로 선언했을때
    for(auto& iter : s)
    {
        std::cout << iter << '\n';
    }
    
    return 0;
}