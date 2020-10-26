#include <iostream>
#include <string>

int main(){
    std::string fellow = "world!";
    std::cout << "Hello_" << fellow << std::endl;
    std::cout.flush();
    while (fellow != "exit"){
        std::cout << "Introduce_yourself:_";
        std::cout.flush();
        std::getline(std::cin, fellow);
        std::cout << "Hello_" << fellow << std::endl;
    }
}