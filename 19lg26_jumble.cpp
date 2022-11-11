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
    //Make sure that the word is the proper length, otherwise throw an exception
    if (size < 3 || size > 10)
    {
        throw BadJumbleException("Invalid length, word must be between 3 and 10 characters");
    }

    //Set the size according to the appropriate difficulty
    //If no size matches, throw the appropriate exception
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

    //There are 4 possible directions, n e s w, choose one of the randomly
    int dir = rand() % 4;
    //Random placements
    int placementA, placementB;
    string directions = "nesw";
    //Choose a random direction from the string above
    direction = directions[dir];

    int placementDirA[4] = {-1, 0, 1, 0};
    int placementDirB[4] = {0, 1, 0, -1};

    placementA = placementDirA[dir];
    placementB = placementDirB[dir];

    int val1S, val2S;
    int val1E, val2E;

    //Essentially in the following statements, we generate a random row and column, and then we use 
    //conditional expressions to check if the word can fit in the given location and direction. If 
    //not, we move onto the next direction and try again until a fit is found
    row = rand() % (size - (placementA ? wordLen - 1 : 0)) + (placementA == -1 ? wordLen - 1 : 0);
    col = rand() % (size - (placementB ? wordLen - 1 : 0)) + (placementB == -1 ? wordLen - 1 : 0);

    //Once we find a location that works, we fill the matrix with random characters using the
    //generate random char function, which returns a random character from a-z 
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

    //Once we generate the matrix, we add in the word in the location that it fit in
    int i = row;
    int j = col;
    int count;
    for (count = 0; count < wordLen; count++)
    {
        matrix[i][j] = word[count];
        i += placementA;
        j += placementB;
    }
}

//Copy constructor that uses the various accessor methods to copy all of the values over to the new puzzle
JumblePuzzle::JumblePuzzle(const JumblePuzzle &puzzle)
{
    row = puzzle.getRowPos();
    col = puzzle.getColPos();
    size = puzzle.getSize();
    direction = puzzle.getDirection();
    matrix = puzzle.getJumble();
}

//Overloading the = operator
JumblePuzzle &JumblePuzzle::operator=(const JumblePuzzle &correct)
{
    if (this != &correct)
    {
        //if they arent equal, make sure to delete the matrix and clear it
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix;
        matrix = nullptr;

        //Copying all of the values
        row = correct.getRowPos();
        col = correct.getColPos();
        size = correct.getSize();
        direction = correct.getDirection();
        matrix = correct.getJumble();
    }

    return *this;
}

//Destructor that will delete the array of pointers and then set all of them to NULL
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

//Create a new matrix that holds the same data, but will prevent memory leaks
//This is why we return a copy, to avoid memory leaks and other issues
charArrayPtr *JumblePuzzle::getJumble() const
{
    //Process is almost exaclty the same as in constructor
    //Initialize the matrix
    charArrayPtr *duplicatedJumple = new char *[size];
    for (int i = 0; i < size; i++)
    {
        duplicatedJumple[i] = new char[size];
    }
    //Nested loop to copy all of the data over from the old to new
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            duplicatedJumple[i][j] = matrix[i][j];
        }
    }
    //Return new one.
    return duplicatedJumple;
}

//Function returns a random character from a-z using ASCII values 
char JumblePuzzle::generateRandomCharacter()
{
    return char(rand() % 26 + 97);
}

//Returns size
int JumblePuzzle::getSize() const
{
    return size;
}
//Returns row
int JumblePuzzle::getRowPos() const
{
    return row;
}
//Returns column
int JumblePuzzle::getColPos() const
{
    return col;
}
//Returns direction
char JumblePuzzle::getDirection() const
{
    return direction;
}

//Bad Jumble Exception class for error handling
BadJumbleException::BadJumbleException(const string& m) : message(m) {}

string& BadJumbleException::what()
{
    return message;
}