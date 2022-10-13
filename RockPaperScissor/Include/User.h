//
//  User.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef User_h
#define User_h

#include "Player.h"

/**
 Class for User, which is derived from Player class
 */
class User: public Player
{
public:
    User() {}
    virtual ~User() {}
    
    /**
     Move method for User class. It allows the user to choose an action
     @return Action
     */
    virtual Utilities::Action Move() override;
};

#endif /* User_h */
