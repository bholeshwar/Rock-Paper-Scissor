//
//  Player.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef Player_h
#define Player_h

#include "Utilities.h"

/**
 An abstract class for player
 */
class Player
{
public:
    Player() {};
    virtual ~Player() {};
    
    /**
     Move method for a player. Inherited classes need to implement it.
     @return Action
     */
    virtual Utilities::Action Move() = 0;
};

#endif /* Player_h */
