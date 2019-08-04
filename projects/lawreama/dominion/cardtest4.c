/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the getWinners() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	
*
*	Include the following lines in the makefile:
*	cardtest4: cardtest4.c dominion.o rngs.o
		gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>




int main() {

	struct gameState testState;
	int random = rand() % 10;
	int result = 0;
	int numPlayers = 2;
	int winners[4] = {0, 1, 0, 0};

	int cards[10] = { gardens, mine, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};


	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(numPlayers, cards, random, &testState);

	assert(result == 0);

	printf("Testing the getWinners() function.\n");

	result = getWinners(winners, &testState);
	assert(result == 0);

	printf("The getWinners() function worked.\n");

	return 0;

}

