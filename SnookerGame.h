
#ifndef SNOOKER_GAME
#define SNOOKER_GAME

#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "pixel-mapper.h"
#include "graphics.h"

#include <curses.h>

class SnookerGame : public rgb_matrix::ThreadedCanvasManipulator{
	public:
		SnookerGame(rgb_matrix::Canvas *m);
		~SnookerGame();
		
		void Run();
		void stop_game();
		bool running();
	
	private:
		bool game_running;
		void setup_scoreboard();
		void update_board(int,int,int,int);
		bool check_for_input(char *c);
	
};

#endif