//
// Created by Romain Bomba on 13/11/2024.
//
#include <iostream>
#include "../headers/pokemon_Card.h"

pokemonCard::pokemonCard(string pokemonName, string pokemonType, string familyName,
                         unsigned int evolutionLevel, unsigned int maxHP,
                         int cost1, string desc1, int dmg1,
                         int cost2, string desc2, int dmg2)
    : familyName(familyName),
      pokemonType(pokemonType),
      evolutionLevel(evolutionLevel),
      MaxHP(maxHP),
      hp(maxHP), currentEnergy(0) {
    cardName = pokemonName;
    attacks.push_back(make_tuple(cost1, desc1, dmg1));
    attacks.push_back(make_tuple(cost2, desc2, dmg2));
}

// Getters
string pokemonCard::getFamilyName() const { return familyName; }
string pokemonCard::getPokemonType() const { return pokemonType; }
unsigned int pokemonCard::getEvolutionLevel() const { return evolutionLevel; }
unsigned int pokemonCard::getMaxHP() const { return MaxHP; }
int pokemonCard::getHP() const { return hp; }
int pokemonCard::getCurrentEnergy() const { return currentEnergy; }
tuple<int, string, int> pokemonCard::getAttack1() const { return attacks[0]; }
tuple<int, string, int> pokemonCard::getAttack2() const { return attacks[1]; }

void pokemonCard::displayInfo() {
    cout << "Pokemon Card - Name: " << cardName;
    cout << ", Type: " << pokemonType;
    cout << ", Evolution Level: " << evolutionLevel;
    cout << ", of the family: \"" << familyName;
    cout << ", HP: " << hp << "\"" << endl;

    cout << "Attacks: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack description: " << get<1>(attacks[i]) << endl;
        cout << "Attack damage: " << get<2>(attacks[i]) << endl;
    }
}

bool pokemonCard::attachEnergy(const energyCard *energyCard) {
    if (energyCard->getEnergyType() == pokemonType or energyCard->getEnergyType() == "normal") {
        currentEnergy += 1;
        return true;
    }
    return false;
}

bool pokemonCard::attack(unsigned int attackNumber, pokemonCard *target) {
    if (currentEnergy >= get<0>(attacks[attackNumber])) {
        target->damage(get<2>(attacks[attackNumber]));
        currentEnergy -= get<0>(attacks[attackNumber]);
        // here the energy is consumed after the attack but it could be stay on the pokemon ( it's a game design choice)
        return target->getHP() == 0;
    }
    return false;
}

void pokemonCard::damage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
        cout << "Pokemon " << cardName << " is KO" << endl;
    }
}

void pokemonCard::heal() {
    hp = MaxHP;
}

void pokemonCard::heal(int healAmount) {
    hp += healAmount;
    if (hp > MaxHP) {
        hp = MaxHP;
    }
}
