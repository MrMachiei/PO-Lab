#include <memory>
#include "Wezel.hpp"

int main(){
    for(int i = 0; i < 10; i++){
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
        w1->next = w2;
        w2->next = w1;
    }
    return 0;
}