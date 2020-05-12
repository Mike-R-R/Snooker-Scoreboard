
#include "SnookerQueue.h"

SnookerQueue::SnookerQueue(){

}


SnookerQueue::SnookerQueue(GameState initial_state){
	gameQueue.push(initial_state);
}


SnookerQueue::~SnookerQueue(){
	
}


/**
 * Adds the current state of the game to the action queue after a game
 *  state change.
 */
void SnookerQueue::game_state_changed(int pointsAddedToPlayer1, int pointsAddedToPlayer2 ,int pointsOnTable, int reds,
							int shootingPlayer, bool onRed ,bool lostRed, bool foul, bool freeBall){
	GameState game;
	game.pointsAddedToPlayer1 = pointsAddedToPlayer1;
	game.pointsAddedToPlayer2 = pointsAddedToPlayer2;
	game.pointsOnTable = pointsOnTable;
	game.reds = reds;
	game.shootingPlayer = shootingPlayer;
	game.onRed = onRed;
	game.lostRed = lostRed;
	game.foul = foul;
	game.lostRed = lostRed;
	
	gameQueue.push(game);
}


GameState* SnookerQueue::previous_game_state(){
	GameState *game = NULL;
	
	if(!gameQueue.empty()){
		game = &gameQueue.front();
		gameQueue.pop();
	}
	
	return game;
}
