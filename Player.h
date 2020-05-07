
#ifndef PLAYER
#define PLAYER

class Player{
    public:
        Player();
        Player(bool);
        ~Player();
        int get_score();
        int get_frames_won();
        int get_current_break();
        int get_high_break();
        bool get_on_red();
        void set_on_red(bool);
        bool get_player_at_table();
        void ball_potted(int);
        void free_ball_potted();
        void end_break();
        void begin_break();
        void won_frame();
        void lost_frame();
        void add_points(int);
    
    private:
        int score;
        int framesWon;
        int currentBreak;
        int highBreak;
        bool onRed;
        bool atTable;
};

#endif
