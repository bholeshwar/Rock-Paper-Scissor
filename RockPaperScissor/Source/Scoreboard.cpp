//
//  Scoreboard.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include "../Include/Scoreboard.h"

Scoreboard::Scoreboard(): computerScore(0), userScore(0) {}

Scoreboard* Scoreboard::GetInstance() {
    static Scoreboard* instance;
    
    if (instance == nullptr)
        instance = new Scoreboard();
    
    return instance;
}

int Scoreboard::GetComputerScore() {
    return computerScore;
}

int Scoreboard::GetUserScore() {
    return userScore;
}

void Scoreboard::UpdateScoreboard(Utilities::Action userAction, Utilities::Action computerAction, int increment) {
    int userActionToScore = Utilities::actionResultMatrix[(int)userAction][(int)computerAction];
    
    if (userActionToScore > 0)
        userScore += increment;
    else if (userActionToScore < 0)
        computerScore += increment;
}
