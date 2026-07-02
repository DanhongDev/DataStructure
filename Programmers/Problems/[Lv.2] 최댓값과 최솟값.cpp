#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) 
{
    vector<int> arr;
    stringstream ss(s);
    int num;

    while(ss >> num)
    {
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    return to_string(arr.front()) + " " + to_string(arr.back());
}