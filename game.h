#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h" //"player.h", <string> , <vector>

class Game{

	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[30];
		std::string welcome;
		bool isFirstInnings;
		Team teamA,teamB;
		Team *battingTeam,*bowlingTeam;
		Player *batsman,*bowler;

		void getWelcome();
		void getInstructions();
		void showAllPlayers();
		void chooseFormat();
		int takeIntegerInput();
		void selectPlayers();
		bool checkSelectedPlayer(int);
		void displayTeams();
		void coinToss();
		void batOrBowl(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void createGameScorecard();
		void startSecondInnings();
		void swap(Team *a, Team*b);
		void displaySummary(Team *a, Team*b);
		bool spellOver(int a);
		void chooseBowler();
		void chooseBatsman();
		void firstBowler();
};
