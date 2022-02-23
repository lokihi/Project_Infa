#include <cstdlib>
#include <string>
#include <Windows.h>
template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}


//Õ≈ “–Œ√¿“‹//
int randomgen()
{
	rand();
	int random, max_value = 15, min_value = 1;
	random = rand() % max_value + min_value;
	return random;
}



//Õ≈ “–Œ√¿“‹//
void place_card(Game_Card** table, Game_Card* card) {
	cout << "Choose position: ";
	int pos;
	cin >> pos;
	if (pos > 0 && pos < 5) {
		if (table[pos - 1]->get_free() == false) {
			cout << "Position is taken. Choose wisely." << endl; place_card(table, card);
		}
		else {
			table[pos - 1] = card;
		}
	}
	else { cout << "I don't want to get into void, sir" << endl; place_card(table, card); }
}


//Õ≈ “–Œ√¿“‹//
void play_card(Player* pl, Game_Card** table, Game_Card** hand) {
	cout << endl << "Pick up a card: " << endl;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (hand[i]->get_free() == false) {
			cout << i + 1 << ". - " << hand[i]->get_name() << endl;
			cout << "=== Damage: " << hand[i]->get_damage() << " ";
			cout << "Health: " << hand[i]->get_health() << " ";
			cout << "Cost: " << hand[i]->get_cost() << " ===" << endl << endl;
		}
	}
	cout << "0. - End turn" << endl << "Your choice: ";
	int pos = 0;
	cin >> pos;
	if (pos == 0) {}
	else {
		if (pl->get_crystals() > hand[pos - 1]->get_cost()) {
			Game_Card* card = hand[pos - 1];
			hand[pos - 1] = new Empty_Field;
			int cards = pl->get_cards_in_hand();
			pl->set_cards_in_hand(cards - 1);
			place_card(table, card);
			int crystals = pl->get_crystals();
			pl->set_crystals(crystals - card->get_cost());
		}
		else { cout << endl << "***Attention: Not enough crystals.***" << endl; play_card(pl, table, hand); }
	}
}


//Õ≈ “–Œ√¿“‹//
void destroy_card(Game_Card** table, int pos) { table[pos] = new Empty_Field; }


//Õ≈ “–Œ√¿“‹//
void pick_card(Player* pl, Game_Card** hand, Game_Card** deka, int cards_in_hand) {
	int num = randomgen();
	if (cards_in_hand < 4) {
		int count = 0;
		while (hand[count]->get_free() == false) count++;
		hand[count] = deka[num];
		pl->set_cards_in_hand(cards_in_hand + 1);
	}
}


//Õ≈ “–Œ√¿“‹//
void play_damage(Game_Card** table_self, Game_Card** table_opp, Player* pl_self, Player* pl_opp, int pos) {
	int opp_health = table_opp[pos]->get_health();
	int opp_hp = pl_opp->get_hp();
	int self_damage = table_self[pos]->get_damage();
	if (table_opp[pos]->get_free() == true) {
		pl_opp->set_hp(opp_hp - self_damage);
	}
	else {
		if (opp_health - self_damage > 0) { table_opp[pos]->set_health(opp_health - self_damage); }
		else { destroy_card(table_opp, pos); }
	}
}


//œŒ ¿ Õ≈ “–Œ√¿“‹//
void show_field(Game_Card** table_1, Game_Card** table_2, Player* pl_1, Player* pl_2) {
	for (int i = 0; i < 11 - pl_1->get_name().length(); i++) cout << " ";
	cout << color < 9, 0> << "Crystals: " << pl_1->get_crystals() << color < 3, 0> << " ===" << pl_1->get_name() << "===" << color < 2, 0> << " HP: " << pl_1->get_hp() << color < 3, 0> << endl << endl;
	cout << "========" << "     " << "========" << "     " << "========" << "     " << "========" << endl;
	for (int i = 0; i < 4; i++) { cout << "#     " << table_1[i]->get_cost() << "#" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) { cout << "#" << table_1[i]->get_name() << " #" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) cout << "#      #" << "     ";
	cout << endl;
	for (int i = 0; i < 4; i++) { cout << "#" << color < 14, 0> << table_1[i]->get_damage() << color < 3, 0> << "    " << color < 10, 0> << table_1[i]->get_health() << color < 3, 0> << "#" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) cout << "========" << "     ";
	cout << endl << endl << endl << endl;
	for (int i = 0; i < 11 - pl_2->get_name().length(); i++) cout << " ";
	cout << color < 9, 0> << "Crystals: " << pl_2->get_crystals() << color < 3, 0> << " ===" << pl_2->get_name() << "===" << color < 2, 0> << " HP: " << pl_2->get_hp() << color < 3, 0> << endl << endl;
	cout << "========" << "     " << "========" << "     " << "========" << "     " << "========" << endl;
	for (int i = 0; i < 4; i++) { cout << "#     " << table_2[i]->get_cost() << "#" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) { cout << "#" << table_2[i]->get_name() << " #" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) cout << "#      #" << "     ";
	cout << endl;
	for (int i = 0; i < 4; i++) { cout << "#" << color < 14, 0> << table_2[i]->get_damage() << color < 3, 0> << "    " << color < 10, 0> << table_2[i]->get_health() << color < 3, 0> << "#" << "     "; }
	cout << endl;
	for (int i = 0; i < 4; i++) cout << "========" << "     ";
	cout << endl << endl;
}


//Õ≈ “–Œ√¿“‹//
void get_crystals(Player* pl) {
	int new_crystals = pl->get_crystals();
	if (new_crystals < 4) pl->set_crystals(new_crystals + 1);
}


//Õ≈ “–Œ√¿“‹//
void choose_action(Player* pl_self, Game_Card** table_self, Game_Card** hand_self) {
	int action = 0;
	cout << "=== " << pl_self->get_name() << " your turn. ===" << endl;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (table_self[i]->get_free() == false) count++;
	}
	if (count != 4) {
		cout << endl << "Choose an action: ";
		cout << endl << "1. - Place a card";
		cout << endl << "0. - End turn" << endl;
		cin >> action;
		if (action == 1) { play_card(pl_self, table_self, hand_self); }
	}
	else {
		cout << endl << "Choose an action: ";
		cout << endl << "***Attention: Not enough space for card***";
		cout << endl << "0. - End turn" << endl;
		cin >> action;
	}
}


//Õ≈ “–Œ√¿“‹//
bool turn(Player* pl_self, Player* pl_opp, Game_Card** table_self, Game_Card** table_opp, Game_Card** deka_self, Game_Card** hand_self, Game_Card** deka_opp, Game_Card** hand_opp, bool turn_count) {
	show_field(table_self, table_opp, pl_self, pl_opp);
	if (turn_count == true) {
		turn_count = false;
		swap(pl_self, pl_opp);
		swap(table_opp, table_self);
		swap(deka_self, deka_opp);
		swap(hand_self, hand_opp);
	}
	else {
		turn_count = true;
	}
	get_crystals(pl_self);
	pick_card(pl_self, hand_self, deka_self, pl_self->get_cards_in_hand());
	choose_action(pl_self, table_self, hand_self);
	for (int i = 0; i < 4; i++) {
		play_damage(table_self, table_opp, pl_self, pl_opp, i);
	}
	swap(pl_self, pl_opp);
	swap(table_opp, table_self);
	swap(deka_self, deka_opp);
	swap(hand_self, hand_opp);
	system("cls");
	return turn_count;
}



//Õ≈ “–Œ√¿“‹//
void fill_empty_hand(Game_Card** hand_1, Game_Card** hand_2, Game_Card** table_1, Game_Card** table_2) {
	for (int i = 0; i < 4; i++) {
		table_1[i] = new Empty_Field;
		table_2[i] = new Empty_Field;
		hand_1[i] = new Empty_Field;
		hand_2[i] = new Empty_Field;
	}
}


//Õ≈ “–Œ√¿“‹//
void fill_terran_deka(Game_Card** deka) {
	for (int i = 0; i < 5; i++) {
		deka[i] = new Marik;
	}
	for (int i = 5; i < 7; i++) {
		deka[i] = new Tank;
	}
	for (int i = 7; i < 9; i++) {
		deka[i] = new Ghost;
	}
	for (int i = 9; i < 12; i++) {
		deka[i] = new Reaper;
	}
	for (int i = 12; i < 14; i++) {
		deka[i] = new Liberator;
	}
	deka[14] = new Thor;
	deka[15] = new MedEvac;
	deka[16] = new MedEvac;
}


//Õ≈ “–Œ√¿“‹//
void init_game(Player* pl_1, Player* pl_2) {
	cout << color < 3, 0> << "***Welcome to StarGwint ver 1.0***" << endl << "***All rights are not reserved.***" << endl << endl;
	cout << "===Player 1 pick up your name (<=8 symbols). Your table is top one.===" << endl;
	cout << "Your name:";
	string name;
	cin >> name;
	pl_1->set_name(name);
	cout << endl << "===Player 2 pick up your name (<=8 symbols). Your table is lower one.===" << endl;
	cout << "Your name:";
	cin >> name;
	pl_2->set_name(name);
	cout << endl << "Great! Let's begin. Hope both of you read the rules." << endl;
	cout << "Type (start), when ready." << endl;
	while (name != "start") {
		cin >> name;
	}
	system("cls");
}


//Õ≈ “–Œ√¿“‹//
void end_game(string player_name) {
	cout << endl << "=== The game has ended. Player: " << player_name << " is the winner.=== " << endl;
}


//Õ≈ “–Œ√¿“‹//
bool check_hp(Player* pl_1, Player* pl_2) {
	if (pl_1->get_hp() <= 0) { end_game(pl_2->get_name()); return false; }
	if (pl_2->get_hp() <= 0) { end_game(pl_1->get_name()); return false; }
	else { return true; }
}