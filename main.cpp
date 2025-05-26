#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

const string DEFAULT_NAME = "n/a";
const string DEFAULT_CREATURE_TYPE = "typeless";

const int TYPELIST_SIZE = 4;
const string TYPES_LIST[TYPELIST_SIZE] = { "Ceffyl", "Nuggle", "Bahamut", "CyberBahamut" };

const int DEFAULT_HEALTH_AND_STRENGTH = 120;
const int DEFAULT_SIZE = 10;

class Creature {
public:

	void setCreature(string newName, string newType, int newHealth, int newStrength);
	void setGameCreature(int newHealth);

	const string getName() { return creatureName; }
	const string getType() { return creatureType; }
	const int  getHealth() { return creatureHealth; }
	const int getStrength() { return creatureStrength; }

	virtual const int getDamage();

	Creature() {

		setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}
	Creature(Creature& otherCreature) {

		setCreature(otherCreature.creatureName, otherCreature.creatureType, otherCreature.creatureHealth, otherCreature.creatureStrength);

	}
	Creature(string newName) {

		setCreature(newName, TYPES_LIST[(rand() % 4)], (rand() % 51) + 50, (rand() % 51) + 50);

	}
	Creature(string newName, string newType, int newHealth, int newStrength) {

		setCreature(newName, newType, newHealth, newStrength);

	}
	~Creature() {

		setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}

	string toString();
protected:

	string creatureName = DEFAULT_NAME;
	string creatureType = DEFAULT_CREATURE_TYPE;
	int creatureHealth = DEFAULT_HEALTH_AND_STRENGTH;
	int creatureStrength = DEFAULT_HEALTH_AND_STRENGTH;
};
class Ceffyl : public Creature {
public:
	
	Ceffyl() { setCreature(DEFAULT_NAME, "Ceffyl", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Ceffyl(Ceffyl &otherCeffyl);
	Ceffyl(string name) { setCreature(name, "Ceffyl", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Ceffyl(string name, int health) { setCreature(name, "Ceffyl", health, DEFAULT_HEALTH_AND_STRENGTH); }
	Ceffyl(string name, int health, int strength) { setCreature(name, "Ceffyl", health, strength); }
	~Ceffyl() { setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }

	const int getDamage();
};
class Bahamut : public Creature {
public:

	Bahamut() { setCreature(DEFAULT_NAME, "Bahamut", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Bahamut(Bahamut& otherBahamut);
	Bahamut(string name) { setCreature(name, "Bahamut", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Bahamut(string name, int health) { setCreature(name, "Bahamut", health, DEFAULT_HEALTH_AND_STRENGTH); }
	Bahamut(string name, int health, int strength) { setCreature(name, "Bahamut", health, strength); }
	~Bahamut() { setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }

	const int getDamage();
};
class CyberBahamut : public Bahamut {
public:
	
	CyberBahamut() { setCreature(DEFAULT_NAME, "CyberBahamut", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	CyberBahamut(CyberBahamut& otherCyberBahamut);
	CyberBahamut(string name) { setCreature(name, "CyberBahamut", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	CyberBahamut(string name, int health) { setCreature(name, "CyberBahamut", health, DEFAULT_HEALTH_AND_STRENGTH); }
	CyberBahamut(string name, int health, int strength) { setCreature(name, "CyberBahamut", health, strength); }
	~CyberBahamut() { setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }

	const int getDamage();
};
class Nuggle : public Creature {
public:
	
	Nuggle() { setCreature(DEFAULT_NAME, "Nuggle", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Nuggle(Nuggle& otherNuggle);
	Nuggle(string name) { setCreature(name, "Nuggle", DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }
	Nuggle(string name, int health) { setCreature(name, "Nuggle", health, DEFAULT_HEALTH_AND_STRENGTH); }
	Nuggle(string name, int health, int strength) { setCreature(name, "Nuggle", health, strength); }
	~Nuggle() { setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH); }

	const int getDamage();
};

class Army {
public:

	Army();
	Army(Army& otherArmy);
	Army(string fileName);
	Army(string newArmyName, string fileName);

	Army(string newArmyName, int armySize);
	Army(string newArmyName, string fileName, int armySize);
	~Army();

	const string getArmyCreatureName(int index) { return ppCreatures[index]->getName(); }
	const string getArmyCreatureType(int index) { return ppCreatures[index]->getType(); }
	const string getArmyName() { return armyName; }
	const string getPrintCreature(int index) { return ppCreatures[index]->toString(); }

	void checkDuplicateNames(Army& otherArmy);
	void setArmy(int size);

	const int getArmyCreatureHealth(int index) { return ppCreatures[index]->getHealth(); }
	const int getArmyCreatureStrength(int index) { return ppCreatures[index]->getStrength(); }
	const int getArmyCreatureDamage(int index) { return ppCreatures[index]->getDamage(); }
	const int getCreatureCount() { return creatureCount; }

	void setCreature(int newHealth, int index) {

		ppCreatures[index]->setGameCreature(newHealth);

	}
	void setCreature(string newName, string newType, int newHealth, int newStrength, int index) {

		ppCreatures[index]->setCreature(newName, newType, newHealth, newStrength);

	}

private:

	string armyName = DEFAULT_NAME;

	int creatureCount = 0;
	int armySize = DEFAULT_SIZE;

	Creature** ppCreatures = nullptr;


};
class Game {
public:

	Game();
	Game(int size);
	Game(int size, string nameA, string nameB);
	Game(int size, string nameA, string nameB, string nameAInput, string nameBInput);

	const int getArmyHealth(Army &army, int size);
	void printTurn(Army &attacker, Army &defender, int health, int damage, int index);
	void printArmies(Army& army1, Army& army2, int size);
	void printStats(Army &army1, Army &army2, int health1, int health2);
	void battleResult(Army &army1, Army &army2, int index);

	void catchFunction(int size);

private:

	int overallHealthA = 0;
	int overallHealthB = 0;

	bool isTurnA = false;
	int currentDamage = 0;

};
class GameSizeExeption
{
public:
	GameSizeExeption()
	{
		exceptionErrorMessage = "UNKNOWN ERROR; SETTING TO DEFAULT";
	}


	GameSizeExeption(string errorMessage)
	{
		exceptionErrorMessage = errorMessage + "; SETTING TO DEFAULT";
	}


	string what()
	{
		return exceptionErrorMessage;
	}


private:
	string exceptionErrorMessage;
};

enum {

	PLAY = 1,
	QUIT

};

void defaultSwitch();
void gameFunction();
int quitFunction(int input);

int main()
{
	srand(time(0));
	int input = 0;

	cout << "Welcome to the Battle Game!\n";

	while (input != QUIT) {
		input = 0;
		cout << "\nMenu:\n"
			"1. Play\n"
			"2. Quit\n"
			"Input: ";

		cin >> input;
		switch (input) {
		case PLAY:
			gameFunction();
			break;
		case QUIT:
			input = quitFunction(input);
			break;
		default:
			defaultSwitch();
			break;
		}
	}
}

void Creature::setCreature(string newName, string newType, int newHealth, int newStrength) {

	int count = 0;
	for (char c : newName) {
		if (std::isalpha(c)) {
			count++;
		}
	}
	if (count < 3 && newName != DEFAULT_NAME) {

		cout << newName << " has less than 3 alphabetic characters, setting to defalut..." << endl;
		newName =  DEFAULT_NAME;

	}

	bool isInlist = false;
	for (int i = 0; i < TYPELIST_SIZE; i++) {

		if (newType == TYPES_LIST[i] || newType == DEFAULT_CREATURE_TYPE) {

			isInlist = true;

		}

	}
	if (!isInlist) {

		cout << newType << " is not 1 of 4 valid types (ceffyl, nuggle, bahamut, Cyber bahamut), setting to default...\n";
		newType = DEFAULT_CREATURE_TYPE;

	}

	if ((newHealth < 120) || (newHealth > 250)) {

		cout << newHealth << " is either less than 120 or greater than 250, setting to default...\n";
		newHealth =  DEFAULT_HEALTH_AND_STRENGTH;

	}

	if ((newStrength < 120) || (newStrength > 250)) {

		cout << newStrength << " is either less than 120 or greater than 250, setting to default...\n";
		newStrength = DEFAULT_HEALTH_AND_STRENGTH;

	}

	creatureName = newName;
	creatureType = newType;
	creatureHealth = newHealth;
	creatureStrength = newStrength;

}
void Creature::setGameCreature(int newHealth) {
	
	if (newHealth < 0) {

		newHealth = 0;

	}

	creatureHealth = newHealth;

}
string Creature::toString() {

	ostringstream text;
	text << creatureName << " the " << creatureType;
	return text.str();

}
const int Creature::getDamage() {
	int damage = rand() % getStrength() + 1;
	return damage;
}

const int Ceffyl::getDamage() {

	int damage = Creature::getDamage();

		if ((rand() % 100) < 15) {
			damage = damage + 25;
			cout << toString() << "'s bonus damage activated!\n";
		}

	return damage;

}
Ceffyl::Ceffyl(Ceffyl& otherCeffyl) {

	setCreature(otherCeffyl.creatureName, otherCeffyl.creatureType, otherCeffyl.creatureHealth, otherCeffyl.creatureStrength);

}

const int Bahamut::getDamage() {

	int damage = Creature::getDamage();

		damage = damage * 2;
		cout << toString() << "'s double attack activated!\n";

	return damage;

}
Bahamut::Bahamut(Bahamut& otherBahamut) {

	setCreature(otherBahamut.creatureName, otherBahamut.creatureType, otherBahamut.creatureHealth, otherBahamut.creatureStrength);

}

CyberBahamut::CyberBahamut(CyberBahamut& otherCyberBahamut) {

	setCreature(otherCyberBahamut.creatureName, otherCyberBahamut.creatureType, otherCyberBahamut.creatureHealth, otherCyberBahamut.creatureStrength);

}
const int CyberBahamut::getDamage() {
	
	int damage = Bahamut::getDamage();

	if ((rand() % 100) < 10) {
		damage = damage + 30;
		cout << toString() << "'s bahamut attack activated!\n";
	}

	return damage;

}

Nuggle::Nuggle(Nuggle& otherNuggle) {

	setCreature(otherNuggle.creatureName, otherNuggle.creatureType, otherNuggle.creatureHealth, otherNuggle.creatureStrength);

}
const int Nuggle::getDamage() {

	int damage = Creature::getDamage();

	if ((rand() % 15) == 0) {
		damage = damage * 2;
		cout << toString() << "'s magical attack multiplier activated!\n";
	}

	return damage;

}

Army::Army() {

	ppCreatures = new Creature * [DEFAULT_SIZE];
	for (int i = 0; i < DEFAULT_SIZE; i++) {

		ppCreatures[i] = new Creature;

	}

	armyName = DEFAULT_NAME;
	creatureCount = DEFAULT_SIZE;
	armySize = DEFAULT_SIZE;

	for (int i = 0; i < armySize; i++) {

		ppCreatures[i]->setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}


}
Army::~Army() {

	armyName = DEFAULT_NAME;
	try {
		delete[] ppCreatures;
	}
	catch (...) {

		for (int i = 0; i < armySize; i++) {

			ppCreatures[i]->setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

		}

	}

}
Army::Army(string fileName) {

	string nameInput;
	setArmy(DEFAULT_SIZE);

	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		cout << "Cannot open file" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < DEFAULT_SIZE; i++) {

		nameInput = "";
		infile >> nameInput;

		ppCreatures[creatureCount]->setCreature(nameInput, ppCreatures[i]->getType(), (rand() % 131) + 120, (rand() % 131) + 120);

		if (nameInput != "") {

			creatureCount++;

		}

	}

}
Army::Army(string newArmyName, string fileName) {

	ppCreatures = new Creature* [DEFAULT_SIZE];
	for (int i = 0; i < DEFAULT_SIZE; i++) {

		ppCreatures[i] = new Creature;

	}

	string nameInput;

	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		cout << "Cannot open file" << endl;
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	for (char c : newArmyName) {
		if (std::isalpha(c)) {
			count++;
		}
	}
	if (count < 3 && newArmyName != DEFAULT_NAME) {

		cout << newArmyName << " has less than 3 alphabetic characters, setting to defalut..." << endl;
		newArmyName = DEFAULT_NAME;

	}
	armyName = newArmyName;

	for (int i = 0; i < DEFAULT_SIZE; i++) {

		nameInput = "";
		infile >> nameInput;

		ppCreatures[creatureCount]->setCreature(nameInput, ppCreatures[i]->getType(), (rand() % 131) + 120, (rand() % 131) + 120);

		if (nameInput != "") {

			creatureCount++;

		}

	}

}
Army::Army(string newArmyName, int newArmySize) {

	armySize = newArmySize;
	
	setArmy(newArmySize);

	int count = 0;
	for (char c : newArmyName) {
		if (std::isalpha(c)) {
			count++;
		}
	}
	if (count < 3 && newArmyName != DEFAULT_NAME) {

		cout << newArmyName << " has less than 3 alphabetic characters, setting to defalut..." << endl;
		newArmyName = DEFAULT_NAME;

	}
	armyName = newArmyName;

	for (int i = 0; i < armySize; i++) {


		ppCreatures[creatureCount]->setCreature("CREATURE_" + to_string(i), ppCreatures[i]->getType(), (rand() % 131) + 120, (rand() % 131) + 120);
			creatureCount++;


	}

}
Army::Army(string newArmyName, string fileName, int newArmySize) {

	armySize = newArmySize;

	setArmy(newArmySize);
	string nameInput;

	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		cout << "Cannot open file" << endl;
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	for (char c : newArmyName) {
		if (std::isalpha(c)) {
			count++;
		}
	}
	if (count < 3 && newArmyName != DEFAULT_NAME) {

		cout << newArmyName << " has less than 3 alphabetic characters, setting to defalut..." << endl;
		newArmyName = DEFAULT_NAME;

	}
	armyName = newArmyName;

	for (int i = 0; i < armySize; i++) {

		nameInput = "";
		infile >> nameInput;

		if (nameInput == "") {

			nameInput = DEFAULT_NAME;

		}

		ppCreatures[creatureCount]->setCreature(nameInput, ppCreatures[i]->getType(), (rand() % 131) + 120, (rand() % 131) + 120);

		if (nameInput != "") {

			creatureCount++;

		}

	}

}
Army::Army(Army& otherArmy) {
	
	ppCreatures = new Creature * [armySize];
	for (int i = 0; i < armySize; i++) {

		ppCreatures[i] = otherArmy.ppCreatures[i];

	}
	armyName = otherArmy.armyName;
	armySize = otherArmy.armySize;
	creatureCount = otherArmy.creatureCount;

}

void Army::checkDuplicateNames(Army &otherArmy) {

	for (int i = 0; i < armySize; i++) {

		for (int j = 0; j < armySize; j++) {

			if (getArmyCreatureName(i) == otherArmy.getArmyCreatureName(j) && getArmyCreatureName(i) != DEFAULT_NAME) {

					setCreature(DEFAULT_NAME,getArmyCreatureType(i),getArmyCreatureHealth(i), getArmyCreatureStrength(i), i);
			}

		}

	}

}
void Army::setArmy(int size) {
	int tempNum = 0;
	ppCreatures = new Creature * [size];
	for (int i = 0; i < size; i++) {
		tempNum = rand() % 4;

		if (tempNum == 0) {

			try {

				ppCreatures[i] = new Ceffyl;

			}
			catch (...) {

				ppCreatures[i] = new Creature;

			}
		}
		else if (tempNum == 1) {

			try {

				ppCreatures[i] = new Bahamut;
			}
			catch (...) {

				ppCreatures[i] = new Creature;

			}
		}
		else if (tempNum == 2) {

			try {

				ppCreatures[i] = new CyberBahamut;
			}
			catch (...) {

				ppCreatures[i] = new Creature;

			}
		}
		else if (tempNum == 3) {
			try {

				ppCreatures[i] = new Nuggle;

			}
			catch (...) {

				ppCreatures[i] = new Creature;

			}

		}
	}
}

Game::Game() {

	Army ArmyA("red", "in_redNames.dat");
	Army ArmyB("blu", "in_bluNames.dat");

	overallHealthA = getArmyHealth(ArmyA, DEFAULT_SIZE);
	overallHealthB = getArmyHealth(ArmyB, DEFAULT_SIZE);

	printArmies(ArmyA, ArmyB, DEFAULT_SIZE);

	for (int i = 0; i < DEFAULT_SIZE; i++) {

		cout << "===================================================================================================\nRound " << i + 1 << ":\n\nAttacker                     Damage     Army      Defender                     Health     Army\n";

		if (isTurnA == true) {

			printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

		}
		else if (isTurnA == false) {

			printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

		}
		
		while ((ArmyA.getArmyCreatureHealth(i)) > 0 && (ArmyB.getArmyCreatureHealth(i) > 0)) {

			if (isTurnA == true) {

				currentDamage = ArmyA.getArmyCreatureDamage(i);
				ArmyB.setCreature((ArmyB.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = false;

			}
			else if (isTurnA == false) {

				currentDamage = ArmyB.getArmyCreatureDamage(i);
				ArmyA.setCreature((ArmyA.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = true;

			}

		}

		overallHealthA = getArmyHealth(ArmyA, DEFAULT_SIZE);
		overallHealthB = getArmyHealth(ArmyB, DEFAULT_SIZE);
	
		battleResult(ArmyA, ArmyB, i);
		printStats(ArmyA, ArmyB, overallHealthA, overallHealthB);
		
		currentDamage = 0;

	}

	cout << "===================================================================================================\n";
	if (overallHealthA > overallHealthB) {

		cout << ArmyA.getArmyName() << " has won with " << overallHealthA << " health!";

	}
	else if (overallHealthA < overallHealthB) {

		cout << ArmyB.getArmyName() << " has won with " << overallHealthB << " health!";

	}
	else if (overallHealthA == overallHealthB) {

		cout << ArmyA.getArmyName() << " and " << ArmyB.getArmyName() << " have tied with " << overallHealthA << " health!";

	}

}
Game::Game(int size) {
	
	try {

		catchFunction(size);

	}
	catch (GameSizeExeption Exeption) {

		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}
	catch (...) {

		GameSizeExeption Exeption;
		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}

	Army ArmyA("red", size);
	Army ArmyB("blu", size);

	overallHealthA = getArmyHealth(ArmyA, size);
	overallHealthB = getArmyHealth(ArmyB, size);

	printArmies(ArmyA, ArmyB, size);

	for (int i = 0; i < size; i++) {

		cout << "===================================================================================================\nRound " << i + 1 << ":\n\nAttacker                     Damage     Army      Defender                     Health     Army\n";

		if (isTurnA == true) {

			printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

		}
		else if (isTurnA == false) {

			printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

		}

		while ((ArmyA.getArmyCreatureHealth(i)) > 0 && (ArmyB.getArmyCreatureHealth(i) > 0)) {

			if (isTurnA == true) {

				currentDamage = ArmyA.getArmyCreatureDamage(i);
				ArmyB.setCreature((ArmyB.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = false;

			}
			else if (isTurnA == false) {

				currentDamage = ArmyB.getArmyCreatureDamage(i);
				ArmyA.setCreature((ArmyA.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = true;

			}

		}

		overallHealthA = getArmyHealth(ArmyA, size);
		overallHealthB = getArmyHealth(ArmyB, size);

		battleResult(ArmyA, ArmyB, i);
		printStats(ArmyA, ArmyB, overallHealthA, overallHealthB);

		currentDamage = 0;

	}

	cout << "===================================================================================================\n";
	if (overallHealthA > overallHealthB) {

		cout << ArmyA.getArmyName() << " has won with " << overallHealthA << " health!";

	}
	else if (overallHealthA < overallHealthB) {

		cout << ArmyB.getArmyName() << " has won with " << overallHealthB << " health!";

	}
	else if (overallHealthA == overallHealthB) {

		cout << ArmyA.getArmyName() << " and " << ArmyB.getArmyName() << " have tied with " << overallHealthA << " health!";

	}
	cout << "\nend game\n\n";
}
Game::Game(int size, string nameA, string nameB) {

	try {

		catchFunction(size);

	}
	catch (GameSizeExeption Exeption) {

		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}
	catch (...) {

		GameSizeExeption Exeption;
		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}

	Army ArmyA(nameA, size);
	Army ArmyB(nameB, size);

	overallHealthA = getArmyHealth(ArmyA, size);
	overallHealthB = getArmyHealth(ArmyB, size);

	printArmies(ArmyA, ArmyB, size);

	for (int i = 0; i < size; i++) {

		cout << "===================================================================================================\nRound " << i + 1 << ":\n\nAttacker                     Damage     Army      Defender                     Health     Army\n";

		if (isTurnA == true) {

			printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

		}
		else if (isTurnA == false) {

			printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

		}

		while ((ArmyA.getArmyCreatureHealth(i)) > 0 && (ArmyB.getArmyCreatureHealth(i) > 0)) {

			if (isTurnA == true) {

				currentDamage = ArmyA.getArmyCreatureDamage(i);
				ArmyB.setCreature((ArmyB.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = false;

			}
			else if (isTurnA == false) {

				currentDamage = ArmyB.getArmyCreatureDamage(i);
				ArmyA.setCreature((ArmyA.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = true;

			}

		}

		overallHealthA = getArmyHealth(ArmyA, size);
		overallHealthB = getArmyHealth(ArmyB, size);

		battleResult(ArmyA, ArmyB, i);
		printStats(ArmyA, ArmyB, overallHealthA, overallHealthB);

		currentDamage = 0;

	}

	cout << "===================================================================================================\n";
	if (overallHealthA > overallHealthB) {

		cout << ArmyA.getArmyName() << " has won with " << overallHealthA << " health!";

	}
	else if (overallHealthA < overallHealthB) {

		cout << ArmyB.getArmyName() << " has won with " << overallHealthB << " health!";

	}
	else if (overallHealthA == overallHealthB) {

		cout << ArmyA.getArmyName() << " and " << ArmyB.getArmyName() << " have tied with " << overallHealthA << " health!";

	}
	cout << "\nend game\n\n";

}
Game::Game(int size, string nameA, string nameB, string nameAInput, string nameBInput) {

	try {

		catchFunction(size);

	}
	catch (GameSizeExeption Exeption) {

		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}
	catch (...) {

		GameSizeExeption Exeption;
		cout << Exeption.what() << endl;
		size = DEFAULT_SIZE;

	}

	Army ArmyA(nameA, nameAInput + ".dat", size);
	Army ArmyB(nameB, nameBInput + ".dat", size);

	overallHealthA = getArmyHealth(ArmyA, size);
	overallHealthB = getArmyHealth(ArmyB, size);

	printArmies(ArmyA, ArmyB, size);

	for (int i = 0; i < size; i++) {
		cout << "===================================================================================================\nRound " << i + 1 << ":\n\nAttacker                     Damage     Army      Defender                     Health     Army\n";

		if (isTurnA == true) {

			printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

		}
		else if (isTurnA == false) {

			printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

		}

		while ((ArmyA.getArmyCreatureHealth(i)) > 0 && (ArmyB.getArmyCreatureHealth(i) > 0)) {

			if (isTurnA == true) {

				currentDamage = ArmyA.getArmyCreatureDamage(i);
				ArmyB.setCreature((ArmyB.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyA, ArmyB, ArmyB.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = false;

			}
			else if (isTurnA == false) {

				currentDamage = ArmyB.getArmyCreatureDamage(i);
				ArmyA.setCreature((ArmyA.getArmyCreatureHealth(i) - currentDamage), i);
				printTurn(ArmyB, ArmyA, ArmyA.getArmyCreatureHealth(i), currentDamage, i);

				isTurnA = true;

			}

		}

		overallHealthA = getArmyHealth(ArmyA, size);
		overallHealthB = getArmyHealth(ArmyB, size);

		battleResult(ArmyA, ArmyB, i);
		printStats(ArmyA, ArmyB, overallHealthA, overallHealthB);

		currentDamage = 0;

	}

	cout << "===================================================================================================\n";
	if (overallHealthA > overallHealthB) {

		cout << ArmyA.getArmyName() << " has won with " << overallHealthA << " health!";

	}
	else if (overallHealthA < overallHealthB) {

		cout << ArmyB.getArmyName() << " has won with " << overallHealthB << " health!";

	}
	else if (overallHealthA == overallHealthB) {

		cout << ArmyA.getArmyName() << " and " << ArmyB.getArmyName() << " have tied with " << overallHealthA << " health!";

	}
	cout << "\nend game\n\n";

}

const int Game::getArmyHealth(Army &army, int arraySize) {

	int totalHealth = 0;

		for (int i = 0; i < arraySize; i++) {

			totalHealth = totalHealth + army.getArmyCreatureHealth(i);
		}
	return totalHealth;
}
void Game::printTurn(Army &attacker, Army &defender, int health, int damage, int index) {
	
		cout << left << setw(30) << attacker.getPrintCreature(index) << right << setw(5)
		<< damage << right << setw(5) << ""
		<< attacker.getArmyName()

		<< "       "

		<< left << setw(30) << defender.getPrintCreature(index) << right << setw(5)
		<< health << right << setw(5) << ""
		<< defender.getArmyName()

		<< endl;
}
void Game::printArmies(Army& Army1, Army& Army2, int size) {

	cout << "===================================================================================================\nCreature                   Strength    Health     Army      Creature                   Strength    Health     Army\n";
	for (int i = 0; i < size; i++) {

		cout << left << setw(30) << Army1.getPrintCreature(i) << right << setw(5)
			<< Army1.getArmyCreatureStrength(i) << right << setw(10) << Army1.getArmyCreatureHealth(i) << right << setw(5) << ""
			<< Army1.getArmyName()

			<< "       "

			<< left << setw(30) << Army2.getPrintCreature(i) << right << setw(5)
			<< Army2.getArmyCreatureStrength(i) << right << setw(10) << Army2.getArmyCreatureHealth(i) << right << setw(5) << ""
			<< Army2.getArmyName()

			<< endl;
	}
}
void Game::printStats(Army &army1, Army &army2, int health1, int health2) {
	cout << endl << endl
	     << army1.getArmyName() << "'s total health: " << health1 << endl
		 << army2.getArmyName() << "'s total health: " << health2 << endl;

}
void Game::battleResult(Army &army1, Army &army2, int index) {

	if (army1.getArmyCreatureHealth(index) == 0) {

		army1.setCreature(0, index);
		cout << "\nWinner: " << army2.getPrintCreature(index) << "\nLoser: " << army1.getPrintCreature(index);

	}
	else if (army2.getArmyCreatureHealth(index) == 0) {

		army2.setCreature(0, index);
		cout << "\nWinner: " << army1.getPrintCreature(index) << "\nLoser: " << army2.getPrintCreature(index);

	}

}
void Game::catchFunction(int size) {

	if (cin.fail()) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw GameSizeExeption("INPUT ERROR - INPUT A VALID SIZE");

	}
	if (size < 1) {

		throw GameSizeExeption("INVALID NUMBER - INPUT A VALID SIZE");

	}

}


void defaultSwitch() {

	cout << "Invalid choice, try again\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void gameFunction() {

	int tempsize = 0;
	string nameA = "";
	string nameB = "";

	cout << "Input size of the armies\nInput:";
	cin >> tempsize;
	cout << "Input name of your 1st army\nInput:";
	cin >> nameA;
	cout << "Input name of your 2nd army\nInput:";
	cin >> nameB;

	Game defaultGame(tempsize, nameA, nameB);

}
int quitFunction(int input) {
	enum {

		YES = 1,
		NO

	};

	input = 0;
	
	while (input != YES && input != NO) {
		
		input = 0;

		cout << "Are you sure you want to quit?\n1. Yes\n2. No\nInput: ";
		cin >> input;

		switch (input) {
		case YES:
			cout << "Quitting Program...\n";
			return 2;
		case NO:
			cout << "Returning to menu...\n";
			return 0;
		default:
			defaultSwitch();
			break;
		}
	}
}
/*
TEST RUNS:
NORMAL RUN======================================================================================================

	Welcome to the Battle Game!

Menu:
1. Play
2. Quit
Input: 1
Input size of the armies
Input:23
Input name of your 1st army
Input:c00l
Input name of your 2nd army
Input:bluu
c00l has less than 3 alphabetic characters, setting to defalut...
===================================================================================================
Creature                   Strength    Health     Army      Creature                   Strength    Health     Army
CREATURE_0 the Bahamut          187       120     n/a       CREATURE_0 the Bahamut          125       225     bluu
CREATURE_1 the Bahamut          149       175     n/a       CREATURE_1 the Nuggle           207       240     bluu
CREATURE_2 the Bahamut          196       136     n/a       CREATURE_2 the Nuggle           128       212     bluu
CREATURE_3 the Ceffyl           239       125     n/a       CREATURE_3 the CyberBahamut     224       207     bluu
CREATURE_4 the Ceffyl           169       201     n/a       CREATURE_4 the CyberBahamut     219       196     bluu
CREATURE_5 the Bahamut          185       249     n/a       CREATURE_5 the Ceffyl           228       172     bluu
CREATURE_6 the Nuggle           223       190     n/a       CREATURE_6 the Bahamut          219       159     bluu
CREATURE_7 the CyberBahamut     191       143     n/a       CREATURE_7 the Bahamut          172       124     bluu
CREATURE_8 the CyberBahamut     200       232     n/a       CREATURE_8 the CyberBahamut     246       226     bluu
CREATURE_9 the Nuggle           219       183     n/a       CREATURE_9 the CyberBahamut     179       169     bluu
CREATURE_10 the Ceffyl          187       126     n/a       CREATURE_10 the CyberBahamut    137       184     bluu
CREATURE_11 the CyberBahamut    131       152     n/a       CREATURE_11 the Ceffyl          204       170     bluu
CREATURE_12 the Ceffyl          197       170     n/a       CREATURE_12 the Nuggle          126       246     bluu
CREATURE_13 the Ceffyl          178       210     n/a       CREATURE_13 the Ceffyl          209       171     bluu
CREATURE_14 the Bahamut         166       187     n/a       CREATURE_14 the Nuggle          160       163     bluu
CREATURE_15 the Bahamut         191       141     n/a       CREATURE_15 the CyberBahamut    187       160     bluu
CREATURE_16 the Ceffyl          243       221     n/a       CREATURE_16 the Ceffyl          163       243     bluu
CREATURE_17 the Ceffyl          154       241     n/a       CREATURE_17 the Ceffyl          208       135     bluu
CREATURE_18 the Nuggle          226       155     n/a       CREATURE_18 the Ceffyl          163       151     bluu
CREATURE_19 the Bahamut         211       221     n/a       CREATURE_19 the Bahamut         249       173     bluu
CREATURE_20 the Ceffyl          160       141     n/a       CREATURE_20 the Bahamut         121       223     bluu
CREATURE_21 the Bahamut         233       147     n/a       CREATURE_21 the Bahamut         186       217     bluu
CREATURE_22 the Bahamut         172       191     n/a       CREATURE_22 the Bahamut         130       176     bluu
===================================================================================================
Round 1:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_0 the Bahamut            0     bluu       CREATURE_0 the Bahamut          120     n/a
CREATURE_0 the Bahamut's double attack activated!
CREATURE_0 the Bahamut          248     bluu       CREATURE_0 the Bahamut            0     n/a

Winner: CREATURE_0 the Bahamut
Loser: CREATURE_0 the Bahamut

n/a's total health: 3937
bluu's total health: 4342
===================================================================================================
Round 2:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_1 the Bahamut            0     n/a       CREATURE_1 the Nuggle           240     bluu
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut          230     n/a       CREATURE_1 the Nuggle            10     bluu
CREATURE_1 the Nuggle            99     bluu       CREATURE_1 the Bahamut           76     n/a
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut          104     n/a       CREATURE_1 the Nuggle             0     bluu

Winner: CREATURE_1 the Bahamut
Loser: CREATURE_1 the Nuggle

n/a's total health: 3838
bluu's total health: 4102
===================================================================================================
Round 3:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_2 the Nuggle             0     bluu       CREATURE_2 the Bahamut          136     n/a
CREATURE_2 the Nuggle           108     bluu       CREATURE_2 the Bahamut           28     n/a
CREATURE_2 the Bahamut's double attack activated!
CREATURE_2 the Bahamut          206     n/a       CREATURE_2 the Nuggle             6     bluu
CREATURE_2 the Nuggle            33     bluu       CREATURE_2 the Bahamut            0     n/a

Winner: CREATURE_2 the Nuggle
Loser: CREATURE_2 the Bahamut

n/a's total health: 3702
bluu's total health: 3896
===================================================================================================
Round 4:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_3 the Ceffyl             0     n/a       CREATURE_3 the CyberBahamut     207     bluu
CREATURE_3 the Ceffyl             3     n/a       CREATURE_3 the CyberBahamut     204     bluu
CREATURE_3 the CyberBahamut's double attack activated!
CREATURE_3 the CyberBahamut      46     bluu       CREATURE_3 the Ceffyl            79     n/a
CREATURE_3 the Ceffyl           145     n/a       CREATURE_3 the CyberBahamut      59     bluu
CREATURE_3 the CyberBahamut's double attack activated!
CREATURE_3 the CyberBahamut     242     bluu       CREATURE_3 the Ceffyl             0     n/a

Winner: CREATURE_3 the CyberBahamut
Loser: CREATURE_3 the Ceffyl

n/a's total health: 3577
bluu's total health: 3748
===================================================================================================
Round 5:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_4 the Ceffyl             0     n/a       CREATURE_4 the CyberBahamut     196     bluu
CREATURE_4 the Ceffyl           105     n/a       CREATURE_4 the CyberBahamut      91     bluu
CREATURE_4 the CyberBahamut's double attack activated!
CREATURE_4 the CyberBahamut     428     bluu       CREATURE_4 the Ceffyl             0     n/a

Winner: CREATURE_4 the CyberBahamut
Loser: CREATURE_4 the Ceffyl

n/a's total health: 3376
bluu's total health: 3643
===================================================================================================
Round 6:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_5 the Bahamut            0     n/a       CREATURE_5 the Ceffyl           172     bluu
CREATURE_5 the Bahamut's double attack activated!
CREATURE_5 the Bahamut          310     n/a       CREATURE_5 the Ceffyl             0     bluu

Winner: CREATURE_5 the Bahamut
Loser: CREATURE_5 the Ceffyl

n/a's total health: 3376
bluu's total health: 3471
===================================================================================================
Round 7:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_6 the Bahamut            0     bluu       CREATURE_6 the Nuggle           190     n/a
CREATURE_6 the Bahamut's double attack activated!
CREATURE_6 the Bahamut          248     bluu       CREATURE_6 the Nuggle             0     n/a

Winner: CREATURE_6 the Bahamut
Loser: CREATURE_6 the Nuggle

n/a's total health: 3186
bluu's total health: 3471
===================================================================================================
Round 8:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_7 the CyberBahamut       0     n/a       CREATURE_7 the Bahamut          124     bluu
CREATURE_7 the CyberBahamut's double attack activated!
CREATURE_7 the CyberBahamut     138     n/a       CREATURE_7 the Bahamut            0     bluu

Winner: CREATURE_7 the CyberBahamut
Loser: CREATURE_7 the Bahamut

n/a's total health: 3186
bluu's total health: 3347
===================================================================================================
Round 9:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_8 the CyberBahamut       0     bluu       CREATURE_8 the CyberBahamut     232     n/a
CREATURE_8 the CyberBahamut's double attack activated!
CREATURE_8 the CyberBahamut     146     bluu       CREATURE_8 the CyberBahamut      86     n/a
CREATURE_8 the CyberBahamut's double attack activated!
CREATURE_8 the CyberBahamut     368     n/a       CREATURE_8 the CyberBahamut       0     bluu

Winner: CREATURE_8 the CyberBahamut
Loser: CREATURE_8 the CyberBahamut

n/a's total health: 3040
bluu's total health: 3121
===================================================================================================
Round 10:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_9 the CyberBahamut       0     bluu       CREATURE_9 the Nuggle           183     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut     102     bluu       CREATURE_9 the Nuggle            81     n/a
CREATURE_9 the Nuggle            16     n/a       CREATURE_9 the CyberBahamut     153     bluu
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut     358     bluu       CREATURE_9 the Nuggle             0     n/a

Winner: CREATURE_9 the CyberBahamut
Loser: CREATURE_9 the Nuggle

n/a's total health: 2857
bluu's total health: 3105
===================================================================================================
Round 11:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_10 the Ceffyl            0     n/a       CREATURE_10 the CyberBahamut    184     bluu
CREATURE_10 the Ceffyl           82     n/a       CREATURE_10 the CyberBahamut    102     bluu
CREATURE_10 the CyberBahamut's double attack activated!
CREATURE_10 the CyberBahamut's bahamut attack activated!
CREATURE_10 the CyberBahamut    186     bluu       CREATURE_10 the Ceffyl            0     n/a

Winner: CREATURE_10 the CyberBahamut
Loser: CREATURE_10 the Ceffyl

n/a's total health: 2731
bluu's total health: 3023
===================================================================================================
Round 12:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_11 the CyberBahamut      0     n/a       CREATURE_11 the Ceffyl          170     bluu
CREATURE_11 the CyberBahamut's double attack activated!
CREATURE_11 the CyberBahamut    188     n/a       CREATURE_11 the Ceffyl            0     bluu

Winner: CREATURE_11 the CyberBahamut
Loser: CREATURE_11 the Ceffyl

n/a's total health: 2731
bluu's total health: 2853
===================================================================================================
Round 13:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_12 the Nuggle            0     bluu       CREATURE_12 the Ceffyl          170     n/a
CREATURE_12 the Nuggle          115     bluu       CREATURE_12 the Ceffyl           55     n/a
CREATURE_12 the Ceffyl          156     n/a       CREATURE_12 the Nuggle           90     bluu
CREATURE_12 the Nuggle           84     bluu       CREATURE_12 the Ceffyl            0     n/a

Winner: CREATURE_12 the Nuggle
Loser: CREATURE_12 the Ceffyl

n/a's total health: 2561
bluu's total health: 2697
===================================================================================================
Round 14:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_13 the Ceffyl            0     n/a       CREATURE_13 the Ceffyl          171     bluu
CREATURE_13 the Ceffyl          125     n/a       CREATURE_13 the Ceffyl           46     bluu
CREATURE_13 the Ceffyl          165     bluu       CREATURE_13 the Ceffyl           45     n/a
CREATURE_13 the Ceffyl           42     n/a       CREATURE_13 the Ceffyl            4     bluu
CREATURE_13 the Ceffyl           54     bluu       CREATURE_13 the Ceffyl            0     n/a

Winner: CREATURE_13 the Ceffyl
Loser: CREATURE_13 the Ceffyl

n/a's total health: 2351
bluu's total health: 2530
===================================================================================================
Round 15:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_14 the Bahamut           0     n/a       CREATURE_14 the Nuggle          163     bluu
CREATURE_14 the Bahamut's double attack activated!
CREATURE_14 the Bahamut         294     n/a       CREATURE_14 the Nuggle            0     bluu

Winner: CREATURE_14 the Bahamut
Loser: CREATURE_14 the Nuggle

n/a's total health: 2351
bluu's total health: 2367
===================================================================================================
Round 16:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_15 the CyberBahamut      0     bluu       CREATURE_15 the Bahamut         141     n/a
CREATURE_15 the CyberBahamut's double attack activated!
CREATURE_15 the CyberBahamut's bahamut attack activated!
CREATURE_15 the CyberBahamut    294     bluu       CREATURE_15 the Bahamut           0     n/a

Winner: CREATURE_15 the CyberBahamut
Loser: CREATURE_15 the Bahamut

n/a's total health: 2210
bluu's total health: 2367
===================================================================================================
Round 17:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_16 the Ceffyl            0     n/a       CREATURE_16 the Ceffyl          243     bluu
CREATURE_16 the Ceffyl          152     n/a       CREATURE_16 the Ceffyl           91     bluu
CREATURE_16 the Ceffyl          119     bluu       CREATURE_16 the Ceffyl          102     n/a
CREATURE_16 the Ceffyl           72     n/a       CREATURE_16 the Ceffyl           19     bluu
CREATURE_16 the Ceffyl           81     bluu       CREATURE_16 the Ceffyl           21     n/a
CREATURE_16 the Ceffyl           58     n/a       CREATURE_16 the Ceffyl            0     bluu

Winner: CREATURE_16 the Ceffyl
Loser: CREATURE_16 the Ceffyl

n/a's total health: 2010
bluu's total health: 2124
===================================================================================================
Round 18:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_17 the Ceffyl            0     bluu       CREATURE_17 the Ceffyl          241     n/a
CREATURE_17 the Ceffyl          202     bluu       CREATURE_17 the Ceffyl           39     n/a
CREATURE_17 the Ceffyl           84     n/a       CREATURE_17 the Ceffyl           51     bluu
CREATURE_17 the Ceffyl          144     bluu       CREATURE_17 the Ceffyl            0     n/a

Winner: CREATURE_17 the Ceffyl
Loser: CREATURE_17 the Ceffyl

n/a's total health: 1769
bluu's total health: 2040
===================================================================================================
Round 19:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_18 the Nuggle            0     n/a       CREATURE_18 the Ceffyl          151     bluu
CREATURE_18 the Nuggle          128     n/a       CREATURE_18 the Ceffyl           23     bluu
CREATURE_18 the Ceffyl           37     bluu       CREATURE_18 the Nuggle          118     n/a
CREATURE_18 the Nuggle          137     n/a       CREATURE_18 the Ceffyl            0     bluu

Winner: CREATURE_18 the Nuggle
Loser: CREATURE_18 the Ceffyl

n/a's total health: 1732
bluu's total health: 1889
===================================================================================================
Round 20:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_19 the Bahamut           0     bluu       CREATURE_19 the Bahamut         221     n/a
CREATURE_19 the Bahamut's double attack activated!
CREATURE_19 the Bahamut         212     bluu       CREATURE_19 the Bahamut           9     n/a
CREATURE_19 the Bahamut's double attack activated!
CREATURE_19 the Bahamut         412     n/a       CREATURE_19 the Bahamut           0     bluu

Winner: CREATURE_19 the Bahamut
Loser: CREATURE_19 the Bahamut

n/a's total health: 1520
bluu's total health: 1716
===================================================================================================
Round 21:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_20 the Bahamut           0     bluu       CREATURE_20 the Ceffyl          141     n/a
CREATURE_20 the Bahamut's double attack activated!
CREATURE_20 the Bahamut         216     bluu       CREATURE_20 the Ceffyl            0     n/a

Winner: CREATURE_20 the Bahamut
Loser: CREATURE_20 the Ceffyl

n/a's total health: 1379
bluu's total health: 1716
===================================================================================================
Round 22:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_21 the Bahamut           0     n/a       CREATURE_21 the Bahamut         217     bluu
CREATURE_21 the Bahamut's double attack activated!
CREATURE_21 the Bahamut         326     n/a       CREATURE_21 the Bahamut           0     bluu

Winner: CREATURE_21 the Bahamut
Loser: CREATURE_21 the Bahamut

n/a's total health: 1379
bluu's total health: 1499
===================================================================================================
Round 23:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_22 the Bahamut           0     bluu       CREATURE_22 the Bahamut         191     n/a
CREATURE_22 the Bahamut's double attack activated!
CREATURE_22 the Bahamut         136     bluu       CREATURE_22 the Bahamut          55     n/a
CREATURE_22 the Bahamut's double attack activated!
CREATURE_22 the Bahamut         238     n/a       CREATURE_22 the Bahamut           0     bluu

Winner: CREATURE_22 the Bahamut
Loser: CREATURE_22 the Bahamut

n/a's total health: 1243
bluu's total health: 1323
===================================================================================================
bluu has won with 1323 health!
end game


Menu:
1. Play
2. Quit
Input: 3
Invalid choice, try again

Menu:
1. Play
2. Quit
Input: 2
Are you sure you want to quit?
1. Yes
2. No
Input: 1
Quitting Program...

C:\Users\Matteo\source\repos\Lab 9 Inheritance\x64\Debug\Lab 9 Inheritance.exe (process 24388) exited with code 0.
Press any key to close this window . . .

WRONG ANSWERS TO EVERY OPTION===================================================================================
Welcome to the Battle Game!

Menu:
1. Play
2. Quit
Input: 3
Invalid choice, try again

Menu:
1. Play
2. Quit
Input: a
Invalid choice, try again

Menu:
1. Play
2. Quit
Input: 2
Are you sure you want to quit?
1. Yes
2. No
Input: 3
Invalid choice, try again
Are you sure you want to quit?
1. Yes
2. No
Input: a
Invalid choice, try again
Are you sure you want to quit?
1. Yes
2. No
Input: 2
Returning to menu...

Menu:
1. Play
2. Quit
Input: 1
Input size of the armies
Input:a
Input name of your 1st army
Input:Input name of your 2nd army
Input:INPUT ERROR - INPUT A VALID SIZE; SETTING TO DEFAULT
 has less than 3 alphabetic characters, setting to defalut...
 has less than 3 alphabetic characters, setting to defalut...
===================================================================================================
Creature                   Strength    Health     Army      Creature                   Strength    Health     Army
CREATURE_0 the Ceffyl           202       246     n/a       CREATURE_0 the CyberBahamut     141       129     n/a
CREATURE_1 the Ceffyl           197       228     n/a       CREATURE_1 the Bahamut          194       134     n/a
CREATURE_2 the Ceffyl           232       134     n/a       CREATURE_2 the Bahamut          231       193     n/a
CREATURE_3 the Nuggle           148       204     n/a       CREATURE_3 the CyberBahamut     131       137     n/a
CREATURE_4 the Nuggle           130       233     n/a       CREATURE_4 the CyberBahamut     228       219     n/a
CREATURE_5 the Bahamut          125       199     n/a       CREATURE_5 the Nuggle           222       224     n/a
CREATURE_6 the CyberBahamut     153       137     n/a       CREATURE_6 the CyberBahamut     210       233     n/a
CREATURE_7 the CyberBahamut     156       237     n/a       CREATURE_7 the Bahamut          121       168     n/a
CREATURE_8 the CyberBahamut     215       142     n/a       CREATURE_8 the CyberBahamut     135       225     n/a
CREATURE_9 the Bahamut          152       155     n/a       CREATURE_9 the Ceffyl           173       168     n/a
===================================================================================================
Round 1:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_0 the CyberBahamut       0     n/a       CREATURE_0 the Ceffyl           246     n/a
CREATURE_0 the CyberBahamut's double attack activated!
CREATURE_0 the CyberBahamut's bahamut attack activated!
CREATURE_0 the CyberBahamut     172     n/a       CREATURE_0 the Ceffyl            74     n/a
CREATURE_0 the Ceffyl           155     n/a       CREATURE_0 the CyberBahamut       0     n/a

Winner: CREATURE_0 the Ceffyl
Loser: CREATURE_0 the CyberBahamut

n/a's total health: 1743
n/a's total health: 1701
===================================================================================================
Round 2:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_1 the Bahamut            0     n/a       CREATURE_1 the Ceffyl           228     n/a
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut          340     n/a       CREATURE_1 the Ceffyl             0     n/a

Winner: CREATURE_1 the Bahamut
Loser: CREATURE_1 the Ceffyl

n/a's total health: 1515
n/a's total health: 1701
===================================================================================================
Round 3:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_2 the Ceffyl             0     n/a       CREATURE_2 the Bahamut          193     n/a
CREATURE_2 the Ceffyl           163     n/a       CREATURE_2 the Bahamut           30     n/a
CREATURE_2 the Bahamut's double attack activated!
CREATURE_2 the Bahamut           34     n/a       CREATURE_2 the Ceffyl           100     n/a
CREATURE_2 the Ceffyl            46     n/a       CREATURE_2 the Bahamut            0     n/a

Winner: CREATURE_2 the Ceffyl
Loser: CREATURE_2 the Bahamut

n/a's total health: 1481
n/a's total health: 1508
===================================================================================================
Round 4:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_3 the CyberBahamut       0     n/a       CREATURE_3 the Nuggle           204     n/a
CREATURE_3 the CyberBahamut's double attack activated!
CREATURE_3 the CyberBahamut     244     n/a       CREATURE_3 the Nuggle             0     n/a

Winner: CREATURE_3 the CyberBahamut
Loser: CREATURE_3 the Nuggle

n/a's total health: 1277
n/a's total health: 1508
===================================================================================================
Round 5:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_4 the Nuggle             0     n/a       CREATURE_4 the CyberBahamut     219     n/a
CREATURE_4 the Nuggle           115     n/a       CREATURE_4 the CyberBahamut     104     n/a
CREATURE_4 the CyberBahamut's double attack activated!
CREATURE_4 the CyberBahamut's bahamut attack activated!
CREATURE_4 the CyberBahamut     290     n/a       CREATURE_4 the Nuggle             0     n/a

Winner: CREATURE_4 the CyberBahamut
Loser: CREATURE_4 the Nuggle

n/a's total health: 1044
n/a's total health: 1393
===================================================================================================
Round 6:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_5 the Bahamut            0     n/a       CREATURE_5 the Nuggle           224     n/a
CREATURE_5 the Bahamut's double attack activated!
CREATURE_5 the Bahamut           54     n/a       CREATURE_5 the Nuggle           170     n/a
CREATURE_5 the Nuggle           157     n/a       CREATURE_5 the Bahamut           42     n/a
CREATURE_5 the Bahamut's double attack activated!
CREATURE_5 the Bahamut           78     n/a       CREATURE_5 the Nuggle            92     n/a
CREATURE_5 the Nuggle           153     n/a       CREATURE_5 the Bahamut            0     n/a

Winner: CREATURE_5 the Nuggle
Loser: CREATURE_5 the Bahamut

n/a's total health: 845
n/a's total health: 1261
===================================================================================================
Round 7:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_6 the CyberBahamut       0     n/a       CREATURE_6 the CyberBahamut     233     n/a
CREATURE_6 the CyberBahamut's double attack activated!
CREATURE_6 the CyberBahamut     270     n/a       CREATURE_6 the CyberBahamut       0     n/a

Winner: CREATURE_6 the CyberBahamut
Loser: CREATURE_6 the CyberBahamut

n/a's total health: 845
n/a's total health: 1028
===================================================================================================
Round 8:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_7 the Bahamut            0     n/a       CREATURE_7 the CyberBahamut     237     n/a
CREATURE_7 the Bahamut's double attack activated!
CREATURE_7 the Bahamut          182     n/a       CREATURE_7 the CyberBahamut      55     n/a
CREATURE_7 the CyberBahamut's double attack activated!
CREATURE_7 the CyberBahamut      96     n/a       CREATURE_7 the Bahamut           72     n/a
CREATURE_7 the Bahamut's double attack activated!
CREATURE_7 the Bahamut           20     n/a       CREATURE_7 the CyberBahamut      35     n/a
CREATURE_7 the CyberBahamut's double attack activated!
CREATURE_7 the CyberBahamut      44     n/a       CREATURE_7 the Bahamut           28     n/a
CREATURE_7 the Bahamut's double attack activated!
CREATURE_7 the Bahamut            6     n/a       CREATURE_7 the CyberBahamut      29     n/a
CREATURE_7 the CyberBahamut's double attack activated!
CREATURE_7 the CyberBahamut     290     n/a       CREATURE_7 the Bahamut            0     n/a

Winner: CREATURE_7 the CyberBahamut
Loser: CREATURE_7 the Bahamut

n/a's total health: 637
n/a's total health: 860
===================================================================================================
Round 9:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_8 the CyberBahamut       0     n/a       CREATURE_8 the CyberBahamut     142     n/a
CREATURE_8 the CyberBahamut's double attack activated!
CREATURE_8 the CyberBahamut     124     n/a       CREATURE_8 the CyberBahamut      18     n/a
CREATURE_8 the CyberBahamut's double attack activated!
CREATURE_8 the CyberBahamut     388     n/a       CREATURE_8 the CyberBahamut       0     n/a

Winner: CREATURE_8 the CyberBahamut
Loser: CREATURE_8 the CyberBahamut

n/a's total health: 513
n/a's total health: 635
===================================================================================================
Round 10:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_9 the Ceffyl             0     n/a       CREATURE_9 the Bahamut          155     n/a
CREATURE_9 the Ceffyl           118     n/a       CREATURE_9 the Bahamut           37     n/a
CREATURE_9 the Bahamut's double attack activated!
CREATURE_9 the Bahamut          142     n/a       CREATURE_9 the Ceffyl            26     n/a
CREATURE_9 the Ceffyl            46     n/a       CREATURE_9 the Bahamut            0     n/a

Winner: CREATURE_9 the Ceffyl
Loser: CREATURE_9 the Bahamut

n/a's total health: 358
n/a's total health: 493
===================================================================================================
n/a has won with 493 health!
end game


Menu:
1. Play
2. Quit
Input: 1
Input size of the armies
Input:10
Input name of your 1st army
Input:10
Input name of your 2nd army
Input:a
10 has less than 3 alphabetic characters, setting to defalut...
a has less than 3 alphabetic characters, setting to defalut...
===================================================================================================
Creature                   Strength    Health     Army      Creature                   Strength    Health     Army
CREATURE_0 the Bahamut          133       230     n/a       CREATURE_0 the Ceffyl           144       152     n/a
CREATURE_1 the Ceffyl           162       146     n/a       CREATURE_1 the CyberBahamut     169       222     n/a
CREATURE_2 the Nuggle           238       148     n/a       CREATURE_2 the Bahamut          219       168     n/a
CREATURE_3 the Ceffyl           169       141     n/a       CREATURE_3 the Bahamut          197       157     n/a
CREATURE_4 the Bahamut          200       247     n/a       CREATURE_4 the CyberBahamut     136       145     n/a
CREATURE_5 the Nuggle           249       213     n/a       CREATURE_5 the Nuggle           217       248     n/a
CREATURE_6 the Bahamut          163       164     n/a       CREATURE_6 the Ceffyl           157       161     n/a
CREATURE_7 the Ceffyl           226       147     n/a       CREATURE_7 the Bahamut          143       121     n/a
CREATURE_8 the Bahamut          125       193     n/a       CREATURE_8 the Ceffyl           177       212     n/a
CREATURE_9 the CyberBahamut     194       222     n/a       CREATURE_9 the CyberBahamut     218       206     n/a
===================================================================================================
Round 1:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_0 the Ceffyl             0     n/a       CREATURE_0 the Bahamut          230     n/a
CREATURE_0 the Ceffyl           103     n/a       CREATURE_0 the Bahamut          127     n/a
CREATURE_0 the Bahamut's double attack activated!
CREATURE_0 the Bahamut          246     n/a       CREATURE_0 the Ceffyl             0     n/a

Winner: CREATURE_0 the Bahamut
Loser: CREATURE_0 the Ceffyl

n/a's total health: 1748
n/a's total health: 1640
===================================================================================================
Round 2:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_1 the CyberBahamut       0     n/a       CREATURE_1 the Ceffyl           146     n/a
CREATURE_1 the CyberBahamut's double attack activated!
CREATURE_1 the CyberBahamut      52     n/a       CREATURE_1 the Ceffyl            94     n/a
CREATURE_1 the Ceffyl's bonus damage activated!
CREATURE_1 the Ceffyl           114     n/a       CREATURE_1 the CyberBahamut     108     n/a
CREATURE_1 the CyberBahamut's double attack activated!
CREATURE_1 the CyberBahamut     320     n/a       CREATURE_1 the Ceffyl             0     n/a

Winner: CREATURE_1 the CyberBahamut
Loser: CREATURE_1 the Ceffyl

n/a's total health: 1602
n/a's total health: 1526
===================================================================================================
Round 3:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_2 the Nuggle             0     n/a       CREATURE_2 the Bahamut          168     n/a
CREATURE_2 the Nuggle            42     n/a       CREATURE_2 the Bahamut          126     n/a
CREATURE_2 the Bahamut's double attack activated!
CREATURE_2 the Bahamut          246     n/a       CREATURE_2 the Nuggle             0     n/a

Winner: CREATURE_2 the Bahamut
Loser: CREATURE_2 the Nuggle

n/a's total health: 1454
n/a's total health: 1484
===================================================================================================
Round 4:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_3 the Ceffyl             0     n/a       CREATURE_3 the Bahamut          157     n/a
CREATURE_3 the Ceffyl            80     n/a       CREATURE_3 the Bahamut           77     n/a
CREATURE_3 the Bahamut's double attack activated!
CREATURE_3 the Bahamut          306     n/a       CREATURE_3 the Ceffyl             0     n/a

Winner: CREATURE_3 the Bahamut
Loser: CREATURE_3 the Ceffyl

n/a's total health: 1313
n/a's total health: 1404
===================================================================================================
Round 5:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_4 the Bahamut            0     n/a       CREATURE_4 the CyberBahamut     145     n/a
CREATURE_4 the Bahamut's double attack activated!
CREATURE_4 the Bahamut           40     n/a       CREATURE_4 the CyberBahamut     105     n/a
CREATURE_4 the CyberBahamut's double attack activated!
CREATURE_4 the CyberBahamut     222     n/a       CREATURE_4 the Bahamut           25     n/a
CREATURE_4 the Bahamut's double attack activated!
CREATURE_4 the Bahamut          354     n/a       CREATURE_4 the CyberBahamut       0     n/a

Winner: CREATURE_4 the Bahamut
Loser: CREATURE_4 the CyberBahamut

n/a's total health: 1091
n/a's total health: 1259
===================================================================================================
Round 6:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_5 the Nuggle             0     n/a       CREATURE_5 the Nuggle           213     n/a
CREATURE_5 the Nuggle's magical attack multiplier activated!
CREATURE_5 the Nuggle            74     n/a       CREATURE_5 the Nuggle           139     n/a
CREATURE_5 the Nuggle            89     n/a       CREATURE_5 the Nuggle           159     n/a
CREATURE_5 the Nuggle            42     n/a       CREATURE_5 the Nuggle            97     n/a
CREATURE_5 the Nuggle            68     n/a       CREATURE_5 the Nuggle            91     n/a
CREATURE_5 the Nuggle           173     n/a       CREATURE_5 the Nuggle             0     n/a

Winner: CREATURE_5 the Nuggle
Loser: CREATURE_5 the Nuggle

n/a's total health: 878
n/a's total health: 1102
===================================================================================================
Round 7:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_6 the Bahamut            0     n/a       CREATURE_6 the Ceffyl           161     n/a
CREATURE_6 the Bahamut's double attack activated!
CREATURE_6 the Bahamut          252     n/a       CREATURE_6 the Ceffyl             0     n/a

Winner: CREATURE_6 the Bahamut
Loser: CREATURE_6 the Ceffyl

n/a's total health: 878
n/a's total health: 941
===================================================================================================
Round 8:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_7 the Bahamut            0     n/a       CREATURE_7 the Ceffyl           147     n/a
CREATURE_7 the Bahamut's double attack activated!
CREATURE_7 the Bahamut           78     n/a       CREATURE_7 the Ceffyl            69     n/a
CREATURE_7 the Ceffyl's bonus damage activated!
CREATURE_7 the Ceffyl           231     n/a       CREATURE_7 the Bahamut            0     n/a

Winner: CREATURE_7 the Ceffyl
Loser: CREATURE_7 the Bahamut

n/a's total health: 800
n/a's total health: 820
===================================================================================================
Round 9:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_8 the Ceffyl             0     n/a       CREATURE_8 the Bahamut          193     n/a
CREATURE_8 the Ceffyl            77     n/a       CREATURE_8 the Bahamut          116     n/a
CREATURE_8 the Bahamut's double attack activated!
CREATURE_8 the Bahamut          102     n/a       CREATURE_8 the Ceffyl           110     n/a
CREATURE_8 the Ceffyl           171     n/a       CREATURE_8 the Bahamut            0     n/a

Winner: CREATURE_8 the Ceffyl
Loser: CREATURE_8 the Bahamut

n/a's total health: 607
n/a's total health: 718
===================================================================================================
Round 10:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_9 the CyberBahamut       0     n/a       CREATURE_9 the CyberBahamut     206     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut     102     n/a       CREATURE_9 the CyberBahamut     104     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut     144     n/a       CREATURE_9 the CyberBahamut      78     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut      24     n/a       CREATURE_9 the CyberBahamut      80     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut     104     n/a       CREATURE_9 the CyberBahamut       0     n/a

Winner: CREATURE_9 the CyberBahamut
Loser: CREATURE_9 the CyberBahamut

n/a's total health: 385
n/a's total health: 592
===================================================================================================
n/a has won with 592 health!
end game


Menu:
1. Play
2. Quit
Input: 1
Input size of the armies
Input:-1
Input name of your 1st army
Input:a
Input name of your 2nd army
Input:a
INVALID NUMBER - INPUT A VALID SIZE; SETTING TO DEFAULT
a has less than 3 alphabetic characters, setting to defalut...
a has less than 3 alphabetic characters, setting to defalut...
===================================================================================================
Creature                   Strength    Health     Army      Creature                   Strength    Health     Army
CREATURE_0 the Nuggle           138       231     n/a       CREATURE_0 the Bahamut          143       199     n/a
CREATURE_1 the Bahamut          162       195     n/a       CREATURE_1 the Bahamut          199       121     n/a
CREATURE_2 the Nuggle           247       198     n/a       CREATURE_2 the Ceffyl           142       179     n/a
CREATURE_3 the Nuggle           157       236     n/a       CREATURE_3 the Bahamut          215       209     n/a
CREATURE_4 the Bahamut          212       134     n/a       CREATURE_4 the Bahamut          230       141     n/a
CREATURE_5 the Nuggle           249       145     n/a       CREATURE_5 the Bahamut          207       218     n/a
CREATURE_6 the CyberBahamut     159       143     n/a       CREATURE_6 the Nuggle           206       231     n/a
CREATURE_7 the Bahamut          218       121     n/a       CREATURE_7 the Bahamut          241       176     n/a
CREATURE_8 the CyberBahamut     240       242     n/a       CREATURE_8 the Bahamut          211       166     n/a
CREATURE_9 the CyberBahamut     198       237     n/a       CREATURE_9 the CyberBahamut     143       123     n/a
===================================================================================================
Round 1:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_0 the Bahamut            0     n/a       CREATURE_0 the Nuggle           231     n/a
CREATURE_0 the Bahamut's double attack activated!
CREATURE_0 the Bahamut           38     n/a       CREATURE_0 the Nuggle           193     n/a
CREATURE_0 the Nuggle            98     n/a       CREATURE_0 the Bahamut          101     n/a
CREATURE_0 the Bahamut's double attack activated!
CREATURE_0 the Bahamut           74     n/a       CREATURE_0 the Nuggle           119     n/a
CREATURE_0 the Nuggle's magical attack multiplier activated!
CREATURE_0 the Nuggle           204     n/a       CREATURE_0 the Bahamut            0     n/a

Winner: CREATURE_0 the Nuggle
Loser: CREATURE_0 the Bahamut

n/a's total health: 1770
n/a's total health: 1564
===================================================================================================
Round 2:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_1 the Bahamut            0     n/a       CREATURE_1 the Bahamut          195     n/a
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut          114     n/a       CREATURE_1 the Bahamut           81     n/a
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut           56     n/a       CREATURE_1 the Bahamut           65     n/a
CREATURE_1 the Bahamut's double attack activated!
CREATURE_1 the Bahamut          338     n/a       CREATURE_1 the Bahamut            0     n/a

Winner: CREATURE_1 the Bahamut
Loser: CREATURE_1 the Bahamut

n/a's total health: 1575
n/a's total health: 1508
===================================================================================================
Round 3:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_2 the Nuggle             0     n/a       CREATURE_2 the Ceffyl           179     n/a
CREATURE_2 the Nuggle           195     n/a       CREATURE_2 the Ceffyl             0     n/a

Winner: CREATURE_2 the Nuggle
Loser: CREATURE_2 the Ceffyl

n/a's total health: 1575
n/a's total health: 1329
===================================================================================================
Round 4:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_3 the Bahamut            0     n/a       CREATURE_3 the Nuggle           236     n/a
CREATURE_3 the Bahamut's double attack activated!
CREATURE_3 the Bahamut          224     n/a       CREATURE_3 the Nuggle            12     n/a
CREATURE_3 the Nuggle            61     n/a       CREATURE_3 the Bahamut          148     n/a
CREATURE_3 the Bahamut's double attack activated!
CREATURE_3 the Bahamut          394     n/a       CREATURE_3 the Nuggle             0     n/a

Winner: CREATURE_3 the Bahamut
Loser: CREATURE_3 the Nuggle

n/a's total health: 1339
n/a's total health: 1268
===================================================================================================
Round 5:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_4 the Bahamut            0     n/a       CREATURE_4 the Bahamut          141     n/a
CREATURE_4 the Bahamut's double attack activated!
CREATURE_4 the Bahamut          406     n/a       CREATURE_4 the Bahamut            0     n/a

Winner: CREATURE_4 the Bahamut
Loser: CREATURE_4 the Bahamut

n/a's total health: 1339
n/a's total health: 1127
===================================================================================================
Round 6:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_5 the Bahamut            0     n/a       CREATURE_5 the Nuggle           145     n/a
CREATURE_5 the Bahamut's double attack activated!
CREATURE_5 the Bahamut          106     n/a       CREATURE_5 the Nuggle            39     n/a
CREATURE_5 the Nuggle           228     n/a       CREATURE_5 the Bahamut            0     n/a

Winner: CREATURE_5 the Nuggle
Loser: CREATURE_5 the Bahamut

n/a's total health: 1233
n/a's total health: 909
===================================================================================================
Round 7:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_6 the Nuggle             0     n/a       CREATURE_6 the CyberBahamut     143     n/a
CREATURE_6 the Nuggle           171     n/a       CREATURE_6 the CyberBahamut       0     n/a

Winner: CREATURE_6 the Nuggle
Loser: CREATURE_6 the CyberBahamut

n/a's total health: 1090
n/a's total health: 909
===================================================================================================
Round 8:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_7 the Bahamut            0     n/a       CREATURE_7 the Bahamut          176     n/a
CREATURE_7 the Bahamut's double attack activated!
CREATURE_7 the Bahamut          384     n/a       CREATURE_7 the Bahamut            0     n/a

Winner: CREATURE_7 the Bahamut
Loser: CREATURE_7 the Bahamut

n/a's total health: 1090
n/a's total health: 733
===================================================================================================
Round 9:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_8 the Bahamut            0     n/a       CREATURE_8 the CyberBahamut     242     n/a
CREATURE_8 the Bahamut's double attack activated!
CREATURE_8 the Bahamut          200     n/a       CREATURE_8 the CyberBahamut      42     n/a
CREATURE_8 the CyberBahamut's double attack activated!
CREATURE_8 the CyberBahamut     206     n/a       CREATURE_8 the Bahamut            0     n/a

Winner: CREATURE_8 the CyberBahamut
Loser: CREATURE_8 the Bahamut

n/a's total health: 890
n/a's total health: 567
===================================================================================================
Round 10:

Attacker                     Damage     Army      Defender                     Health     Army
CREATURE_9 the CyberBahamut       0     n/a       CREATURE_9 the CyberBahamut     237     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut      42     n/a       CREATURE_9 the CyberBahamut     195     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut      96     n/a       CREATURE_9 the CyberBahamut      27     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut's bahamut attack activated!
CREATURE_9 the CyberBahamut      98     n/a       CREATURE_9 the CyberBahamut      97     n/a
CREATURE_9 the CyberBahamut's double attack activated!
CREATURE_9 the CyberBahamut      34     n/a       CREATURE_9 the CyberBahamut       0     n/a

Winner: CREATURE_9 the CyberBahamut
Loser: CREATURE_9 the CyberBahamut

n/a's total health: 750
n/a's total health: 444
===================================================================================================
n/a has won with 750 health!
end game


Menu:
1. Play
2. Quit
Input: 2
Are you sure you want to quit?
1. Yes
2. No
Input: 1
Quitting Program...

C:\Users\Matteo\source\repos\Lab 9 Inheritance\x64\Debug\Lab 9 Inheritance.exe (process 4424) exited with code 0.
Press any key to close this window . . .
*/