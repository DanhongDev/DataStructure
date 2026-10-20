#include <string>
#include <vector>
using namespace std;

void Preorder(const vector<pair<int, int>> &nodes, int left, int right, vector<int> &pre)
{
    //부모 찾기
    int mid = -1, maxY = -1;
    for(int i=left; i<right; i++)
    {
        if(nodes[i].first != 0 && nodes[i].second > maxY)
        {
            maxY = nodes[i].second;
            mid = i;
        }
    }
    if(mid != -1)
    {
        pre.push_back(nodes[mid].first);
        // 왼쪽 재귀
        Preorder(nodes, left, mid, pre);
        // 오른쪽 재귀
        Preorder(nodes, mid+1, right, pre);
    }
    return;
}
void Postorder(const vector<pair<int, int>> &nodes, int left, int right, vector<int> &pre)
{
    //부모 찾기
    int mid = -1, maxY = -1;
    for(int i=left; i<right; i++)
    {
        if(nodes[i].first != 0 && nodes[i].second > maxY)
        {
            maxY = nodes[i].second;
            mid = i;
        }
    }
    if(mid != -1)
    {
        // 왼쪽 재귀
        Postorder(nodes, left, mid, pre);
        // 오른쪽 재귀
        Postorder(nodes, mid+1, right, pre);

        pre.push_back(nodes[mid].first);
    }
    return;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    int n = nodeinfo.size();
    
    //nodeinfo의 x값중 가장 큰 값이 길이가 된다.
    int len=0;
    for(int i=0; i<n; i++)
    {
        len = max(len, nodeinfo[i][0]);
    }
    len++; // 맨 마지막 요소가 (< right)에 막히는것을 방지하여 크기를 1개 늘림.

    // nodes: 2차원 nodeinfo를 1차원으로 압축
        // first: 해당 노드 번호, second: 해당 노드의 Y값
    vector<pair<int, int>> nodes(len);
    for(int i=0; i<n; i++)
    {
        // nodes[x] = {idx, y};
        nodes[nodeinfo[i][0]] = {i+1, nodeinfo[i][1]};
    }
    
    //PreOrder: 전위 순회
    vector<int> pre;
    Preorder(nodes, 0, len, pre);

    vector<int> post;
    Postorder(nodes, 0, len, post);

    //정답 리턴
    return {pre, post};
}