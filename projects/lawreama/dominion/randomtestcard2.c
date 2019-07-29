/*
*	Amanda Lawrence
*	July 28, 2019
*	CS 362 - Software Engineering II
*	Assignment 4 - Learn how to create a Random Tester
*	
*	Random tester to test the minion card in dominion.c file.
*	
*	+1 Action
*	Choose one: +$2; or discard your hand, +4 Cards, and each other player with at least 5 cards in hand discards 
*	their hand and draws 4 cards.
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

	struct gameState state, testState;
	int handPos = 0;
	int choice1 = 1;  /* choice1:  1 = +2 coin, 2 = redraw */
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int player = 0;
	int i = 0;
	int numPlayers = 2;


	int cards[10] = { gardens, mine, smithy, minion, great_hall, steward, cutpurse, embargo, outpost, salvager};

	for(i = 0; i < 100; i++){

		if(i >= 49){
			choice1 = 2;
		}

		printf("\n***********Testing: MINION CARD. Attempt: %d of 100.***********\n", i+1);

		// int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)
		int random = rand() % 100;
		initializeGame(numPlayers, cards, random, &state);

		//Run our tests on the copy of our gameState, testState.
		memcpy(&testState, &state, sizeof(struct gameState));
		cardEffect(minion, choice1, choice2, choice3, &state, handPos, &bonus);

		//Let whoseTurn() generate which player
		player = whoseTurn(&state);

		// check their hand, to see if they received card
		if(state.hand[player][testState.handCount[player]-1] != -1){
			printf("Successfully added Minion card to players hand \n");	// played minion card, and gained 2 coins. 
		} else if (state.hand[player][testState.handCount[player]+3] != -1){
			printf("Successfully added Minion card to players hand \n");	// played minion card, and drew 4 cards.
		} else {
			printf("Failed to add Minion card to players hand.\n");
		}

		// Check if they played the minion card, 
		if(testState.playedCardCount == state.playedCardCount-1){
			printf("Player successfully played Minion card.\n");	// played minion card, and gained 2 coins. 
		} else if (testState.playedCardCount+3 == state.playedCardCount){
			printf("Player successfully played Minion card.\n");	// played minion card, and drew 4 cards.
		} else {
			printf("Player did not successfully play Minion card.\n");
		}

		// Check if card was discarded.
		if(testState.discardCount[player] == state.discardCount[player]){
			printf("Successfully discarded Minion card.\n");
		} else {
			printf("Did not successfully discard Minion card.\n");
		}

		// Check if our actions counter was incremented
		if(testState.numActions == state.numActions-1){
			printf("Successfully added to our number of actions.\n");
		} else {
			printf("Did not add to our number of actions.\n");
		}

	}


	return 0;
}




