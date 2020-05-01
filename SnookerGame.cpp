
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
	canvas()->SetPixel( 13, 1, 255, 0, 0);
	canvas()->SetPixel( 14, 1, 255, 0, 0);
	canvas()->SetPixel( 15, 1, 255, 0, 0);
	canvas()->SetPixel( 16, 1, 255, 0, 0);
	canvas()->SetPixel( 13, 2, 255, 0, 0);
	canvas()->SetPixel( 17, 2, 255, 0, 0);
	canvas()->SetPixel( 13, 3, 255, 0, 0);
	canvas()->SetPixel( 17, 3, 255, 0, 0);
	canvas()->SetPixel( 13, 4, 255, 0, 0);
	canvas()->SetPixel( 14, 4, 255, 0, 0);
	canvas()->SetPixel( 15, 4, 255, 0, 0);
	canvas()->SetPixel( 16, 4, 255, 0, 0);
	canvas()->SetPixel( 13, 5, 255, 0, 0);
	canvas()->SetPixel( 13, 6, 255, 0, 0);
	canvas()->SetPixel( 13, 7, 255, 0, 0);
	
	canvas()->SetPixel( 13, 9, 255, 0, 0);
	canvas()->SetPixel( 14, 9, 255, 0, 0);
	canvas()->SetPixel( 15, 9, 255, 0, 0);
	canvas()->SetPixel( 16, 9, 255, 0, 0);
	canvas()->SetPixel( 13, 10, 255, 0, 0);
	canvas()->SetPixel( 17, 10, 255, 0, 0);
	canvas()->SetPixel( 13, 11, 255, 0, 0);
	canvas()->SetPixel( 17, 11, 255, 0, 0);
	canvas()->SetPixel( 13, 12, 255, 0, 0);
	canvas()->SetPixel( 14, 12, 255, 0, 0);
	canvas()->SetPixel( 15, 12, 255, 0, 0);
	canvas()->SetPixel( 16, 12, 255, 0, 0);
	canvas()->SetPixel( 13, 13, 255, 0, 0);
	canvas()->SetPixel( 17, 13, 255, 0, 0);
	canvas()->SetPixel( 13, 14, 255, 0, 0);
	canvas()->SetPixel( 17, 14, 255, 0, 0);
	canvas()->SetPixel( 13, 15, 255, 0, 0);
	canvas()->SetPixel( 14, 15, 255, 0, 0);
	canvas()->SetPixel( 15, 15, 255, 0, 0);
	canvas()->SetPixel( 16, 15, 255, 0, 0);
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
