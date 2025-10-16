#include<iostream>
#include<string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    int bit;
    std::cin >> bit;

    long long res = 0, mul = 1;

    for(int i=str.length()-1; i>=0; i--)
    {
        int val = 0;
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            val = str[i] - 'A' + 10;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            val = str[i] - '0';
        }
        res += val * mul;
        mul *= bit;
    }

    std::cout << res << '\n';

    return 0;
}