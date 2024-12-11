
// TrainerCard.cpp
//
// Created by Romain Bomba on 13/11/2024.
//
#include "../headers/trainer_Card.h"
#include <iostream>
#include <ostream>

TrainerCard::TrainerCard(string trainerName, string trainerEffect) {
    cardName = trainerName;
    this->trainerEffect = trainerEffect;
}

string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

void TrainerCard::displayInfo() {
    cout << "Trainer Name - " << cardName;
    cout << ", Effect: " << trainerEffect << endl;
}
