#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int width=0, height=0;
    //for(int i=0; i<sizes.size(); i++)
    //{
    //    if(sizes[i][0] < sizes[i][1])
    //    {
    //        swap(sizes[i][0], sizes[i][1]);
    //    }
    //    width = sizes[i][0] > width ? sizes[i][0] : width;
    //    height = sizes[i][1] > height ? sizes[i][1] : height;
    //}

    for(const auto& size : sizes)
    {
        int cur_w = max(size[0], size[1]);
        int cur_h = min(size[0], size[1]);

        width = max(width, cur_w);
        height = max(height, cur_h);
    }
    return width * height;
}