//#include "Pracownik.hpp"
//#include "Student.hpp"
#include "Osoba.hpp"

int main(int argc, char* argv[]){
    Osoba stas;
    stas.setDataUrodzenia("27/07/2000");
    stas.setAdresZamieszkania("Brzozowa", 9,1, 87800, "Włocławek");
    stas.przedstaw();
    return 0;
}