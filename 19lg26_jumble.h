#ifndef 19lg26_jumble_H
#define 19lg26_jumble_H

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
    int len;
    int row;
    int col;
    char direction; // nesw
    string word;
    charArrayPtr *matrix;

public:
    JumblePuzzle(const string &word, const string &difficulty);
    JumblePuzzle(const JumblePuzzle& puzzle);
    ~JumblePuzzle();

    JumblePuzzle& operator=(const JumblePuzzle& puzzle);

    int getSize() const;
    int getRowPosition() const;
    int getColPosition() const;
    char getDirection() const;

    charArrayPtr *getJumble() const;
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