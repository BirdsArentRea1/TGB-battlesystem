#include<iostream>
using namespace std;

void BattleSystem();
int MonsterGen();
int PlayerHealth = 100;

int main() {
	int room = 1;
	char input = 'a';
	srand(time(NULL));
	while (PlayerHealth >= 0 && input != 'q')
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


	int MonsterType = MonsterGen();
	int MonsterHealth = 0;
	int MonsterAtk = 0;
	if (MonsterType == 1)
		MonsterHealth = 40;
	else if (MonsterType == 2)
		MonsterHealth = 20;


	while (MonsterHealth > 0 && PlayerHealth > 0) {
		if (MonsterType == 1)
			MonsterAtk = rand() % 26;
		else if (MonsterType == 2)
			MonsterAtk = rand() % 10 + 5;
		cout << "the monster attacks you for " << MonsterAtk << "dmg!" << endl;
		cout << "the monster attacks! -10 hp" << endl;
		PlayerHealth -= 10;
		cout << "you attack the monster! +10 dmg" << endl;
		MonsterHealth -= 10;
		system("pause");
		cout << "your health is now " << PlayerHealth << ", and the monsters health is now " << MonsterHealth << endl;

		PlayerHealth -= MonsterAtk;

	}//end of battle loop

	if (MonsterHealth <= 0) 
		cout << "you survived" << endl;


	else
		cout << "you died" << endl;
	
}//end of battle function
