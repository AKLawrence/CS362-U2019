/*
*	Amanda Lawrence
*	July 13, 2019
*	CS 362 - Software Engineering II
*	Assignment 3 - Learn how to create unit tests
*	
*	Unit test to test the do_minion() function in dominion.c file.
* 	This unit test should: initialize variables, call the refactored function, and assert results. 
*
*	+1 Action. Choose one: +$2; or discard your hand, +4 Cards, and each other player with at least 
*	5 cards in hand discards their hand and draws 4 cards.
*
*	Include the following lines in the makefile:
*	unittest2: unittest2.c dominion.o rngs.o
		gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define TESTCARD "minion"



int main() {


	struct gameState testState;
	int choice1 = 1; /* choice1:  1 = +2 coin, 2 = redraw */
	int choice2 = 0;
	int handPos = 0;
	int random = rand() % 100;
	int result = 0;
	int currentPlayer;


	int cards[10] = { gardens, minion, smithy, village, great_hall, steward, cutpurse, embargo, outpost, salvager};

	// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
	result = initializeGame(2, cards, random, &testState);

	assert(result == 0);

	printf("Testing the playMinion() function.\n");


	currentPlayer = whoseTurn(&testState);


	result = playMinion(choice1, choice2, &testState, currentPlayer, handPos);
	assert(result == 0);


	choice1 = 2;
	result = playMinion(choice1, choice2, &testState, currentPlayer, handPos);
	assert(result == 0);

	printf("The playMinion() function worked.\n");

	return 0;


	
}



