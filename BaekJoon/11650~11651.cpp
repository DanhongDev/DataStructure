#include<iostream>
#include<vector>
#include<algorithm>

struct Point
{
    int x, y;
};

bool compare(Point a, Point b)
{
    if(a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}

bool compare_2(Point a, Point b)
{
    if(a.y == b.y)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<Point> arr(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> arr[i].x >> arr[i].y;
    }

    //std::sort(arr.begin(), arr.end(), compare); //11650
    std::sort(arr.begin(), arr.end(), compare_2); //11651

    for(int i=0; i<N; i++)
    {
        std::cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    //pair 버전
    // std::vector<std::pair<int, int>> arr(N);

    // for(int i=0; i<N; i++)
    // {
    //     std::cin>> arr[i].first >> arr[i].second;
    // }
    // std::sort(arr.begin(), arr.end());

    // for(int i=0; i<N; i++)
    // {
    //     std::cout << arr[i].first << ' ' << arr[i].second << '\n';
    // }

    return 0;
}