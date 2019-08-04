/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the initializeGame() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	
*
*	Include the following lines in the makefile:
*	cardtest1: cardtest1.c dominion.o rngs.o
		gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
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

	int cards[10] = { gardens, mine, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};


	printf("Testing the initializeGame() function.\n");

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(numPlayers, cards, random, &testState);
	assert(result == 0);

	// This game only allows for 4 players, and should therefore return and set result equal to -1.
	result = initializeGame(5, cards, random, &testState);
	assert(result == -1);

	printf("The initializeGame() function worked.\n");

	return 0;



}