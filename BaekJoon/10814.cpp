#include<iostream>
#include<vector>
#include<algorithm>

struct data
{
    int year;
    std::string name;
    int order;
};

bool compare(data a, data b)
{
    if(a.year == b.year)
    {
        return a.order < b.order;
    }
    else
    {
        return a.year < b.year;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<data> arr(N);

    int cnt = 1;
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i].year >> arr[i].name;
        arr[i].order = cnt++;
    }
    std::sort(arr.begin(), arr.end(), compare);

    for(int i=0; i<N; i++)
    {
        std::cout << arr[i].year << ' ' << arr[i].name << '\n';
    }


    return 0;
}