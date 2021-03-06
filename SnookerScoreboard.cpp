
#include "SnookerScoreboard.h"

#include <iostream>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define BROWN 4
#define BLUE 5
#define PINK 6
#define BLACK 7


/**
 * Default constructor for SnookerScoreboard class
 */
SnookerScoreboard::SnookerScoreboard(rgb_matrix::Canvas *m) : rgb_matrix::ThreadedCanvasManipulator(m) 
{
	game_running = true;
	theGame = new SnookerGame();
}


/**
 * Default destructor for SnookerScoreboard class
 */
SnookerScoreboard::~SnookerScoreboard()
{

}


/**
 * The main loop of the scoreboard
 */
void SnookerScoreboard::Run()
{
	// Curses initializations
	char key = ' ';
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	
	// Draw the static members of the scoreboard
	setup_scoreboard();
	
	while(game_running){
		if(check_for_input(&key)) {
			// Handle input of keys we care about
			switch(int(key)){
				case 7:
					// Handle backspace key press
					theGame->revert_game_state();
					break;
				case 10:
					// Handle enter key press
					theGame->end_break();
					break;
				case 42:
					// Handle '*' key press
					theGame->end_frame();
					break;
				case 43:
					// Handle '+' key press
					theGame->free_ball();
					break;
				case 45:
					// Handle '-' key press
					theGame->lost_red();
					break;
				case 47:
					// Handle '/' key press
					theGame->revert_game_state();
					break;
				case 48:
					// Handle '0' key press
					theGame->foul_occurred();
					break;
				case 49:
					// Handle '1' key press
					theGame->receive_point_input(RED);
					break;
				case 50:
					// Handle '2' key press
					theGame->receive_point_input(YELLOW);
					break;
				case 51:
					// Handle '3' key press
					theGame->receive_point_input(GREEN);
					break;
				case 52:
					// Handle '4' key press
					theGame->receive_point_input(BROWN);
					break;
				case 53:
					// Handle '5' key press
					theGame->receive_point_input(BLUE);
					break;
				case 54:
					// Handle '6' key press
					theGame->receive_point_input(PINK);
					break;
				case 55:
					// Handle '7' key press
					theGame->receive_point_input(BLACK);
					break;
				default:
					std::cout << key << std::endl;
					std::cout << int(key) << "\n" << std::endl;
					break;
			}
			update_board();
		}
	}
}


/**
 * Stops the scoreboard program
 */
void SnookerScoreboard::stop_game()
{
	game_running = false;
}


/**
 * Returns true if game is running and false otherwise.
 */
bool SnookerScoreboard::running()
{
	return game_running;
}


/**
 * Sets up the inital layout for the scoreboard
 */
void SnookerScoreboard::setup_scoreboard()
{
	
	// Initial shooting player
	player_shooting(1, false);
	
	// Setup P area indicating player points
	canvas()->SetPixel( 14, 3, 255, 0, 0);
	canvas()->SetPixel( 15, 3, 255, 0, 0);
	canvas()->SetPixel( 16, 3, 255, 0, 0);
	canvas()->SetPixel( 14, 4, 255, 0, 0);
	canvas()->SetPixel( 17, 4, 255, 0, 0);
	canvas()->SetPixel( 14, 5, 255, 0, 0);
	canvas()->SetPixel( 17, 5, 255, 0, 0);
	canvas()->SetPixel( 14, 6, 255, 0, 0);
	canvas()->SetPixel( 15, 6, 255, 0, 0);
	canvas()->SetPixel( 16, 6, 255, 0, 0);
	canvas()->SetPixel( 14, 7, 255, 0, 0);
	canvas()->SetPixel( 14, 8, 255, 0, 0);
	canvas()->SetPixel( 14, 9, 255, 0, 0);
	
	// Line break
	DrawLine(canvas(), 2, 11, 29, 11, rgb_matrix::Color(100, 0, 0));
	
	// Setup B area indicating current break
	canvas()->SetPixel( 14, 13, 255, 0, 0);
	canvas()->SetPixel( 15, 13, 255, 0, 0);
	canvas()->SetPixel( 16, 13, 255, 0, 0);
	canvas()->SetPixel( 14, 14, 255, 0, 0);
	canvas()->SetPixel( 17, 14, 255, 0, 0);
	canvas()->SetPixel( 14, 15, 255, 0, 0);
	canvas()->SetPixel( 17, 15, 255, 0, 0);
	canvas()->SetPixel( 14, 16, 255, 0, 0);
	canvas()->SetPixel( 15, 16, 255, 0, 0);
	canvas()->SetPixel( 16, 16, 255, 0, 0);
	canvas()->SetPixel( 14, 17, 255, 0, 0);
	canvas()->SetPixel( 17, 17, 255, 0, 0);
	canvas()->SetPixel( 14, 18, 255, 0, 0);
	canvas()->SetPixel( 17, 18, 255, 0, 0);
	canvas()->SetPixel( 14, 19, 255, 0, 0);
	canvas()->SetPixel( 15, 19, 255, 0, 0);
	canvas()->SetPixel( 16, 19, 255, 0, 0);
	
	// Frame reds and points on table area.
	DrawLine(canvas(), 0, 21, 31, 21, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 12, 21, 12, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 0, 21, 0, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 0, 31, 12, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 31, 21, 31, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 13, 31, 15, 31, rgb_matrix::Color(170, 170, 0));
	DrawLine(canvas(), 16, 31, 18, 31, rgb_matrix::Color(0, 170, 0));
	DrawLine(canvas(), 19, 31, 21, 31, rgb_matrix::Color(102, 51, 0));
	DrawLine(canvas(), 22, 31, 24, 31, rgb_matrix::Color(0, 0, 170));
	DrawLine(canvas(), 25, 31, 27, 31, rgb_matrix::Color(255, 0, 127));
	DrawLine(canvas(), 28, 31, 30, 31, rgb_matrix::Color(32, 32, 32));

	update_board();
}


/**
 * Draws a number on the scoreboard at the x and y coordinates
 *  in the rgb color passed to the function.
 */
void SnookerScoreboard::draw_number(int number, int x, int y, int r, int g, int b)
{
	switch(number){
		case 0:
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y, x, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+6, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 1:
			DrawLine(canvas(), x+1, y, x+1, y+6, rgb_matrix::Color(r, g, b));
			canvas()->SetPixel(x, y+1, r, g, b);
			break;
		case 2:
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+6, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 3:
			canvas()->SetPixel(x, y+1, r, g, b);
			DrawLine(canvas(), x+1, y, x+2, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y+1, x+3, y+2, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+1, y+3, x+2, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y+4, x+3, y+5, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+1, y+6, x+2, y+6, rgb_matrix::Color(r, g, b));
			canvas()->SetPixel(x, y+5, r, g, b);
			break;
		case 4:
			DrawLine(canvas(), x, y, x, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 5:
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y, x, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y+3, x+3, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+6, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 6:
			DrawLine(canvas(), x, y, x, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y+3, x+3, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+6, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 7:
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+1, rgb_matrix::Color(r, g, b));
			canvas()->SetPixel(x+2, y+2, r, g, b);
			DrawLine(canvas(), x+1, y+3, x+1, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 8:
			DrawLine(canvas(), x, y, x, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+6, x+3, y+6, rgb_matrix::Color(r, g, b));
			break;
		case 9:
			DrawLine(canvas(), x, y, x+3, y, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x+3, y, x+3, y+6, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y, x, y+3, rgb_matrix::Color(r, g, b));
			DrawLine(canvas(), x, y+3, x+3, y+3, rgb_matrix::Color(r, g, b));
			break;
		default:
			break;
	}
}


/**
 * Helper method for drawing the shooting indicator based on the
 *  player currently at the table.
 */
void SnookerScoreboard::player_shooting(int player, bool onRed)
{
	if(player == 1){
		draw_shooting_indicator(0, onRed);
	} else {
		draw_shooting_indicator(18, onRed);
	}
}


/**
 * Draws the shooting indicator over the player at the table
 *  based on whether player is shooting reds or colors.
 */
void SnookerScoreboard::draw_shooting_indicator(int x, bool onRed)
{
	int y = 0;
	int remainingPoints = theGame->remaining_points();
	
	// Handle the special cases for drawing the shooting indicator and
	//  default to typical drawing behavior
	switch(remainingPoints){
		case 27:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(170, 170, 0));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(170, 170, 0));
			break;
		case 25:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(0, 170, 0));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(0, 170, 0));
			break;
		case 22:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(102, 51, 0));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(102, 51, 0));
			break;
		case 18:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(0, 0, 170));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(0, 0, 170));
			break;
		case 13:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(255, 0, 127));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(255, 0, 127));
			break;
		case 7:
			DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
			DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(32, 32, 32));
			DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(32, 32, 32));
			break;
		default:
			if(!onRed){
				DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
				DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
				DrawLine(canvas(), x+1, y, x+1, y+1, rgb_matrix::Color(170, 170, 0));
				DrawLine(canvas(), x+2, y, x+2, y+1, rgb_matrix::Color(170, 170, 0));
				DrawLine(canvas(), x+3, y, x+3, y+1, rgb_matrix::Color(0, 170, 0));
				DrawLine(canvas(), x+4, y, x+4, y+1, rgb_matrix::Color(0, 170, 0));
				DrawLine(canvas(), x+5, y, x+5, y+1, rgb_matrix::Color(102, 51, 0));
				DrawLine(canvas(), x+6, y, x+6, y+1, rgb_matrix::Color(102, 51, 0));
				DrawLine(canvas(), x+7, y, x+7, y+1, rgb_matrix::Color(0, 0, 170));
				DrawLine(canvas(), x+8, y, x+8, y+1, rgb_matrix::Color(0, 0, 170));
				DrawLine(canvas(), x+9, y, x+9, y+1, rgb_matrix::Color(255, 0, 127));
				DrawLine(canvas(), x+10, y, x+10, y+1, rgb_matrix::Color(255, 0, 127));
				DrawLine(canvas(), x+11, y, x+11, y+1, rgb_matrix::Color(32, 32, 32));
				DrawLine(canvas(), x+12, y, x+12, y+1, rgb_matrix::Color(32, 32, 32));
			} else {
				DrawLine(canvas(), x, y, x, y+2, rgb_matrix::Color(100, 0, 0));
				DrawLine(canvas(), x+13, y, x+13, y+2, rgb_matrix::Color(100, 0, 0));
				DrawLine(canvas(), x+1, y, x+12, y, rgb_matrix::Color(100, 0, 0));
				DrawLine(canvas(), x+1, y+1, x+12, y+1, rgb_matrix::Color(100, 0, 0));
			}
			break;
	}
}


/**
 * Draw the foul indicator over the offending player.
 */
void SnookerScoreboard::draw_foul_indicator(int player)
{
	int y = 0;
	int x;
	
	if(player == 1){
		x = 0;
	} else {
		x = 17;
	}
	
	DrawLine(canvas(), x, y, x+2, y+2, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x, y+2, x+2, y, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+4, y, x+6, y+2, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+4, y+2, x+6, y, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+8, y, x+10, y+2, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+8, y+2, x+10, y, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+12, y, x+14, y+2, rgb_matrix::Color(255, 0, 0));
	DrawLine(canvas(), x+12, y+2, x+14, y, rgb_matrix::Color(255, 0, 0));
}


/**
 * Updates the output of the scoreboard to match the current
 *  state of the game.
 */
void SnookerScoreboard::update_board()
{
	clear_board();
	populate_board();

	int player = theGame->shooting_player();
	
	if(theGame->player_fouled()){
		draw_foul_indicator(player);
	} else {
		player_shooting(player, theGame->player_shooting_red());
	}
}


/** 
 * Clears the point, break, reds, and points on table
 *  values from the board.
 */
void SnookerScoreboard::clear_board()
{	
	// Clear shoting indicator
	DrawLine(canvas(), 0, 0, 31, 0, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 1, 31, 1, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 2, 31, 2, rgb_matrix::Color(0, 0, 0));
	
	// Clear points
	DrawLine(canvas(), 0, 3, 13, 3, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 4, 13, 4, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 5, 13, 5, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 6, 13, 6, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 7, 13, 7, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 8, 13, 8, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 9, 13, 9, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 0, 10, 13, 10, rgb_matrix::Color(0, 0, 0));
	
	DrawLine(canvas(), 18, 3, 31, 3, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 4, 31, 4, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 5, 31, 5, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 6, 31, 6, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 7, 31, 7, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 8, 31, 8, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 9, 31, 9, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 18, 10, 31, 10, rgb_matrix::Color(0, 0, 0));
	
	// Clear break
	DrawLine(canvas(), 1, 13, 12, 13, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 14, 12, 14, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 15, 12, 15, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 16, 12, 16, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 17, 12, 17, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 18, 12, 18, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 19, 12, 19, rgb_matrix::Color(0, 0, 0));
	
	DrawLine(canvas(), 19, 13, 30, 13, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 14, 30, 14, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 15, 30, 15, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 16, 30, 16, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 17, 30, 17, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 18, 30, 18, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 19, 30, 19, rgb_matrix::Color(0, 0, 0));
	
	// Clear reds
	DrawLine(canvas(), 3, 23, 9, 23, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 24, 9, 24, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 25, 9, 25, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 26, 9, 26, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 27, 9, 27, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 28, 9, 28, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 29, 9, 29, rgb_matrix::Color(0, 0, 0));
	
	// Clear remaining points
	DrawLine(canvas(), 16, 23, 27, 23, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 24, 27, 24, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 25, 27, 25, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 26, 27, 26, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 27, 27, 27, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 28, 27, 28, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 29, 27, 29, rgb_matrix::Color(0, 0, 0));
}


/**
 * Populates the current points, break, reds, and points
 *  on table value spaces on the board.
 */
void SnookerScoreboard::populate_board()
{	
	// Populate player points
	int points[2];
	theGame->get_player_scores(points);
	int pointDiff = theGame->point_spread();
	int remainingPoints = theGame->remaining_points();
	
	// Determine if a player is further behind in points than are left
	//  on the table and invert their score coloring if they are.
	if(pointDiff >= 0 && pointDiff > remainingPoints){
		// Draw player 2 inverted
		draw_left_aligned(points[0], 1, 3, 128, 128, 128);
		draw_right_inverted(points[1]);
	} else if((pointDiff*-1) > remainingPoints){
		// Draw player 1 inverted
		draw_left_inverted(points[0]);
		draw_right_aligned(points[1], 19, 3, 128, 128, 128);
	} else {
	
		draw_left_aligned(points[0], 1, 3, 128, 128, 128);
		draw_right_aligned(points[1], 19, 3, 128, 128, 128);
	}
	
	
	// Populate player breaks
	int breaks[2];
	theGame->get_player_breaks(breaks);

	draw_left_aligned(breaks[0], 1, 13, 128, 128, 128);
	draw_right_aligned(breaks[1], 19, 13, 128, 128, 128);
	
	
	// Popluate reds on table
	int reds = theGame->remaining_reds();
	
	if((reds/10)%10 != 0){
		draw_number(1, 3, 23, 128, 128, 128);
	}
	
	draw_number(reds%10, 6, 23, 128, 128, 128);
	
	
	// Populate points on table
	int pointsOnTable = theGame->remaining_points();
	
	draw_right_aligned(pointsOnTable, 16, 23, 128, 128, 128);
}


/**
 * Draws a value left aligned.
 */
void SnookerScoreboard::draw_left_aligned(int value, int x, int y, int r, int g, int b)
{	
	// Draw hundreds place if present
	if((value/100)%10 != 0){
		draw_number(1, x, y, r, g, b);
		x += 3;
	}
	
	// Draw tens place if present
	if((value/10)%10 != 0 || x == 4){
		draw_number((value/10)%10, x, y, r, g, b);
		x += 5;
	}
	
	// Draw ones place
	draw_number(value%10, x, y, r, g, b);
}


/**
 * Draws a value right aligned.
 */
void SnookerScoreboard::draw_right_aligned(int value, int x, int y, int r, int g, int b)
{	
	// Draw hundreds place if present
	if((value/100)%10 != 0){
		draw_number(1, x, y, r, g, b);
	}
	
	// Draw tens place if present
	if((value/10)%10 != 0 || (value/100)%10 != 0){
		draw_number((value/10)%10, x+3, y, r, g, b);
	}
	
	// Draw ones place
	draw_number(value%10, x+8, y, r, g, b);
}


/**
 * Draws the passed value left aligned and in inverted colors
 */
void SnookerScoreboard::draw_left_inverted(int value)
{
	DrawLine(canvas(), 1, 2, 12, 2, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 3, 13, 3, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 4, 13, 4, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 5, 13, 5, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 6, 13, 6, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 7, 13, 7, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 8, 13, 8, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 9, 13, 9, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 0, 10, 13, 10, rgb_matrix::Color(128, 128, 128));

	draw_left_aligned(value, 1, 3, 0, 0, 0);
}

/**
 * Draws the passed value right aligned and in inverted colors
 */
void SnookerScoreboard::draw_right_inverted(int value)
{
	DrawLine(canvas(), 19, 2, 30, 2, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 3, 31, 3, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 4, 31, 4, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 5, 31, 5, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 6, 31, 6, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 7, 31, 7, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 8, 31, 8, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 9, 31, 9, rgb_matrix::Color(128, 128, 128));
	DrawLine(canvas(), 18, 10, 31, 10, rgb_matrix::Color(128, 128, 128));
	
			
	draw_right_aligned(value, 19, 3, 0, 0, 0);
}

/**
 * Private helper method that detects and retrieves keyboard input
 */
bool SnookerScoreboard::check_for_input(char *c)
{
	// If error value of 255 received do nothing, otherwise 
	if((*c = getch()) != 255) {
		return true; // Key Was Hit
	}

	return false; // No keys were pressed
}
