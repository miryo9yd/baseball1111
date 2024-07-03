#include "pch.h"
#include "../BaseBall/baseball.cpp"


TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game; 
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	try {
		game.guess(string("12s"));
		FAIL(); 
	}catch(exception e) {

	}

	
}