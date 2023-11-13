#include<iostream>
using namespace std;

int PlayerHealth = 100;
string inventory[5] = { "sword", "shield", "potion"," ", " " };

void BattleSystem();
int MonsterGen();

int main() {
	int room = 1;
	char input = 'a';
	//for (int i = 0; i < 10; i++)
	//	inventory[i] = " ";
	srand(time(NULL));

	while (PlayerHealth >= 0 && input != 'q') {

		cout << "your inventory: ";
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " ";
		cout << endl;

		switch (room) {
		case 1:
			cout << "you're in room 1, you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:
			BattleSystem();
			cout << "you're in room 2, you can go (n)orth" << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			break;

		}
	}
}

int MonsterGen() {
	int num = rand() % 100;
	if (num < 50) {
		cout << "A skeleton spawns" << endl;
		return 1;
	}
	else {
		cout << " A Spider spawns" << endl;
		return 2;
	}
}

void BattleSystem() {
	cout << "The fight begins" << endl;

	int MonsterType = MonsterGen();
	int MonsterHealth = 0;
	int MonsterAtk = 0;
	if (MonsterType == 1)
		MonsterHealth = 40;
	else if (MonsterType == 2)
		MonsterHealth = 20;


	while (MonsterHealth > 0 && PlayerHealth > 0) {
		char input;
		if (MonsterType == 1)
			MonsterAtk = rand() % 26;
		else if (MonsterType == 2)
			MonsterAtk = rand() % 10 + 5;
		if (inventory[1] == "shield") {
			cout << "the monster attacks you for" << MonsterAtk - 5 << "dmg" << endl;
			PlayerHealth -= 10;
		}
		else {
			cout << "the monster attacks you for " << MonsterAtk << "dmg!" << endl;
			cout << "the monster attacks! -10 hp" << endl;
			PlayerHealth -= 10;
		}
		if (inventory[0] == "sword") {
			cout << "you attack the monster! + 15 dmg" << endl;
			MonsterHealth -= 15;
		}
		else {
			cout << "you attack the monster! +10 dmg" << endl;
			MonsterHealth -= 5;
		}
		cout << "your health is now " << PlayerHealth << ", and the monsters health is now " << MonsterHealth << endl;
		system("pause");

		PlayerHealth -= MonsterAtk;

		if (PlayerHealth > 0 && MonsterHealth > 0) { //check to make sure nobody is dead before giving choices
			cout << "you can (f)ight, (r)un, or use (p)otion" << endl;
			cin >> input;
			if (input == 'r') {
				int num = rand() % 100;
				if (num < 40) {
					cout << "you escape the battle" << endl;
					break;
				}
				else
					cout << "you failed to escape" << endl;
			}

			if (input == 'p') {
				if (inventory[2] == "potion") {
					cout << "you drink you potion, + 25 health" << endl;
					PlayerHealth += 25;
					inventory[2] = " ";
				}
				else
					cout << "you do not have any potions" << endl;
			}
			if (input == 'f') cout << "the battle continues..." << endl;
		} //end of player choice 



	}//end of battle loop

	if (MonsterHealth <= 0)
		cout << "you survived" << endl;


	else
		cout << "you died" << endl;

}//end of battle function
