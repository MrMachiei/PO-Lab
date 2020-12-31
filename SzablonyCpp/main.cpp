#include "Y.hpp"
#include "AB.hpp"

using namespace std;


template <typename T>
T maximum(T const& a, T const& b){
    return a > b ? a : b;
}

auto maxLambda = [](auto a, auto b){ return a > b ? a : b;};

int main(){
    cout << maximum(6, 7) << endl;
    cout << maximum(6.3, 7.3) << endl;
    //cout << maximum(6.5, 7) << endl; // argumnety sa roznych typow - nie wiadomo czy pod T ma byc dopasowany int czy double
    cout << maximum<double>(4, 5) << endl;
    cout << maximum<double>(4.1, 5.7) << endl;
    cout << maximum<int>(4.6, 3) << endl; // obcinamy wartosc 4.6 do 4
    cout << maximum<double>(4.6, 3) << endl;
    cout << maximum<bool>(4.6, 3) << endl; // 4.6 na true
    //cout << maximum<string>(4.6, 3) << endl; // nie da się zrzutować tych wartosci na string
    cout << maximum<string>("aaa", "bb") << endl;
    cout << maximum(X(4), X(3)) << endl;
    cout << maximum(X<int>(4), X<int>(3)) << endl;
    cout << maximum(X<string>("aaa"), X<string>("bb")) << endl;
    Y<int> y;
    Y<int, double> y1;
    A<B> ab;
    ab.f();
    bool b = maxLambda(3, 3.14);
    auto c = maxLambda(3, 3.14);
    return 0;
}