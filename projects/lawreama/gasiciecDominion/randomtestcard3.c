/*
*	Amanda Lawrence
*	July 28, 2019
*	CS 362 - Software Engineering II
*	Assignment 4 - Learn how to create a Random Tester
*	
*	Random tester to test the tribute card in dominion.c file.
*	
*	The player to your left reveals then discards the top 2 cards of his deck. For each differently named card 
*	revealed, if it is an…
*		Action Card, +2 Actions
*		Treasure Card, +$2
*		Victory Card, +2 Cards
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
	int choice1 = 0;  
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int player = 0;
	int i = 0;
	int numPlayers = 0;

	int cards[10] = { gardens, mine, smithy, tribute, great_hall, steward, cutpurse, embargo, outpost, salvager};


	for(i = 0; i < 100; i++){

		printf("\n***********Testing: TRIBUTE CARD. Attempt: %d of 100.***********\n", i+1);

		// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
		int random = rand() % 100;
		numPlayers = rand() % (3) + 2; // gives us 2, 3, or 4 players.
		player = floor(rand() % numPlayers);

		initializeGame(numPlayers, cards, random, &state);

		//Run our tests on the copy of our gameState, testState.
		memcpy(&testState, &state, sizeof(struct gameState));
		cardEffect(tribute, choice1, choice2, choice3, &state, handPos, &bonus);

		//Let whoseTurn() generate which player
		player = whoseTurn(&state);

		// check their hand, to see if they received card
		if(state.hand[player][testState.handCount[player]-1] != -1){
			printf("Successfully added Tribute card to players hand \n");
		} else if (state.hand[player][testState.handCount[player]+1] != -1){
			printf("Successfully added Tribute card to players hand \n");	// played tribute card, and drew 2 cards.
		} else {
			printf("Failed to add Tribute card to players hand.\n");
		}

		// Check if they played the tribute card
		if(testState.playedCardCount == state.playedCardCount-1){
			printf("Player successfully played Tribute card.\n");
		} else if (testState.playedCardCount == state.playedCardCount+1){
			printf("Player successfully played Tribute card.\n");	// played tribute card, and drew 2 cards.
		} else {
			printf("Player did not successfully play Tribute card.\n");
		}

		// Check if card was discarded.
		if(testState.discardCount[player] == state.discardCount[player]){
			printf("Successfully discarded Tribute card.\n");
		} else {
			printf("Did not successfully discard Tribute card.\n");
		}


		// Check if 4 or 2 coins added 
		if(testState.coins-4 == state.coins){
			printf("Successfully added four coins.\n");
		} else if (testState.coins-2 == state.coins) {
			printf("Successfully added two coins.\n");
		} else {
			printf("Did not add two coins.\n");
		}


		// Check if our actions counter was incremented
		if(testState.numActions == state.numActions-4){
			printf("Successfully added 4 to our number of actions.\n");
		} else if (testState.numActions == state.numActions-2){
			printf("Successfully added 2 to our number of actions.\n");
		} else {
			printf("Did not add to our number of actions.\n");
		}

	}


	return 0;
}






