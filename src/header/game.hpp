// File: game.hpp
#ifndef __GAME_HPP__
#define __GAME_HPP__

class Game{
    public:
        Game();
        ~Game();
        void readConfig();
        void save();
        void load();
};

#endif