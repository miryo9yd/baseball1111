#include "pch.h"
#include "../BaseBall/baseball.cpp"

class BaseballFixture : public testing::Test {
public : 
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		// game.guess() 수행후 Exception이 발생해야 PASS !
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {

		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	
}