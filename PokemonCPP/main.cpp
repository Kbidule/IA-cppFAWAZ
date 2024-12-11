#include "headers/Card.h"
#include "headers/pokemon_Card.h"
#include "headers/energy_Card.h"
#include"headers/trainer_Card.h"
#include"headers/player.h"
#include <gtk/gtk.h>
#include <iostream>
#include <string>

using namespace std;
int main (int argc, char *argv[]) {
    Player player1("Hadi");
    player1.addCardToBench(new energyCard("Electric"));
    player1.addCardToBench(new energyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new pokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm", 30));
    player1.activatePokemonCard(3); player1.attachEnergyCard(0, 0); player1.attachEnergyCard(0, 0);
    cout << endl; player1.displayBench(); cout << endl; player1.displayAction();
    Player player2("Germain");
    player2.addCardToBench(new energyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new pokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "LeechSeed", 15, 3, "Vine Whip", 25)); player2.activatePokemonCard(2);

    player2.attachEnergyCard(0, 0);
    cout << endl; player2.displayBench(); cout << endl; player2.displayAction();
    player1.attack(0, 0, player2 , 0); cout << endl; player2.displayAction(); player2.useTrainer(0);
    cout << endl; player2.displayAction();



    return 0;

}