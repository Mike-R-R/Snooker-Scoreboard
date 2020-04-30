
#ifndef SNEK
#define SNEK

#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "pixel-mapper.h"
#include "graphics.h"
#include "Snek_Segment.h"

#include <curses.h>
#include <deque>

class Snek : public rgb_matrix::ThreadedCanvasManipulator {
	public:
		Snek(rgb_matrix::Canvas *m);
  
		void Run();
		void stop_game();
		bool running();
		
	private:
		std::deque <SnekSegment> segments;
		bool game_running;
		const int worldX;
		const int worldY;
		
		void draw_snek();
		void update_game();
		bool collision_detected(int, int, bool);
		bool grow();
		bool check_for_input(char *c);
};

#endif
