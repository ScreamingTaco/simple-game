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

#include "fighters.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
lifeform::lifeform(int initial_speed, int initial_attack, int initial_defense, int initial_xp):speed(initial_speed), attack(initial_attack), defense(initial_defense), xp(initial_xp){ //lifeform constructor

	// cout << "lifeform constructor called" << endl; //debug
}

void lifeform::show_all_stats() const{
	std::cout << "Name: " << this->name << std::endl;
	switch(this->type){ //show type and weakness
		case warrior:
			cout << "Type: warrior" << endl;
			cout << "Weakness: mage" << endl;
			break;
		case mage:
			cout << "Type: mage" << endl;
            cout << "Weakness: archer" << endl;
			break;
		case archer:   
			cout << "Type: archer" << endl;
			cout << "Weakness: warrior" << endl;
			break;
		default:
			cout << "switch error" << endl;
}
	cout << "Max Health Points: " << this->max_hp << endl;
	cout << "Current Health Points: " << this->current_hp << endl;
	cout << "Attack: " << this->attack << endl;
	cout << "Defense: " << this->defense << endl;
	cout << "Speed: " << this->speed << endl;
	cout << "Experience Points: " << this->xp << endl;
    cout << "Alive? ";
        if (this->is_alive() == true){cout << "Yes." << endl;}
        if (this->is_alive() == false){cout << "No" << endl;}
}

bool lifeform::is_alive() const{
    if (this->current_hp > 0){return true;}
    if (this->current_hp <= 0) {return false;}
}


FIGHTER_TYPE lifeform::get_weakness () const{
        return weakness;
}

player::player (FIGHTER_TYPE initial_type, std::string initial_name, int initial_xp, int initial_max_hp){ //player constructor
	name = initial_name;
	type = initial_type;
	switch (initial_type){
		case warrior:
			weakness = mage;
			attack = 10;
			speed = 10;
			defense = 20;
			break;
		case mage:
			weakness = archer;
			attack = 20;
			speed = 10;
			defense = 10;
			break;
		case archer:
			weakness = warrior;
			attack = 10;
			speed = 20;
			defense = 10;
			break;
}
	max_hp = initial_max_hp;// max hp a player can have (can be upgraded with xp)
	current_hp = max_hp;//start player with full health
	xp = initial_xp;

}

void player::take_damage(int attack_damage){
    if (is_alive() == false){
        cout << name << " is already dead, they cannot be attacked!" << endl;
        return;
    }
    if (speed > attack_damage){ //controls dodging
        int dodge_chance = rand() % 2;
        switch (dodge_chance){
            case 0:
                cout << name << " dodged the attack!" << endl;
                return;
                break;
            default:
                break;
        }
    }
    if (defense > attack_damage){
        cout << "Your defense is too high. Your enemy can't harm you" << endl;
        return;
    }
            current_hp -= attack_damage - defense;
            cout << name << " took " << attack_damage - defense << " damage!" << endl;
            if (is_alive() == false) {
                cout << name << " is dead!" << endl;
                return;
            }
            else if (is_alive() == true){
                cout << name << " has " << current_hp << " health points remaining." << endl;
                return;
            }
                
        
}

void player::attack_enemy(enemy &target_enemy){
        if (target_enemy.get_weakness() == this->type){
            int attack_value = this->attack * 2;
            target_enemy.take_damage(attack_value);
            if (target_enemy.is_alive() == false){
                this->xp += target_enemy.get_xp();
                //cout << xp << endl;
            }
            return;
        }
        else{
            int attack_value = this->attack;
            target_enemy.take_damage(attack_value);
            if (target_enemy.is_alive() == false){
                this->xp += target_enemy.get_xp();
                //cout << xp << endl;
            }
            return;
        }
}

void player::upgrade(){
        char choice;
        char continue_upgrading = 'y';
        int upgrade_amount;
        while (tolower(continue_upgrading) == 'y'){
        cout << "You have " << xp << " Experience points to use on upgrades. One xp can be used to upgrade any stat by one point, or fully heal you." << endl
        << "Would you like to upgrade attack (a), defense (d), speed (s), max health (m), or perform a full heal(h)? Type q to quit." << endl;
        cin >> choice;
        switch (tolower(choice)){
            case 'a':
                cout << "How many xp points would you like to use to upgrade attack? " << endl;
                cin >> upgrade_amount;
                if (upgrade_amount > xp || upgrade_amount <= 0) {
                    cout << "That operation can't be performed at this time." << endl;
                    break;
                }
                else if (upgrade_amount > 0 && upgrade_amount <= xp){
                    attack = attack + upgrade_amount;
                    xp = xp - upgrade_amount;
                    break;
                }
                else{
                    cout << "I dont understand what you mean" << endl;
                    break;
                }
            case 'd':
                cout << "How many xp points would you like to use to upgrade defense? " << endl;
                cin >> upgrade_amount;
                if (upgrade_amount > xp || upgrade_amount <= 0) {
                    cout << "That operation can't be performed at this time." << endl;
                    break;
                }
                else if (upgrade_amount > 0 && upgrade_amount <= xp){
                    defense = defense + upgrade_amount;
                    xp = xp - upgrade_amount;
                    break;
                }
                else{
                    cout << "I dont understand what you mean" << endl;
                    break;
                }
            case 's':
                cout << "How many xp points would you like to use to upgrade speed? " << endl;
                cin >> upgrade_amount;
                if (upgrade_amount > xp || upgrade_amount <= 0) {
                    cout << "That operation can't be performed at this time." << endl;
                    break;
                }
                else if (upgrade_amount > 0 && upgrade_amount <= xp){
                    speed = speed + upgrade_amount;
                    xp = xp - upgrade_amount;
                    break;
                }
                else{
                    cout << "I dont understand what you mean" << endl;
                    break;
                }
            case 'm':
                cout << "How many xp points would you like to use to upgrade your max health? " << endl;
                cin >> upgrade_amount;
                if (upgrade_amount > xp || upgrade_amount <= 0) {
                    cout << "That operation can't be performed at this time." << endl;
                    break;
                }
                else if (upgrade_amount > 0 && upgrade_amount <= xp){
                    max_hp = max_hp + upgrade_amount;
                    xp = xp - upgrade_amount;
                    break;
                }
                else{
                    cout << "I dont understand what you mean" << endl;
                    break;
                }
            case 'h':
                if (current_hp == max_hp){
                    cout << "You do not need to be healed!" << endl;
                    break;
                }
                cout << "Would you like to use 1 xp point to fully heal you? (y/n)" << endl;
                cin >> choice;
                if (tolower(choice) == 'y' && xp >= 1){
                    current_hp = max_hp;
                    xp -= 1;
                    cout << "All healed up!" << endl;
                    break;
                }
                if (tolower(choice) == 'n'){
                    cout << "Ok. Goodbye!" << endl;
                    break;
                }
                else{
                    cout << "I dont understand what you mean" << endl;
                    break;
                }
            case 'q':
                cout << "Have a nice day!" << endl;
                return;
                break;
            default:
                cout << "It looks like something went wrong!" << endl;
                return;
                break;
        }
        cout << "Your stats are now:" << endl << endl;
        show_all_stats();
        cout << endl;
        cout << "Would you like to continue upgrading? (y/n)" << endl;
        cin >> continue_upgrading;
        if (continue_upgrading != 'y'){
            cout << "Have a nice day! " << endl;
            return;
        }
    }
}

void player::save(){
    std::ofstream savefile;
    savefile.open("player.txt");
    if (savefile.is_open()){
    savefile << name << endl;
    savefile << type << endl;
    savefile << weakness << endl;
    savefile << max_hp << endl;
    savefile << current_hp << endl;
    savefile << attack << endl;
    savefile << defense << endl;
    savefile << speed << endl;
    savefile << xp << endl;
    return;        
    }
    else{
        cout << "Unable to open file" << endl;
        return;
    }
}

void player::load(){
    std::ifstream savefile;
    savefile.open("player.txt");
    std::string string_playertype;
    std::string string_weakness;
    std::string string_max_hp;
    std::string string_current_hp;
    std::string string_attack;
    std::string string_defense;
    std::string string_speed;
    std::string string_xp;
    if (savefile.is_open()){
    //cout << "Opening file" << endl; //debug
    std::getline(savefile, this->name, '\n');
    std::getline(savefile, string_playertype, '\n');
    std::getline(savefile, string_weakness, '\n');
    std::getline(savefile, string_max_hp, '\n');
    std::getline(savefile, string_current_hp, '\n');
    std::getline(savefile, string_attack, '\n');
    std::getline(savefile, string_defense, '\n');
    std::getline(savefile, string_speed, '\n');
    std::getline(savefile, string_xp, '\n');
   // cout << "Reading type" << endl;//debug
    type = static_cast<FIGHTER_TYPE>(std::stoi(string_playertype));
    //cout << "Reading weakness" << endl;//debug
    weakness = static_cast<FIGHTER_TYPE>(std::stoi(string_weakness));
    //cout << "Reading max_hp)" << endl;//debug
    max_hp = std::stoi(string_max_hp);
    current_hp = std::stoi(string_current_hp);
    attack = std::stoi(string_attack);
    defense = std::stoi(string_defense);
    speed = std::stoi(string_speed);
    xp = std::stoi(string_xp);
    return;
    }
    else{
        cout << "Unable to open file" << endl;
        return;
    }
}

enemy::enemy(FIGHTER_TYPE initial_type, std::string initial_name, int initial_attack, int initial_defense, int initial_speed, int initial_max_hp){ //enemy constructor
	  switch (initial_type){
                case warrior:
                        weakness = mage;
                        break;
                case mage:
                        weakness = archer;
                        break;
                case archer:
                        weakness = warrior;
                        break;
}
	type = initial_type;
	name = initial_name;
	max_hp = initial_max_hp;
	current_hp = max_hp;
	speed = initial_speed;
	defense = initial_defense;
	attack = initial_attack;
    xp = 0;
}


void enemy::randomize_strong_enemy(){ //randomizes an enemy
    this->attack = rand() % 150 + 100;
    this->defense = rand() % 150 + 100;
    this->speed = rand() % 150 + 100;
    this->max_hp = rand() % 150 + 100;
    this->current_hp = max_hp;
    this->xp = rand() % 50 + 40;
    int new_type = rand() % 4;
    switch (new_type){
        case 1:
            type = warrior;
            weakness = mage;
            break;
        case 2:
            type = mage;
            weakness = archer;
            break;
        case 3:
            type = archer;
            weakness = mage;
            break;
        default:
            type = archer;
            weakness = mage;
            break;
    }
}

void enemy::randomize_medium_enemy(){
    this->attack = rand() % 75 + 40;
    this->defense = rand() % 75 + 40;
    this->speed = rand() % 75 + 40;
    this->max_hp = rand() % 75 + 40;
    this->current_hp = max_hp;
    this->xp = rand() % 20 + 15;
    int new_type = rand() % 4;
    switch (new_type){
        case 1:
            type = warrior;
            weakness = mage;
            break;
        case 2:
            type = mage;
            weakness = archer;
            break;
        case 3:
            type = archer;
            weakness = mage;
            break;
        default:
            type = archer;
            weakness = mage;
            break;
    }
}
void enemy::randomize_weak_enemy(){
    this->attack = rand() % 15 + 1;
    this->defense = rand() % 15 + 1;
    this->speed = rand() % 15 + 1;
    this->max_hp = rand() % 15 + 1;
    this->current_hp = max_hp;
    this->xp = rand() % 10 + 1;
    int new_type = rand() % 4;
    switch (new_type){
        case 1:
            type = warrior;
            weakness = mage;
            break;
        case 2:
            type = mage;
            weakness = archer;
            break;
        case 3:
            type = archer;
            weakness = mage;
            break;
        default:
            type = archer;
            weakness = mage;
            break;
    }
}

void enemy::take_damage(int attack_damage){
    if (is_alive() == false){
        cout << name << " is already dead, they cannot be attacked!" << endl;
        return;
    }
    if (speed > attack_damage){ //controls dodging
        int dodge_chance = rand() % 2;
        switch (dodge_chance){
            case 0:
                cout << name << " dodged the attack!" << endl;
                return;
                break;
            default:
                break;
        }
    }
    if (defense > attack_damage){
        cout << name << "'s defense is too high. You can't hurt " << name << ". Come back when you have more attack points." << endl;
        return;
    }
            current_hp -= attack_damage - defense;
            cout << name << " took " << attack_damage - defense << " damage!" << endl;
            if (is_alive() == false) {
                cout << name << " is dead!" << endl;
                cout << "You got " << xp << " experience points!" << endl;
                return;
            }
            else if (is_alive() == true){
                cout << name << " has " << current_hp << " health points remaining." << endl;
                return;
            }
    
}

void enemy::attack_player(player &target_player){
        if (target_player.get_weakness() == this->type){
            int attack_value = this->attack * 2;
            target_player.take_damage(attack_value);
            return;
        }
        else{
            int attack_value = this->attack;
            target_player.take_damage(attack_value);
            return;
        }
}

int enemy::get_xp() const {return xp;}
