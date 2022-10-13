//
//  PrintUtils.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#ifndef PrintUtils_h
#define PrintUtils_h

#include "Scoreboard.h"

class PrintUtils
{
public:
    /**
     Method to print the beginning of the game
     */
    static void InitiateGame();
    
    /**
     Method to print to ask the user to move
     */
    static void RequestMoveFromUser();
    
    /**
     Method to ask use if they want to quit the game
     */
    static void AskIfUserWantsToQuit();
    
    /**
     Method to ask for valid input in the case of invalid inputs
     */
    static void AskForValidInput();
    
    /**
     Method to check if the user is quitting the game
     @return true if the user wants to quit the game
     @param input user input
     */
    static bool CheckIfQuittingTheGame(std::string input);
    
    /**
     Method to check if the user input is valid for starting the game
     @return true if correct input
     @param input user input
     */
    static bool IsValidInputForInitiate(std::string input);
    
    /**
     Method to check if the user input is a valid move
     @return true if the user action is valid
     @param input user input
     */
    static bool IsValidInputForMove(std::string input);
    
    /**
     Method to print user's action
     @param action the action of the user
     */
    static void PrintUserAction(Utilities::Action action);
    
    /**
     Method to print computer's action
     @param action the action of the computer
     */
    static void PrintComputerAction(Utilities::Action action);
    
    /**
     Method to print the final result after the game is quit
     @param scoreboard The current scoreboard
     */
    static void PrintFinalResult(Scoreboard* scoreboard);
    
    /**
     Method to print the current round's result
     @param userAction The user's action
     @param computerAction The computer's action
     */
    static void PrintCurrentRoundResult(Utilities::Action userAction, Utilities::Action computerAction);
    
    /**
     Method to display the scoreboard
     @param scoreboard The current scoreboard
     */
    static void DisplayScoreboard(Scoreboard* scoreboard);
};

#endif /* PrintUtils_h */
