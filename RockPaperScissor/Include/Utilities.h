//
//  Utilities.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef Utilities_h
#define Utilities_h

#include <unordered_map>
#include <string>

class Utilities
{
public:
    /// Currently there are three number of actions: Rock, Paper or Scissor
    static constexpr int numberOfActions = 3;
    
    /// enum for Actions
    typedef enum {
        kQuit = -1,
        kRock = 0,
        kPaper,
        kScissor
    } Action;
    
    /**
     Matrix to get result of 2 actions. Matrix[i][j] represents the result for action i to action j
        Matrix[i][j] = -1 => j beats i
        Matrix[i][j] = 0 => i is equalt to j
        Matrix[i][j] = 1 => i beats j
     
                kRock       kPaper      kScissor
     kRock                   0              -1              1
     kPaper                 1               0               -1
     kScissor               -1              1               0
     */
    static constexpr int actionResultMatrix[3][3] = {
        {0, -1, 1},
        {1, 0, -1},
        {-1, 1, 0}
    };
    
    /// A map pointing user input to corresponding Action
    static std::unordered_map<std::string, Utilities::Action> userInputToActionMap;
    
    /// A map pointing action to the corresponding string
    static std::unordered_map<Utilities::Action, std::string> actionToString;
};


#endif /* Utilities_h */
