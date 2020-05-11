
#ifndef SNOOKER_SCOREBOARD
#define SNOOKER_SCOREBOARD

#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "pixel-mapper.h"
#include "graphics.h"
#include "SnookerGame.h"

#include <curses.h>

class SnookerScoreboard : public rgb_matrix::ThreadedCanvasManipulator{
	public:
		SnookerScoreboard(rgb_matrix::Canvas *m);
		~SnookerScoreboard();
		
		void Run();
		void stop_game();
		bool running();
	
	private:
		bool game_running;
		SnookerGame* theGame;
		
		void setup_scoreboard();
		void draw_number(int,int,int,int,int,int);
		void player_shooting(int, bool);
		void draw_shooting_indicator(int,int,bool);
		void draw_foul_indicator(int);
		void update_board();
		void clear_board();
		void populate_board();
		void draw_left_aligned(int,int,int,int,int,int);
		void draw_right_aligned(int,int,int,int,int,int);
		void draw_left_inverted(int);
		void draw_right_inverted(int);
		bool check_for_input(char *c);
	
};

#endif
