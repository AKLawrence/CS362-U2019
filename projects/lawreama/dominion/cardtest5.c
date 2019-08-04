/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the drawCard() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	
*
*	Include the following lines in the makefile:
*	cardtest5: cardtest5.c dominion.o rngs.o
		gcc -o cardtest5 -g cardtest5.c dominion.o rngs.o $(CFLAGS)
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
	int player = 1;

	int cards[10] = { gardens, mine, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};


	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(numPlayers, cards, random, &testState);

	assert(result == 0);

	printf("Testing the drawCard() function.\n");

	// int drawCard(int player, struct gameState *state)
	result = drawCard(player, &testState);
	assert(result == 0);

	// Testing with an invalid input, with a player that doesn't exist
	result = drawCard(6, &testState);
	assert(result == -1);


	printf("The drawCard() function worked.\n");

	return 0;

}