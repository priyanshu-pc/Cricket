#include <vector>
#include "player.h" //<string>

class Team{

	public:
		Team();
		std::string name;
		int totalRunsScored;
		int wicketsLost;
		int totalBallsBowled;
		float totalOversBowled;
		std::vector<Player> players;


};
