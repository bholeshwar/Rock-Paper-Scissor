//
//  Computer.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include <stdlib.h>
#include "../Include/Computer.h"
#include "../Include/PrintUtils.h"

Utilities::Action Computer::Move() {
    Utilities::Action action = static_cast<Utilities::Action>(rand() % Utilities::numberOfActions);
    
    PrintUtils::PrintComputerAction(action);
    return action;
}
