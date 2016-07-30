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
#include "fighters.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void game::play(){
    show_story();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    string player_name;
    char player_type_selection;
    char path_choice; // battle random enemy, fight boss, upgrade, etc
    FIGHTER_TYPE player_Type;
    //cout << "Welcome to the Adventures of Linus!" << endl
    cout << "Please enter your character's name (leave blank for default): " << endl;
    std::getline (cin, player_name);
    cout << "Please enter your character's type (m for mage, a for archer, or w for warrior( blank will make you warrior): " << endl;
    std::cin.get (player_type_selection);
    player main_player (calc_Type(player_type_selection), player_name.empty() ? "Linus" : player_name);
    cout << "Your starting stats are:" << endl << endl;
    main_player.show_all_stats();
    cout << endl << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    show_help(); 
    cout << endl;
    enemy temp_enemy;
    enemy yogitach(mage, "Yogitach", 200, 200, 200, 200);
    while (true){
        if (main_player.is_alive() == false){
            cout << "Game over!" << endl << endl;
            return;
        }
        cout << "(home) ";
        cin >> path_choice;
        cout << endl;
        switch (tolower(path_choice)){
            case 'h':
                show_help();
                break;
            case 'w':
                //enemy temp_weak_enemy;
                temp_enemy.randomize_weak_enemy();
                battle (main_player, temp_enemy);
                break;
            case 'm':
                //enemy temp_enemy;
                temp_enemy.randomize_medium_enemy();
                battle(main_player, temp_enemy);
                break;
            case 's':
                //enemy temp_strong_enemy;
                temp_enemy.randomize_strong_enemy();
                battle(main_player, temp_enemy);
                break;
            case 'u':
                main_player.upgrade();
                break;
            case 'l':
                main_player.show_all_stats();
                break;
            case 'y':
                //enemy yogitach(mage, "Yogitach", 200, 200, 200, 200);
                battle(main_player, yogitach);
                if (main_player.is_alive()){
                    show_credits();
                    return;
                }
                else {
                    cout << "Game over!" << endl;
                    return;
                }
                return;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
    }
}
}

void game::show_story() const {
    cout << "Long ago there was a great hero." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    cout << "One day he was killed by an evil wizard, along with his wife." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    cout << "His son, however, survived." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    cout << "That hero was your father." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout << "The man who killed your father is named Yogitach" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout << "You must go defeat him!" << endl;
    cout << "                   -your friend and mentor," << endl;
    cout << "                                       Azamuku" << endl;   
}

FIGHTER_TYPE game::calc_Type(char input) {
    switch (input){
        case 'm':
            return mage;
            break;
        case 'a':
            return archer;
            break;
        default :
            return warrior;
            break;
        
    }
    
}

void game::battle(player &battle_player, enemy &battle_enemy){
    //while (battle_player.is_alive() == true && battle_enemy.is_alive() == true){
    char battle_choice;
    cout << "Current battle stats are: " << endl << endl;
    battle_player.show_all_stats();
    cout << endl << endl;
    battle_enemy.show_all_stats();
    cout << endl << endl;
    while (battle_player.is_alive() == true && battle_enemy.is_alive() == true){
    cout << "(battle)Would you like to attack(a), see stats (s), or flee(f)?" << endl;
    //std::cin.get (battle_choice);
    cin >> battle_choice;
    switch (tolower(battle_choice)){
        case 'f':
            cout << "Ok. Maybe you'll have better luck next time. *cough coward *cough" << endl;
            return;
            break;
        case 's':
            battle_player.show_all_stats();
            cout << endl << endl;
            battle_enemy.show_all_stats();
            cout << endl << endl;
            break;
        default:
            battle_player.attack_enemy(battle_enemy);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                if (battle_enemy.is_alive() == false){
                    //cout << "(battle)You won!" << endl;
                    return;
                    break;
                }
            battle_enemy.attack_player(battle_player);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                if (battle_player.is_alive() == false){
                    cout << "You died!" << endl;
                    return;
                    break;
                }
            break;
    }
        
    }
}

void game::show_help() const{
    cout << "Press h to display this help later." << endl;
    //cout << "By typing b, you will enter a battle with a random opponent." << endl;
    cout << "By typing w, you will face an opponent with weak stats" << endl;
    cout << "By typing m, you will face an opponent with the potential to have higher level stats." << endl;
    cout << "By typing s, you will face an opponent with the potential to be very strong." << endl;
    cout << "Type u when you want to upgrade" << endl;
    cout << "Type l to see current stats" << endl;
    cout << "When you feel ready to face Yogitach, press y" << endl; 
}

void game::show_credits() const{
        cout << "Game by Carlos Vzquez (fwcarlitos@icloud.com)" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        cout << "I would like to thank my family and friends for support and feedback." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        cout << "I would also like to thank all the game testers. I couldnt have made this game what it is without you!" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        cout << "Lastly, I would like to thank the Lord for saving me and giving me strength." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        cout << "Thanks for playing!" << endl;
    
}
