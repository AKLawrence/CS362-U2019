/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the do_ambassador() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
* 	
*	Reveal a card from your hand. Return up to 2 copies of it from your hand to the Supply. Then 
*	each other player gains a copy of it.
*
*	Include the following lines in the makefile:
*	unittest3: unittest3.c dominion.o rngs.o
		gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define TESTCARD "ambassador"



int main() {

	struct gameState testState;
	int choice1 = 0; 	// choice1 = hand# 
	int choice2 = 0;	// choice2 = number to return to supply(can be 0, 1, or 2)
	int handPos = 3;
	int random = rand() % 100;
	int result = 0;
	int currentPlayer = 0;
	int j = 0;

	int cards[10] = { gardens, ambassador, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(2, cards, random, &testState);

	assert(result == 0);

	printf("Testing the do_ambassador() function.\n");

	for (choice2 = 0; choice2 > 3; choice2++){
		result = do_ambassador(j, choice1, choice2, handPos, &testState, currentPlayer);
		assert(result == 0);
	}


	printf("The do_ambassador() function worked.\n");

	return 0;

	
}




