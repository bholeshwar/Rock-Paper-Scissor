//
//  main.cpp
//  RockPaperScissor
//
//  Created by Bholeshwar Khurana on 10/09/22.
//

#include <iostream>
#include "Include/Game.h"

int main(int argc, const char * argv[]) {
    Game* game = Game::GetInstance();
    game->PlayGame();
    
    delete game;
    return 0;
}
