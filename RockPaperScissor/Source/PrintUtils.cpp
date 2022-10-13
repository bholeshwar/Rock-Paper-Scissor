//
//  PrintUtils.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include <iostream>
#include "../Include/PrintUtils.h"
#include "../Include/Utilities.h"

void PrintUtils::InitiateGame() {
    std::cout << "Welcome to Rock Paper Scissor.\nPress I to start the game, Q to quit." << std::endl;
}

void PrintUtils::RequestMoveFromUser() {
    std::cout << "Please select one of (R) Rock, (P) Paper or (S) Scissor." << std::endl;
}

void PrintUtils::AskIfUserWantsToQuit() {
    std::cout << "Press Q to quit the game" << std::endl;
}

void PrintUtils::AskForValidInput() {
    std::cout << "Invalid input! Please enter a valid input." << std::endl;
}

bool PrintUtils::CheckIfQuittingTheGame(std::string input) {
    return (input == "Q");
}

bool PrintUtils::IsValidInputForInitiate(std::string input) {
    return (input == "I" || input == "Q");
}

bool PrintUtils::IsValidInputForMove(std::string action) {
    return (action == "R" || action == "P" || action == "S");
}

void PrintUtils::PrintUserAction(Utilities::Action action) {
    std::cout << "You chose " << Utilities::actionToString[action] << std::endl;
}

void PrintUtils::PrintComputerAction(Utilities::Action action) {
    std::cout << "The computer chose " << Utilities::actionToString[action] << std::endl;
}

void PrintUtils::PrintFinalResult(Scoreboard* scoreboard) {
    int userScore = scoreboard->GetUserScore();
    int computerScore = scoreboard->GetComputerScore();
    
    if (userScore < computerScore)
        std::cout << "\nYou lost!\n" << std::endl;
    else if (userScore > computerScore)
        std::cout << "\nYou won!\n" << std::endl;
    else
        std::cout << "\nDraw!\n" << std::endl;
    
    std::cout << "Final scoreboard:" << std::endl << "Computer: " << scoreboard->GetComputerScore() << std::endl << "You: " << scoreboard->GetUserScore() << std::endl << std::endl;
}

void PrintUtils::PrintCurrentRoundResult(Utilities::Action userAction, Utilities::Action computerAction) {
    int userActionToScore = Utilities::actionResultMatrix[(int)userAction][(int)computerAction];
    
    if (userActionToScore > 0)
        std::cout << "You beat Computer!" << std::endl;
    else if (userActionToScore < 0)
        std::cout << "Computer beat you!" << std::endl;
    else
        std::cout << "It was a draw!" << std::endl;
}

void PrintUtils::DisplayScoreboard(Scoreboard* scoreboard) {
    std::cout << "The current score is:" << std::endl << "Computer: " << scoreboard->GetComputerScore() << std::endl << "You: " << scoreboard->GetUserScore() << std::endl << std::endl;
}
