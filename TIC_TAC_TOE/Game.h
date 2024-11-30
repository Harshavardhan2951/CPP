#pragma once

#include "AbstracGame.h"
#include <vector>
#include <string>
using namespace std;

class Game : public AbstractGame {
private:
    int Numb;
    int Points;
    char Character;
    vector<vector<char>> playBoard;
    string Name;

public:
    // Constructors
    Game(); // Default Constructor
    Game(int Numb, int Points, char Character, const vector<vector<char>>& playBoard, const string& Name);

    // Other member functions
    void setNumb(int Number);
    int getNumb();
    void setCharacter(char Char);
    char getCharacter();
    void setPoints(int Point);
    int getPoints();
    void setName(string name);
    string getName();
    void Play() override;
    void displayBoard();
    bool checkWin();
};
