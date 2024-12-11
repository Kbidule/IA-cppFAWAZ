// Player.cpp
//
// Created by Romain Bomba on 13/11/2024.
//
#include "../headers/player.h"
#include <iostream>
#include "../headers/trainer_Card.h"

Player::Player(string playerName) : playerName(playerName) {}

/**
 * Adds a card to the player's bench
 * @param card The card to add to benchCards
 */
void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

/**
 * Activates a Pokemon card from the bench to the action zone
 * @param index Index of the Pokemon card in benchCards to activate
 */
void Player::activatePokemonCard(int index) {
    pokemonCard* pokemon = dynamic_cast<pokemonCard*>(benchCards[index]);
    actionCards.push_back(pokemon);

    // Output action
    cout << "Player " << playerName << " is activating a Pokemon card: " << pokemon->getCardName() << endl;

    // Remove from bench
    benchCards.erase(benchCards.begin() + index);
}

/**
 * Attaches an energy card to a Pokemon in the action zone
 * @param benchIndex Index of the energy card in benchCards
 * @param actionIndex Index of the Pokemon card in actionCards
 */
void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    // Get Pokemon in actionCards and apply energy if same type
    pokemonCard* pokemon = actionCards[benchIndex];
    energyCard* energy = dynamic_cast<energyCard*>(benchCards[actionIndex]);

    // Output action
    cout << "Player " << playerName << " is attaching an energy card of type " << energy->getEnergyType()
         << " to the Pokemon " << pokemon->getCardName() << endl;

    // Remove energy card if successfully attached
    if(pokemon->attachEnergy(energy)) {
        benchCards.erase(benchCards.begin() + actionIndex);
    }
}

/**
 * Uses a trainer card from the bench
 * @param index Index of the trainer card in benchCards
 */
void Player::useTrainer(int index) {
    // Trainer heals all Pokemon in actionCards
    for(auto &pokemon : actionCards) {
        pokemon->heal();
    }

    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);

    // Output action
    cout << playerName << " is using the Trainer Card to " << trainer->getTrainerEffect() << endl;

    // Remove trainer card
    benchCards.erase(benchCards.begin() + index);
}

/**
 * Executes an attack against an opponent's Pokemon
 * @param pokemonIndex Index of the attacking Pokemon in actionCards
 * @param attackIndex Index of the attack to use (0 or 1)
 * @param opponent Opponent player to attack
 * @param opponentPokemonIndex Index of the target Pokemon in opponent's actionCards
 */
void Player::attack(int pokemonIndex, int attackIndex, Player &opponent, int opponentPokemonIndex) {
    pokemonCard* pokemon = actionCards[pokemonIndex];
    pokemonCard* opponentPokemon = opponent.actionCards[opponentPokemonIndex];

    bool ko = pokemon->attack(attackIndex, opponentPokemon);

    // Get attack details and output action
    tuple<int, string, int> attack = attackIndex == 0 ? pokemon->getAttack1() : pokemon->getAttack2();
    cout << playerName << " attacking " << opponent.playerName << " pokemon " << opponentPokemon->getCardName()
         << " with the Pokemon " << pokemon->getCardName() << " attack: " << get<2>(attack) << endl;

    cout << "Reducing " << get<2>(attack) << " from " << opponent.playerName << " pokemon "
         << opponentPokemon->getCardName() << " HP" << endl;

    if(ko) {
        cout << opponent.playerName << " pokemon " << opponentPokemon->getCardName() << " is KO" << endl;
    } else {
        cout << "Pokemon " << opponentPokemon->getCardName() << " is still alive" << endl;
    }
}

/**
 * Displays all cards in the player's bench
 */
void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for(auto &card : benchCards) {
        card->displayInfo();
    }
}

/**
 * Displays all cards in the player's action zone
 */
void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for(auto &card : actionCards) {
        card->displayInfo();
    }
}