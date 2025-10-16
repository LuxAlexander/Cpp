#include <iostream>
#include <memory>
#include <vector>

enum class farbe{Orange,Rot,Gruen,Schwarz};
enum class zahl{ass,zehn,koenig,dame,bube,neun,acht,sieben};

typedef struct{
    farbe _farbe;
    zahl _zahl;

}Skatcard;
// helper functions for printing enums
std::string farbeToString(farbe f) {
    switch (f) {
        case farbe::Orange: return "Orange";
        case farbe::Rot: return "Rot";
        case farbe::Gruen: return "Gruen";
        case farbe::Schwarz: return "Schwarz";
        default: return "Unknown";
    }
}

std::string zahlToString(zahl z) {
    switch (z) {
        case zahl::bube: return "Bube";
        case zahl::dame: return "Dame";
        case zahl::koenig: return "Koenig";
        case zahl::zehn: return "Zehn";
        case zahl::ass: return "Ass";
        case zahl::sieben: return "Sieben";
        case zahl::acht: return "Acht";
        case zahl::neun: return "Neun";
        default: return "Unknown";
    }
}
void shuffle(std::vector<std::shared_ptr<Skatcard>>& deck) {
    int randomNum;
    int randomNum2;
    std::cout<<"Shuffling"<<std::endl;
    for (int i = 0; i < 10; i++) {
        randomNum = rand() % 32;
        randomNum2 = rand() % 32;
        std::cout<<randomNum<<" "<<randomNum2<<std::endl;
        std::shared_ptr<Skatcard> temp = deck[randomNum];
        deck[randomNum]=deck[randomNum2];
        deck[randomNum2]=temp;
    }
    std::cout<<"Finished"<<std::endl;

}
int main() {
    srand(time(0));
    std::vector<std::shared_ptr<Skatcard>> deck1;


    for(int i=0;i<4;i++) {
        for(int j=0;j<8;j++){
            auto shr_ptr = std::make_shared<Skatcard>();
            shr_ptr->_farbe = static_cast<farbe>(i);
            shr_ptr->_zahl = static_cast<zahl>(j);


            deck1.push_back(shr_ptr);
        }
    }
    auto deck2 = deck1; // copy

    for(auto& card:deck1) {
        std::cout << "Farbe: "<<farbeToString(card->_farbe) <<" Zahl: "<< zahlToString(card->_zahl)<< std::endl;
    }
    std::cout << "First card use_count: " << deck1[0].use_count() << std::endl;
    std::cout << deck1.size() << std::endl;
    shuffle(deck1);
    /*
    std::cout << "Deck2" << std::endl;
    for(auto& card:deck2) {
        std::cout << "Farbe: "<<farbeToString(card->_farbe) <<" Zahl: "<< zahlToString(card->_zahl)<< std::endl;
    }*/
    std::cout << "Deck1" << std::endl;
    for(auto& card:deck1) {
        std::cout << "Farbe: "<<farbeToString(card->_farbe) <<" Zahl: "<< zahlToString(card->_zahl)<< std::endl;
    }

    return 0;
}