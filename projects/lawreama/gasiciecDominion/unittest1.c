/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the do_baron() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
* 	The Baron card reads: +1 Buy. You may discard an Estate for +$4. If you don't, gain an Estate.
*
*	Include the following lines in the makefile:
*	unittest1: unittest1.c dominion.o rngs.o
		gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define TESTCARD "baron"



int main() {

	struct gameState testState;
	int choice1 = 1; /* choice1 is boolean for discard of estate. 0 or less means we do not discard an estate. */
	int random = rand() % 10;
	int result = 0;
	int currentPlayer = 0;

	int cards[10] = { gardens, baron, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(2, cards, random, &testState);

	assert(result == 0);

	printf("Testing the do_baron() function.\n");

	// int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	// Baron's choice1 is boolean for discard of estate. 0 or less means we do not discard an estate.
	result = do_baron(&testState, choice1, currentPlayer);
	assert(result == 0);

	choice1 = 0;
	result = do_baron(&testState, choice1, currentPlayer);

	assert(result == 0);

	printf("The do_baron() function worked.\n");

	return 0;
}



