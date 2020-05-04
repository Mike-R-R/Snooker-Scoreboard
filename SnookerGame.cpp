
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
	
	// Initial shooting player
	DrawLine(canvas(), 0, 0, 17, 0, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 0, 1, 17, 1, rgb_matrix::Color(100, 0, 0));
	
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
	DrawLine(canvas(), 1, 11, 30, 11, rgb_matrix::Color(100, 0, 0));
	
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
	
	//Initial Point and Break values
	draw_number(0, 1, 3, 128, 128, 128);
	draw_number(0, 27, 3, 128, 128, 128);
	draw_number(0, 1, 13, 128, 128, 128);
	draw_number(0, 27, 13, 128, 128, 128);
	
	// Frame red and points on table area.
	DrawLine(canvas(), 0, 21, 31, 21, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 13, 21, 13, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 0, 21, 0, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 0, 31, 13, 31, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 31, 21, 31, 30, rgb_matrix::Color(100, 0, 0));
	DrawLine(canvas(), 14, 31, 16, 31, rgb_matrix::Color(170, 170, 0));
	DrawLine(canvas(), 17, 31, 19, 31, rgb_matrix::Color(0, 170, 0));
	DrawLine(canvas(), 20, 31, 22, 31, rgb_matrix::Color(102, 51, 0));
	DrawLine(canvas(), 23, 31, 25, 31, rgb_matrix::Color(0, 0, 170));
	DrawLine(canvas(), 26, 31, 28, 31, rgb_matrix::Color(255, 0, 127));
	DrawLine(canvas(), 29, 31, 31, 31, rgb_matrix::Color(32, 32, 32));
	
	// Initial points on table
	draw_number(7, 25, 23, 128, 128, 128);
	draw_number(4, 20, 23, 128, 128, 128);
	draw_number(1, 17, 23, 128, 128, 128);
	
	// Initial number of reds on table
	draw_number(1, 4, 23, 128, 128, 128);
	draw_number(5, 7, 23, 128, 128, 128);
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
