
#include "SnookerGame.h"
#include <iostream>

SnookerGame::SnookerGame(rgb_matrix::Canvas *m) : rgb_matrix::ThreadedCanvasManipulator(m) {
	game_running = true;
}

SnookerGame::~SnookerGame(){}

void SnookerGame::Run(){
	//curses initializations
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
				case 10:
					// Handle enter key press
					break;
				case 43:
					// Handle '+' key press
					break;
				case 45:
					// Handle '-' key press
					break;
				case 49:
					break;
				case 50:
					break;
				case 51:
					break;
				case 52:
					break;
				case 53:
					break;
				case 54:
					break;
				case 55:
					break;
				default:
					std::cout << key << std::endl;
					std::cout << int(key) << "\n" << std::endl;
					break;
			}
		}	
	}
}

void SnookerGame::stop_game(){
	game_running = false;
}

bool SnookerGame::running(){
	return game_running;
}

void SnookerGame::setup_scoreboard(){
	// Setup P area indicating player points
	canvas()->SetPixel( 14, 1, 255, 0, 0);
	canvas()->SetPixel( 15, 1, 255, 0, 0);
	canvas()->SetPixel( 16, 1, 255, 0, 0);
	canvas()->SetPixel( 14, 2, 255, 0, 0);
	canvas()->SetPixel( 17, 2, 255, 0, 0);
	canvas()->SetPixel( 14, 3, 255, 0, 0);
	canvas()->SetPixel( 17, 3, 255, 0, 0);
	canvas()->SetPixel( 14, 4, 255, 0, 0);
	canvas()->SetPixel( 15, 4, 255, 0, 0);
	canvas()->SetPixel( 16, 4, 255, 0, 0);
	canvas()->SetPixel( 14, 5, 255, 0, 0);
	canvas()->SetPixel( 14, 6, 255, 0, 0);
	canvas()->SetPixel( 14, 7, 255, 0, 0);
	
	// Setup B area indicating current break
	canvas()->SetPixel( 14, 9, 255, 0, 0);
	canvas()->SetPixel( 15, 9, 255, 0, 0);
	canvas()->SetPixel( 16, 9, 255, 0, 0);
	canvas()->SetPixel( 14, 10, 255, 0, 0);
	canvas()->SetPixel( 17, 10, 255, 0, 0);
	canvas()->SetPixel( 14, 11, 255, 0, 0);
	canvas()->SetPixel( 17, 11, 255, 0, 0);
	canvas()->SetPixel( 14, 12, 255, 0, 0);
	canvas()->SetPixel( 15, 12, 255, 0, 0);
	canvas()->SetPixel( 16, 12, 255, 0, 0);
	canvas()->SetPixel( 14, 13, 255, 0, 0);
	canvas()->SetPixel( 17, 13, 255, 0, 0);
	canvas()->SetPixel( 14, 14, 255, 0, 0);
	canvas()->SetPixel( 17, 14, 255, 0, 0);
	canvas()->SetPixel( 14, 15, 255, 0, 0);
	canvas()->SetPixel( 15, 15, 255, 0, 0);
	canvas()->SetPixel( 16, 15, 255, 0, 0);
	
	//Initial Point and Break values
	draw_number(0, 1, 1, 255, 255, 255);
	draw_number(0, 27, 1, 255, 255, 255);
	draw_number(0, 1, 9, 255, 255, 255);
	draw_number(0, 27, 9, 255, 255, 255);
	
	// Initial points on table
	draw_number(7, 26, 23, 255, 255, 255);
	draw_number(4, 21, 23, 255, 255, 255);
	draw_number(1, 18, 23, 255, 255, 255);
	
	// Initial number of reds on table
	draw_number(1, 1, 24, 255, 255, 255);
	draw_number(5, 4, 24, 255, 255, 255);
}

void SnookerGame::draw_number(int number, int x, int y, int r, int g, int b){
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

/***
 * Private helper method that detects and retrieves keyboard input
 */
bool SnookerGame::check_for_input(char *c){
	// If error value of 255 received do nothing, otherwise 
	if((*c = getch()) != 255) {
		return true; // Key Was Hit
	}

	return false; // No keys were pressed
}
