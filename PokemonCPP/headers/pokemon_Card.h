#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

#include "energy_Card.h"

using namespace std;

class pokemonCard : public Card {
private:
    string familyName;
    string pokemonType;
    unsigned int evolutionLevel;
    unsigned int MaxHP;
    int hp;
    int currentEnergy;
    vector<tuple<int, string, int>> attacks;
public:
    pokemonCard(string pokemonName, string pokemonType, string familyName, unsigned int evolutionLevel,
                unsigned int MaxHP,
                int cout1, string desc1, int dmg1,
                int cout2, string desc2, int dmg2);
    ~pokemonCard() = default;

    //getter
    string getFamilyName() const;
    string getPokemonType() const;
    unsigned int getEvolutionLevel() const;
    unsigned int getMaxHP() const;
    int getCurrentEnergy() const;
    int getHP() const;
    tuple<int, string, int> getAttack1() const;
    tuple<int, string, int> getAttack2() const;
    //setter
    void setCurrentEnergy(int energy);
    void increaseCurrentEnergy(int energy);

    //functions
    void displayInfo() override;
    bool attachEnergy(const energyCard *energyCard);
    bool attack(unsigned int attackNumber, pokemonCard *target);
    void damage(int damage);
    void heal();
    void heal(int point_de_vie_heal);
};

#endif //POKEMONCARD_H