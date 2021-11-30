// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 12: 
// 10/7/2021

#include <iostream>
#include <string>
#include "input.h"
#include "optionOne.h"
#include "optionTwo.h"

void programOne(void);
void programTwo(void);

using namespace std;

//PreCondition: NA
//PostCondition: Main function
int main(void)
{
    do
    {
        clearScreen();

        cout << "\n\tCMPR131 Chapter 13: Sortings by Anthony, An, Van, Vincent, Nhan (12/2/21)" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        cout << "\t\t1> Sorting simulations" << endl;
        cout << "\t\t2> Application of student records" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        cout << "\t\t0> exit" << endl;
        cout << "\t" + string(100, char(205)) << endl;

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: exit(1); break;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..2." << endl;
        }

    } while (true);
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: 
void programOne(void)
{
    do
    {
        clearScreen();

        cout << "\n\t1> Sort simulations" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        cout << "\t\tA> Create a dynamic array and fill with random elements" << endl;
        cout << "\t\tB> Display the unsorted array" << endl;
        cout << "\t\tC> Perform BubbleSort" << endl;
        cout << "\t\tD> Perform SelectionSort" << endl;
        cout << "\t\tE> Perform InsertionSort" << endl;
        cout << "\t\tF> Perform QuickSort" << endl;
        cout << "\t\tG> Perform MergeSort" << endl;
        cout << "\t\tH> Perform HeapSort" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        cout << "\t\t0> return" << endl;
        cout << "\t" + string(100, char(205)) << endl;

        int option = inputChar("\t\tOption: ");


        switch (option)
        {
        case '0': return;
        case 'A': /*funciton here*/ break;
        case 'B': /*funciton here*/ break;
        case 'C': /*funciton here*/ break;
        case 'D': /*funciton here*/ break;
        case 'E': /*funciton here*/ break;
        case 'F': /*funciton here*/ break;
        case 'G': /*funciton here*/ break;
        case 'H': /*funciton here*/ break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G', or 'H'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    do
    {
        clearScreen();

        cout << "\n\t2> Application of sorting student records" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        cout << "\t\tA> Read in data file" << endl;
        cout << "\t\tB> Display records" << endl;
        cout << "\t\tC> Insert a record" << endl;
        cout << "\t\tD> remove a record" << endl;
        cout << "\t\tE> Sort records by ID, name, major or GPA" << endl;
        cout << "\t\tF> Write out data file" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        cout << "\t\t0> return" << endl;
        cout << "\t" + string(100, char(205)) << endl;

        int option = inputChar("\t\tOption: ");


        switch (option)
        {
        case '0': return;
        case 'A': /*funciton here*/ break;
        case 'B': /*funciton here*/ break;
        case 'C': /*funciton here*/ break;
        case 'D': /*funciton here*/ break;
        case 'E': /*funciton here*/ break;
        case 'F': /*funciton here*/ break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E', or 'F'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}

