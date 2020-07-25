#include "game.h"

Game::Game(){


	playersPerTeam = 11;
	totalPlayers = 45;
	welcome = "------------------------------------------\n|===============CRIC-IN==================|\n|                                        |\n|     Welcome to Virtual Cricket Game    |\n------------------------------------------\n";

		players[0] = "Virat";
		players[1] = "Rohit";
		players[2] = "Babar";
		players[3] = "Ross";
		players[4] = "Faff";
		players[5] = "Warner";
		players[6] = "Williamson";
		players[7] = "Root";
		players[8] = "Finch";
		players[9] = "Kock";
		players[10] = "Roy";
		players[11] = "Imam";
		players[12] = "Hope";
		players[13] = "Bairstow";
		players[14] = "Guptill";
		players[15] = "Boult";
		players[16] = "Rahman";
		players[17] = "Cummins";
		players[18] = "Rabada";
		players[19] = "Woakes";
		players[20] = "Amir";
		players[21] = "Henry";
		players[22] = "Ferguson";
		players[23] = "Starc";
		players[24] = "Rashid";
		players[25] = "Mehedi";
		players[26] = "Chahal";
		players[27] = "Ngidi";
		players[28] = "Akila";
		players[29] = "Butler";


	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

void Game :: getWelcome() {
	std::cout << welcome << std::endl;
}

void Game :: getInstructions(){
	 std::cout <<"-------------------------------------------------------------------\n"
			 	 "|==========================Instructions===========================|\n"
			 	 "-------------------------------------------------------------------\n"
			 	 "|                                                                 |\n"
			 	 "| 1. Create 2 teams (Team A and Team B with 4 players each)      |\n"
			 	 "|	 from a given pool of 11 players.                              |\n"
			 	 "| 2. Win the toss and decide the choice of play.                  |\n"
			 	 "| 3. Each innings will be of 6 balls.                             |\n"
			 	 "------------------------------------------------------------------- " << std::endl;
}

void Game :: showAllPlayers(){
	std::cout << std::endl;
	std::cout << "------------------------------------------\n"
				 "|=============Pool of Players============|\n"
				 "------------------------------------------\n" << std::endl;
	for (int i = 0; i < 30; i++){
		std::cout << "[" << i << "] " << players[i] << std::endl;
	}
	std::cout << std::endl;
}

int Game :: takeIntegerInput(){
	int n;

	while(!(std::cin >> n)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Please try again with valid input.";
	}

	return n;
}

void Game :: chooseFormat(){
	std::cout << "Choose the Format which you want to play. You can choose 5, 10, 20 and 50.\n" << std::endl;
	formatChoice:
		int totalOvers = takeIntegerInput();
		switch (totalOvers){
		case 5 :
			maxBalls = totalOvers * 6;
			std::cout << "This will be a 5 over match.\n" << std::endl;
			break;
		case 10 :
			maxBalls = totalOvers * 6;
			std::cout << "This will be a 10 over match.\n" << std::endl;
			break;
		case 20 :
			maxBalls = totalOvers * 6;
			std::cout << "This will be a T-20 match.\n" << std::endl;
			break;
		case 50 :
			maxBalls = totalOvers * 6;
			std::cout << "This will be an ODI match.\n" << std::endl;
			break;
		default:
			std::cout << "You have chosen an invalid value. Please choose bettween 5, 10, 20 and 50.\n" << std::endl;
			goto formatChoice;
		}
}

void Game :: selectPlayers(){
	std::cout << "-------------------------------------------------------------------\n"
				 "|====================Create Team-A and Team-B=====================|\n"
				 "-------------------------------------------------------------------\n" << std :: endl;

		for(int i = 0; i < playersPerTeam; i++ ){
			teamASelection:
				std::cout << std::endl << "Select player " << i + 1 << " of Team A - ";
				int playerIndexTeamA = takeIntegerInput();

				if(playerIndexTeamA < 0|| playerIndexTeamA > 29){
					std::cout << std::endl << "Please enter a number from given pool of players" << std::endl;
					goto teamASelection;
					}else if(!checkSelectedPlayer(playerIndexTeamA)){
						std::cout << "Player already chosen. Please select a different player." << std::endl;
					goto teamASelection;
				}else{
					Player teamAPlayer;
					teamAPlayer.id = playerIndexTeamA;
					teamAPlayer.name = players[playerIndexTeamA];
					teamA.players.push_back(teamAPlayer);
			}
		teamBSelection:
			std::cout << std::endl << "Select player " << i + 1 << " of Team B - ";
			int playerIndexTeamB = takeIntegerInput();

			if(playerIndexTeamB < 0|| playerIndexTeamB > 29){
				std::cout << std::endl << "Please enter a number from given pool of players" << std::endl;
				goto teamBSelection;
			}else if(!checkSelectedPlayer(playerIndexTeamB)){
				std::cout << "Player already chosen. Please select a different player." << std::endl;
				goto teamBSelection;
			}
				else{
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}

			}

}

bool Game :: checkSelectedPlayer(int playerID){
	int n = teamA.players.size();
	for(int i = 0; i < n; i++){
		if(teamA.players[i].id == playerID){
			return false;
		}
	}

	n = teamB.players.size();
	for(int i = 0; i < n; i++){
		if(teamB.players[i].id == playerID){
			return false;
		}
	}
	return true;
}

void Game :: displayTeams(){
	std::cout << "--------------------------                    --------------------------\n"
				 "|========Team A==========|                    |=========Team B=========|\n"
				 "--------------------------                    --------------------------\n";
	for(int i = 0; i < playersPerTeam; i++){
		std::cout << "|	 [" << i << "]" << teamA.players[i].name << "	 |" << "                    " << "|		[" << i << "]" << teamB.players[i].name << "	|" << std::endl;
	}
	std::cout << "--------------------------                    --------------------------\n" << std::endl;
}

void Game::coinToss(){
	std::cout << "----------------------------------------\n"
				 "|===============Let's Toss=============|\n"
				 "----------------------------------------\n" << std::endl;


	std::cout << "Which team will make the call? (Team A = 0,Team B =1).Choose between 0 and 1." << std::endl;


	tossChoice:
			int n = takeIntegerInput();
			if (n == 0){
				std::cout << "Team A will make the call for the Toss." << std::endl;
			}else if (n == 1){
				std::cout << "Team B will make the call for the Toss." << std::endl;
			}else{
				std::cout << "Please choose between 0 and 1." << std::endl;
				std::cin.clear();
				goto tossChoice;
			}

		std::cout << "Choose between 0 or 1 for the toss." << std::endl;

		tossProcess:
			int tossChoice = takeIntegerInput();
			if(!(tossChoice == 0||tossChoice == 1)){
				std::cout << "Please choose between 0 and 1." << std::endl;
				goto tossProcess;
			}

			int tossValue = rand() % 2;

		if(n == 0){
			if(tossChoice == tossValue){
				std::cout << "Team A has won the Toss." << std::endl;
				batOrBowl(teamA);
			}else{
				std::cout << "Team B has won the Toss." << std::endl;
				batOrBowl(teamB);
			}
		}else{
			if(tossChoice == tossValue){
				std::cout << "Team B has won the Toss." << std::endl;
				batOrBowl(teamB);
			}else{
				std::cout << "Team A has won the Toss." << std::endl;
				batOrBowl(teamA);
			}
		}
}

void Game :: batOrBowl(Team tossWinnerTeam){
	std::cout << "Press 1 or 2 to Bat or Bowl\n"
				 "1.Bat\n"
				 "2.Bowl\n" << std::endl;
	int batOrBowlChoice = takeIntegerInput();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch(batOrBowlChoice){
		case 1:
			std::cout << tossWinnerTeam.name + " has chosen to Bat first.\n" << std::endl;
			if(tossWinnerTeam.name.compare("Team-A") == 0){
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}else{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		case 2:
			std::cout << tossWinnerTeam.name + " has chosen to Bowl first.\n" << std::endl;
			if(tossWinnerTeam.name.compare("Team-B") == 0){
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}else{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		default:
			std::cout << "Invalid input. Please choose 1 or 2.\n" << std::endl;
			batOrBowl(tossWinnerTeam);
			break;
	}

}

void Game :: startFirstInnings(){
	std::cout << "		|||FIRST INNINGS STARTS|||\n" << std::endl;
	isFirstInnings = true;
	initializePlayers();
}

void Game :: initializePlayers(){
	chooseBatsman();
	firstBowler();

	std::cout << battingTeam->name << " - " << batsman->name << " is batting." << std::endl;
	std::cout << bowlingTeam->name << " - " << bowler->name << " is bowling." << std::endl;
}

void Game::playInnings(){
	battingTeam->totalRunsScored = 0;
	for(int i = 0; i < maxBalls; i++){
		for(int j = 0; j < 6; j++){



			std::cout << "Press Enter to Bowl" << std::endl;
			getchar();
			std::cout << "Bowling..." << std::endl;
			bat();
			if(!validateInningsScore()){
				break;
			}
		}
		bowler->overs = bowler->overs + 0.4;
		bowlingTeam->totalOversBowled = bowlingTeam->totalOversBowled + 0.4;
		std::cout << "End of the over.\n" << std::endl;
		chooseBowler();
	}

}

void Game::bat(){
	srand(time(NULL));

	int runsScored = rand() % 7;
	int outChance = rand() % 101;

	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;


	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
	bowler->overs = bowler->overs + 0.1;
	bowlingTeam->totalOversBowled = bowlingTeam->totalOversBowled + 0.1;


	if(runsScored !=0){
		std::cout << std::endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!\n" << std::endl;
		createGameScorecard();
	} else if (runsScored == 0 && outChance > 70){
		std::cout << std::endl << bowler->name << " to " << batsman->name << " OUT!\n" << std::endl;
		battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		bowler->wicketsTaken = bowler->wicketsTaken + 1;
		batsman->wicketLost = 1;
		createGameScorecard();

		chooseBatsman();
	}else{
		std::cout << std::endl << bowler->name << " to " << batsman->name << " dot ball.\n" << std::endl;
		createGameScorecard();
	}


}

bool Game :: validateInningsScore(){
	if(isFirstInnings){
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){

			std::cout << "			||| FIRST INNINGS ENDS ||| \n" << std::endl;
			std::cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalOversBowled << ")" << std::endl;
			std::cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1 << " runs to win the match.\n" << std::endl;
			return false;
		}
	}else {
		if (battingTeam->wicketsLost == playersPerTeam || (bowlingTeam->totalBallsBowled == maxBalls && battingTeam->totalRunsScored < bowlingTeam->totalRunsScored)){

			std::cout << bowlingTeam->name << " won the match.\n" << std::endl;
			std::cout << "			||| MATCH ENDS ||| \n" << std::endl;
			displaySummary(bowlingTeam, battingTeam);
			return false;
		}else if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored ) {
			std::cout << battingTeam->name << " won the match.\n" << std::endl;
			std::cout << "			||| MATCH ENDS ||| \n" << std::endl;
			displaySummary(battingTeam, bowlingTeam);
			return false;
		}else if (battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
			std::cout << "Match ends in a Draw." << std::endl;
			std::cout << "			||| MATCH ENDS ||| \n" << std::endl;
			displaySummary(bowlingTeam, battingTeam);
		}
	}
	return true;
}

void Game :: createGameScorecard(){
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "	" << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalOversBowled << ") | " << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")	" << bowler->name << " " << bowler->overs << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << std::endl;
	std::cout << "--------------------------------------------------------------------------\n" << std::endl;
}

void Game :: startSecondInnings(){
	std::cout << "			||| SECOND INNINGS BEGINS ||| \n" << std::endl;
	isFirstInnings = false;
	swap(battingTeam , bowlingTeam);
	initializePlayers();
	return;
}

void Game :: swap(Team *a,Team *b){
	Team temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void Game :: displaySummary(Team *a, Team *b){
	std::cout << a->name << " " << a->totalRunsScored << " - " << a->wicketsLost << " (" << b->totalOversBowled << ")" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << "| PLAYER	BATTING	BOWLING |" << std::endl;
	for (int i = 0; i < playersPerTeam; i++){
		std::cout << "|-------------------------------|" << std::endl;
		std::cout << "| [" << i << "] " << a->players[i].name << "	" << a->players[i].runsScored << "(" << a->players[i].ballsPlayed << ")" <<	 "	" << a->players[i].overs << "." << a->players[i].ballsBowled << "-" << a->players[i].runsGiven << "-" << a->players[i].wicketsTaken << "	|" << std::endl;
	}
	std::cout << "=================================\n" << std::endl;

	std::cout << b->name << " " << b->totalRunsScored << " - " << b->wicketsLost << " (" << a->totalOversBowled << ")" << std::endl;
		std::cout << "=================================" << std::endl;
		std::cout << "| PLAYER	BATTING	BOWLING |" << std::endl;
		for (int i = 0; i < playersPerTeam; i++){
			std::cout << "|-------------------------------|" << std::endl;
			std::cout << "| [" << i << "] " << b->players[i].name << "	" << b->players[i].runsScored << "(" << b->players[i].ballsPlayed << ")" <<	 "	" << b->players[i].overs << "." << b->players[i].ballsBowled << "-" << b->players[i].runsGiven << "-" << b->players[i].wicketsTaken << "	|" << std::endl;
		}
		std::cout << "=================================\n" << std::endl;
}

bool Game :: spellOver(int a){
	if(bowlingTeam->players[a].ballsBowled == (maxBalls/5)){
		return true;
	}else{
		return false;
	}
}


void Game :: firstBowler(){
	int nextBowler;
	std::cout << "Choose Bowler.\n" << std::endl;
	choosingBowler:
		nextBowler = takeIntegerInput();
		if(nextBowler < 0 || nextBowler > 10){
			std::cout << "Choose a valid Player." << std::endl;
			goto choosingBowler;
		}else{
			bowler = &bowlingTeam->players[nextBowler];
			std::cout << bowler->name << " is the bowler.\n" << std::endl;
		}
}


void Game :: chooseBowler(){
	int nextBowler;
	std::cout << "Choose Bowler.\n" << std::endl;
	choosingBowler:
		nextBowler = takeIntegerInput();
		if(nextBowler < 0 || nextBowler > 10){
			std::cout << "Choose a valid Player." << std::endl;
			goto choosingBowler;
		}else if(spellOver(nextBowler)){
			std::cout << "This bowler has finished his quota. Please choose a different bowler.\n" << std::endl;
			goto choosingBowler;
		}else if(bowlingTeam->players[nextBowler].id == bowler->id){
			std::cout << "This bowler bowled the previous over. Please choose a different bowler.\n" << std::endl;
			goto choosingBowler;
		}else{
			bowler = &bowlingTeam->players[nextBowler];
			std::cout << bowler->name << " is the bowler.\n" << std::endl;
		}
}

void Game :: chooseBatsman(){
	int nextBatsman;
	std::cout << "Choose Batsman.\n" << std :: endl;
	choosingBatsman:
		nextBatsman = takeIntegerInput();
		if(nextBatsman < 0 || nextBatsman > 10){
			std::cout << "Choose a valid player.\n" << std::endl;
			goto choosingBatsman;
		}else if(battingTeam->players[nextBatsman].wicketLost == 1){
			std::cout << "Batsman has already been declared out. Please choose a different Batsman,\n" << std::endl;
			goto choosingBatsman;
		}else{
			batsman = &battingTeam->players[nextBatsman];
			std::cout << batsman->name << " is the batsman.\n" << std::endl;
		}
}
