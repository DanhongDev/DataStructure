#include<iostream>
#include<vector>
#include<set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;
    std::set<std::string> s;

    
    for(int i=0; i<str.size(); i++)
    {
        std::string temp = "";
        for(int j=i; j<str.size(); j++)
        {
            temp += str[j];
            s.insert(temp);
        }
    }

    std::cout << s.size() << '\n';

    return 0;
}