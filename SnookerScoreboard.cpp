
#include "SnookerScoreboard.h"

#include <iostream>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define BROWN 4
#define BLUE 5
#define PINK 6
#define BLACK 7

SnookerScoreboard::SnookerScoreboard(rgb_matrix::Canvas *m) : rgb_matrix::ThreadedCanvasManipulator(m) {
	game_running = true;
	theGame = new SnookerGame();
}

SnookerScoreboard::~SnookerScoreboard(){}

void SnookerScoreboard::Run(){
	// Curses initializations
	char key = ' ';
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	
	setup_scoreboard();
	
	while(game_running){
		if(check_for_input(&key)) {
			// Handle input of keys we care about
			switch(int(key)){
				case 7:
					// Handle backspace key press
					break;
				case 10:
					// Handle enter key press
					//theGame.endBreak();
					break;
				case 42:
					// Handle '*' key press
					break;
				case 43:
					// Handle '+' key press
					break;
				case 45:
					// Handle '-' key press
					//theGame.lostRed();
					break;
				case 49:
					//theGame.addPoints(RED);
					break;
				case 50:
					//theGame.addPoints(YELLOW);
					break;
				case 51:
					//theGame.addPoints(GREEN);
					break;
				case 52:
					//theGame.addPoints(BROWN);
					break;
				case 53:
					//theGame.addPoints(BLUE);
					break;
				case 54:
					//theGame.addPoints(PINK);
					break;
				case 55:
					//theGame.addPoints(BLACK);
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

void SnookerScoreboard::stop_game(){
	game_running = false;
}

bool SnookerScoreboard::running(){
	return game_running;
}

void SnookerScoreboard::setup_scoreboard(){
	
	// Initial shooting player
	player_at_table(1, false);
	
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
	
	/*
	draw_number(0, 1, 3, 128, 128, 128);
	draw_number(0, 27, 3, 128, 128, 128);
	*/
	
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
	
	/*
	draw_number(0, 1, 13, 128, 128, 128);
	draw_number(0, 27, 13, 128, 128, 128);
	*/
	
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
	
	/*
	// Initial points on table
	draw_number(7, 24, 23, 128, 128, 128);
	draw_number(4, 19, 23, 128, 128, 128);
	draw_number(1, 16, 23, 128, 128, 128);
	
	// Initial number of reds on table
	draw_number(1, 3, 23, 128, 128, 128);
	draw_number(5, 6, 23, 128, 128, 128);
	*/
	
	update_board();
}

void SnookerScoreboard::draw_number(int number, int x, int y, int r, int g, int b){
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

void SnookerScoreboard::player_at_table(int player, bool color){
	if(player == 1){
		draw_shooting_indicator(0, 0, color);
	} else {
		draw_shooting_indicator(18, 0, color);
	}
}

void SnookerScoreboard::draw_shooting_indicator(int x, int y, bool color){
	if(color){
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
}

void SnookerScoreboard::update_board(){
	clear_board();
	update_board();
}

void SnookerScoreboard::clear_board(){
	// Clear points
	DrawLine(canvas(), 1, 3, 12, 3, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 4, 12, 4, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 5, 12, 5, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 6, 12, 6, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 7, 12, 7, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 8, 12, 8, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 1, 9, 12, 9, rgb_matrix::Color(0, 0, 0));
	
	DrawLine(canvas(), 19, 3, 30, 3, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 4, 30, 4, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 5, 30, 5, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 6, 30, 6, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 7, 30, 7, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 8, 30, 8, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 19, 9, 30, 9, rgb_matrix::Color(0, 0, 0));
	
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
	DrawLine(canvas(), 3, 23, 12, 23, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 24, 12, 24, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 25, 12, 25, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 26, 12, 26, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 27, 12, 27, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 28, 12, 28, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 3, 29, 12, 29, rgb_matrix::Color(0, 0, 0));
	
	// Clear remaining points
	DrawLine(canvas(), 16, 23, 27, 23, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 24, 27, 24, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 25, 27, 25, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 26, 27, 26, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 27, 27, 27, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 28, 27, 28, rgb_matrix::Color(0, 0, 0));
	DrawLine(canvas(), 16, 29, 27, 29, rgb_matrix::Color(0, 0, 0));
}


void SnookerScoreboard::populate_board(){
	
	// Populate player points
	int points[2];
	theGame->getPlayerScores(points);
	int x = 1;
	
	if((points[0]/100)%10 != 0){
		draw_number(1, x, 3, 128, 128, 128);
		x += 3;
	}
	
	if((points[0]/10)%10 != 0 || x == 4){
		draw_number((points[0]/10)%10, x, 3, 128, 128, 128);
		x += 5;
	}
	
	draw_number(points[0]%10, x, 3, 128, 128, 128);
	
	if((points[1]/100)%10 != 0){
		draw_number(1, 19, 3, 128, 128, 128);
	}
	
	if((points[1]/10)%10 != 0){
		draw_number((points[0]/10)%10, 22, 3, 128, 128, 128);
	}
	
	draw_number(points[1]%10, 27, 3, 128, 128, 128);
	
	// Populate player breaks
	int breaks[2];
	theGame->getPlayerBreaks(breaks);
	x = 1;
	
	if((breaks[0]/100)%10 != 0){
		draw_number(1, x, 13, 128, 128, 128);
		x += 3;
	}
	
	if((breaks[0]/10)%10 != 0 || x == 4){
		draw_number((breaks[0]/10)%10, x, 13, 128, 128, 128);
		x += 5;
	}
	
	draw_number(breaks[0]%10, x, 13, 128, 128, 128);
	
	if((breaks[1]/100)%10 != 0){
		draw_number(1, 19, 13, 128, 128, 128);
	}
	
	if((breaks[1]/10)%10 != 0){
		draw_number((breaks[0]/10)%10, 22, 13, 128, 128, 128);
	}
	
	draw_number(breaks[1]%10, 27, 13, 128, 128, 128);
	
	// Popluate reds on table
	int reds = theGame.remainingReds();
	
	if((reds/10)%10 != 0){
		draw_number(1, 3, 13, 128, 128, 128);
	}
	
	draw_number(reds%10, 6, 23, 128, 128, 128);
	
	// Populate points on table
	int pointsOnTable = theGame->remainingPoints();
	
	if((pointsOnTable/100)%10 != 0){
		draw_number(1, 16, 23, 128, 128, 128);
	}
	
	if((pointsOnTable/10)%10 != 0){
		draw_number((pointsOnTable/10)%10, 19, 23, 128, 128, 128);
	}
	
	draw_number(pointsOnTable%10, 24, 23, 128, 128, 128);
}


/***
 * Private helper method that detects and retrieves keyboard input
 */
bool SnookerScoreboard::check_for_input(char *c){
	// If error value of 255 received do nothing, otherwise 
	if((*c = getch()) != 255) {
		return true; // Key Was Hit
	}

	return false; // No keys were pressed
}
