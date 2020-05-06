#ifndef PLAYER
#define PLAYER

class Player{
    int score;
    int highBreak;
    int framesWon;
    int currentBreak;
    bool atTable;
    bool onRed;
    
    public:
        Player();
        Player(bool);
        ~Player();
        Player& operator= (const Player&);
        int getScore();
        int getFrameswon();
        int getCurrentBreak();
        int getHighBreak();
        bool getOnRed();
        bool playerAtTable();
        void addPoints(int);
        void endBreak();
        void beginBreak();
        void wonFrame();
        void lostFrame();
};

#endif
