//
// Created by Romain Bomba on 13/11/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;
class Card {
protected:
    string cardName;
public:
    void virtual displayInfo() = 0;
    string getCardName() const;
    virtual ~Card() = default;
    Card() = default;

};

#endif //CARD_H
