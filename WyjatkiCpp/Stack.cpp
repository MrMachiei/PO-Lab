#include "Stack.hpp"


Stack::Stack():maxStackSize(0), top(0), dfs(std::vector<int>()){}
Stack::Stack(int max):maxStackSize(max),dfs(std::vector<int>()), top(0){}
void Stack::push(int newItem){
    if (top >= maxStackSize) throw StackFullException("PELEN STOS!", newItem, maxStackSize);
    else{
        top++;
        dfs.push_back(newItem);
    }
}
int Stack::pop(){
    if (top <= 0) throw StackEmptyException("PUSTY STOS!");
    else{
        top--;
        int a = dfs[top];
        dfs.pop_back();
        return a;
    }
}