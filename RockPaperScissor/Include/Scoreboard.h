//
//  Scoreboard.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef Scoreboard_h
#define Scoreboard_h

#include "Utilities.h"

/**
 A singleton class for the Scoreboard
 */
class Scoreboard
{
private:
    Scoreboard(); ///< private constructor
    Scoreboard(const Scoreboard&) = delete; ///< no copies
    Scoreboard& operator=(Scoreboard&) = delete; ///< no self-assignments
    
    int computerScore;
    int userScore;

public:
    /**
     Return the instance of the Scoreboard object
     */
    static Scoreboard* GetInstance();
    
    ~Scoreboard() {}; ///< Destructor
    
    /**
     Method to get the computer score
     @return computerScore
     */
    int GetComputerScore();
    
    /**
     Method to get the user score
     @return userScore
     */
    int GetUserScore();
    
    /**
     Method to update the scoreboard
     @param userAction the user's action
     @param computerAction the computer's action
     @param increment the increment in the score to be done, by default it is 1
     */
    void UpdateScoreboard(Utilities::Action userAction, Utilities::Action computerAction, int increment=1);
};


#endif /* Scoreboard_h */
