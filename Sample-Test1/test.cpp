#include "pch.h"
#include "../BaseBall/baseball.cpp"

class BaseballFixture : public testing::Test {
public : 
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		// game.guess() ������ Exception�� �߻��ؾ� PASS !
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInputLengthIsUnmached) {
	assertIllegalArgument("12");
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {
	assertIllegalArgument("12s");

	
}