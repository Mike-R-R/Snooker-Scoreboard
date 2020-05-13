
#include "SnookerQueue.h"


SnookerQueue::SnookerQueue(){

}


SnookerQueue::~SnookerQueue(){
	
}


/**
 * Adds the passed new game state to the state queue.
 */
void SnookerQueue::add_new_state(GameState newState){
	gameQueue.push(newState);
}


/**
 * Adds a game state to the queue based on passed values.
 */
void SnookerQueue::add_new_state(int pointsAdded, int pointsOnTable, int reds, int shootingPlayer, 
										bool onRed ,bool lostRed, bool foul, bool freeBall){
	GameState game;
	game.pointsAdded = pointsAdded;
	game.pointsOnTable = pointsOnTable;
	game.reds = reds;
	game.shootingPlayer = shootingPlayer;
	game.onRed = onRed;
	game.lostRed = lostRed;
	game.foul = foul;
	game.freeBall = freeBall;
	
	gameQueue.push(game);
}


/**
 * Removes the last state pushed to the queue and returns it.
 */
GameState* SnookerQueue::previous_game_state(){
	GameState *game = 0;
	
	if(!gameQueue.empty()){
		game = &gameQueue.front();
		gameQueue.pop();
	}
	
	return game;
}
