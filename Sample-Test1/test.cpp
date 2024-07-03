#include "pch.h"
#include "../BaseBall/baseball.cpp"

class BaseballFixture : public testing::Test {
public : 
	Baseball game{ "123" };
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
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolveResultIfMatchedNumber) {

	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}