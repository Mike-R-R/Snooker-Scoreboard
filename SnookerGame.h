
#ifndef SNOOKER_GAME
#define SNOOKER_GAME

#include "Player.h"

class SnookerGame {
    Player player1;
    Player player2;
    int reds;
    int pointsOnTable;

    public:
        SnookerGame();
        SnookerGame(bool, bool);
        ~SnookerGame();
        SnookerGame& operator= (const SnookerGame&);
        int remainingReds();
        int remainingPoints();
        void getPlayerScores(int *);
        void getPlayerBreaks(int *);
        void pointSpread(int *);
        void addPoints(int);
        void foul(int);
        void freeBall();
        void endFrame();
        void endBreak();
        void lostRed();
};

#endif
