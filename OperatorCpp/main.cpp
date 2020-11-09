#include "Samochod.hpp"
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
    if(s1){
        std::cout << "S1\n";
    }
    if(!s1){
        std::cout << "!S1\n";
    }
    if(s2){
        std::cout << "S2\n";
    }
    if(!s2){
        std::cout << "!S2\n";
    }
    if(s3){
        std::cout << "S3\n";
    }
    if(!s3){
        std::cout << "!S3\n";
    }
    vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it) cout << *it << endl;
    set <Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it = s.begin(); it != s.end(); ++it) cout << *it << endl;
    cout << ++s1 << endl;
    cout << s1 << endl;
    cout << s1++ << endl;
    cout << s1;
}