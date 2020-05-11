
#include "SnookerGame.h"


/**
 * Default constructor for a game of snooker
 */
SnookerGame::SnookerGame(){
    player1 = new Player(true);
    player2 = new Player(false);
    reds = 15;
    pointsOnTable = 147;
    freeBall = false;
    foul = false;
}

/**
 * Constructor for a game of snooker where p1 and p2 are
 *  true if the player is breaking and false if not.
 */
SnookerGame::SnookerGame(bool p1, bool p2){
    player1 = new Player(p1);
    player2 = new Player(p2);
    reds = 15;
    pointsOnTable = 147;
    freeBall = false;
    foul = false;
}

/**
 * Default destructor
 */
SnookerGame::~SnookerGame(){

}

/**
 * Copy assignment for a game of snooker
 */
SnookerGame& SnookerGame::operator= (const SnookerGame& g) {
    this->player1 = g.player1;
    this->player2 = g.player2;
    this->reds = g.reds;
    this->freeBall = g.freeBall;
    return *this;
}

int SnookerGame::remaining_reds(){
    return reds;
}


int SnookerGame::remaining_points(){
	return pointsOnTable;
}

/**
 * Returns the players scores in an array where the
 *  first integer is player 1 and the second is
 *  player 2
 */
void SnookerGame::get_player_scores(int * scores){
    *scores = player1->get_score();
    *(scores + 1) = player2->get_score();
}


/**
 * Returns the players breaks in an array where the
 *  first integer is player 1 and the second is
 *  player 2
 */
void SnookerGame::get_player_breaks(int * breaks){
    *breaks = player1->get_current_break();
    *(breaks + 1) = player2->get_current_break();
}


/**
 * Returns the difference in points between the two
 *  players where a positive result indicates player
 *  1 is winning and a negative indicates player
 *  2 is in the lead.
 */
int SnookerGame::point_spread(){
    int scores[2];
    get_player_scores(scores);
    
    return scores[0] - scores[1];
}


/**
 * Player potted a ball
 */
void SnookerGame::receive_point_input(int points){
	Player* playerAtTable = player_at_table();
	bool color_shot_valid = false;
	
	if(freeBall){
	    if(points > 1){
		playerAtTable->ball_potted(points);
		playerAtTable->set_on_red(false);
		freeBall = false;
	    }
	} else if(foul){
	    if(points < 4){
		add_foul_points(4);
	    } else {
		add_foul_points(points);
	    }
	} else {
		switch(points){
			case 1:
				if(reds > 0 && playerAtTable->get_on_red()){
					playerAtTable->ball_potted(points);
					reds--;
					pointsOnTable -= 1;
				}
				break;
			case 2:
				if(pointsOnTable == 27){
					color_shot_valid = true;
				}
				break;
			case 3:
				if(pointsOnTable == 25){
					color_shot_valid = true;
				}
				break;
			case 4:
				if(pointsOnTable == 22){
					color_shot_valid = true;
				}
				break;
			case 5:
				if(pointsOnTable == 18){
					color_shot_valid = true;
				}
				break;
			case 6:
				if(pointsOnTable == 13){
					color_shot_valid = true;
				}
				break;
			case 7:
				if(pointsOnTable == 7){
					color_shot_valid = true;
				}
				break;
		}
		
		if(points > 1 && !playerAtTable->get_on_red() && pointsOnTable > 27){
			color_shot_valid = true;
		}
		
		if(color_shot_valid && reds == 0 && pointsOnTable <= 27){
			playerAtTable->ball_potted(points);
			playerAtTable->set_on_red(false);
			pointsOnTable -= points;
		} else if (color_shot_valid){
			playerAtTable->ball_potted(points);
			pointsOnTable -= 7;
		}
		
	}
}


/*
 * Gets the foul status of the shooting player
 */
bool SnookerGame::player_fouled(){
    return foul;
}

/*
 * Indicates that the player at the table has fouled.
 */
void SnookerGame::foul_occurred(){
    foul = true;
}


/*
 * Add foul points to the player not at the table and end the break
 *  of the player at the table.
 */
void SnookerGame::add_foul_points(int points)
{
	Player* playerNotAtTable = player_not_at_table();
	
	playerNotAtTable->add_points(points);
	end_break();
	foul = false;
}


/**
 * Shooting player made a free ball
 */
void SnookerGame::free_ball()
{
	Player* playerAtTable = player_at_table();

    playerAtTable->add_points(1);
    playerAtTable->set_on_red(false);
    freeBall = true;
}


/**
 * This function awards a frame to the player with the
 *  highest score and resets for the next frame
 */
void SnookerGame::end_frame()
{
    int scores[2];
    get_player_scores(scores);
    
    if(scores[0] > scores[1])
    {
        player1->won_frame();
        player2->lost_frame();
    }
    else
    {
        player2->won_frame();
        player1->lost_frame();
    }
    
    reds = 15;
    pointsOnTable = 147;
}


/**
 * This function ends the break of the player at the
 *  table and begins the next players break
 */
void SnookerGame::end_break()
{
	Player* playerAtTable = player_at_table();
	Player* playerNotAtTable = player_not_at_table();
	
	if(!playerAtTable->get_on_red() && !freeBall && pointsOnTable > 27){
		pointsOnTable -= 7;
	}
	
	playerAtTable->end_break();
	playerNotAtTable->begin_break();
}


/**
 * This function accounts for a red lost during the
 *  course of play
 */
void SnookerGame::lost_red()
{
    reds--;
    pointsOnTable -= 8;
}


/**
 * Gets the player at the table and returns a 1 for player
 *  1 and a 2 for player 2.
 */
int SnookerGame::shooting_player(){
	if(player1->get_player_at_table())
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


bool SnookerGame::player_shooting_red(){
	return player_at_table()->get_on_red();
}


/**
 * Private helper method to get player at table.
 */
Player* SnookerGame::player_at_table(){
	 if(player1->get_player_at_table())
    {
        return player1;
    }
    else
    {
        return player2;
    }
}


/**
 * Private helper method to get player not at table.
 */
Player* SnookerGame::player_not_at_table(){
	 if(player1->get_player_at_table())
    {
        return player2;
    }
    else
    {
        return player1;
    }
}

