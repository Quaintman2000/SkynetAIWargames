#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



int targetLocationPrediction;
int searchGridHighNumber = 64;
int searchGridLowNumber = 1;
int humanGuess;
int linearAiGuess = 1;
int randAiGuess = rand() % 64 + 1;
int guesses = 0;

bool humanSolved = false;
bool algorSolved = false;
bool linSolved = false;
bool ranSolved = false;


int main()
{
	// setting the seed for the random num generator so it's different each run
	srand(static_cast<unsigned int>(time(0)));

	//selects a random answer from 1 to 64
	int answer = rand() % 64 + 1;


	cout << "Sending search party...\n\n";


	cout << "----------------------------------------------------------------------------\n" << endl;
	//Human
	while (humanSolved == false)
	{
		//Human
		
		cout << "Human Guess..." << endl;
		cin >> humanGuess;
		//human guesses too low
		if (humanGuess < answer)
		{
			cout << "Too low. Try again" << endl;
			guesses++;
		}
		//human guesses too high
		else if (humanGuess > answer)
		{
			cout << "Too high. Try again" << endl;
			guesses++;
		}
		//human guesses correctly
		else
		{
			guesses++;
			cout << "Target located! The Humans found the target at "<<answer <<" in " << guesses<<" guesses."<< endl;
			humanSolved = true;
		}
		cout << "----------------------------------------------------------------------------\n" << endl;
	}


	guesses = 0;
	//Algorithm Ai
	while (algorSolved == false)
	{
		//Algorithm AI
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		
		//If the target was 'found'
		if (targetLocationPrediction == answer) 
		{
			guesses++;
			cout << "Target located! The Binary Ai found the target at " << answer << " in " << guesses << " guesses." << endl;
			algorSolved = true;

		
		}
		//If the search 'overshot'
		else if (targetLocationPrediction > answer)
		{
			guesses++;
			cout << "Target not found at this location... " << targetLocationPrediction << " ...overshot. Rerouting search.\n" << endl;
			searchGridHighNumber = targetLocationPrediction;

			
		}
		// the search 'undershot'
		else if (targetLocationPrediction < answer)
		{
			guesses++;
			cout << "Target not found at this location... " << targetLocationPrediction << " ...undershot. Rerouting search.\n" << endl;
			searchGridLowNumber = targetLocationPrediction;

		}
		cout << "----------------------------------------------------------------------------\n" << endl;
	}
	guesses = 0;
	// linear Ai
	while (linSolved == false)
	{
		
		//Linear Ai guesses too high
		if (linearAiGuess > answer)
		{
			guesses++;
			cout << "Linear Ai's guess of " << linearAiGuess << " was too high." << endl;
			linearAiGuess--;
		}
		//Linear Ai guesses too low
		else if (linearAiGuess < answer)
		{
			guesses++;
			cout << "Linear Ai's guess of " << linearAiGuess << " was too low." << endl;
			linearAiGuess++;
		}
		//when found
		else
		{
			guesses++;
			cout << "Target located! The Linear Ai found the target at " << answer << " in " << guesses << " guesses." << endl;
			linSolved = true;
		}
		cout << "----------------------------------------------------------------------------\n" << endl;
	}

	guesses = 0;
	//Rand Ai
	while (ranSolved == false)
	{
		
		//Random Ai guess too high
		if (randAiGuess > answer)
		{
			guesses++;
			cout << "Random Ai's guess of " << randAiGuess << " was too high." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		//Random Ai guess too low
		else if (randAiGuess < answer)
		{
			guesses++;
			cout << "Random Ai's guess of " << randAiGuess << " was too low." << endl;
			randAiGuess = rand() % 64 + 1;
		}
		////Random Ai guess correctly
		else
		{
			guesses++;
			cout << "Target located! The Random Ai found the target at " << answer << " in " << guesses << " guesses." << endl;
			ranSolved = true;
		}
		cout << "----------------------------------------------------------------------------\n" << endl;
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