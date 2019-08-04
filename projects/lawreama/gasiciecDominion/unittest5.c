/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the do_mine() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	You may trash a Treasure from your hand. Gain a Treasure to your hand costing up to $3 more than it.
*
*	Include the following lines in the makefile:
*	unittest5: unittest5.c dominion.o rngs.o
		gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define TESTCARD "mine"



int main() {


	struct gameState testState;
	int choice1 = 0; 	// choice1 is hand# of money to trash
	int choice2 = 4;	// choice2 is supplyPos (aka. card enum) of money to put in hand
	int handPos = 3;
	int random = rand() % 100;
	int result = 0;
	int currentPlayer = 0;
	int j = 0;
	int numPlayers = 2;



	int cards[10] = { gardens, mine, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(numPlayers, cards, random, &testState);

	assert(result == 0);

	printf("Testing the do_mine() function.\n");

	for(currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++){
		if(testState.hand[currentPlayer][choice1] == copper || testState.hand[currentPlayer][choice1] == silver || testState.hand[currentPlayer][choice1] == gold){
			// runs with choice2 equal to 4 for copper, 5 for silver, and 6 for gold. 
			for (choice2 = 4; choice2 < 7; choice2++){
				do_mine(j, &testState, choice1, choice2, currentPlayer, handPos);
				assert(result == 0);
			}
		}
	}



	printf("The do_mine() function worked.\n");

	return 0;
	
}