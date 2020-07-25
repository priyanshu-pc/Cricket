#include "game.h"
using namespace std;

int main() {
	Game game1;
	game1.getWelcome();
	game1.getInstructions();

	cout << "Press ENTER to continue..."<< endl;
	getchar();

	game1.chooseFormat();


	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Press ENTER to continue..."<< endl;
	getchar();
	game1.showAllPlayers();


	cout << "Press ENTER to continue..."<< endl;
	getchar();

	game1.selectPlayers();

	cout << endl << endl;

	game1.displayTeams();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Press ENTER to have the coin Toss..."<< endl;
	getchar();

	game1.coinToss();

	game1.startFirstInnings();
	game1.playInnings();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Press ENTER to start the Second Innings."<< endl;
	getchar();
	game1.startSecondInnings();
	game1.playInnings();

	return 0;
}
