#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sstream"
#include <stdlib.h>

using namespace std;

int main(){
  //srand(time(0));
  string hiddenWord = "test";
  int size = hiddenWord.length();
  int dir = 2;
	int south_inc, east_inc;
	string directions = "nesw";
	int south_incs[4] = {-1, 0, 1, 0};
	int east_incs[4] = {0, 1, 0, -1};
	char direction = directions[dir];
	south_inc = south_incs[dir];
	east_inc = east_incs[dir];
	int wordLen = hiddenWord.length();
	
	// Pick a spot where the word is sure to fit, based on which way it's going

  // // printf("%d\n",dir);
  
  // int temp;
  // if(south_inc){
  //    temp  = wordLen - 1;
  // }
  // else{
  //    temp = 0;
  // }

  // printf("%d\n", temp);

  // // if((south_inc ? wordLen - 1 : 0)){
  // //   printf("true");
  // // }

    
    int val1S, val2S;
    int val1E, val2E;

    if (south_inc)
        val1S = wordLen - 1;
    else
        val1S = 0;

    if (south_inc == -1)
        val2S = wordLen - 1;
    else
        val2S = 0;

    if (east_inc)
        val1E = wordLen - 1;
    else
        val1E = 0;

    if (east_inc == -1)
        val2E = wordLen - 1;
    else
        val2E = 0;

   int row = rand() % (size - val1S) + val2S;
   int col = rand() % (size - val1E) + val2E;

  printf("row: %d\ncol: %d\n", row, col);
}