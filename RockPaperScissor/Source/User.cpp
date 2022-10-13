//
//  User.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include <iostream>
#include "../Include/User.h"
#include "../Include/PrintUtils.h"

Utilities::Action User::Move() {
    PrintUtils::RequestMoveFromUser();
    PrintUtils::AskIfUserWantsToQuit();
    std::string userAction;
    std::cin >> userAction;
    while (!PrintUtils::IsValidInputForMove(userAction) && !PrintUtils::CheckIfQuittingTheGame(userAction)) {
        PrintUtils::AskForValidInput();
        std::cin >> userAction;
    }
    
    if (PrintUtils::CheckIfQuittingTheGame(userAction))
        return Utilities::kQuit;
    
    Utilities::Action action = Utilities::userInputToActionMap[userAction];
    
    PrintUtils::PrintUserAction(action);
    
    return action;
}
