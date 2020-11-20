#include "Pracownik.hpp"
#include "Student.hpp"
#include "Osoba.hpp"
#include "FabrykaPracownikow.hpp"
#include "FabrykaStudentow.hpp"
#include "FabrykaOsob.hpp"

void foo(Osoba &os){
    os.przedstaw();
}

void bar(Osoba *os){ 
    os->przedstaw();
}

int main(int argc, char* argv[]){
    /*Osoba adam;
    adam.setImieNazwisko("adam adam");
    adam.setDataUrodzenia("27/07/2000");
    adam.setAdresZamieszkania("Brzozowa", 9,1, 87800, "Włocławek");
    //adam.przedstaw();
    foo(adam);
    bar(&adam);
    */
    Student *stas = new Student();
    stas->setImieNazwisko("stas stas");
    stas->setDataUrodzenia("27/07/2000");
    stas->setAdresZamieszkania("Brzozowa", 9,1, 87800, "Włocławek");
    stas->setOcena("Polski", 2);
    //stas.przedstaw();
    foo(*stas);
    bar(stas);

    Pracownik *jan = new Pracownik();
    jan->setImieNazwisko("jan jan");
    jan->setDataUrodzenia("27/07/2000");
    jan->setAdresZamieszkania("Brzozowa", 9,1, 87800, "Włocławek");
    //jan.przedstaw();
    jan->dodajPrzedmiot("Angielski");
    jan->dodajPrzedmiot("Polski");
    //jan.przedstaw();
    jan->usunPrzedmiot("Kus");
    jan->usunPrzedmiot("Polski");
    //jan.przedstaw();
    foo(*jan);
    bar(jan);
    // Zmienne typu Pracownik i Student są po prostu traktowane jako zmienne typu Osoba, zostają ucięte do ich "podobiektu", ktrego metoda została uyta
    // Dodanie słowa virtual sprawia, ze uzywane są nadpisane metody

    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1 ) ;
    Osoba **o3 = new Osoba*;
    Pracownik *p2 = static_cast<Pracownik *>(*o3) ;  
    // Wszytskie są poprawne(jednak oczywiście przy pracownik->osoba tracimy dane), niepotrzebne są rzutowania z pracownika na osobę

    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    Pracownik *p4 = dynamic_cast<Pracownik *>(o4);
    
    //
    // Nalezy ich unikać - obiekt, z ktorego rzutujemy, mogl byc nullptr pierwotnie

    Osoba **o5 = new Osoba*;
    Pracownik *p5 = dynamic_cast<Pracownik *>(*o5);
    if(p5 == nullptr) std::cout << "Błąd rzutowania!" << std::endl;
    else p5->przedstaw();
    delete p1;
    delete o3;
    delete p3;
    delete o5;
    // Klasa Osoba stała się abstrakcyjna - nie mozna tworzyć obiektow jej typu
    delete stas;
    delete jan;
    // Nie, pamięć nie zwalnia się prawidłowo
    // Teraz odpowiednio zostaje wykonany detruktor obiektu a nie typu wskaźnika
    FabrykaPracownikow* fPrac = new FabrykaPracownikow();
    FabrykaStudentow* fStud = new FabrykaStudentow();
    Osoba* oskar = fPrac->utworz();
    Pracownik* kabza = fPrac->utworz();
    Student* oki = fStud->utworz();
    delete oskar;
    delete kabza;
    delete oki;

    std::map<std::string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    // map mapuje klucze na wartości
    std::vector <Osoba*> tablicaOsob;
    std::string currentCommand;
    while(true){
        std::cin >> currentCommand;
        if(currentCommand == "wyjscie") break;
        if(currentCommand == "wypisz"){
            for(auto it = tablicaOsob.begin(); it != tablicaOsob.end(); it++) (*it)->przedstaw();
        }else{
            tablicaOsob.push_back(m[currentCommand]->utworz());
        }
    }
    delete fPrac;
    delete fStud;
    return 0;
}