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
