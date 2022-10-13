//
//  main.cpp
//  Test
//
//  Created by Bholeshwar Khurana on 11/09/22.
//

#include <iostream>
#include <gtest/gtest.h>
#include "../RockPaperScissor/Include/Scoreboard.h"

void CommonTest(Utilities::Action computerAction, Utilities::Action userAction , int computerScoreDelta, int userScoreDelta) {
    Scoreboard *scoreboard = Scoreboard::GetInstance();
    
    int curComputerScore = scoreboard->GetComputerScore();
    int curUserScore = scoreboard->GetUserScore();
    
    scoreboard->UpdateScoreboard(userAction, computerAction);
    
    int newComputerScore = scoreboard->GetComputerScore();
    int newUserScore = scoreboard->GetUserScore();
    
    ASSERT_EQ(curComputerScore+computerScoreDelta, newComputerScore);
    ASSERT_EQ(curUserScore+userScoreDelta, newUserScore);
}

TEST(RPSUnitTest, ComputerRockUserRock) {
    CommonTest(Utilities::kRock, Utilities::kRock, 0, 0);
}

TEST(RPSUnitTest, ComputerRockUserPaper) {
    CommonTest(Utilities::kRock, Utilities::kPaper, 0, 1);
}

TEST(RPSUnitTest, ComputerRockUserScissor) {
    CommonTest(Utilities::kRock, Utilities::kScissor, 1, 0);
}

TEST(RPSUnitTest, ComputerPaperUserRock) {
    CommonTest(Utilities::kPaper, Utilities::kRock, 1, 0);
}

TEST(RPSUnitTest, ComputerPaperUserPaper) {
    CommonTest(Utilities::kPaper, Utilities::kPaper, 0, 0);
}

TEST(RPSUnitTest, ComputerPaperUserScissor) {
    CommonTest(Utilities::kPaper, Utilities::kScissor, 0, 1);
}

TEST(RPSUnitTest, ComputerScissorUserRock) {
    CommonTest(Utilities::kScissor, Utilities::kRock, 0, 1);
}

TEST(RPSUnitTest, ComputerScissorUserPaper) {
    CommonTest(Utilities::kScissor, Utilities::kPaper, 1, 0);
}

TEST(RPSUnitTest, ComputerScissorUserScissor) {
    CommonTest(Utilities::kScissor, Utilities::kScissor, 0, 0);
}

int main(int argc, const char * argv[]) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
