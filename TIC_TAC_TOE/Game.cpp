#include "Game.h"
#include <iostream>
using namespace std;

/* Default Constructor */
Game::Game() {
    cout << "Random Number from 1-10" << endl;
    Numb = (rand() % 10) + 1;
    Points = 0; // Default points
    Character = 'X'; // Default character
    playBoard = vector<vector<char>>(3, vector<char>(3, ' ')); // Empty 3x3 board
}

/* Parameterized Constructor */
Game::Game(int Numb, int Points, char Character, const vector<vector<char>>& playBoard, const string& Name)
    : Numb(Numb), Points(Points), Character(Character), playBoard(playBoard), Name(Name)
{}

/* Setter & Getter for Character */
void Game::setCharacter(char Char) { this->Character = Char; }
char Game::getCharacter() { return Character; }

/* Setter & Getter for Numb */
void Game::setNumb(int Number) { this->Numb = Number; }
int Game::getNumb() { return Numb; }

/* Setter & Getter for Points */
void Game::setPoints(int Point) { this->Points = Point; }
int Game::getPoints() { return Points; }

/* Setter & Getter for Name */
void Game::setName(string name) { this->Name = name; }
string Game::getName() { return Name; }

/* Display the Board */
void Game::displayBoard() {
    cout << "\nCurrent Board:\n";
    for (const auto& row : playBoard) {
        for (const char& cell : row) {
            cout << (cell == ' ' ? '.' : cell) << " ";
        }
        cout << endl;
    }
}

/* Check if the Player has Won */
bool Game::checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((playBoard[i][0] == playBoard[i][1] && playBoard[i][1] == playBoard[i][2] && playBoard[i][0] != ' ') ||
            (playBoard[0][i] == playBoard[1][i] && playBoard[1][i] == playBoard[2][i] && playBoard[0][i] != ' ')) {
            return true;
        }
    }

    // Check diagonals
    if ((playBoard[0][0] == playBoard[1][1] && playBoard[1][1] == playBoard[2][2] && playBoard[0][0] != ' ') ||
        (playBoard[0][2] == playBoard[1][1] && playBoard[1][1] == playBoard[2][0] && playBoard[0][2] != ' ')) {
        return true;
    }

    return false; // No win condition met
}

/* Core Play Logic */
void Game::Play() {
    int currentPlayer = 1; // Player 1 starts
    bool gameWon = false;
    int moves = 0; // Maximum moves in a 3x3 board is 9

    while (!gameWon && moves < 9) {
        displayBoard();
        cout << "Player " << currentPlayer << " (" << (currentPlayer == 1 ? 'X' : 'O') << ")'s turn.\n";
        cout << "Enter row and column (0-2): ";
        int row, col;
        cin >> row >> col;

        // Validate input
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && playBoard[row][col] == ' ') {
            // Place the player's mark
            playBoard[row][col] = (currentPlayer == 1) ? 'X' : 'O';
            moves++;

            // Check if this move won the game
            if (checkWin()) {
                gameWon = true;
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                return;
            }

            // Switch player
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else {
            cout << "Invalid move. Try again.\n";
        }
    }

    if (!gameWon) {
        displayBoard();
        cout << "It's a draw!\n";
    }
}
