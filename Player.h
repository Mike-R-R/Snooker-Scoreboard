#ifndef PLAYER
#define PLAYER

class Player{
    int score;
    int framesWon;
    int currentBreak;
    int highBreak;
    bool onRed;
    bool atTable;
    
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
