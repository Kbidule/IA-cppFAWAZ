//
// Created by Romain Bomba on 13/11/2024.
//
#include "Card.h"
#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H
class energyCard : public Card {
private:
    string energyType;
public:
    energyCard(string energyType);
    ~energyCard() = default;

    //getter
    string getEnergyType() const;
    void displayInfo() override;
};
#endif //ENERGY_CARD_H
