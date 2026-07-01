#include<iostream>

int cnt=0;

int recursion(std::string& s, int l, int r)
{
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(std::string& s)
{
    return recursion(s, 0, s.length()-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string str;
    while(n--)
    {
        cnt = 0;
        std::cin >> str;
        
        std::cout << isPalindrome(str) << ' ';
        std::cout << cnt << '\n';
    }

    
    
    return 0;
}