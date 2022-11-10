#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sstream"
#include <stdlib.h>
#include "19lg26_jumble.h"

using namespace std;

JumblePuzzle::JumblePuzzle(const string &word, const string &difficulty)
{
    len = word.length();
    if (len < 3 || len > 10)
    {
        throw BadJumbleException("Invalid length, word must be between 3 and 10 characters");
    }

    if (difficulty == "easy")
    {
        len = len * 2;
    } 
    else if (difficulty == "medium")
    {
        len = len * 3;
    } 

    else if (difficulty == "hard")
    {
        len = len * 4;
    } 
    else
    {
        throw BadJumbleException("Invalid difficulty. Difficulty must be one of the following: easy, medium, or hard.");
    } 

    srand(time(0));

    matrix = new char*[len];
    for(int i = 0; i < len; i++){
        matrix[i] = new char[len];
    }

    const char *possibleDirections = "nesw";

    //putting random chars into array
    fillWithRandomCharacters();
    
    bool placed = false;

    while(!placed)
    {
        row = rand() % len;
        col = rand() % len;
        direction = possibleDirections[rand() % 4];

        
    }
}

JumblePuzzle::JumblePuzzle(const JumblePuzzle &puzzle){
    row = puzzle.row;
    col = puzzle.col;
    len = puzzle.len;
    direction = puzzle.direction;
    word = puzzle.word;
}

void JumblePuzzle::fillWithRandomCharacters()
{
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            matrix[i][j] = generateRandomCharacter();
        }
    }
}

char JumblePuzzle::generateRandomCharacter()
{
    return char(rand() % 26 + 97);
}

int JumblePuzzle::getSize()
{
    return size;
}
int JumblePuzzle::getRowPosition()
{
    return row;
}
int JumblePuzzle::getColPosition()
{
    return col;
}
char JumblePuzzle::getDirection()
{
    return direction;
}