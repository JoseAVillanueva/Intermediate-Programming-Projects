// Author: Jose Villanueva 
// Course: COSC 1437
// Program 1.1
// References/Option: The program set PDF provided under the Program set 1 assignment 

#include <iostream>
#include <string>
#include <cmath>

const int SIZE = 100;
const int GradeSize = 11;

float AvgHW, AvgQ, ExamGrade = 0;

int GradesHW[SIZE];
int GradesQ[SIZE];
int Percentages[3];
float GradeA[GradeSize] = { 90,91,92,93,94,95,96,97,98,99,100 };
float GradeB[GradeSize] = { 80,81,82,83,84,85,86,87,88,89,90 };
float GradeC[GradeSize] = { 70,71,72,73,74,75,76,77,78,79,80 };

//function used to gather grade data and process the averages
void ArrayInfo(int[], int, float&);

//function used to calculate the final grade
void GradeCal(float[], int[], float, float, float, int, char);


using namespace std;

int main()
{
	char Alet = 'A', Blet = 'B', Clet = 'C', Again = 'Y';
	int PercentageTotal = 0;
																															
	string FirstName; 

	//while Again is not equal to N or n, then the program will continue to loop
	while(Again != 'N' && Again != 'n') 
	{
		AvgHW = 0;
		AvgQ = 0;
		PercentageTotal = 0;

		cout << "Student Name: ";
		cin >> FirstName;
		cout << "Homework, Quiz, and Test Percentages: ";

		//the while loop is used to gather the Percentages for the grades
		//while the total sum of the percentages does not equal 100
		//then the loop will repeat
		while (PercentageTotal != 100)
		{

			//PercentageTotal is set to at the beginning of each loop
			PercentageTotal = 0;

			//the foor loop goes through the Percentages array
			//the array will only accept three values
			for (int INDEX = 0; INDEX < 3; INDEX++)
			{
				cin >> Percentages[INDEX];

				//collects the sum of the given percentages
				PercentageTotal += Percentages[INDEX];
			}

			//if the sum of the percentages is not equal to 100, then an error is displayed 
			// and the user has to re-enter the percentages 
				if (PercentageTotal != 100)
				{
					cout << "The data you've entered does not total to 100, please enter the contents again\n";
					cout << "" << endl;
				}
			}

		cout << "Homework Grades: ";
		//Gather the Data for Homework Grades and calculate the average homework
		ArrayInfo(GradesHW, SIZE, AvgHW);

		cout << "Quiz Grades: ";
		//Gather the data for Quiz Grades and calculate the average for the quizes
		ArrayInfo(GradesQ, SIZE,AvgQ);
		cout << "\n";

		cout << "Minimum Grades needed for: " << FirstName << endl;
		cout << "\n";

		//the following functions calculate the final graded need to get an A, B, or C
		GradeCal(GradeA, Percentages, AvgHW, AvgQ, ExamGrade, GradeSize, Alet);
		GradeCal(GradeB, Percentages, AvgHW, AvgQ, ExamGrade, GradeSize, Blet);
		GradeCal(GradeC, Percentages, AvgHW, AvgQ, ExamGrade, GradeSize, Clet);

		cout << endl;

		cout << "Run Again (Y/N): ";
		cin >> Again;
		cout << endl;
	}

	return 0;	
}

/*--------------------------------------------------------------------------------------

 The ArrayInfo Function used to gather the infromation for the Quiz and Homework Grades
 as well as calculate the averages for Quiz and Homework grades

--------------------------------------------------------------------------------------*/

void ArrayInfo(int nums[], int size, float& Avg)
{
	int sum = 0;
	int counter = 0;
	int num = 0;

	cin >> num;

	//while the value num is not equal to (-1)
	//then the loop will continue to repeat
	while (num != -1)
	{
		//gathers the information for the Arrays
		nums[counter] = num;

		//sum collects the value of each array
		sum += nums[counter];

		//counter is incremented by one to move the nums array
		counter++;
		cin >> num;


		//Avg is used to calculate the average of the given grades
		Avg = static_cast<float>(sum / counter);

	}
	
	counter = 0;
	sum = 0;
	num = 0;

	//and if statement is here to check if the Average is invlaid 
	//if the data is invalid then an error is displayed and the user is asked to 
	//re-enter the data
	if (!(Avg >= 0 && Avg <= 100))
	{
		cout << "The contents entered are invalid, please re-enter the contents.\n";

		cin >> num;

		//while the value num is not equal to (-1)
		//then the loop will continue to repeat
		while (num != -1)
		{
			//gathers the information for the Arrays
			nums[counter] = num;

			//sum collects the value of each array
			sum += nums[counter];

			//counter is incremented by one to move the nums array
			counter++;
			cin >> num;


			//Avg is used to calculate the average of the given grades
			Avg = static_cast<float>(sum / counter);

		}
	}
}


/*-----------------------------------------------------------------------------------------

The GradeCal function is used to calculate the final grade needed to achieve an A, B, or C

-----------------------------------------------------------------------------------------*/

void GradeCal(float GrA[], int Per[], float HWavg, float Qavg, float A, int size, char GradeLetter)
{

	float Percen= 100;
	float B = 101;

	//the for loop is used to step through the grades array
	for (int index = 0; index < size; index++)
	{
		//the following equation is used to calculate the grades
		//A is the value of the final grade
		//GrA is the array used to step through the scores needed for an A, B, or C
		//Per is the percentages gather for Quiz, Homework, and test Percentages(all divided by Percent(100) to get a decmical for grade conversion)
		//The percentages are multiplied by the Averages of Homework and Quizes
		//The averages are added and subtracted by the scores needed for an A, B, or C
		//The value is then divided by the test score percentage to get the final grade needed for an A, B, or C
		A = (GrA[index] - (((Per[0] / Percen)* HWavg) + ((Per[1] / Percen) * Qavg))) / (Per[2]/Percen);

		//if the final grade is a valid grade then it enters rhe nested loop
		if (A >= 0 && A <= 100)
		{

			//if the final grade is a valid grade, and is lower than the value of B (an invalid grade) 
			//then the value of B is now the final grade
			if (A < B)
			{
				B = A;
			}
		}
	}

	//if the value of B is between 0-100, then the following message is printed 
	//with the graded needed to achieve an A, B, or C
	if (B >= 0 && B <= 100)
	{
		cout << GradeLetter << "- " << ceil(B) << endl;
	}

	//else, a sorry is displayed 
	else
	{
		cout << GradeLetter << "- SORRY" << endl;
	}
}