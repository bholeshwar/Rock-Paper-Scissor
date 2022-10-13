//
//  Computer.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef Computer_h
#define Computer_h

#include "Player.h"

/**
 Class for Computer, which is derived from Player class
 */
class Computer: public Player
{
public:
    Computer() {}
    virtual ~Computer() {}
    
    /**
     Move method for Computer class. It chooses a random action.
     @return Action
     */
    virtual Utilities::Action Move() override;
};

#endif /* Computer_h */
