
#include "SnookerStack.h"


/**
 * Default constructor for SnookerStack class
 */
SnookerStack::SnookerStack()
{

}


/**
 * Default destructor for SnookerStack class
 */
SnookerStack::~SnookerStack()
{
	
}


/**
 * Adds the passed game state to the state stack.
 */
void SnookerStack::add_game_state(GameState newState)
{
	gameQueue.push(newState);
}


/**
 * Adds a game state to the stack based on passed values.
 */
void SnookerStack::add_game_state(int p1Points, p2Points, int pointsOnTable, int reds,
									int shootingPlayer, bool onRed, bool foul, bool freeBall)
{
	GameState game;
	game.p1Points = p1Points;
	game.p2Points = p2Points;
	game.pointsOnTable = pointsOnTable;
	game.reds = reds;
	game.shootingPlayer = shootingPlayer;
	game.onRed = onRed;
	game.foul = foul;
	game.freeBall = freeBall;
	
	gameQueue.push(game);
}


/**
 * Removes the last state pushed to the stack and returns it.
 */
GameState* SnookerStack::previous_game_state()
{
	GameState *game = 0;
	
	if(!gameStack.empty()){
		game = &gameStack.top();
		gameStack.pop();
	}
	
	return game;
}
