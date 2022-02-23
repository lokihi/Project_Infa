#include <iostream>
using namespace std;
//Õ≈ “–Œ√¿“‹//
class Player {
public:
	Player() {}
	void set_hp(int new_hp) { this->hp = new_hp; }
	int get_hp() { return this->hp; }
	void set_crystals(int new_crystals) { this->crystals = new_crystals; }
	int get_crystals() { return this->crystals; }
	void set_cards_in_hand(int new_cards) { this->cards_in_hand = new_cards; }
	int get_cards_in_hand() { return this->cards_in_hand; }
	void set_name(string name) { this->player_name = name; }
	string get_race() { return this->race; }
	string get_name() { return this->player_name; }
private:
	int hp = 20;
	int cards_in_hand = 0;
	int crystals = 1;
	string race = "Terran";
	string player_name = "PLAYER";
};

class Game_Card {
public:
	virtual void show_card() = 0;
	virtual int get_health() = 0;
	virtual int get_damage() = 0;
	virtual int get_cost() = 0;
	virtual bool get_free() = 0;
	virtual string get_name() = 0;
	virtual void set_health(int new_health) = 0;
};

//Õ≈ “–Œ√¿“‹//
class Empty_Field : public Game_Card {
public:
	void show_card() {
		cout << "*==*==*==Empty   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = true;
	int health = 0;
	int damage = 0;
	int cost = 0;
	string name = "Empty";
};


//Õ≈ “–Œ√¿“‹//
class Marik : public Game_Card {
public:
	Marik() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 1;
	int damage = 1;
	int cost = 1;
	string name = "MARIK";
};


class MedEvac : public Game_Card {
public:
	MedEvac() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 2;
	int damage = 0;
	int cost = 3;
	string name = "MEDE.";
};
//Õ≈ “–Œ√¿“‹//
class Reaper : public Game_Card {
public:
	Reaper() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 1;
	int damage = 2;
	int cost = 2;
	string name = "REAP.";
};


class Tank : public Game_Card {
public:
	Tank() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 3;
	int damage = 1;
	int cost = 2;
	string name = "TANK.";
};


class Ghost : public Game_Card {
public:
	Ghost() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 2;
	int damage = 3;
	int cost = 3;
	string name = "GHOST";
};


//Õ≈ “–Œ√¿“‹//
class Thor : public Game_Card {
public:
	Thor() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 3;
	int damage = 3;
	int cost = 4;
	string name = "THOR.";
};


class Liberator : public Game_Card {
public:
	Liberator() {}
	void show_card() {
		cout << this->damage << "==" << this->health << "==" << this->cost << "==" << this->name << "   ";
	}
	int get_health() { return this->health; }
	int get_damage() { return this->damage; }
	int get_cost() { return this->cost; }
	bool get_free() { return this->is_free; }
	string get_name() { return this->name; }
	void set_health(int new_health) {
		this->health = new_health;
	}
private:
	bool is_free = false;
	int health = 2;
	int damage = 2;
	int cost = 3;
	string name = "LIBER";
};
