#include "SnookerGame.h"

/*
 * Default constructor for a game of snooker
 */
SnookerGame::SnookerGame()
{
    player1 = Player(true);
    player2 = Player(false);
    reds = 15;
    pointsOnTable = 147;
}

/*
 * Constructor for a game of snooker where p1 and p2 are
 *  true if the player is breaking and false if not.
 */
SnookerGame::SnookerGame(bool p1, bool p2)
{
    player1 = Player(p1);
    player2 = Player(p2);
    reds = 15;
    pointsOnTable = 147;
}

/*
 * Default destructor
 */
SnookerGame::~SnookerGame()
{}

/*
 * Copy assignment for a game of snooker
 */
SnookerGame& SnookerGame::operator= (const SnookerGame& g) 
{
    this->player1 = g.player1;
    this->player2 = g.player2;
    this->reds = g.reds;
    return *this;
}

int SnookerGame::remainingReds()
{
    return reds;
}


int SnookerGame::remainingPoints()
{
	return pointsOnTable;
}

/*
 * Returns the players scores in an array where the
 *  first integer is player 1 and the second is
 *  player 2
 */
void SnookerGame::getPlayerScores(int * arr)
{
    *arr = player1.getScore();
    *(arr + 1) = player2.getScore();
}


/*
 * Returns the players breaks in an array where the
 *  first integer is player 1 and the second is
 *  player 2
 */
void SnookerGame::getPlayerBreaks(int *)
{
    *arr = player1.getCurrentBreak();
    *(arr + 1) = player2.getCurrentBreak();
}


/*
 * Returns the spread of points between players where
 *  the first integer is player 1 spread and the
 *  second is player 2
 */
void SnookerGame::pointSpread(int * arr)
{
    int scores[2];
    getPlayerScores(scores);
    
    *arr = scores[0] - scores[1];
    *(arr + 1) = *arr * (-1);
}


/*
 * Add scored points to the player at the table
 */
void SnookerGame::addPoints(int points)
{
    if(player1.playerAtTable())
    {
        player1.addPoints(points);
    }
    else
    {
        player2.addPoints(points);
    }
    
    if(points == 1)
        reds--;
}


/*
 * Add foul points to the player not at the table
 */
void SnookerGame::foul(int points)
{
    if(!player1.playerAtTable())
    {
        player1.addPoints(points);
        player2.endBreak();
        player1.beginBreak();
    }
    else
    {
        player2.addPoints(points);
        player1.endBreak();
        player2.beginBreak();
    }
}


/*
 * Shooting player made a free ball
 */
void SnookerGame::freeBall()
{
    if(!player1.playerAtTable())
    {
        player1.addPoints(1);
    }
    else
    {
        player2.addPoints(1);
    }
}


/*
 * This function awards a frame to the player with the
 *  highest score and resets for the next frame
 */
void SnookerGame::endFrame()
{
    int scores[2];
    getPlayerScores(scores);
    
    if(scores[0] > scores[1])
    {
        player1.wonFrame();
    }
    else
    {
        player2.wonFrame();
    }
    
    reds = 15;
    pointsOnTable = 147;
}


/*
 * This function ends the break of the player at the
 *  table and begins the next players break
 */
void SnookerGame::endBreak()
{
    if(player1.playerAtTable())
    {
        player1.endBreak();
        player2.beginBreak();
    }
    else
    {
        player1.beginBreak();
        player2.endBreak();
    }
}


/**
 * This function accounts for a red lost during the
 *  course of play
 */
void SnookerGame::lostRed()
{
    reds--;
}


