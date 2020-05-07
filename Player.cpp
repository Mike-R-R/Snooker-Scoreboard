#include "Player.h"

/**
 * Default constructor for Player class
 */
Player::Player()
{
    score = 0;
    highBreak = 0;
    framesWon = 0;
    onRed = true;
    atTable = false;
}


/**
 * Constructor for Player where _shooting sets
 *  if the Player is currently at the table
 */
Player::Player(bool breaking)
{
    score = 0;
    highBreak = 0;
    framesWon = 0;
    onRed = true;
    atTable = breaking;
}


/**
 * Default destructor for Player
 */
Player::~Player()
{}


/**
 * Copy assignment for Player
 */
Player& Player::operator= (const Player& temp)
{
    this->score = temp.score;
    this->highBreak = temp.highBreak;
    this->framesWon = temp.framesWon;
    this->currentBreak = temp.currentBreak;
    this->atTable = temp.atTable;
    this->onRed = temp.onRed;
    return *this;
}


/**
 * Returns Player score
 */
int Player::getScore(){return score;}


/**
 * Returns frames won by Player
 */
int Player::getFrameswon(){return framesWon;}


/***
 * Returns the players current break
 */
int Player::getCurrentBreak(){return currentBreak;}

/**
 * Returns Players highest break
 */
int Player::getHighBreak(){return highBreak;}


/***
 * Returns whether the player is shooting a red or color
 */
bool Player::getOnRed(){return onRed;}


/**
 * Returns boolean representing whether the Player
 *  is currently at the table
 */
bool Player::playerAtTable(){return atTable;}


/**
 * Adds input integer points to players score
 */
void Player::addPoints(int points)
{
    score += points;
    currentBreak += points;
    onRed = !onRed;
}


/**
 * Ends the Players current break
 */
void Player::endBreak()
{
    atTable = false;
    if(currentBreak > highBreak)
        highBreak = currentBreak;
    currentBreak = 0;
    onRed = true;
}


/**
 * Begins the Players break
 */
void Player::beginBreak()
{
    atTable = true;
}


/**
 * This function adds a won frame to Player
 *  and resets Player for next frame
 */
void Player::wonFrame()
{
    framesWon++;
    score = 0;
    currentBreak = 0;
}


/**
 * This function resets player for next frame
 */
void Player::lostFrame()
{
    score = 0;
    currentBreak = 0;
}
