
#include "Snek.h"
#include <unistd.h>
#include <iostream>

Snek::Snek(rgb_matrix::Canvas *m) : rgb_matrix::ThreadedCanvasManipulator(m), worldX(31), worldY(31) {
	segments.push_front(SnekSegment(15, 6, 15, 0));
	game_running = true;
}

void Snek::Run() {
	//curses initializations
	char key = ' ';
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE); 
	
	while(game_running){
		
		if(!check_for_input(&key)) {
			draw_snek();
			
			update_game();
			//sleep(1);
		} else {
			// Handle input of keys we care about
			switch(int(key)){
				case 2: //KEY_DOWN:
					std::cout << "You Pressed: Down Arrow" << std::endl;
					break;
				case 3: //KEY_UP:
					std::cout << "You Pressed: Up Arrow" << std::endl;
					break;
				case 4: //KEY_LEFT:
					std::cout << "You Pressed: Left Arrow" << std::endl;
					break;
				case 5: //KEY_RIGHT:
					std::cout << "You Pressed: Right Arrow" << std::endl;
					break;
			}
		}
		usleep(60 * 1000);
	}
}

void Snek::stop_game(){
	game_running = false;
}

/***
 * Draws each segment of the snake from segments on to the world
 */
void Snek::draw_snek(){
	int deque_size = static_cast<int>(segments.size());
	
	for(int i = 0; i < deque_size; i++){
		const int* coords = segments[i].get_coords();
		DrawLine(canvas(), coords[0], coords[1], coords[2], coords[3], rgb_matrix::Color(255, 0, 0));
	}
}

bool Snek::running(){
	return game_running;
}

/***
 * Advances the state of the snake
 */
void Snek::update_game(){
	// Advance snake head and check that new position is valid
	bool advanced = segments.front().advance_head();
	const int* coords = segments.front().get_coords();
	int x = coords[0];
	int y = coords[1];
	
	if( !advanced || collision_detected(x, y, true) ){
		game_running = false;
	}
	
	// Advance tail and clear LEDs in trailing spots
	int* clear_coords = segments.back().advance_tail();
	
	if(!grow()){
		canvas()->SetPixel(clear_coords[0], clear_coords[1], 0, 0, 0);
	}
	
	delete clear_coords;
}

/***
 * Checks that the snake has not collided with itself
 */
bool Snek::collision_detected(int x, int y, bool is_head){
	int deque_size = static_cast<int>(segments.size());
	int start;
	
	if(is_head){
		start = 1;
	} else {
		start = 0;
	}

	for(int i = start; i < deque_size; i++){
		if(segments[i].collides_with_segment(x, y)){
			return true;
		}
	}

	return false;
}  

/***
 * Checks if the snake has consumed food and should grow
 */
bool Snek::grow(){
	// TODO: Implement
	return false;
}

/***
 * Private helper method that detects and retrieves keyboard input
 */
bool Snek::check_for_input(char *c){
	// If error value of 255 received do nothing, otherwise 
	if((*c = getch()) != 255) {
		return true; // Key Was Hit
	}

	return false; // No keys were pressed
}
