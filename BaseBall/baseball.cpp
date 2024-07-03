#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;

};
class Baseball {
public : 
	explicit Baseball(const string& question) 
		:question{ question } {
	
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true,3,0 };
		}

		return checkString(guessNumber);
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != NUMBER_LENGTH ) {

			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be Number");
		}

		if (isDuplicatedNumber(guessNumber)) {

			throw invalid_argument("Must not have the same nubmer.");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}


	GuessResult checkString(const string& guessNumber) {
		GuessResult retResult = { false,0,0 } ;

		for (int charorder = 0; charorder < NUMBER_LENGTH; charorder++) {
			for (int queorder = 0; queorder < NUMBER_LENGTH; queorder++) {

				if (guessNumber[charorder] == question[queorder] && charorder == queorder) {
					retResult.strikes++;
					break;
				}
				if (guessNumber[charorder] == question[queorder]) {
					retResult.balls++;
					break; 
				}

			}

		}
		return retResult; 
	}
private :
	string question; 
	const int NUMBER_LENGTH = 3;
};
