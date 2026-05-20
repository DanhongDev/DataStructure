#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) 
{
    //해시 생성
    unordered_set<string> list(phone_book.begin(), phone_book.end());
    
    for(string str : phone_book)
    {
        string substr = "";
        for(int i=0; i<str.size()-1; i++)
        {
            substr += str[i];

            if(list.find(substr) != list.end())
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<string> phone_book = {"119", "97674223", "1195524421"};

    std::cout << solution(phone_book) << '\n';
}