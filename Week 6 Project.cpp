/*
Noah Yacoub
ITCS 2530
11/29/21
Week 6 - Project

Write a program to calculate a bowling league's average bowling scores. You will need to read the input data from the file BowlingScores.txt  Download BowlingScores.txt. Note: The file format is guaranteed to remain the same.

You must use three arrays:
a one-dimensional array to store the bowler's names.
a (parallel) two-dimensional array to store the bowling scores.
a one-dimensional array to store the bowler's average score.
Your program must contain at least the following functions:
a function called GetBowlingData to read and store data into two arrays. The function should take as input parameters the file name and both empty arrays, which it should fill from the file (BowlingScores.txt  Download BowlingScores.txt) and return a status of either success or failure (i.e. true or false).
a function called GetAverageScore that is used to calculate the average bowling score. The function should take as input the populated arrays and return the average score of each bowler in a separate array.
a function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.
Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.
Use repetition structures (loops) in your functions to perform calculations and printing. Remember "dimensions = loops". So, a 2-dimensional array will require 2 loops to completely iterate over all of the elements in the array.
Don't use magic numbers. Instead use global constants at the top of the program under the includes.
And as always include lots of meaningful comments so that I can follow your logic and know that you understand the program you wrote.
*/

#include <iostream>
//adds format manipulators
#include <iomanip>
//includes to_string()
#include <string>
//allows for transforming strings to uppercase easily
#include <algorithm>
//allows input file
#include <fstream>
//allows us to break up
#include <sstream>
using namespace std;

//define functions
int GetBowlingData(int argc, char* argv[]);
void GetAverageScore();
void PrettyPrintResults();

//constant variables
const int rounds_per_game = 5; //meaning 4 rounds
const int player_count = 10; //meaning 10 players max

//arrays
string BowlerNames[player_count];
int BowlerScores[player_count][rounds_per_game];
double BowlerAvScores[player_count];


int main(int argc, char* argv[])
{
    if (argc < 2) //arguement count check
    {
        cout << "Error with input agrs.." << endl;
        return false;
    }

    GetBowlingData(argc, argv);
    GetAverageScore();
    PrettyPrintResults();

    return 0;
}


//takes inputs of filename, and two empty arrays
int GetBowlingData(int argc, char* argv[])
{
    //inputs we will take from argv[1]
    string name;
    int round[rounds_per_game];

    //counting variables
    int bowlerCount;
    double temp_bowlerfulltotal;
    double bowleravg;

    ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile) //file check 
    {
        cout << "Error with wrong file name!" << endl;
        return false;
    }

    while (!inputFile.eof())
    {
        bowlerCount = 0;
        //limits format to name followed by 4 scores exactly
        while (inputFile >> name >> round[0] >> round[1] >> round[2] >> round[3] >> round[4])
        {
            //stores bowler name to array
            BowlerNames[bowlerCount] = name;

            //resets full total for each player to zero
            temp_bowlerfulltotal = 0;
            for (int i = 0; i < rounds_per_game; i++)
            {
                //sets up BowlerScores and stores bowlerCount ID with score for each individual round 
                BowlerScores[bowlerCount][i] = round[i];

                //adds up rounds together for use later, stores the current bowlers full total pins
                temp_bowlerfulltotal += round[i];
            }

            //calculates bowler average score
            bowleravg = temp_bowlerfulltotal / rounds_per_game;
            //stores bowler score in double array
            BowlerAvScores[bowlerCount] = bowleravg;

            //sets bowlerCounter to next number, as we are done and will work on next bowlers data
            bowlerCount++;
        }
    }
    inputFile.close();
    return true; 
}

void GetAverageScore()
{
    //prints bowler average scores
    cout << "Bowler average scores" << endl;
    for (int y = 0; y < player_count; y++)
    {
        cout << BowlerAvScores[y] << endl;
    }
    cout << endl;
}

void PrettyPrintResults()
{
    //prints bowler names
    cout << "Bowler names" << endl;
    for (int x = 0; x < player_count; x++)
    {
        cout << BowlerNames[x] << endl;
    }
    cout << endl;

    //prints bowler scores
    for (int x = 0; x < player_count; x++)
    {
        cout << "bowler " << x << "'s scores" << endl;
        for (int x2 = 0; x2 < rounds_per_game; x2++)
        {
            cout << BowlerScores[x][x2] << endl;
        }
    }
    cout << endl;
}

/* UNUSED CODE
    lots of various debugging lines, some were helpful some were not
    //string line;
    //getline(inputFile, line);
    //cout << line;
    //inputFile.get(x);
    //getline(inputFile, stringinput, ' ');

    //for(i=0;i%5=0;i++)

    //getline(inputFile, stringinput);
    //cout << stringinput << endl;

    //cout << x;

    //int round1, round2, round3, round4;
    //cout << '\n' << name << endl;

    //cout << bowlerCount;
    //cout << name << " " << round1 << " " << round2 << " " << round3 << " " << round4 << '\n' << endl;

    /////cout << BowlerNames[bowlerCount] << " ";

    //cout << sizeof(BowlerScores) << endl;

    //
    //BowlerScores[bowlerCount][0] = round1;
    //BowlerScores[bowlerCount][1] = round2;
    //BowlerScores[bowlerCount][2] = round3;
    //BowlerScores[bowlerCount][3] = round4;

    //cout << "adding..." << temp_bowlerfulltotal << endl;
    //cout << "added: " << temp_bowlerfulltotal << endl;
    //cout << name;

    /*
    //prints bowler names
    cout << "Bowler names" << endl;
    for (int x = 0; x < player_count; x++)
    {
        cout << BowlerNames[x] << endl;
    }
    cout << endl;

    //prints bowler scores
    for (int x = 0; x < player_count; x++)
    {
        cout << "bowler " << x << "'s scores" << endl;
        for (int x2 = 0; x2 < rounds_per_game; x2++)
        {
            cout << BowlerScores[x][x2] << endl;
        }
    }
    cout << endl;

    //prints bowler average scores
    cout << "bowler average scores" << endl;
    for (int y = 0; y < player_count; y++)
    {
        cout << BowlerAvScores[y] << endl;
    }
    cout << endl;
*/