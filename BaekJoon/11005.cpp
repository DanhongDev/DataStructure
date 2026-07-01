#include<iostream>
#include<string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long num;
    int bit;
    std::cin >> num >> bit;

    std::string str;

    while(num != 0)
    {
        int val = num % bit;
        char c;
        if(val >= 10)
        {
            c = val + 'A' - 10;
        }
        else
        {
            c = val + '0';
        }

        str += c;
        num /= bit;
    }

    for(int i=str.length()-1; i>=0; i--)
    {
        std::cout << str[i];
    }

    return 0;
}