#include<iostream>
#include<vector>
#include<stdexcept>

template <typename T>
class MyStack
{
    private:
        std::vector<T> stk;
    public:
        void Push(T x)
        {
            stk.push_back(x);
        }

        T Pop()
        {
            if(IsEmpty())
            {
                throw std::out_of_range("Stack is Empty");
            }
            T topVal = stk.back();
            stk.pop_back();
            return topVal;
        }

        T Top()
        {
            if(IsEmpty())
            {
                throw std::out_of_range("Stack is Empty");
            }
            return stk.back();
        }

        bool IsEmpty()
        {
            return stk.empty();
        }

        int Size()
        {
            return stk.size();
        }

        void Clear()
        {
            stk.clear();
        }
};

int main()
{
    
}