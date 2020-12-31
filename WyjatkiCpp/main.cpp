#include "Stack.hpp"
#include <iostream>

void foo(Stack &s){
    try{
        int i = 0;
        while(true){
            s.push(i);
            i++;
        }
    }catch (StackException e){
        std::cout << e.what() << std::endl;
    }
}

void bar(Stack &s){
    try{
        int i = 0;
        while(true){
            s.push(i);
            i++;
        }
    }catch (StackException &e){
        std::cout << e.what() << std::endl;
    }
}
//&e wywoluje nadpisana metode
int main(){
    Stack* s = new Stack(5);
    int op;
    while(true){
        std::cout << "Podaj opcje: 1 - dodaj, 2 - usun, 0 - zakoncz: ";
        std::cin >> op;
        if(op == 0) break;
        if(op == 1){
            try{
                int x;
                std::cout << "Podaj element: ";
                std::cin >> x;
                s->push(x);
            }catch(StackException &e){
                std::cout << e.what() << std::endl;
            }
        }else{
             try{
                int x = s->pop();
                std::cout << "Usuniety element: " << x  << std::endl;
            }catch(StackException &e){
                std::cout << e.what() << std::endl;
            }
        }
    }
    delete s;
    return 0;
}