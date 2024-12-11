// EnergyCard.cpp
//
// Created by Romain Bomba on 13/11/2024.
//
#include "../headers/energy_Card.h"
#include <iostream>
#include <string>
using namespace std;
/**
 * Constructor for the Energy Card
 * @param energyType The type of energy this card represents (e.g., "Fire", "Water", "Electric"
 */
energyCard::energyCard(string energyType) : energyType(energyType) {
    cardName = "Energy";
}

string energyCard::getEnergyType() const {
    return energyType;
}

void energyCard::displayInfo() {
    cout << "Energy Card of type " << energyType;
}
