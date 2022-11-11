#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sstream"
#include <stdlib.h>
#include "19lg26_jumble.h"

using namespace std;

JumblePuzzle::JumblePuzzle()
{
    matrix = nullptr;
    row = 0;
    col = 0;
    direction = 0;
    size = 0;
}

JumblePuzzle::JumblePuzzle(const string &word, const string &difficulty)
{
    size = word.length();
    int wordLen = size;
    if (size < 3 || size > 10)
    {
        throw BadJumbleException("Invalid length, word must be between 3 and 10 characters");
    }

    if (difficulty == "easy")
    {
        size = size * 2;
    }
    else if (difficulty == "medium")
    {
        size = size * 3;
    }

    else if (difficulty == "hard")
    {
        size = size * 4;
    }
    else
    {
        throw BadJumbleException("Invalid difficulty. Difficulty must be one of the following: easy, medium, or hard.");
    }

    srand(time(0));

    // putting random chars into array
   // fillWithRandomCharacters();

    int dir = rand() % 4;
    int south, east;
    string directions = "nesw";
    direction = directions[dir];

    int placementDirSouth[4] = {-1, 0, 1, 0};
    int placementDirEast[4] = {0, 1, 0, -1};

    south = placementDirSouth[dir];
    east = placementDirEast[dir];

    // int val1S, val2S;
    // int val1E, val2E;

    // if (south)
    //     val1S = wordLen - 1;
    // else
    //     val1S = 0;

    // if (south == -1)
    //     val2S = wordLen - 1;
    // else
    //     val2S = 0;

    // if (east)
    //     val1E = wordLen - 1;
    // else
    //     val1E = 0;

    // if (east == -1)
    //     val2E = wordLen - 1;
    // else
    //     val2E = 0;

    // row = rand() % (size - val1S) + val2S;
    // col = rand() % (size - val1E) + val2E;

    row = rand() % (size - (south ? wordLen - 1 : 0)) + (south == -1 ? wordLen - 1 : 0);
    col = rand() % (size - (east ? wordLen - 1 : 0)) + (east == -1 ? wordLen - 1 : 0);

    matrix = new char *[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new char[size];
    }   
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = generateRandomCharacter();
        }
    }

    int i = row;
    int j = col;
    int count;
    for (count = 0; count < wordLen; count++)
    {
        matrix[i][j] = word[count];
        i += south;
        j += east;
    }
}

JumblePuzzle::JumblePuzzle(const JumblePuzzle &puzzle)
{
    row = puzzle.getRowPos();
    col = puzzle.getColPos();
    size = puzzle.getSize();
    direction = puzzle.getDirection();
    matrix = puzzle.getJumble();
}

JumblePuzzle &JumblePuzzle::operator=(const JumblePuzzle &correct)
{
    if (this != &correct)
    {
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix;
        matrix = nullptr;

        row = correct.getRowPos();
        col = correct.getColPos();
        size = correct.getSize();
        direction = correct.getDirection();
        matrix = correct.getJumble();
    }

    return *this;
}

JumblePuzzle::~JumblePuzzle()
{
    for(int i = 0; i < size; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}


charArrayPtr *JumblePuzzle::getJumble() const
{
    charArrayPtr *duplicatedJumple = new char *[size];
    for (int i = 0; i < size; i++)
    {
        duplicatedJumple[i] = new char[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            duplicatedJumple[i][j] = matrix[i][j];
        }
    }
    return duplicatedJumple;
}

char JumblePuzzle::generateRandomCharacter()
{
    return char(rand() % 26 + 97);
}

int JumblePuzzle::getSize() const
{
    return size;
}
int JumblePuzzle::getRowPos() const
{
    return row;
}
int JumblePuzzle::getColPos() const
{
    return col;
}
char JumblePuzzle::getDirection() const
{
    return direction;
}

BadJumbleException::BadJumbleException(const string& m) : message(m) {}

string& BadJumbleException::what()
{
    return message;
}