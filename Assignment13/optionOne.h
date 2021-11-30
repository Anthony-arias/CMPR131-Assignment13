#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
#include "input.h"

using namespace std;

void createArray(vector<double>& temp);
void displayArray(vector<double>& temp, bool isSorted);

void performBubbleSort(vector<double>& temp);
void bubbleSort_Ascending(vector<double>& temp);
void bubbleSort_Descending(vector<double>& temp);

void performSelectionSort(vector<double>& temp);
void selectionSort_Ascending(vector<double>& temp);
void selectionSort_Descending(vector<double>& temp);

void performInsertionSort(vector<double>& temp);
void insertionSort_Ascending(vector<double>& temp);
void insertionSort_Descending(vector<double>& temp);

void performQuickSort(vector<double>& temp);
void quickSort_Ascending(vector<double>& temp, int low, int high, int& count);
int partitionAscending(vector<double>& temp, int low, int high, int& count);
void quickSort_Descending(vector<double>& temp, int low, int high, int& count);
int partitionDescending(vector<double>& temp, int low, int high, int& count);

void performMergeSort(vector<double>& temp);
void mergeSort_Ascending(vector<double>& temp, int left, int right, int& count);
void mergeAscending(vector<double>& sub_array_1, int left, int mid, int right, int& count);
void mergeSort_Descending(vector<double>& temp, int left, int right, int& count);
void mergeDescending(vector<double>& sub_array_1, int left, int mid, int right, int& count);

void performHeapSort(vector<double>& temp);
void heapSort_Ascending(vector<double>& temp, int& count);
void heapifyAscending(vector<double>& temp, int n, int i, int& count);
void heapSort_Descending(vector<double>& temp, int& count);
void heapifyDescending(vector<double>& temp, int n, int i, int& count);

// Precondition: None
// Postcondition: Asks user to input the size and initializes the vector with size amount of random double
void createArray(vector<double>& temp)
{
	int elements = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
	srand(time(0));
	double randomNumber = 0.0;
	temp.clear();

	for (int i = 0; i < elements; i++)
	{
		randomNumber = 1.0 + (double)(rand()) / ((double)(RAND_MAX / ((elements * 2.0) - 1.0)));
		temp.push_back(randomNumber);
	}

	cout << "\n\t\tDynamic array's size of " << elements << " has been created with random elements.\n";
}

// Precondition: vector is not empty
// Postcondition: Displays all vector's elements
void displayArray(vector<double>& temp, bool isSorted)
{
	if (isSorted)
	{
		int index = 0;
		cout << "\n\t\t";

		for (int i = 0; i < temp.size(); i++)
		{
			index++;
			cout << fixed << setprecision(1) << temp.at(i);
			if (index == 14)
			{
				cout << "\n\t\t";
				index = 0;
			}
			else if (i == temp.size() - 1)
				break;
			else
				cout << ", ";
		}
		cout << "\n";
	}
	else
	{
		int index = 0;

		cout << "\n\t\tUnsorted dynamic array:\n";
		cout << "\n\t\t";

		for (int i = 0; i < temp.size(); i++)
		{

			index++;

			cout << fixed << setprecision(1) << temp.at(i);

			if (index == 14)
			{
				cout << "\n\t\t";
				index = 0;
			}
			else if (i == temp.size() - 1)
				break;
			else
				cout << ", ";
		}
		cout << "\n";
	}

}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to bubble sort the array in ascending or descending order
void performBubbleSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		cout << "\n\t\tBubbleSort:";

		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A': bubbleSort_Ascending(temp);
			break;
		case 'D': bubbleSort_Descending(temp);
			break;
		}
	}

}

// Precondition: Array is not empty
// Postcondition: Bubble sorts the dynamic array in ascending order
void bubbleSort_Ascending(vector<double>& temp)
{
	int count = 0;

	for (int i = 0; i < temp.size() - 1; i++)
	{
		for (int j = 0; j < temp.size() - i - 1; j++)
		{
			if (temp[j] > temp[j + 1])
			{
				swap(temp[j], temp[j + 1]);
				count++;
			}
			count++;
		}
	}
	cout << "\n\t\tAscending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;

}

// Precondition: Array is not empty
// Postcondition: Bubble sorts the dynamic array in descending order
void bubbleSort_Descending(vector<double>& temp)
{
	int count = 0;

	for (int i = 0; i < temp.size() - 1; i++)
	{
		for (int j = 0; j < temp.size() - i - 1; j++)
		{
			if (temp[j] < temp[j + 1])
			{
				swap(temp[j], temp[j + 1]);
				count++;
			}
			count++;
		}
	}
	cout << "\n\t\tDescending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to selection sort the array in ascending or descending order
void performSelectionSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		cout << "\n\t\tSelectionSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A': selectionSort_Ascending(temp);
			break;
		case 'D': selectionSort_Descending(temp);
			break;
		}
	}

}

// Precondition: Array is not empty
// Postcondition: Selection sorts the dynamic array in ascending order
void selectionSort_Ascending(vector<double>& temp)
{
	int count = 0;

	for (int k = 0; k < temp.size() - 1; k++)
	{
		int min_index = k;
		for (int i = k + 1; i < temp.size(); i++)
		{
			if (temp[i] < temp[min_index])
			{
				min_index = i;
				count++;
			}
		}
		count++;
		swap(temp[k], temp[min_index]);
	}

	cout << "\n\t\tAscending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;
	
}

// Precondition: Array is not empty
// Postcondition: Selection sorts the dynamic array in descending order
void selectionSort_Descending(vector<double>& temp)
{
	int count = 0;

	for (int k = 0; k < temp.size() - 1; k++)
	{
		int min_index = k;
		for (int i = k + 1; i < temp.size(); i++)
		{
			if (temp[i] > temp[min_index])
			{
				min_index = i;
				count++;
			}
		}
		count++;
		swap(temp[k], temp[min_index]);
	}

	cout << "\n\t\tDescending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to insertion sort the array in ascending or descending order
void performInsertionSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		cout << "\n\t\tInsertionSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A': insertionSort_Ascending(temp);
			break;
		case 'D': insertionSort_Descending(temp);
			break;
		}
	}

}

// Precondition: Array is not empty
// Postcondition: Insertion sorts the dynamic array in ascending order
void insertionSort_Ascending(vector<double>& temp)
{
	int count = 0;
	int key, index;

	for (int i = 1; i < temp.size(); i++)
	{
		key = temp[i];
		index = i - 1;

		while (index >= 0 && temp[index] > key)
		{
			temp[index + 1] = temp[index];
			index--;
			count++;
		}
		temp[index + 1] = key;
		count++;
	}
	cout << "\n\t\tAscending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;
}

// Precondition: Array is not empty
// Postcondition: Insertion sorts the dynamic array in descending order
void insertionSort_Descending(vector<double>& temp)
{
	int count = 0;
	int key, index;

	for (int i = 1; i < temp.size(); i++)
	{
		key = temp[i];
		index = i - 1;

		while (index >= 0 && temp[index] < key)
		{
			temp[index + 1] = temp[index];
			index--;
			count++;
		}

		temp[index + 1] = key;
		count++;
	}
	cout << "\n\t\tDescending:\n";
	displayArray(temp, true);
	cout << "\n\t\tNumber of swapping routines = " << count;
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to quick sort the array in ascending or descending order
void performQuickSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		int count = 0;
		cout << "\n\t\tQuickSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A':
			quickSort_Ascending(temp, 0, temp.size() - 1, count);
			cout << "\n\t\tAscending:\n";
			displayArray(temp, true);
			cout << "\n\t\tNumber of swapping routines = " << count;
			break;
		case 'D':
			quickSort_Descending(temp, 0, temp.size() - 1, count);
			cout << "\n\t\tDescending:\n";
			displayArray(temp, true);
			cout << "\n\t\tNumber of swapping routines = " << count;
			break;
		}
	}
	
}

// Precondition: Array is not empty
// Postcondition: Quick sorts the dynamic array in ascending order
void quickSort_Ascending(vector<double>& temp, int low, int high, int& count)
{
	if (low < high)
	{
		int index = partitionAscending(temp, low, high, count);

		quickSort_Ascending(temp, low, index - 1, count);
		quickSort_Ascending(temp, index + 1, high, count);
	}
}

// Precondition: low and high are within the range of the array
// Postcondition: Splits the array into a smaller partition, takes last element as pivot, places the pivot element at
//	its correct position in sorted array, and places all smaller to left of pivot and all greater elements to right of pivot
int partitionAscending(vector<double>& temp, int low, int high, int& count)
{
	double pivot = temp[high]; // pivot
	int index = (low - 1); // small index

	for (int j = low; j <= high - 1; j++)
	{
		// if current element is smaller than pivot
		if (temp[j] < pivot)
		{
			index++;
			swap(temp[index], temp[j]);
			count++;
		}
		
	}
	swap(temp[index + 1], temp[high]);
	return (index + 1);
}

// Precondition: Array is not empty
// Postcondition: Quick sorts the dynamic array in descending order
void quickSort_Descending(vector<double>& temp, int low, int high, int& count)
{
	if (low < high)
	{
		int index = partitionDescending(temp, low, high, count);

		quickSort_Descending(temp, low, index - 1, count);
		quickSort_Descending(temp, index + 1, high, count);
	}
}

// Precondition: low and high are within the range of the array
// Postcondition: Splits the array into a smaller partition, takes last element as pivot, places the pivot element at
//	its correct position in sorted array, and places all greater to left of pivot and all smaller elements to right of pivot
int partitionDescending(vector<double>& temp, int low, int high, int& count)
{
	double pivot = temp[high]; // pivot
	int index = (low - 1); // small index

	for (int j = low; j <= high - 1; j++)
	{
		// if current element is greater than pivot
		if (temp[j] > pivot)
		{
			index++;
			swap(temp[index], temp[j]);
			count++;
		}
		
	}
	swap(temp[index + 1], temp[high]);
	return (index + 1);
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to merge sort the array in ascending or descending order
void performMergeSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		int count = 0;
		cout << "\n\t\tMergeSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A':
			mergeSort_Ascending(temp, 0, temp.size() - 1, count);
			cout << "\n\t\tAscending:\n";
			displayArray(temp, true);
			cout << "\n\t\tnumber of swapping routines = " << count;
			
			break;
		case 'D':
			mergeSort_Descending(temp, 0, temp.size() - 1, count);
			cout << "\n\t\tDescending:\n";
			displayArray(temp, true);
			cout << "\n\t\tnumber of swapping routines = " << count;
			
			break;
		}
	}
	
}

// Precondition: Array is not empty
// Postcondition: Merge sorts the dynamic array in ascending order
void mergeSort_Ascending(vector<double>& temp, int left, int right, int& count)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort_Ascending(temp, left, mid, count);
	mergeSort_Ascending(temp, mid + 1, right, count);
	mergeAscending(temp, left, mid, right, count);
}

// Precondition: sub_array_2[left..mid] and sub_array_2[mid+1..right] are sorted in ascending order
// Postcondition: Merges the two sorted sub-arrays into one
void mergeAscending(vector<double>& sub_array_1, int left, int mid, int right, int& count)
{
	vector<double> sub_array_2;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (sub_array_1[i] <= sub_array_1[j])
		{
			sub_array_2.push_back(sub_array_1[i]);
			i++;
		}
		else
		{
			sub_array_2.push_back(sub_array_1[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		sub_array_2.push_back(sub_array_1[i]);
		i++;
	}

	while (j <= right)
	{
		sub_array_2.push_back(sub_array_1[j]);
		j++;
	}

	for (int i = left; i <= right; ++i)
	{
		sub_array_1[i] = sub_array_2[i - left];
		count++;
	}
}

// Precondition: Array is not empty
// Postcondition: Merge sorts the dynamic array in descending order
void mergeSort_Descending(vector<double>& temp, int left, int right, int& count)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort_Descending(temp, left, mid, count);
	mergeSort_Descending(temp, mid + 1, right, count);
	mergeDescending(temp, left, mid, right, count);
}

// Precondition: sub_array_2[left..mid] and sub_array_2[mid+1..right] are sorted in descending order
// Postcondition: Merges the two sorted sub-arrays into one
void mergeDescending(vector<double>& sub_array_1, int left, int mid, int right, int& count)
{
	vector<double> sub_array_2;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (sub_array_1[i] > sub_array_1[j])
		{
			sub_array_2.push_back(sub_array_1[i]);
			i++;
		}
		else
		{
			sub_array_2.push_back(sub_array_1[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		sub_array_2.push_back(sub_array_1[i]);
		i++;
	}

	while (j <= right)
	{
		sub_array_2.push_back(sub_array_1[j]);
		j++;
	}

	for (int i = left; i <= right; ++i)
	{
		sub_array_1[i] = sub_array_2[i - left];
		count++;
	}
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to heap sort the array in ascending or descending order
void performHeapSort(vector<double>& temp)
{
	if (temp.empty())
	{
		cout << "\n\t\tThe dynamic array is empty\n";
	}
	else
	{
		int count = 0;

		cout << "\n\t\tHeapSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)scending or (D)escending order: ", "AD");

		switch (toupper(sorting))
		{
		case 'A':
			heapSort_Ascending(temp, count);
			cout << "\n\t\tAscending:\n";
			displayArray(temp, true);
			cout << "\n\t\tNumber of swapping routines = " << count;

			break;
		case 'D':
			heapSort_Descending(temp, count);
			cout << "\n\t\tDescending:\n";
			displayArray(temp, true);
			cout << "\n\t\tNumber of swapping routines = " << count;
			
			break;
		}
	}
	
}

// Precondition: Array is not empty
// Postcondition: Heap sorts the dynamic array in ascending order
void heapSort_Ascending(vector<double>& temp, int& count)
{
	int n = temp.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyAscending(temp, n, i, count);

	for (int i = n - 1; i > 0; i--)
	{
		swap(temp[0], temp[i]);
		count++;
		heapifyAscending(temp, i, 0, count);
	}
}

// Precondition: n is the size of the heap, i is an index in temp
// Postcondition: Swapping node i to the correct location, with largest be the parent root
void heapifyAscending(vector<double>& temp, int n, int i, int& count)
{
	//n is size of heap, i is root
	int largest = i;
	int left = 2 * i + 1; // left = 2*i + 1
	int right = 2 * i + 2; // right = 2*i + 2

	if (left < n && temp[left] > temp[largest])
		largest = left;

	if (right < n && temp[right] > temp[largest])
		largest = right;

	//if largest not root
	if (largest != i)
	{
		swap(temp[i], temp[largest]);
		count++;
		heapifyAscending(temp, n, largest, count);
	}
}

// Precondition: Array is not empty
// Postcondition: Heap sorts the dynamic array in descending order
void heapSort_Descending(vector<double>& temp, int& count)
{
	int n = temp.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyDescending(temp, n, i, count);

	for (int i = n - 1; i > 0; i--)
	{
		swap(temp[0], temp[i]);
		count++;
		heapifyDescending(temp, i, 0, count);
	}
}

// Precondition: n is the size of the heap, i is an index in temp
// Postcondition: Swapping node i to the correct location, with smallest be the parent root
void heapifyDescending(vector<double>& temp, int n, int i, int& count)
{
	//n is size of heap, i is root
	int smallest = i;
	int left = 2 * i + 1; // left = 2*i + 1
	int right = 2 * i + 2; // right = 2*i + 2

	if (left < n && temp[left] < temp[smallest])
	{
		smallest = left;
	}

	if (right < n && temp[right] < temp[smallest])
	{
		smallest = right;
	}

	//if smallest not root
	if (smallest != i)
	{
		swap(temp[i], temp[smallest]);
		count++;
		heapifyDescending(temp, n, smallest, count);
	}
}




