#ifndef fighters_h
#define fighters_h
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//using namespace std::cout;
//using namespace std::endl;
enum FIGHTER_TYPE {warrior = 1, mage = 2, archer = 3};

class lifeform;
class enemy;

class lifeform {
	public:
		lifeform(int initial_speed = 1, int initial_attack = 1, int initial_defense = 1, int initial_xp = 0);//constructor
		void show_all_stats() const;
        bool is_alive() const;
        //void take_damage(int attack_damage); //pass attack level to this argument
        FIGHTER_TYPE get_weakness() const;
	protected:
		FIGHTER_TYPE type;
		std::string name;
		FIGHTER_TYPE weakness;
		int max_hp;
		int current_hp;
		int speed;
		int defense;
		int attack;
		int xp; //for player, xp is for leveling up. for enemy, xp is how much xp u get if you defeat them
};

class player : public lifeform {
	public:
		player(FIGHTER_TYPE initial_type = warrior, std::string initial_name = "Linus", int initial_xp = 0, int initial_max_hp = 20); //constructor
        void take_damage(int attack_damage);
        void attack_enemy(enemy &target_enemy);
        void upgrade();
};

class enemy : public lifeform {
	public:
		enemy(FIGHTER_TYPE initial_type = warrior, std::string initial_name = "Opponent", int initial_attack = 10, int initial_defense = 10, int initial_speed = 10, int initial_max_hp = 10); // cunstructor
        //int calc_xp();
        void randomize_strong_enemy(); //makes a random enemy
        void randomize_medium_enemy();
        void randomize_weak_enemy();
        void take_damage(int attack_damage);
        void attack_player(player &target_player);
        int get_xp() const;
};

#endif
