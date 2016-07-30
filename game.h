#ifndef game_h
#define game_h

#include "fighters.h"

class game {
	public:
		void play(); //this should be the only public function
	private: // everything not in fighters.h goes here
        void show_story() const;
        FIGHTER_TYPE calc_Type(char input);
		void battle(player &battle_player, enemy &battle_enemy);
        void show_help() const;
        void show_credits() const;
};

#endif
