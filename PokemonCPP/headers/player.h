//
// Created by Romain Bomba on 13/11/2024.
//
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "Card.h"
#include "pokemon_Card.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<pokemonCard*> actionCards;

public:
    Player(string playerName);
    ~Player() = default;

    //functions
    void addCardToBench(Card* card);
    void activatePokemonCard(int indice);
    void attachEnergyCard(int benchIndice, int actionIndice);
    void useTrainer(int indice);
    void attack(int pokemonIndice, int attackIndice, Player &opponent, int opponentPokemonIndice);


    //display
    void displayBench() const;
    void displayAction() const;
};

#endif //PLAYER_H