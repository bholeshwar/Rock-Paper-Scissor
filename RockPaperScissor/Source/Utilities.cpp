//
//  Utilities.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include "../Include/Utilities.h"

std::unordered_map<std::string, Utilities::Action> Utilities::userInputToActionMap = {
    {"Q", Utilities::Action::kQuit},
    {"R", Utilities::Action::kRock},
    {"P", Utilities::Action::kPaper},
    {"S", Utilities::Action::kScissor}
};

std::unordered_map<Utilities::Action, std::string> Utilities::actionToString = {
    {Utilities::Action::kQuit, "Quit"},
    {Utilities::Action::kRock, "Rock"},
    {Utilities::Action::kPaper, "Paper"},
    {Utilities::Action::kScissor, "Scissor"}
};
