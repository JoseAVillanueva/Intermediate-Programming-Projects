// Author: Jose Villanueva 
// Course: COSC 1437
// Program 1.3
// References/Option: The bowling PDF provided under the Program set 1 assignment 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int throws = 0;
int temp = 1;

const int SIZE = 100;
const int SIZE2 = 10;

int Scores[SIZE2] = { 0, };
int ScoreData[SIZE] = { 0, };


int main()
{
	int game = 1;
	int SumScores = 0;
	int NumberOfGames;
	int counter = 0;

	string FileName, GameData;
	ifstream inputFile;
	

	//The user is asked to enter the name of the file
	cout << "Enter the file name: ";
	cin >> FileName;
	cout << endl;


	//the file is opened 
	inputFile.open(FileName);


	//the if loop determines if the file opened, if it fails then the program is ended
	if (inputFile.fail())
	{
		cout << "An error occured while opening the file" << endl;
	}

	//if the file is opened, then the data is processed 
	else
	{

		inputFile >> NumberOfGames;


		//sets the top row of numbers to display the amount of throws
		cout << "Game      1    2    3    4    5    6    7    8    9      10\n";


		//while data is still being pulled from the file, the program will continue to run
		while (inputFile >> GameData)
		{

			//the for loop retrieves and process the data from GameData
			//the processed information is saved in the ScoreData array
			//the processed information is saved as an integer for later use
			for (int index = 0; index < GameData.length(); index++)
			{
				//if the data is a spare(/), then the value in ScoreData
				//is the previous score minus ten
				if (GameData[index] == '/')
				{
					ScoreData[index] = 10 - ScoreData[index - 1];
				}

				//else, if the data is a Strike(X), then the value in scoreData
				//is a(n) 10
				else if (GameData[index] == 'X')
				{
					ScoreData[index] = 10;
				}

				//else, if the current data is a foul ball/a missed ball (-)
				//then the value in ScoreData is a(n) 0
				else if (GameData[index] == '-')
				{
					ScoreData[index] = 0;
				}

				//else if the current data is a 9, then the value in ScoreData is a 9
				else if (GameData[index] == '9')
				{
					ScoreData[index] = 9;
				}

				//else if the current data is a 8, then the value in ScoreData is a 8
				else if (GameData[index] == '8')
				{
					ScoreData[index] = 8;
				}

				//else if the current data is a 7, then the value in ScoreData is a 7
				else if (GameData[index] == '7')
				{
					ScoreData[index] = 7;
				}

				//else if the current data is a 6, then the value in ScoreData is a 6
				else if (GameData[index] == '6')
				{
					ScoreData[index] = 6;
				}

				//else if the current data is a 5, then the value in ScoreData is a 5
				else if (GameData[index] == '5')
				{
					ScoreData[index] = 5;
				}

				//else if the current data is a 4, then the value in ScoreData is a 4
				else if (GameData[index] == '4')
				{
					ScoreData[index] = 4;
				}

				//else if the current data is a 3, then the value in ScoreData is a 3
				else if (GameData[index] == '3')
				{
					ScoreData[index] = 3;
				}

				//else if the current data is a 2, then the value in ScoreData is a 2
				else if (GameData[index] == '2')
				{
					ScoreData[index] = 2;
				}
				//else if the current data is a 1, then the value in ScoreData is a 1
				else if (GameData[index] == '1')
				{
					ScoreData[index] = 1;
				}
			}

			//the for loop processes the data collected in the ScoreData Array
			//The ScoreData array and GameData are ran together to process Scores for the match
			//once the counter reaches two, throw is incremented by one, and the position of
			//the scores array is increased to hold the next set of scores 
			for (int index2 = 0; index2 < GameData.length(); index2++)
			{

				//if the current data in GameData is a /, then the scores
				//are adjusted for a spare (add the current data and the next throw)
				//and the counter is incremented by one
				if (GameData[index2] == '/')
				{

					SumScores += ScoreData[index2] + ScoreData[index2 + 1];
					counter++;
				}

				//else, if the current data in GameData is an(n) X, then the socres 
				//are adjusted for a strike (add the current data and the next two throws)
				//and the counter is incremented by two
				else if (GameData[index2] == 'X')
				{
					SumScores += ScoreData[index2] + ScoreData[index2 + 1] + ScoreData[index2 + 2];

					counter++;
					counter++;
				}

				//else, add the data normally ( the pervious throw and the current throw)
				//and the counter is incremented by one
				else
				{
					SumScores += ScoreData[index2];
					counter++;
				}

				//if the value of counter is equal to two, then the Data in the Scores
				//Array is set equal to the current SumScores, throws is incremented 
				//to move the position of the Scores array, and the counter is set to 0
				if (counter == 2)
				{
					Scores[throws] = SumScores;
					throws++;
					counter = 0;
				}
			}

			//reset the counter and throws for the next set of data 
			//that is going to be processed 
			throws = 0;
			counter = 0;

			//the data is formated here
			//the following code is used to format the data into the bowling score card/chart
			cout << "------------------------------------------------------------\n";
			cout << "|      |";

			//the for loop is used to format the data gained from each throw/game
				for (int index6 = 0; index6 < GameData.length(); index6++)
				{

					//if the current value of temp is 10, then the data is formated for the final 
					//throw/game
					if (temp == 10)
					{

						//if the remaining data in GameData is equal to three
						//then the data is formated for the final 3 throws
						if (GameData.length() - index6 == 3)
						{
							cout << " "
								<< GameData[index6] << "|"
								<< GameData[index6 + 1] << "|"
								<< GameData[index6 + 2] << "|";
						}

						//else, if the remaining data in GameData is equal to two
						//then the data is formated for the final 2 throws
						else if (GameData.length() - index6 == 2)
						{
							cout << " "
								<< GameData[index6] << "|"
								<< GameData[index6 + 1] << "| |";
						}

						//else, if the data is somehow lower than two, then the data
						//is formated for the final (single/one) throw.
						else
						{
							cout << " " << GameData[index6]
								<< "| | |";
						}
						//index is incremented by 2 to skip the remaining data
						//so it is not processed twice
							index6++;
							index6++;
					}

					//else, the data is formated normally for games 1-9
					else
					{

					//if the counters value is 0, then the data will be formated normally
						if (counter == 0)
						{

							//if the data within GameData is an X, then the data is formated 
							//for a strike and counter is incremented by two
							if (GameData[index6] == 'X')
							{
								cout << "  |" << GameData[index6] << "|";
								counter++;
								counter++;
							}

							//else, the data is formated normally and counter is incremeted by one
							else
							{
								cout << " " << GameData[index6] << "|";
								counter++;
							}
						}

						//else, if the counters current value is one, then the data is formated for
						//the final throw in the current game and counter is incremented by one
						else if (counter == 1)
						{
							cout << GameData[index6] << "|";
							counter++;
						}

						//if the value of counter is two, then the value of temp is incremented by one
						//and counter is set to zero
						if (counter == 2)
						{
							temp++;
							counter = 0;
						}

					}


				}
			//reset temp(to one), counter, and throws to zero 
			temp = 1;
			counter = 0;
			throws = 0;


			cout << endl;
			cout << "|      |----|----|----|----|----|----|----|----|----|------|\n";
			cout << "|Game " << game;

			//the for loop formats the data to display the scores for each game
			for (int index7 = 0; index7 < 10; index7++)
			{

				//if the current value of counter is 9, then the data is formated for the final score
				if (counter == 9)
				{
					//if the current value of scores is between 10-100
					//then the data is formated accordingly
					if (Scores[counter] < 100 && Scores[counter] >= 10)
					{
						cout << "|    " << Scores[counter];
					}

					//if the current value of scores is equal or greater than 100
					//then the data is formated accordingly
					else if (Scores[counter] >= 100)
					{
						cout << "|   " << Scores[counter];
					}

					//if the current value of scores is lower than 10
					//then the data is formated accordingly 
					else
					{
						cout << "|     " << Scores[counter];
					}
				}

				//else, if the counters current value is lower than 9
				//then the data is formated accordingly
				else if (counter < 9)
				{

					//if the current value of scores is between 10-100
					//then the data is formated accordingly
					if (Scores[counter] < 100 && Scores[counter] >= 10)
					{
						cout << "|  " << Scores[counter];
					}

					//if the current value of scores is equal or greater than 100
					//then the data is formated accordingly
					else if (Scores[counter] >= 100)
					{
						cout << "| " << Scores[counter];
					}

					//if the current value of scores is lower than 10
					//then the data is formated accordingly 
					else
					{
						cout << "|   " << Scores[counter];
					}
				}

				//counter is incremented by one
				counter++;
			}
			cout << "|" << endl;

			//the for loop sets all the elements within the ScoreData array to zero
			for (int index3 = 0; index3 < GameData.length(); index3++)
			{
				ScoreData[index3] = 0;
			}

			//the for loop sets all the elements within the Scores array to zero
			for (int index5 = 0; index5 < 10; index5++)
			{
				Scores[index5] = 0;
			}

			//resets throws, SumScores, and counter to zero
			throws = 0;
			SumScores = 0;
			counter = 0;

			//increments game by one 
			game++;
		}

		//the final line for the formated data
		cout << "------------------------------------------------------------\n";
	}
	return 0;
}