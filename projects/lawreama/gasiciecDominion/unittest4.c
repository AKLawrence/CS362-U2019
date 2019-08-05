/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the do_tribute() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	The player to your left reveals then discards the top 2 cards of his deck. For each differently named card revealed, if it is an…
*		Action Card, +2 Actions
*		Treasure Card, +$2
*		Victory Card, +2 Cards
*
*	Include the following lines in the makefile:
*	unittest4: unittest4.c dominion.o rngs.o
		gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define TESTCARD "tribute"



int main() {

	struct gameState testState;
	//int tributeRevealedCards[2] = {-1, -1};
	int random = rand() % 100;
	int nextPlayer = 0;
	int currentPlayer = 1;
	int result = 0;

	int cards[10] = { gardens, tribute, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(2, cards, random, &testState);

	assert(result == 0);

	printf("Testing the playTribute() function.\n");

	result = playTribute(&testState, nextPlayer, currentPlayer);

	assert(result == 0);

	printf("The playTribute() function worked.\n");

	return 0;


	
}