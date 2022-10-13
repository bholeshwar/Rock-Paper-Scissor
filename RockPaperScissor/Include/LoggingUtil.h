//
//  LoggingUtil.h
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 11/09/22.
//

#ifndef LoggingUtil_h
#define LoggingUtil_h

#include <string>
#include "Scoreboard.h"

/**
 A singleton class for LoggingUtil
 
 It is currently implemented as "Write-back cache", i.e. the logging happens in file when the game ends. During the game, the log is written in memory, which is written to a file "logs.txt" at the end. It is implemented like this to prevent performance issues during the game.
 
 It can also be implemented similar to "Write-through cache", where the log would be written to the file synchronously. It would be better when the game might run for long or there is a constraint on the memory of the device.
 */
class LoggingUtil {
public:
    /**
     Returns the instance of the LoggingUtil object
     */
    static LoggingUtil* GetInstance();
    
    ~LoggingUtil() {}; ///< Destructor
    
    /**
     Method to log the action of the player
     @param player the player, viz Computer or User
     @param action the action of the player
     */
    void LogAction(std::string player, std::string action);
    
    /**
     Method to log the final score
     @param scoreboard the current scoreboard
     */
    void LogScore(Scoreboard* scoreboard);
    
    /**
     Method to write the buffer to the file (write-back)
     */
    void WriteBackLog();
    
private:
    LoggingUtil(); ///< private constructor
    LoggingUtil(const LoggingUtil&) = delete; ///< no copies
    LoggingUtil& operator=(LoggingUtil&) = delete; ///< no self-assignments
    
    /**
     String buffer which stores the log in the memory
     */
    std::string buffer;
};

#endif /* LoggingUtil_h */
