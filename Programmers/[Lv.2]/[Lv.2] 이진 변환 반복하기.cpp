#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ChangeToBinary(int n)
{
    string bin = "";
    while(n!=0)
    {
        bin += to_string((n%2));
        n /= 2;
    }
    reverse(bin.begin(), bin.end());

    return bin;
}

vector<int> solution(string s) 
{
    vector<int> answer;

    int cnt_chg = 0, cnt_0 = 0, size = 0;
    string binary = s;
    while(size != 1)
    {
        string new_bin = "";
        for(int i=0; i<binary.size(); i++)
        {
            if(binary[i] == '1')
            {
                new_bin += "1";
            }
            else
            {
                cnt_0++;
            }
        }
        size = new_bin.size();

        binary = ChangeToBinary(size);

        cnt_chg++;
    }
    
    return {cnt_chg, cnt_0};
}

vector<int> solution_Ge(string s)
{
    int cnt_chg = 0;
    int cnt_0;
    string binary = s;
    
    while(binary != "1")
    {
        int zeros = count(binary.begin(), binary.end(), '0');
        cnt_0 += zeros;

        int size = binary.size() - zeros;

        binary = ChangeToBinary(size);

        cnt_chg++;
    }

    return {cnt_chg, cnt_0};
}