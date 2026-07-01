#include<iostream>
#include<vector>
#include<cmath>

void Kanto(std::string& str, int left, int len)
{
    if(len==1)
    {
        return;
    }
    int split_len = len / 3; //나눠지는 길이
    for(int i=split_len+left; i<split_len*2+left; i++)
    {
        str[i] = ' ';
    }
    Kanto(str, left, split_len);
    Kanto(str, split_len*2+left, split_len);
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;

    while(std::cin >> n)
    {
        int len = std::pow(3, n);

        std::string str(len, '-');

        Kanto(str, 0, len);
    
        std::cout << str << '\n';
    }    
    
    return 0;
}