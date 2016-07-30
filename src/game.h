/*  Adventures of Linus- text based adventure game
    Copyright (C) 2016  Carlos Vazquez
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
    Contact me at fwcarlitos@icloud.com
*/

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
        void game_loop(player player1, enemy temporary_enemy, enemy boss, char path_choice = 'h');
        void new_game();
        void save_game(player player_to_save)
        void load_game();
};

#endif
