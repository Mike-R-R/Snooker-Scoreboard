
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
	
	while(game_running){
		if(check_for_input(&key)) {
		// Handle input of keys we care about
			switch(int(key)){
				std::cout << key << std::endl;
				std::cout << int(key) << "\n" << std::endl;
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
