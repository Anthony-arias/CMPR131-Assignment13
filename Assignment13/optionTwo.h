// optionTwo.h
// Team: Anthony, An, Van, Vincent, Nhan

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "input.h"
#include "Student.h"

using namespace std;

void IdInsertionSort(vector<Student>& studentList, bool ascending );
void NameInsertionSort(vector<Student>& studentList, bool ascending );
void MajorInsertionSort(vector<Student>& studentList, bool ascending );
void GpaInsertionSort(vector<Student>& studentList, bool ascending );

//PreCondition: input Student vector
//PostCondition: reads student records from file and inserts records in to vector
void readFromFile(vector<Student>& studentList)
{
    studentList.clear();
    ifstream source;
    source.open("Students.dat");
    if (source.fail())
    {
        cout << "\n\t\tERROR: file, students.dat, cannot be found.";
        return;
    }

    while (true)
    {
        string line;
        getline(source, line);
        if (source.fail()) break;

        stringstream stream(line);
        int counter = 1;
        Student newStudent;
        while (stream.good()) {
            string substr;
            getline(stream, substr, ',');
            if (counter == 1) 
                newStudent.setId(stoi(substr));
            else if (counter == 2) 
                newStudent.setFullName(substr);
            else if (counter == 3) 
                newStudent.setMajor(substr);
            else 
                newStudent.setGpa(stof(substr));

            counter++;
        }
        studentList.push_back(newStudent);
    }
    cout << "\n\t\tData have been read from students.dat.";
}

//PreCondition: input Student vector
//PostCondition: writes student records in to .dat file
void writeToFile(vector<Student> studentList)
{
    if (studentList.empty())
    {
        cout << "\n\t\tERROR: No student records found.";
        return;
    }
    
    ofstream myfile("Students.dat");
    if (myfile.is_open())
    {
        int size = studentList.size() - 1;
        for (int i = 0; i < size; i++)
        {
            myfile << studentList[i].getId() << "," << studentList[i].getFullName()
                << "," << studentList[i].getMajor() << "," << studentList[i].getGpa() << endl;
        }
        myfile << studentList[size].getId() << "," << studentList[size].getFullName()
            << "," << studentList[size].getMajor() << "," << studentList[size].getGpa();
        cout << "\n\t\tData have been saved to " << fileName << ".";
        myfile.close();
    }
    else cout << "\n\t\tERROR: Unable to open file.";
}

//PreCondition: input Student vector
//PostCondition: display student records from vector
void displayRecords(vector<Student> studentList)
{
    if (studentList.empty())
    {
        cout << "\n\t\tERROR: No student records found.";
        return;
    }

    cout << "\n\t\tStudent records:" << endl;
    cout << "\t\t";
    cout.width(6); cout << right << "ID";
    cout.width(25); cout << right << "Name";
    cout.width(25); cout << right << "Major";
    cout << "\t" << "GPA" << endl;
    cout << "\t\t" << string(70, char(196)) << endl;
    for (int i = 0; i < studentList.size(); i++)
    {
        cout << "\t\t";
        cout.width(6); cout << right << studentList[i].getId();
        cout.width(25); cout << right << studentList[i].getFullName();
        cout.width(25); cout << right << studentList[i].getMajor();
        cout << "\t" << studentList[i].getGpa() << endl;
    }
}

//PreCondition: input Student vector
//PostCondition: insert student record in to vector
void insertRecord(vector<Student>& studentList)
{
    int _id = inputInteger("\n\t\tEnter a new student ID: ", true);
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].getId() == _id)
        {
            cout << "\n\t\tError: Student already exists in student records.";
            return;
        }
    }
    string _name = inputString("\t\tEnter the student's name: ", true);
    string _major = inputString("\t\tEnter the student's major: ", true);
    float _gpa = inputDouble("\t\tEnter the student's GPA: ", 0, 4.0);

    Student newStudent(_id, _name, _major, _gpa);

    studentList.push_back(newStudent);
}

//PreCondition: input Student vector
//PostCondition: removes student record from vector
void removeRecord(vector<Student>& studentList)
{
    if (studentList.empty())
    {
        cout << "\n\t\tERROR: No student records found.";
        return;
    }

    string _name = inputString("\t\tEnter a student's name to remove: ", true);

    int index = -1;
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].getFullName() == _name)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "\n\t\tThe student record cannot be found to be removed.";
    }
    else
    {
        studentList.erase(studentList.begin() + index);
        cout << "\n\t\tThe student record has been removed.";
    }
}

//PreCondition: input Student vector
//PostCondition: allow user to select type of sort
void sortRecords(vector<Student>& studentList)
{
    if (studentList.empty())
    {
        cout << "\n\t\tERROR: No student records found.";
        return;
    }

    cout << endl;
    while (true)
    {
        char input = inputChar("\t\tChoose sort in (A)-ascending or (D)-descending order: ");
        if (toupper(input) == 'A')
        {
            while (true)
            {
                input = inputChar("\t\tChoose by (I)-ID, (N)-name, (M)-major or (G)-GPA: ");
                switch (toupper(input))
                {
                case 'I': IdInsertionSort(studentList, true); return;
                case 'N': NameInsertionSort(studentList, true); return;
                case 'M': MajorInsertionSort(studentList, true); return;
                case 'G': GpaInsertionSort(studentList, true); return;
                default:
                    cout << "\n\t\tERROR-1A: Invalid input. Must be 'I','N','M', or 'G'." << endl;
                }
            }
            break;
        }
        else if (toupper(input) == 'D')
        {
            while (true)
            {
                input = inputChar("\t\tChoose by (I)-ID, (N)-name, (M)-major or (G)-GPA: ");
                switch (toupper(input))
                {
                case 'I': IdInsertionSort(studentList, false); return;
                case 'N': NameInsertionSort(studentList, false); return;
                case 'M': MajorInsertionSort(studentList, false); return;
                case 'G': GpaInsertionSort(studentList, false); return;
                default:
                    cout << "\n\t\tERROR-1A: Invalid input. Must be 'I','N','M', or 'G'." << endl;
                }
            }
            break;
        }
        else cout << "\n\t\tERROR-1A: Invalid input. Must be 'A', or 'D'." << endl;
    }    
}

//PreCondition: input Student vector
//PostCondition: Insertion sorts student records based on student id
void IdInsertionSort(vector<Student>& studentList, bool ascending )
{
    vector<Student> temp = studentList;

    int count = 0;
    int index;
    Student key;

    for (int i = 1; i < temp.size(); i++)
    {
        key = temp[i];
        index = i - 1;

        if (ascending)
        {
            while (index >= 0 && temp[index].getId() > key.getId())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }
        else
        {
            while (index >= 0 && temp[index].getId() < key.getId())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }        

        temp[index + 1] = key;
        count++;
    }
    if (ascending) cout << "\n\t\tAscending order:" << endl;
    else cout << "\n\t\tDescending order:" << endl;
    displayRecords(temp);
    cout << "\n\t\tNumber of swapping routines = " << count;
}

//PreCondition: input Student vector
//PostCondition: Insertion sorts student records based on student name
void NameInsertionSort(vector<Student>& studentList, bool ascending )
{
    vector<Student> temp = studentList;

    int count = 0;
    int index;
    Student key;

    for (int i = 1; i < temp.size(); i++)
    {
        key = temp[i];
        index = i - 1;

        if (ascending)
        {
            while (index >= 0 && temp[index].getFullName() > key.getFullName())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }
        else
        {
            while (index >= 0 && temp[index].getFullName() < key.getFullName())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }


        temp[index + 1] = key;
        count++;
    }
    if (ascending) 
        cout << "\n\t\tAscending order:" << endl;
    else 
        cout << "\n\t\tDescending order:" << endl;
    displayRecords(temp);
    cout << "\n\t\tNumber of swapping routines = " << count;
}

//PreCondition: input Student vector
//PostCondition: Insertion sorts student records based on student major
void MajorInsertionSort(vector<Student>& studentList, bool ascending )
{
    vector<Student> temp = studentList;

    int count = 0;
    int index;
    Student key;

    for (int i = 1; i < temp.size(); i++)
    {
        key = temp[i];
        index = i - 1;

        if (ascending)
        {
            while (index >= 0 && temp[index].getMajor() > key.getMajor())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }
        else
        {
            while (index >= 0 && temp[index].getMajor() < key.getMajor())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }

        temp[index + 1] = key;
        count++;
    }
    if (ascending) 
        cout << "\n\t\tAscending order:" << endl;
    else 
        cout << "\n\t\tDescending order:" << endl;
    displayRecords(temp);
    cout << "\n\t\tNumber of swapping routines = " << count;
}

//PreCondition: input Student vector
//PostCondition: Insertion sorts student records based on student gpa
void GpaInsertionSort(vector<Student>& studentList, bool ascending )
{
    vector<Student> temp = studentList;

    int count = 0;
    int index;
    Student key;

    for (int i = 1; i < temp.size(); i++)
    {
        key = temp[i];
        index = i - 1;

        if (ascending)
        {
            while (index >= 0 && temp[index].getGpa() > key.getGpa())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }
        else
        {
            while (index >= 0 && temp[index].getGpa() < key.getGpa())
            {
                temp[index + 1] = temp[index];
                index--;
                count++;
            }
        }

        temp[index + 1] = key;
        count++;
    }
    if (ascending) 
        cout << "\n\t\tAscending order:" << endl;
    else 
        cout << "\n\t\tDescending order:" << endl;
    displayRecords(temp);
    cout << "\n\t\tNumber of swapping routines = " << count;
}

#endif
