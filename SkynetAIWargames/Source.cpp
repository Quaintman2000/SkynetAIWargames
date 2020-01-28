#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string myArray[63];
string linearMyArray[63];
string randMyArray[63];
string disp;

int targetLocationPrediction;
int searchGridHighNumber = 64;
int searchGridLowNumber = 1;
int humanGuess;
int linearAiGuess = 1;
int randAiGuess = rand() % 64 + 1;

bool solved = false;

inline string displayGrid() {
	string str = "";
	// displays grid
	for (int i = 0; i < 65; i++)
	{
		//Appropiately spaces & 0's for nums 1-8 for neatness then then skips to i=7 since it did them all.
		if ((i + 1) < 8)
		{
			str += " " + myArray[i] + "  " + myArray[i + 1] + "  " + myArray[i + 2] + "  "
				+ myArray[i + 3] + "  " + myArray[i + 4] + "  " + myArray[i + 5] + "  " + myArray[i + 6]
				+ "  ";
			i += 6;
		}
		//adds a space & a 0 infront of the 9
		else if ((i + 1) == 9) {
			str += " " + myArray[i] + " ";
		}
		//any number divisible by 8 makes a new line
		else if ((i + 1) % 8 == 0)
		{
			str += myArray[i] + "\n";
		}
		else
		{
			str += myArray[i] + " ";
		}
	}
	return str;
}

int main()
{
	// setting the seed for the random num generator so it's different each run
	srand(static_cast<unsigned int>(time(0)));

	//selects a random answer from 1 to 64
	int answer = rand() % 64 + 1;


	cout << "Sending search party...\n";

	//puts numbers 1-64 into the myArray array
	for (int i = 1; i <= 64; i++)
	{
		myArray[i - 1] = to_string(i);
		linearMyArray[i - 1] = to_string(i);
		randMyArray[i - 1] = to_string(i);
	}

	//displays grid
	cout << disp << displayGrid() << endl;
	//Initiates the 'search'
	while (solved == false)
	{
		//Human
		cout << "Human Guess..." << endl;
		cin >> humanGuess;

		if (humanGuess < answer)
		{
			cout << "Too low. Try again" << endl;
		}
		else if (humanGuess > answer)
		{
			cout << "Too high. Try again" << endl;
		}
		else
		{
			cout << "Target located! Humans win!" << endl;
			solved = true;
			break;
		}

		//Linear Ai
		if (linearAiGuess > answer)
		{
			cout << "Linear Ai's guess of " << linearAiGuess << " was too high." << endl;
			linearAiGuess--;
		}
		else if (linearAiGuess < answer)
		{
			cout << "Linear Ai's guess of " << linearAiGuess << " was too low." << endl;
			linearAiGuess++;
		}
		else
		{
			cout << "linear Ai has found the target at " << linearAiGuess << "! Linear Ai wins!" << endl;
			solved = true;
			break;
		}

		//Random Ai
		if (randAiGuess > answer)
		{
			cout << "Random Ai's guess of " << randAiGuess << " was too high." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		else if (randAiGuess < answer)
		{
			cout << "Random Ai's guess of " << randAiGuess << " was too low." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		else
		{
			cout << "linear Ai has found the target at " << randAiGuess << "! Random Ai wins!" << endl;
			solved = true;
			break;
		}

		//Algorithm AI
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		cout << "Searching...\n" << endl;
		//If the target was 'found'
		if (targetLocationPrediction == answer) {
			cout << "found! " << targetLocationPrediction << endl;
			solved = true;
			break;
			//cout << disp << displayGrid() << endl;
		}
		//If the search 'overshot'
		else if (targetLocationPrediction > answer)
		{
			cout << "Target not found at this location... " << targetLocationPrediction << " ...overshot. Rerouting search.\n" << endl;
			searchGridHighNumber = targetLocationPrediction;

			for (int i = targetLocationPrediction; i <= 64; i++)
			{
				myArray[i - 1] = " x";
			}

			//cout << disp << displayGrid() << endl;
		}
		// the search 'undershot'
		else if (targetLocationPrediction < answer)
		{
			cout << "Target not found at this location... " << targetLocationPrediction << " ...undershot. Rerouting search.\n" << endl;
			searchGridLowNumber = targetLocationPrediction;

			for (int i = 1; i <= targetLocationPrediction; i++)
			{
				myArray[i - 1] = " x";
			}

			//cout << disp << displayGrid() << endl;
		}
	}
}

// original grid display
	//for (int i = 0; i < 65; i++)
	//{
	//	//Appropiately spaces & 0's for nums 1-8 for neatness then then skips to i=7 since it did them all.
	//	if ((i+1) < 8) 
	//	{
	//		cout << "0" << myArray[i] << " 0" << myArray[i+1] << " 0" << myArray[i+2] << " 0" 
	//			<< myArray[i + 3] << " 0" << myArray[i+4] << " 0" << myArray[i + 5] << " 0" << myArray[i + 6]
	//			<< " 0" ;
	//		i += 6;
	//	}
	//	//adds a space & a 0 infront of the 9
	//	else if ((i + 1) == 9) {
	//		cout << "0" << myArray[i] << " ";
	//	}
	//	//any number divisible by 8 makes a new line
	//	else if ((i + 1) % 8 == 0)
	//	{
	//		cout << myArray[i] << endl;
	//	}
	//	else
	//	{
	//		cout << myArray[i] << " ";
	//	}
	//}
/// trenton