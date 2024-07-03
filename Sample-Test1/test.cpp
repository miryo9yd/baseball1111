#include "pch.h"
#include "../BaseBall/baseball.cpp"

class BaseballFixture : public testing::Test {
public : 
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, ReturnSolveResultCheck2Strike) {

	GuessResult result = game.guess("125");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);

}

TEST_F(BaseballFixture, ReturnSolveResultCheck1Strike2Ball) {

	GuessResult result = game.guess("132");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);

}