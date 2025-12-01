#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N, 0);
    std::vector<int> B(M, 0);

    for(int i=0; i<N; i++)
    {
        std::cin >> A[i];
    }
    for(int i=0; i<M; i++)
    {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    int A_B=N, B_A=M;

    for(int i=0; i<N; i++)
    {
        if(std::binary_search(B.begin(), B.end(), A[i]))
        {
            A_B--;
        }
    }
    for(int i=0; i<M; i++)
    {
        if(std::binary_search(A.begin(), A.end(), B[i]))
        {
            B_A--;
        }
    }
    
    std::cout << A_B + B_A << '\n';
    return 0;
}