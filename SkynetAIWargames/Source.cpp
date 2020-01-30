#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string humanArray[64];
string binaryArray[64];
string linearArray[64];
string randomArray[64];
string disp;

int targetLocationPrediction;
int searchGridHighNumber = 64;
int searchGridLowNumber = 1;
int humanGuess;
int linearAiGuess = 1;
int randAiGuess = rand() % 64 + 1;
//guess counter
int humans = 0;
int binary = 0;
int linear = 0;
int random = 0;

bool humanSolved = false;
bool algorSolved = false;
bool linSolved = false;
bool ranSolved = false;

//function to display the grid
string displayGrid(string myArray[]) {

	string str = "";
	// displays grid
	for (int i = 0; i < 64; i++)
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
	//fills in the arrays
	for (int i = 1; i < 64 + 1; i++)
	{
		humanArray[i - 1] = to_string(i);
		binaryArray[i - 1] = to_string(i);
		linearArray[i - 1] = to_string(i);
		randomArray[i - 1] = to_string(i);
	}
	// setting the seed for the random num generator so it's different each run
	srand(static_cast<unsigned int>(time(0)));

	//selects a random answer from 1 to 64
	int answer = rand() % 64 + 1;


	cout << "We've received intel that the enemy is within grids 1-64, find them!\n\n";


	cout << "----------------------------------------------------------------------------\n" << endl;
	cout << "Enter a number between 1-64 to search..." << endl;
	//Human
	while (humanSolved == false)
	{
		//Human

		cout << "Enter the number..." << endl;
		cin >> humanGuess;
		//human guesses too low
		if (humanGuess < answer)
		{
			cout << "Too low. Try again" << endl;
			//adds a guess
			humans++;
			//x's out the wrong answer on the human grid
			humanArray[humanGuess - 1] = " x";
		}
		//human guesses too high
		else if (humanGuess > answer)
		{
			cout << "Too high. Try again" << endl;
			//adds a guess
			humans++;
			//x's out the wrong answer on the human grid
			humanArray[humanGuess - 1] = " x";
		}
		//human guesses correctly
		else
		{
			//adds a guess
			humans++;
			cout << "Target located! The Humans found the target at " << answer << " in " << humans << " guesses." << endl;
			humanSolved = true;
			cout << "----------------------------------------------------------------------------\n" << endl;
		}

	}

	cout << "\n Human's grid \n";
	//displays human grid
	cout << disp << displayGrid(humanArray) << endl;


	//Algorithm Ai
	while (algorSolved == false)
	{
		//Algorithm AI
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//If the target was 'found'
		if (targetLocationPrediction == answer)
		{
			//adds a guess
			binary++;
			cout << "Target located! The Binary Ai found the target at " << answer << " in " << binary << " guesses." << endl;
			algorSolved = true;
			cout << "----------------------------------------------------------------------------\n" << endl;

		}
		//If the search 'overshot'
		else if (targetLocationPrediction > answer)
		{
			//adds a guess
			binary++;
			//cout << "Target not found at this location... " << targetLocationPrediction << " ...overshot. Rerouting search.\n" << endl;
			searchGridHighNumber = targetLocationPrediction;
			for (int i = targetLocationPrediction; i <= 64; i++)
			{
				binaryArray[i - 1] = " x";
			}
		}
		// the search 'undershot'
		else if (targetLocationPrediction < answer)
		{
			//adds a guess
			binary++;
			//cout << "Target not found at this location... " << targetLocationPrediction << " ...undershot. Rerouting search.\n" << endl;
			searchGridLowNumber = targetLocationPrediction;
			for (int i = 1; i <= targetLocationPrediction; i++)
			{
				binaryArray[i - 1] = " x";
			}
		}

	}

	cout << "\n Binary Ai's grid \n";
	//displays binary grid
	cout << disp << displayGrid(binaryArray) << endl;


	// linear Ai
	while (linSolved == false)
	{

		//Linear Ai guesses too high
		if (linearAiGuess > answer)
		{
			//adds a guess
			linear++;
			//	cout << "Linear Ai's guess of " << linearAiGuess << " was too high." << endl;
			linearAiGuess--;
			//x's out the wrong answer on the linear AI grid
			linearArray[linearAiGuess - 1] = "x";
		}
		//Linear Ai guesses too low
		else if (linearAiGuess < answer)
		{
			//adds a guess
			linear++;
			//cout << "Linear Ai's guess of " << linearAiGuess << " was too low." << endl;
			linearAiGuess++;
			//x's out the wrong answer on the linear AI grid
			linearArray[linearAiGuess - 1] = "x";
		}
		//when found
		else
		{
			//adds a guess
			linear++;
			cout << "Target located! The Linear Ai found the target at " << answer << " in " << linear << " guesses." << endl;
			linSolved = true;
			cout << "----------------------------------------------------------------------------\n" << endl;
		}

	}

	cout << "\n Linear Ai's grid \n";
	//displays linear grid
	cout << disp << displayGrid(linearArray) << endl;


	//Rand Ai
	while (ranSolved == false)
	{

		//Random Ai guess too high
		if (randAiGuess > answer)
		{
			//adds a guess
			random++;
			//x's out the wrong answer on the random AI grid
			randomArray[randAiGuess - 1] = "x";
			//cout << "Random Ai's guess of " << randAiGuess << " was too high." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		//Random Ai guess too low
		else if (randAiGuess < answer)
		{
			//adds a guess
			random++;
			//x's out the wrong answer on the random AI grid
			randomArray[randAiGuess - 1] = "x";
			//cout << "Random Ai's guess of " << randAiGuess << " was too low." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		////Random Ai guess correctly
		else
		{
			//adds a guess
			random++;
			cout << "Target located! The Random Ai found the target at " << answer << " in " << random << " guesses." << endl;
			ranSolved = true;
			cout << "----------------------------------------------------------------------------\n" << endl;
		}

	}

	cout << "\n Random Ai's grid \n";
	//displays random ai's gird
	cout << disp << displayGrid(randomArray) << endl;

	if (humans < random && humans < binary && humans < linear)
	{
		cout << "\n Humans were the best at finding the target with " << humans << " guesses\n";
	}
	else if (random < humans && random < binary && random < linear)
	{
		cout << "\n Random ai was the best at finding the target with " << random << " guesses\n";
	}
	else if (binary < humans && binary < linear && binary < random) {
		cout << "\n binary ai was the best at finding the target with " << binary << " guesses\n";
	}
	else {
		cout << "\n linear ai was the best at finding the target with " << linear << " guesses\n";
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