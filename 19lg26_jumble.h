#ifndef JUMBLE_H
#define JUMBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sstream"
#include <stdlib.h>

//Typedef to make things more convenient when declaring, as opposed to using ** in the creation of the matrix
typedef char *charArrayPtr;

using namespace std;

class JumblePuzzle
{
//All of the private fields used in jumble puzzle, prevents unwanted access, which could cause leaks
private:
    int size; //Size of matrix
    int row;  //Current row
    int col;  //Current column
    char direction; // nesw
    string word;    //the word to be found/hidden
    charArrayPtr *matrix;   //The jumble puzzle matrix of type charArrayPtr, redeuces the need for double star

public:
    //Constructor that takes in a word and difficulty, and sets up the game as expected
    JumblePuzzle(const string &word, const string &difficulty);
    //This is a copy constructor that returns a copy to the original jumble matrix, preventing memory leaks
    JumblePuzzle(const JumblePuzzle& puzzle);
    //Default construtor, sets all parameters to either 0 or nullptr. While not needed it is good to have incase someone creates an instance with no fields
    JumblePuzzle();
    //Destructor that gets rid of the old matrix after either a successful find or termination of the program
    //Aims to clean up memory and the heap
    ~JumblePuzzle();

    //Assignment operator overloading 
    JumblePuzzle& operator=(const JumblePuzzle& puzzle);

    
    //These are the accessors that are used not only in the test file, but also in the implementation file for the copy construtor
    int getSize() const; //Returns size
    int getRowPos() const; //Returns row
    int getColPos() const; //Returns col
    char getDirection() const; //Returns the direction
    //Using the typedef defined above in this file, this function will return the jumble matrix
    charArrayPtr *getJumble() const;

    //Will generate and return a random character from a-z, using random ASCII values
    char generateRandomCharacter();
};

//Class used for throwing various exceptions related to inputs
class BadJumbleException
{
private:
    string message;

public:
    BadJumbleException(const string &);
    string &what();
};

#endif