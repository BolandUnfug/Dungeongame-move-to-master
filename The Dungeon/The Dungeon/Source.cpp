#include<iostream>
#include<string>
#include<ctime>
using namespace std;
//FUNCTIONS
void encounter();
void monstergen(char t);
int damagecalc(char m);
void lootdrop(string n);
string lootbox(char r);
// GLLOBAL VARIABLES
int health = 2000;
char monstertype;
//string inventory [5] = {};
//string cratetype;
int main() {
	//LOCAL VARIABLES

	string answer;

	srand(time(NULL));

	int room = 1;
	while (health > 0) {
		cout << " you have " << health << " health left." << endl;
		if (room == 1) {

			cout << " you are in room 1. you can go south or east." << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("s") == 0 || answer.compare("S") == 0 || answer.compare("south") == 0 || answer.compare("South") == 0) {
				room = 4;
			}
			else if (answer.compare("e") == 0 || answer.compare("E") == 0 || answer.compare("east") == 0 || answer.compare("East") == 0) {
				room = 2;
			}
		}
		else if (room == 2) {

			cout << " you are in room 2. you can go west or east." << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("w") == 0 || answer.compare("W") == 0 || answer.compare("west") == 0 || answer.compare("West") == 0) {
				room = 1;
			}
			else if (answer.compare("e") == 0 || answer.compare("E") == 0 || answer.compare("east") == 0 || answer.compare("East") == 0) {
				room = 3;
			}

		}
		else if (room == 3) {

			cout << " you are in room 3. you can go south or west." << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("s") == 0 || answer.compare("S") == 0 || answer.compare("south") == 0 || answer.compare("South") == 0) {
				room = 5;
			}
			else if (answer.compare("w") == 0 || answer.compare("W") == 0 || answer.compare("west") == 0 || answer.compare("West") == 0) {
				room = 2;
			}

		}
		else if (room == 4) {

			cout << " you are in room 4. You can go north" << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("n") == 0 || answer.compare("S") == 0 || answer.compare("north") == 0 || answer.compare("North") == 0) {
				room = 1;
			}

		}
		else if (room == 5) {

			cout << " you are in room 5. you can go south, norht, or east." << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("s") == 0 || answer.compare("S") == 0 || answer.compare("south") == 0 || answer.compare("South") == 0) {
				room = 8;
			}
			else if (answer.compare("e") == 0 || answer.compare("E") == 0 || answer.compare("east") == 0 || answer.compare("East") == 0) {
				room = 6;
			}
			else if (answer.compare("n") == 0 || answer.compare("S") == 0 || answer.compare("north") == 0 || answer.compare("North") == 0) {
				room = 3;
			}

		}
		else if (room == 6) {

			cout << " you are in room 6. you can go west" << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("w") == 0 || answer.compare("W") == 0 || answer.compare("west") == 0 || answer.compare("West") == 0) {
				room = 5;
			}

		}
		else if (room == 7) {

			cout << " you are in room 7. you can go east" << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("e") == 0 || answer.compare("E") == 0 || answer.compare("east") == 0 || answer.compare("East") == 0) {
				room = 8;
			}
		}
		else if (room == 8) {

			cout << " you are in room 7. you can go east" << endl;
			getline(cin, answer);
			encounter();
			if (answer.compare("w") == 0 || answer.compare("W") == 0 || answer.compare("west") == 0 || answer.compare("West") == 0) {
				room = 8;
			}
			else if (answer.compare("n") == 0 || answer.compare("S") == 0 || answer.compare("north") == 0 || answer.compare("North") == 0) {
				room = 5;
			}

		}
	}
}

void encounter() {
	int randencounter = rand() % 100;
	//cout << "encounter function activated" << endl;
	//system("pause");
	if (randencounter <= 10) {
		cout << "You came into an empty room." << endl;
	}
	else if (randencounter <= 50 && randencounter > 10) {
		cout << "You found a monster" << endl;
		monstergen('e');
	}
	else if (randencounter <= 70 && randencounter > 50) {
		cout << "You found a healer!" << endl;
		health = health + rand() % 100;
		if (health > 200) {
			health = 200;
		}
		cout << "You are now at " << health << " health!" << endl;
	}
	else if (randencounter <= 90 && randencounter > 70) {
		cout << "You found a trader! he does not have anything for you yet." << endl;
	}
	else if (randencounter <= 100 && randencounter > 90) {

		cout << "Wow! A treasure room! Wait..." << endl;
		monstergen('d');
		string cratetype = lootbox('t');
		lootdrop(cratetype);
	}
}

void monstergen(char t) {
	string cratetype;
	int damage;
	//cout << "monster function activated" << endl;
	//system("pause");
	if (t == 'd') {
		cout << "could it be? you have to fight a dragon!" << endl;
		monstertype = 'd';
		cout << "You killed it!" << endl;
		damage = damagecalc('d');
		health = health - damage;
		cout << "You took " << damage << "!" << endl;
		cratetype = lootbox('d');
		cout << "The dragon dropped a " << cratetype << " lootbox!" << endl;
		lootdrop(cratetype);
	}
	else {
		int randmonster = rand() % 100;


		if (randmonster <= 25) {
			cout << "You happened upon a goblin!" << endl;
			monstertype = 'g';
			cout << "You killed it!" << endl;
			damage = damagecalc('g');
			health = health - damage;
			cout << "You took " << damage << "!" << endl;
			cratetype = lootbox('g');
			cout << "The goblin dropped a " << cratetype << " lootbox!" << endl;
			lootdrop(cratetype);
		}
		else if (randmonster <= 50 && randmonster > 25) {
			cout << "You got startled by a zombie!" << endl;
			monstertype = 'z';
			cout << "You killed it!" << endl;
			damage = damagecalc('z');
			health = health - damage;
			cout << "You took " << damage << "!" << endl;
			cratetype = lootbox('z');
			cout << "The zombie dropped a " << cratetype << " lootbox!" << endl;
			lootdrop(cratetype);
		}
		else if (randmonster <= 70 && randmonster > 50) {
			cout << "A skeleton was around the corner!" << endl;
			monstertype = 's';
			cout << "You killed it!" << endl;
			damage = damagecalc('s');
			health = health - damage;
			cout << "You took " << damage << "!" << endl;
			cratetype = lootbox('s');
			cout << "The skeleton dropped a " << cratetype << " lootbox!" << endl;
			lootdrop(cratetype);
		}
		else if (randmonster <= 90 && randmonster > 70) {
			cout << "Oh no! A witch!" << endl;
			monstertype = 'w';
			cout << "You killed it!" << endl;
			damage = damagecalc('w');
			health = health - damage;
			cout << "You took " << damage << "!" << endl;
			cratetype = lootbox('w');
			cout << "The wich dropped a " << cratetype << " lootbox!" << endl;
			lootdrop(cratetype);

		}
		else if (randmonster <= 100 && randmonster > 90) {
			cout << "Could it be? you have to fight a dragon!" << endl;
			monstertype = 'd';
			cout << "You killed it!" << endl;
			damage = damagecalc('d');
			health = health - damage;
			cout << "You took " << damage << "!" << endl;
			cratetype = lootbox('d');
			cout << "The dragon dropped a " << cratetype << " lootbox!" << endl;
			lootdrop(cratetype);
		}

	}
}

int damagecalc(char m) {
	//cout << "damage function activated" << endl;
	//system("pause");
	int randdamage;
	if (m == 'g') {
		randdamage = rand() % 10 + 10;
	}
	if (m == 'z') {
		randdamage = rand() % 20 + 10;
	}
	else if (m = 's') {
		randdamage = rand() % 25 + 15;
	}
	else if (m = 'w') {
		randdamage = rand() % 30 + 20;
	}
	else if (m = 'd') {
		randdamage = rand() % 50 + 50;
	}
	return randdamage;
}

void lootdrop(string n) {
	//cout << "lootdrop function activated" << endl;
	//system("pause");
	int randloot;
	string loottype;
	if (n == "common") {
		randloot = rand() % 10;
		if (randloot <= 4) {
			cout << "You got a rusty sword." << endl;
		}
		else if (randloot > 7) {
			cout << "You got a wooden sword." << endl;
		}
		else if (randloot > 10) {
			cout << "You collected a standard sword!" << endl;
		}
	}
	else if (n == "rare") {
		randloot = rand() % 10;
		if (randloot <= 4) {
			cout << "You got an iron sword." << endl;
		}
		else if (randloot > 7) {
			cout << "You got a slightly magical sword." << endl;
		}
		else if (randloot > 10) {
			cout << "You got an interestingly shaped weapon!" << endl;
		}
	}
	else if (n == "epic") {
		randloot = rand() % 10;
		if (randloot <= 4) {
			cout << "You got a magical sword." << endl;
		}
		else if (randloot > 7) {
			cout << "You got a Diamond sword" << endl;
		}
		else if (randloot > 10) {
			cout << "You got a scythe!" << endl;
		}
	}
	else if (n == "legendary") {
		randloot = rand() % 10;
		if (randloot <= 4) {
			cout << "You got a SUPER MAGICAL SWORD!" << endl;
		}
		else if (randloot > 7) {
			cout << "You got a MAGIC WAND!" << endl;
		}
		else if (randloot > 10) {
			cout << "You got DEATH'S SCYTHE!" << endl;
		}
	}
	else
		cout << "something did not trigger" << endl;
}

string lootbox(char m) {
	//cout << "lootbox function activated" << endl;
	//system("pause");
	int randcrate = 0;
	string cratetype = "oops";
	if (m == 'g') {
		cout << "goblin" << endl;
		randcrate = rand() % 10;
		if (randcrate <= 9) {
			cratetype = "common";
		}
		else if (randcrate > 9) {
			cratetype = "rare";
		}
	}
	else if (m == 'z') {
		randcrate = rand() % 10;
		if (randcrate <= 8) {
			cratetype = "common";
		}
		else if (randcrate > 8) {
			cratetype = "rare";
		}
	}
	else if (m = 's') {
		randcrate = rand() % 10;
		if (randcrate <= 7) {
			cratetype = "common";
		}
		else if (randcrate <= 9) {
			cratetype = "rare";
		}
		else if (randcrate == 10) {
			cratetype = "epic";
		}
	}
	else if (m = 'w') {
		randcrate = rand() % 10;
		if (randcrate <= 6) {
			cratetype = "common";
		}
		else if (randcrate <= 9) {
			cratetype = "rare";
		}
		else if (randcrate == 10) {
			cratetype = "epic";
		}
	}
	else if (m = 'd') {
		randcrate = rand() % 10;
		if (randcrate <= 5) {
			cratetype = "epic";
		}
		else if (randcrate <= 10) {
			cratetype = "legendary";
		}
	}
	else if (m == 't') {
		if (randcrate <= 2) {
			cratetype = "common";
		}
		else if (randcrate <= 5) {
			cratetype = "rare";
		}
		else if (randcrate <= 8) {
			cratetype = "epic";
		}
		else if (randcrate <= 10) {
			cratetype = "legendary";
		}
	}
	return cratetype;

}