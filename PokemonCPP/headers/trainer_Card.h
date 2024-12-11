//
// Created by Romain Bomba on 13/11/2024.
//
// headers/trainer_Card.h
#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H
#include "Card.h"
#include <string>

using namespace std;


class TrainerCard : public Card {
private:
    string trainerEffect;
public:
    TrainerCard(string trainerName, string trainerEffect);
    ~TrainerCard() = default;

    //getter
    string getTrainerEffect() const;

    //functions
    void displayInfo() override;
};

#endif // TRAINER_CARD_H