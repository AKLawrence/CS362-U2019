/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the shuffle() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	
*
*	Include the following lines in the makefile:
*	cardtest2: cardtest2.c dominion.o rngs.o
		gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
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
	int random = rand() % 100;
	int result = 0;
	int numPlayers = 2;
	int player = 0;

	int cards[10] = { gardens, mine, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};



	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(numPlayers, cards, random, &testState);

	assert(result == 0);

	printf("Testing the shuffle() function.\n");

	// int shuffle(int player, struct gameState *state)
	for (player = 0; player < numPlayers; player++){
		result = shuffle(player, &testState);
		assert(result == 0);
	}

	// testing on an invalid input, of player 5, which is greater than the maximum allowed players in this game.
	result = shuffle(4, &testState);
	assert(result == -1);

	printf("The shuffle() function worked.\n");

	return 0;

}


