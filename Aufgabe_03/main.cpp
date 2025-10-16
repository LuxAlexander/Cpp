#include <iostream>
#include <vector>

#include "Konto.h"

int main() {
    try {
        std::vector<Konto*> kontos{new Konto("Alex", 0)};
        int input=0,betrag=0;
        std::string name;


        for(int index=0; input!=999;) {
            std::cout<<"1: Neues Kontos, 2:Einzahlen, 3:Auszahlen,4:Konto schließen,5:print,999:Schließen"<<std::endl;
            std::cin>>input;
            switch (input) {
                case 1:
                    std::cout<<"Neues Kontos: "<<std::endl;
                    std::cout<<"Enter name: \n";
                    std::cin>>name;
                    std::cout<<"Enter Startkapital: \n";
                    std::cin>>betrag;
                    kontos.push_back(new Konto(name, betrag));
                    index++;
                    break;
                case 2:
                    std::cout<<"Einzahlen: "<<std::endl;
                    std::cin>>betrag;
                    if (!kontos[index]->Konto::einzahlen(betrag)) {
                        std::cout<<"Error Einzahlen"<<std::endl;
                    }
                    break;
                case 3:
                    std::cout<<"Auszahlen: "<<std::endl;
                    std::cin>>betrag;
                    if (!kontos[index]->Konto::auszahlen(betrag)) {
                        std::cout<<"Error Auszahlen"<<std::endl;
                    }
                    break;
                case 4:
                    std::cout<<"Kontos: "<<std::endl;
                    delete kontos[index];
                    index--;
                    break;
                case 5:
                    std::cout<<"Kontodaten: "<<std::endl;
                    kontos[index]->Konto::print();
                    break;
                case 999:
                    std::cout<<"Bye Bye"<<std::endl;
                default:
                    std::cout<<"Keine Operation Bekannt"<<std::endl;
            }
            betrag=0;
            name="";
        }
    }catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
