#include "Game.h"
#include <iostream>
#include <ctime> // For random number seeding
using namespace std;

int main() {
    // Seed the random number generator for the Game constructor
    srand(static_cast<unsigned>(time(0)));

    // Create a Game object
    Game game;

    // Set up the player details
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    game.setName(playerName);
    game.setPoints(0); // Initialize player points

    cout << "\nWelcome, " << game.getName() << "! Let's play Tic-Tac-Toe.\n";

    // Start the game
    game.Play();

    return 0;
}
