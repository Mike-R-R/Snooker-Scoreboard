
#ifndef SNOOKER_QUEUE
#define SNOOKER_QUEUE

#include <queue>

struct GameState{
	int pointsAdded;
	int pointsOnTable;
	int reds;
	int shootingPlayer;
	bool onRed;
	bool lostRed;
	bool foul;
	bool freeBall;
};

class SnookerQueue{
	public:
		SnookerQueue();
		~SnookerQueue();
		void add_new_state(GameState);
		void add_new_state(int,int,int,int,bool,bool,bool,bool);
		GameState* previous_game_state();
	
	private:
		std::queue<GameState> gameQueue; 

};

#endif
