
#ifndef SNOOKER_QUEUE
#define SNOOKER_QUEUE

#include <queue>

struct GameState{
	int pointsAddedToPlayer1;
	int pointsAddedToPlayer2;
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
		SnookerQueue(GameState);
		~SnookerQueue();
		void game_state_changed(int,int,int,int,int,bool,bool,bool,bool);
		GameState* previous_game_state();
	
	private:
		std::queue<GameState> gameQueue; 

};

#endif
