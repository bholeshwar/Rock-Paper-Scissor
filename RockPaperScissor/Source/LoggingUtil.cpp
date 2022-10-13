//
//  LoggingUtil.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 11/09/22.
//

#include <chrono>
#include <ctime>
#include <fstream>
#include "../Include/LoggingUtil.h"

LoggingUtil* LoggingUtil::GetInstance() {
    static LoggingUtil* instance;
    
    if (instance == nullptr)
        instance = new LoggingUtil();
    
    return instance;
}

LoggingUtil::LoggingUtil(): buffer("") {}

void LoggingUtil::LogAction(std::string player, std::string action) {
    auto curTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string curTimeString = std::ctime(&curTime);
    curTimeString.erase(curTimeString.find('\n', 0), 1);
    
    buffer.append(curTimeString);
    buffer.append(", Player:");
    buffer.append(player);
    buffer.append(", Action:");
    buffer.append(action);
    buffer.append("\n");
}

void LoggingUtil::LogScore(Scoreboard* scoreboard) {
    auto curTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string curTimeString = std::ctime(&curTime);
    curTimeString.erase(curTimeString.find('\n', 0), 1);
    
    buffer.append(curTimeString);
    buffer.append(", ComputerScore:");
    buffer.append(std::to_string(scoreboard->GetComputerScore()));
    buffer.append(", UserScore:");
    buffer.append(std::to_string(scoreboard->GetUserScore()));
    buffer.append("\n");
}

void LoggingUtil::WriteBackLog() {
    std::ofstream logFile;
    logFile.open("logs.txt", std::fstream::app);
    logFile << buffer;
    
    logFile.close();
}
