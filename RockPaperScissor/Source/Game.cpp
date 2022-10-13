//
//  Game.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include <iostream>
#include "../Include/Game.h"
#include "../Include/PrintUtils.h"
#include "../Include/Computer.h"
#include "../Include/User.h"


Game* Game::GetInstance() {
    static Game* instance;
    
    if (instance == nullptr)
        instance = new Game();
    
    return instance;
}

Game::Game(): scoreboard(Scoreboard::GetInstance()), computer(new Computer()), user(new User()), logger(LoggingUtil::GetInstance()) {}

Game::~Game() {
    delete scoreboard;
    delete computer;
    delete user;
    delete logger;
}

void Game::StartGame() {
    PrintUtils::InitiateGame();
    
    std::string userInput;
    std::cin >> userInput;
    
    while (!PrintUtils::IsValidInputForInitiate(userInput)) {
        PrintUtils::AskForValidInput();
        std::cin >> userInput;
    }
    
    while (!PrintUtils::CheckIfQuittingTheGame(userInput)) {
        Utilities::Action userAction = user->Move();
        logger->LogAction("User", Utilities::actionToString[userAction]);
        if (userAction == Utilities::kQuit)
            return;
        Utilities::Action computerAction = computer->Move();
        logger->LogAction("Computer", Utilities::actionToString[computerAction]);
        scoreboard->UpdateScoreboard(userAction, computerAction);
        PrintUtils::PrintCurrentRoundResult(userAction, computerAction);
        PrintUtils::DisplayScoreboard(scoreboard);
    }
}

void Game::EndGame() {
    PrintUtils::PrintFinalResult(scoreboard);
    logger->LogScore(scoreboard);
    logger->WriteBackLog();
}

void Game::PlayGame() {
    StartGame();
    EndGame();
}
