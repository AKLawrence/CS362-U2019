/*
*	Amanda Lawrence
*	July 28, 2019
*	CS 362 - Software Engineering II
*	Assignment 4 - Learn how to create a Random Tester
*	
*	Random tester to test the baron card in dominion.c file.
*	
*	Baron Card: +1 Buy You may discard an Estate card for +$4. If you don't, gain an Estate.
*
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {

	struct gameState state, testState;
	int handPos = 0;
	int choice1 = 0;  /* choice1 is boolean for discard of estate. 0 or less means we do not discard an estate. */
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int player = 0;
	int i = 0;
	int numPlayers = 0;
	int random = 0;

	int cards[10] = { gardens, mine, smithy, baron, great_hall, steward, cutpurse, estate, outpost, salvager};


	for(i = 0; i < 100; i++){

		printf("\n***********Testing: BARON CARD. Attempt: %d of 100.***********\n", i+1);

		// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
		random = rand() % 100;
		numPlayers = rand() % (3) + 2; // gives us 2, 3, or 4 players.
		player = floor(rand() % numPlayers);
		choice1 = rand() % (2) + 0;		// gives us either 0 or 1.

		initializeGame(numPlayers, cards, random, &state);

		//printf("\nGet here?\n");

		//Run our tests on the copy of our gameState, testState.
		memcpy(&testState, &state, sizeof(struct gameState));

		//printf("\nHow aboout here?\n");
		
		cardEffect(baron, choice1, choice2, choice3, &state, handPos, &bonus);



		//Let whoseTurn() generate which player
		//player = whoseTurn(&state);

		// check their hand, to see if they received card
		if(state.hand[player][testState.handCount[player]-1] != -1){
			printf("Successfully added Baron card to players hand \n");
		} else if (state.hand[player][testState.handCount[player]-2] != -1){
			printf("Successfully added Baron card to players hand \n");
		} else {
			printf("Failed to add Baron card to players hand.\n");
		}

		// Check if they played the baron card
		if(testState.playedCardCount == state.playedCardCount-1){
			printf("Player successfully played Baron card.\n");
		} else {
			printf("Player did not successfully play Baron card.\n");
		}

		// Check if card was discarded.
		if(testState.discardCount[player] == state.discardCount[player]){	// Discarded Baron card, and gained an estate card.
			printf("Successfully discarded Baron card, and gained an estate card.\n");
		} else if(testState.discardCount[player] == state.discardCount[player]-1){		// Discarded Baron and Estate card.
			printf("Successfully discarded Baron and Estate card.\n");
		} else {
			printf("Did not successfully discard Baron card.\n");
		}


		// Check if 4 coins added 
		if(testState.coins+4 == state.coins){
			printf("Successfully added four coins.\n");
		} else {
			printf("Did not add four coins.\n");
		}


		// Check if our buys counter was incremented
		if(testState.numBuys+1 == state.numBuys){
			printf("Successfully added to our number of buys.\n");
		} else {
			printf("Did not successfully add to our number of buys.\n");
		}

	}


	return 0;
}





