// Author: Jose Villanueva 
// Course: COSC 1437
// Required Program
// References/Option: The poker PDF provider under the Program set 1 assignment 


#include <iostream> 
#include <string> 
#include <iomanip> 

using namespace std;


bool Flag = false;
bool HouseFlagPair = false;
bool HouseFlagThree = false;
 
bool ROYAL_FLUSH = 0;  
bool FLUSH = 0;
bool FOUR_OF_A_KIND = 0;
bool THREE_OF_A_KIND = 0;
bool ONE_PAIR = 0;
bool TWO_PAIR = 0;
bool HIGH_CARD = 1;
bool FULL_HOUSE = 0;
bool STRAIGHT_FLUSH = 0;
bool STRAIGHT = 0;
bool StraightPairOne = 0;
bool StraightPairTwo = 0;

const int RANKS = 15; 
const int SUITS = 4;
const int SIZE = 5;

int RankValues[RANKS] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
int HandRankValues[SIZE];

string Suits[SUITS] = {"D", "C", "S", "H"};
string Ranks[RANKS] = {"A","2","3","4","5","6","7","8","9","T","J","Q","K","A"};
string CARDS[SIZE];
string CARDS2[SIZE];
string HandSuits[SIZE];
string HandRanks[SIZE];

//These are functions that are used to determine is the given hand
//is a flush, royal flush, or straight flush
bool Flush(string[], string[], int);
bool RoyalFlush(string[], string[], int [], const int);
bool StraightFlush(string [], string[], int[], const int);

//the following function is used to sort an array of integers in order
//(will be used to determine straights)
void BubbleSortArray(int[]);

int main()
{
    char Val = 'Y';
    int counter = 0;
    int Pairs = 0;

    //the program enters a while loop to take in the values of the hand
    while (Val != 'N' && Val != 'n')
    {

        //the for loop is used to move through the CARDS array
        //the HandRanks Array(used to get the ranks of each card)
        //the HandSuits Array(used to get the suits of each card)
        //and The HandRankValues Array(used to get the value of each rank)
        for (int index = 0; index < SIZE; index++)
        {
            cout << "Enter a card: ";
            cin >> CARDS[index];

            //While the bool Flag is false, the loop will continue to repeat 
            //this while loop is used to check for duplicate and bad cards
            //and is used to save the Ranks, Suits, and Rank value in seperate arrays
            while (Flag == false)
            {

                //The for loop is used to step through the SUITS Array
                for (int index5 = 0; index5 < SUITS; index5++)
                    {

                    //The for loop is used to step through the RANKS Array
                        for ( int index4 = 0; index4 < RANKS; index4++)
                        {

                            //If the current Card from the CARDS Array equals a combnation 
                            //of the Ranks and Suits array, then the value is saved into 
                            //the HandSuits, HandRanks, and HandRankValues Array

                            //the bool Flag is also changed to true
                            if (CARDS[index] == (Ranks[index4] + Suits[index5]))
                            {
                                HandSuits[index] = Suits[index5];
                                HandRanks[index] = Ranks[index4];
                                Flag = true;

                                //the following statments are used to determine what value
                                //HandRankValues has

                                //If HandRanks is equal to A then the value of HandRankValues is 0
                                if (HandRanks[index] == "A")
                                {
                                    HandRankValues[index] = 0;
                                }

                                //else, if HandRanks is equal to 2 then the value of HandRankValues is 1
                                else if (HandRanks[index] == "2")
                                {
                                    HandRankValues[index] = 1;
                                }

                                //else, if HandRanks is equal to 3 then the value of HandRankValues is 2
                                else if (HandRanks[index] == "3")
                                {
                                    HandRankValues[index] = 2;
                                }

                                //else, if HandRanks is equal to 4 then the value of HandRankValues is 3
                                else if (HandRanks[index] == "4")
                                {
                                    HandRankValues[index] = 3;
                                }

                                //else, if HandRanks is equal to 5 then the value of HandRankValues is 4
                                else if (HandRanks[index] == "5")
                                {
                                    HandRankValues[index] = 4;
                                }

                                //else, if HandRanks is equal to 6 then the value of HandRankValues is 5
                                else if (HandRanks[index] == "6")
                                {
                                    HandRankValues[index] = 5;
                                }

                                //else, if HandRanks is equal to 7 then the value of HandRankValues is 6
                                else if (HandRanks[index] == "7")
                                {
                                    HandRankValues[index] = 6;
                                }

                                //else, if HandRanks is equal to 8 then the value of HandRankValues is 7
                                else if (HandRanks[index] == "8")
                                {
                                    HandRankValues[index] = 7;
                                }

                                //else, if HandRanks is equal to 9 then the value of HandRankValues is 8
                                else if (HandRanks[index] == "9")
                                {
                                    HandRankValues[index] = 8;
                                }

                                //else, if HandRanks is equal to T then the value of HandRankValues is 9
                                else if (HandRanks[index] == "T")
                                {
                                    HandRankValues[index] = 9;
                                }

                                //else, if HandRanks is equal to J then the value of HandRankValues is 10
                                else if (HandRanks[index] == "J")
                                {
                                    HandRankValues[index] = 10;
                                }

                                //else, if HandRanks is equal to Q then the value of HandRankValues is 11
                                else if (HandRanks[index] == "Q")
                                {
                                    HandRankValues[index] = 11;
                                }

                                //else, if HandRanks is equal to K then the value of HandRankValues is 12
                                else if (HandRanks[index] == "K")
                                {
                                    HandRankValues[index] = 12;
                                }
                            }
                        }
                    }

                //if the bool Flag is false, then the bad card message is displayed 
                //and the user is asked to re-enter the card
                if (Flag == false)
                {
                    cout << "Bad Card. Try Again.\n";
                    cout << "Enter a card: ";
                    cin >> CARDS[index];
                }

                //the for loop checks for any duplicate cards, if there are any duplicate cards
                //an error is displayed and the user is asked to re-enter the card
                //once the card is entered the bool Flag is changed to false
                //and the entire loop will repeat to check is the card is a bad card 
                for (int index2 = 0; index2 < SIZE; index2++)
                {

                    //if the duplicate cards are equal, then the user is asked to re-enter the card
                    while (CARDS[index] == CARDS2[index2])
                    {
                        cout << "Duplicate Card. Try Again.\n";
                        cout << "Enter a card: ";
                        cin >> CARDS[index];
                        Flag = false;
                    }
                }
            }

            //the bool Flag is reset to false for the next card being entered 
            Flag = false;

            //the valuse of CARDS is saved to the CARDS2 Array
            CARDS2[index] = CARDS[index];
        }
        
        //the HandRankValues Array is sorted using a bubble sort 
        BubbleSortArray(HandRankValues);
        cout << endl;

/*---------------------------------------------------------------------------------------------

I added these block test throughout the program for a better explanation behind the algorithm 

The following for loops checks for a FOUR_OF_A_KIND or a THREE_OF_A_KIND within the given hand

-The first for loop iterates through the Ranks.
-The second for loop iterates through the values of the hand(rank numbers).
-If a value from the hand matches the ranks current position then counter is incremented by 1.
-When the counter is equal to 3, then the bool THREE_OF_A_KIND is set to true(1).
-When counter is equal to 4, then the bool FOUR_OF_A_KIND is set to true(1).

-When the second for loop ends, the counter is set to 0.
---------------------------------------------------------------------------------------------*/

        //the for loop steps through the contents of the RANKS array
        for (int index = 1; index < RANKS; index++)
        {
            counter = 0;

            //the for loop steps through the contents of the HandRanks Array
            for (int index2 = 0; index2 < 5; index2++)
            {
                //the if checks to see if the values are equal
                if (HandRanks[index2] == Ranks[index])
                {
                    counter++;
                }
            }

            //if the counter is equal to the current value, the value of the bool is changed to one (true)
            if (counter == 4)
            {
                FOUR_OF_A_KIND = 1;
            }

            //if the counter is equal to the current value, the value of the bool is changed to one (true)
            else if (counter == 3)
            {
                THREE_OF_A_KIND = 1;
            }
        }
        counter = 0;

/*___________________________________________________________________________________

I added these block test throughout the program for a better explanation behind the algorithm

The Following for loop checks for ONE or TWO PAIR(S) within the given hand

-The first for loop iterates through the ranks. 
-The second for loop iterates through the values of the hand(rank numbers).
-If a value from the hand matches the ranks current position then counter is incremented by 1.
-When the counter is equal to 2, pair is incremented by 1.
-When pair is equal to 1 then the bool for ONE_PAIR is changed to true(1).
-When pair is equal to 2 then the bool for TWO_PAIR is changed to true(1).

-When the second for loop ends, the value of counter is set to 0
-----------------------------------------------------------------------------------*/

        //the for loop steps through the contents of the RANKS array
        for (int index = 1; index < RANKS; index++)
        {

            //the for loop steps through the contents of the HandRanks Array
            for (int index2 = 0; index2 < 5; index2++)
            {

                //if the values are equal, then the counter is incremented by one
                if (HandRanks[index2] == Ranks[index])
                {
                    counter++;
                } 
            }

            //if the counter is equal to two then the counter is set to zero
            // and pairs is incremented by one
            if (counter == 2)
            {
                Pairs++;
                counter = 0;
            }

            //if Pairs is equal to one then the bool is changed to one (true)
            if (Pairs == 1)
            {
                ONE_PAIR = 1;
            }

            //if the value of Pairs is equal to two, then the bool is changed to one (true)
            else if (Pairs == 2)
            {
                TWO_PAIR = 1;
            }
            counter = 0;
        }

        counter = 0;
        Pairs = 0;

/*--------------------------------------------------------------------------------------------

I added these block test throughout the program for a better explanation behind the algorithm

The Following if statement checks to see if the hand is a FULL_HOUSE

-the for loop steps through the Ranks array
-the second for loop steps through the HandRanks array
-the if statements checks to see if the values of HandRanks and Ranks are equal
-if the statement is true then the counter is incremeneted by one
-once the for loop ends, the counter is check by two if statements to see
-if they meet the conditions for HouseFlagPair and HouseFlagThree

-if the value of HouseFlagPair is true(1) and
-if the value of HouseFlagThree is true(1)
-Then the bool FULL_HOUSE is set to true(1)

---------------------------------------------------------------------------------------------*/

        //the for loop steps through the Ranks array
        for (int index = 1; index < RANKS; index++)
        {
            counter = 0;

            //the for loop steps through the HandRanks Array
            for (int index2 = 0; index2 < 5; index2++)
            {

                //if the statement is true then the counter is incremented by one
                if (HandRanks[index2] == Ranks[index])
                {
                    counter++;
                }
            }

            //if the counter is equal to two, then the bool is changed to one(true)
            if (counter == 2)
            {
                HouseFlagPair = 1;
            }

            //if the counter is equal to three, then the bool is changed to one(true)
            if (counter == 3)
            {
                HouseFlagThree = 1;
            }

            //if both of the conditions are met, then the bool is changed to one(true)
            if (HouseFlagPair == 1 && HouseFlagThree == 1)
            {
                FULL_HOUSE = 1;
            }
            counter = 0;
        }

/*----------------------------------------------------------------------------------

I added these block test throughout the program for a better explanation behind the algorithm

The following for loop checks for a STRAIGHT within the given hand 

-The first for loop is used to house(nest) the second for loop
-The Array being used to check for the straight is the sroted values of the HandRankValues Array
-The first if statement checks to see if the hand is similar to a royal flush
-if the statement is true then the counter is incremented by one
-The second for loop moves through the values of the HandRankValues 
-Array and will increment the values (on the opposite side of the statement)
-by one after each loop
-if the statement is true then the counter is incremented by one
-if the counter is equal to one then the bool STRAIGHT is changed to one(true)

-------------------------------------------------------------------------------*/

            //the for loop is used to contain the if statement and second for loop
            for (int index = 0; index < 1; index++)
            {
                //if the statement is true then counter is incremented by one
                if (HandRankValues[0] == 0 &&
                    HandRankValues[1] == 9 &&
                    HandRankValues[2] == 10 &&
                    HandRankValues[3] == 11 &&
                    HandRankValues[4] == 12)
                {
                    counter++;
                }

                //the for loop moves throught a series of given values
                for (int index3 = 0; index3 < 10; index3++)
                {

                    //if the statement is true, then the counter is incremented by one
                    if (HandRankValues[0] == 0 + index3 &&
                        HandRankValues[1] == 1 + index3 &&
                        HandRankValues[2] == 2 + index3 &&
                        HandRankValues[3] == 3 + index3 &&
                        HandRankValues[4] == 4 + index3)
                    {
                        counter++;
                    }
                }

                //if the value of the counter is equal to one then the bool is changed to one (true)
                if (counter == 1)
                {
                    STRAIGHT = 1;
                }
            }

        counter = 0;


        //the following functions are used to check if the hand is a Flush, royal flush, or straight flush
        FLUSH = Flush(HandSuits, Suits, SUITS);
        ROYAL_FLUSH = RoyalFlush(Suits, HandSuits, HandRankValues, SUITS);
        STRAIGHT_FLUSH = StraightFlush(Suits,HandSuits, HandRankValues, SUITS);
        
        counter = 0;


        cout << "Hand: ";

        //the for loop is used to move through the contents of the CARDS array
        //and also displays the values within the CARDS array
        for (int index = 0; index < SIZE; index++)
        {

            //if the index is less than four, then the values will be printed 
            if (index < 4)
            {
                cout << CARDS[index] << " ";
            }

            //if the index is equal to four, then the last value is printed with a (:)
            else if (index == 4)
            {
                cout << CARDS[index] << ":";
            }
        }

/*-------------------------------------------------------------------------------------

The following if(and else if) statements check to see which bools are valid

-Depending on which bool is valid, some will take priority over others
-When a bool is true then a message coresponding to the bools name will be printed out

------------------------------------------------------------------------------------*/

        if ( ROYAL_FLUSH == 1)
        {
            cout << " Royal Flush" << endl;
        }
        else if (STRAIGHT_FLUSH == 1)
        {
            cout << " Straight Flush" << endl;
        }
        else if (FOUR_OF_A_KIND == 1)
        {
            cout << " Four of a Kind" << endl;
        }
        else if (FULL_HOUSE == 1)
        {
            cout << " Full House" << endl;
        }
        else if (FLUSH == 1)
        {
            cout << " Flush" << endl;
        }
        else if (STRAIGHT == 1)
        {
            cout << " Straight" << endl;
        }
        else if (THREE_OF_A_KIND == 1)
        {
            cout << " Three of a Kind" << endl;
        }
        else if (TWO_PAIR == 1)
        {
            cout << " Two Pair" << endl;
        }
        else if (ONE_PAIR == 1)
        {
            cout << " Pair" << endl;
        }
        else if (HIGH_CARD == 1)
        {
            cout << " High Card" << endl;
        }



/*-----------------------------------------------------------------------------------------------

The following statements reset the values of the bool to equal false(0)

-The bools are reset to false (0) to prepare for the next run is the user enters  another hand

----------------------------------------------------------------------------------------------*/

        ROYAL_FLUSH = 0;
        FLUSH = 0;
        FOUR_OF_A_KIND = 0;
        THREE_OF_A_KIND = 0;
        ONE_PAIR = 0;
        TWO_PAIR = 0;
        FULL_HOUSE = 0;
        STRAIGHT_FLUSH = 0;
        STRAIGHT = 0;
        HouseFlagPair = 0;
        HouseFlagThree = 0;

        //the foor loop sets the contents of CARDS2 array to zero
        //as to not mistaken any value for duplicate card
        //if the user chooses to run the program again
        for (int index = 0; index < SIZE; index++)
        {
            CARDS2[index] = "0";
        }


        cout << " " << endl;
        cout << "Run Again (Y/N): ";
        cin >> Val;

        //A while loop has been implemented to check for any invalid characters that may be entered 
        //while chosing to continue or exit the program 
        //if a value does not equal a given value for val then the while loop will 
        //continue to repeat
        while (Val != 'Y' && Val != 'y' && Val != 'N' && Val != 'n')
        {
            cout << endl;
            cout << "An Invalid Character has been entered\n";
            cout << "Please re-enter your choice\n";
            cout << endl;
            cout << "Run Again (Y/N): ";
            cin >> Val;
        }
        cout << " " << endl;



    }
    return 0;
}

/*----------------------------------------------------------------------------------------

The bubble sort array is used to sort the values of the HandRankValues in asecnding order

----------------------------------------------------------------------------------------*/

void BubbleSortArray(int HandValues[])
{
    bool swap;
    int temp;
    int ArraySize = 5;
    int size = ArraySize - 1;

    //While the bool swap is not false, the loop will continue to 
    //sort the contents of the HandValueRanks Array
    //once swap is true, then the sorting is completeed 
    do
    {
        swap = false;

        //the for loop steps through the HandRankValues(HandValues) Array
        for (int count = 0; count < size; count++)
        {

            //if the current position of the array
            //is greater than the next position,
            //then the two values are swapped
            if (HandValues[count] > HandValues[count + 1])
            {
                temp = HandValues[count];
                HandValues[count] = HandValues[count + 1];
                HandValues[count + 1] = temp;
                swap = true;
            }
        }
        size--;
    } while (swap != false);

}

/*-------------------------------------------------------------

The RoyalFlush function is used to determine if the given hand 
is a royal flush, if the hand is a royal flush,
then the value returned is a 1 (true), if else, the value
is returned as a 0 (false)

-------------------------------------------------------------*/

bool RoyalFlush(string suit[], string HandSuits[], int HandValues[], const int Suit)
{
    int counter = 0;

    //the for loop steps through the SUITS(suit) array
    for (int index = 0; index < Suit; index++)
    {

        //the for loop steps through the HandSuits Array
        for (int index2 = 0; index2 < 5; index2++)
        {

            //if a value in the HandSuits Array is equal 
            //to a value in the suit Array, then counter is incremented by one
            if (HandSuits[index2] == suit[index])
            {
                counter++;
            }
        }

        //if the value of the counter is equal to 5(checks for 5 matching suits)
        //then the HandValues are check to see if they are a royal flush
        if (counter == 5)
        {     

            //if the statement is true then the value returned is 1 (true)
            if (HandValues[0] == 0 &&           
                HandValues[1] == 9 &&           
                HandValues[2] == 10 &&            
                HandValues[3] == 11 &&           
                HandValues[4] == 12)
            {
                return 1;
            }
        }

        //the value of counter is set to 0
        counter = 0;
    }
    return 0;
}

/*-------------------------------------------------------------

The Flush function is used to determine if the given hand
is a flush, if the hand is a flush,
then the value returned is a 1 (true), if else, the value
is returned as a 0 (false)

-------------------------------------------------------------*/

bool Flush(string hand_suits[], string suit[], const int Suit)
{
int counter = 0;

    //the for loop steps through the contents of the suit array
    for (int index = 0; index < Suit; index++)
    {
        counter = 0;

        //the for loop moves through the contents of the hand_suits array
        for (int index2 = 0; index2 < 5; index2++)
        {
            //if a value in the hand_suits array is equal to a value in the suits array
            //then the counter is incremented by one
            if (hand_suits[index2] == suit[index])
            {
                counter++;
            }
        }

        //if the value of the counter is equal to five, then the value returned is one (true)
        if (counter == 5)
        {
            return 1;
        }
    }
        return 0;
}

/*----------------------------------------------------------------

The StraightFlush function is used to determine if the given hand
is a straight flush, if the hand is a straight flush,
then the value returned is a 1 (true), if else, the value
is returned as a 0 (false)

---------------------------------------------------------------*/

bool StraightFlush(string suit[], string HandSuit[], int HandValues[], const int Suit)
{
    int counter = 0;

    //the for loop steps through the SUITS(suit) array
    for (int index = 0; index < Suit; index++)
    {

        //the for loop steps through the HandSuits Array
        for (int index2 = 0; index2 < 5; index2++)
        {

            //if a value in the HandSuits Array is equal 
            //to a value in the suit Array, then counter is incremented by one
            if (HandSuits[index2] == suit[index])
            {
                counter++;
            }
        }

        //if the value of the counter is equal to 5(checks for 5 matching suits)
        //then the HandValues are check to see if they are a straight flush
        if (counter == 5)
        {

            //the for loop moves through the contents of the HandValues Array to see
            //if they are a straight flush
            for (int index3 = 0; index3 <= 9; index3++)
            {

                //if the statement is true then the value returned is 1 (true)
                if (HandValues[0] == 0 + index3 &&
                    HandValues[1] == 1 + index3 &&
                    HandValues[2] == 2 + index3 &&
                    HandValues[3] == 3 + index3 &&
                    HandValues[4] == 4 + index3)
                {
                    return 1;
                }
            }
        }
        counter = 0;
    }
    return 0;
}