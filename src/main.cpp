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

    Contact me at fwcarlitos@icloud.com*/


#include "game.h"
#include <cctype>
using std::cout;
using std::endl;

int main(){
    srand(time(NULL));
    game Main_Game;
    char continue_playing = 'y';
    while (tolower(continue_playing) == 'y'){
        Main_Game.play();
        cout << "Would you like to play again?" << endl;
        std::cin >> continue_playing;        
    }
    cout << endl << endl << endl;
    cout << "Have a nice day!" << endl;
    return 0;
}
