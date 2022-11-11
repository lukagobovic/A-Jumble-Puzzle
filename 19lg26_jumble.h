#ifndef JUMBLE_H
#define JUMBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sstream"
#include <stdlib.h>

typedef char *charArrayPtr;

using namespace std;

class JumblePuzzle
{
private:
    int size;
    int row;
    int col;
    char direction; // nesw
    string word;
    charArrayPtr *matrix;

public:
    JumblePuzzle(const string &word, const string &difficulty);
    JumblePuzzle(const JumblePuzzle& puzzle);
    JumblePuzzle();
    ~JumblePuzzle();

    JumblePuzzle& operator=(const JumblePuzzle& puzzle);

    int getSize() const;
    int getRowPos() const;
    int getColPos() const;
    char getDirection() const;

    charArrayPtr *getJumble() const;

    char generateRandomCharacter();
   // void fillWithRandomCharacters();
};

class BadJumbleException
{
private:
    string message;

public:
    BadJumbleException(const string &);
    string &what();
};

#endif