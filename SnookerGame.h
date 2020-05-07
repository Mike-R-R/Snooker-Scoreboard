
#ifndef SNOOKER_GAME
#define SNOOKER_GAME

#include "Player.h"

class SnookerGame {
    public:
        SnookerGame();
        SnookerGame(bool, bool);
        ~SnookerGame();
        SnookerGame& operator= (const SnookerGame& g);
        int remaining_reds();
        int remaining_points();
        void get_player_scores(int *);
        void get_player_breaks(int *);
        void point_spread(int *);
        void add_points(int);
        void potted_ball(int);
        void foul(int);
        void free_ball();
        void end_frame();
        void end_break();
        void lost_red();
        int player_at_table(bool *);
        
	private:
		Player* player1;
		Player* player2;
		int reds;
		int pointsOnTable;
		
		Player* player_at_table();
		Player* player_not_at_table();
};

#endif
