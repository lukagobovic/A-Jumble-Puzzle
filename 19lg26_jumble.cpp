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