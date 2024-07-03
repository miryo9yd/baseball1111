#include <stdexcept>
using namespace std;
class Baseball {
public : 
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);




	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {

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
};
