//
//  Game.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef Game_h
#define Game_h

#include "Scoreboard.h"
#include "Player.h"
#include "LoggingUtil.h"

/**
 A singleton class for the Game
 */
class Game
{
public:
    /**
     Returns the instance of the Game object
     */
    static Game* GetInstance();
    
    ~Game(); ///< Destructor
    
    /**
     Method to start the game
     */
    void StartGame();
    
    /**
     Method to end the game
     */
    void EndGame();
    
    /**
     Method to play the game
     */
    void PlayGame();
    
private:
    Game(); ///< private constructor
    Game(const Game&) = delete; ///< no copies
    Game& operator=(Game&) = delete; ///< no self-assignments
    
    Scoreboard* scoreboard;
    Player* computer;
    Player* user;
    LoggingUtil* logger;
};

#endif /* Game_h */
