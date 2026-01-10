#include<iostream>
#include<set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::set<std::string> s;
    s.insert("ChongChong");
    
    while(N--)
    {
        std::string a, b;
        std::cin >> a >> b;
        if(s.count(a) || s.count(b))
        {
            s.insert(a);
            s.insert(b);
        }
    }
    
    std::cout << s.size() << '\n';

    return 0;
}