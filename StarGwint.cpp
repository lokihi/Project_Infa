//StarGwint ver 1.9//
#include <iostream>
#include "Cards.cpp"
#include "Functions.cpp"
using namespace std;


int main() {

	//Потом закинуть в функцию init_game//
	Player* pl_1 = new Player;
	Player* pl_2 = new Player;


	Game_Card* table_1[4]{};
	Game_Card* table_2[4]{};
	
	bool turn_count = false;


	int cards_in_deka_1 = 17;
	int cards_in_deka_2 = 17;


	Game_Card* deka_1[17];
	Game_Card* deka_2[17];
	fill_terran_deka(deka_1);
	fill_terran_deka(deka_2);


	Game_Card* hand_1[4];
	Game_Card* hand_2[4];


	fill_empty_hand(hand_1, hand_2, table_1, table_2);
	
	init_game(pl_1, pl_2);

	//Игра//
	while (check_hp(pl_1, pl_2) == true) {
		turn_count = turn(pl_1, pl_2, table_1, table_2, deka_1, hand_1, deka_2, hand_2, turn_count);
	}
	show_field(table_1, table_2, pl_1, pl_2);
}
