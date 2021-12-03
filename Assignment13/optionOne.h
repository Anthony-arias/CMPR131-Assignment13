#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
#include "input.h"

using namespace std;


// Precondition: None
// Postcondition: Asks user to input the size and initializes the vector with size amount of random double
void createArray(vector<double>& vector)
{
	int elements = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
	srand(time(0));
	double randomNumber = 0.0;
	vector.clear();

	for (int i = 0; i < elements; i++)
	{
		randomNumber = 1.0 + (double)(rand()) / ((double)(RAND_MAX / ((elements * 2.0) - 1.0)));
		vector.push_back(randomNumber);
	}

	cout << "\n\t\tDynamic array's size of " << elements << " has been created with random elements." << endl;
}




// Precondition: vector is not empty
// Postcondition: Displays all vector's elements
void displayArray(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{

		int size = vector.size() - 1;
		cout << "\n\t\t";
		for (int i = 0; i < size; i++)
			cout << fixed << setprecision(1) << vector[i] << ", ";
		cout << fixed << setprecision(1) << vector[size];
	}
	cout << endl;
}

// Precondition: vector is not empty
// Postcondition: Displays all vector's elements
void unsortedArray(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		cout << "\n\t\tUnsorted dynamic array:" << endl;
		displayArray(vector);
	}
}

// Precondition: Array is not empty
// Postcondition: Bubble sorts the dynamic array in ascending order
void bubbleSort_Ascending(vector<double> &vector, int arraySize, int& count)
{
	if (arraySize == 1)
		return;

	for (int i = 0; i < arraySize - 1; i++)
	{
		if (vector[i] > vector[i + 1])
		{
			swap(vector[i], vector[i + 1]);
			count++;
		}
		count++;
	}

	bubbleSort_Ascending(vector, arraySize - 1, count);
}

// Precondition: Array is not empty
// Postcondition: Bubble sorts the dynamic array in descending order
void bubbleSort_Descending(vector<double> &vector, int arraySize, int& count)
{
	if (arraySize == 1)
		return;

	for (int i = 0; i < arraySize - 1; i++)
	{
		if (vector[i] < vector[i + 1])
		{
			swap(vector[i], vector[i + 1]);
			count++;
		}
		count++;
	}

	bubbleSort_Descending(vector, arraySize - 1, count);
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to bubble sort the array in ascending or descending order
void performBubbleSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{

		int count = 0;
		cout << "\n\t\tBubbleSort:";

		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A','D');

		if (toupper(sorting) == 'A')
		{
			bubbleSort_Ascending(vector, vector.size(), count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		
		else
		{
			bubbleSort_Descending(vector, vector.size(), count);
			cout << "\n\t\tDescending:\n";
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}

}

// Precondition: NA
// Postcondition: Return minimum index
int minIndex(vector<double> vector, int i, int j, int& count)
{
	if (i == j)
		return i;
	count++;
	int k = minIndex(vector, i + 1, j, count);
	if (vector[i] < vector[k])
		return i;
	else
		return k;
}

// Precondition: NA
// Postcondition: Return maximum index
int maxIndex(vector<double> vector, int i, int j, int& count)
{
	if (i == j)
		return i;
	count++;
	int k = maxIndex(vector, i + 1, j, count);
	if (vector[i] > vector[k])
		return i;
	else
		return k;
}

// Precondition: Array is not empty
// Postcondition: Selection sorts the dynamic array in ascending order
void selectionSort_Ascending(vector<double>& vector, int arraySize, int index, int& count)
{
	if (index == arraySize)
		return;

	int k = minIndex(vector, index, arraySize - 1, count);

	if (k != index)
	{
		swap(vector[k], vector[index]);
		count++;
	}

	selectionSort_Ascending(vector, arraySize, index + 1, count);
}


// Precondition: Array is not empty
// Postcondition: Selection sorts the dynamic array in descending order
void selectionSort_Descending(vector<double>& vector, int arraySize, int index, int& count)
{
	if (index == arraySize)
		return;

	int k = maxIndex(vector, index, arraySize - 1, count);

	if (k != index)
	{
		swap(vector[k], vector[index]);
		count++;
	}

	selectionSort_Descending(vector, arraySize, index + 1, count);
}


// Precondition: Array is not empty
// Postcondition: Asks user to either choose to selection sort the array in ascending or descending order
void performSelectionSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		int count = 0;
		cout << "\n\t\tSelectionSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A','D');

		if (toupper(sorting) == 'A')
		{
			selectionSort_Ascending(vector, vector.size(), 0, count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		else
		{
			selectionSort_Descending(vector, vector.size(), 0, count);
			cout << "\n\t\tDescending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}

}

// Precondition: Array is not empty
// Postcondition: Insertion sorts the dynamic array in ascending order
void insertionSort_Ascending(vector<double>& vector, int arraySize, int& count)
{
	if (arraySize <= 1)
		return;

	insertionSort_Ascending(vector, arraySize - 1, ++count);
	double key = vector[arraySize - 1];
	int index = arraySize - 2;

	while (index >= 0 && vector[index] > key)
	{
		vector[index + 1] = vector[index];
		index--;
		count++;
	}
	vector[index + 1] = key;
}

// Precondition: Array is not empty
// Postcondition: Insertion sorts the dynamic array in descending order
void insertionSort_Descending(vector<double>& vector, int arraySize, int& count)
{

	if (arraySize <= 1)
		return;

	insertionSort_Descending(vector, arraySize - 1, ++count);
	double key = vector[arraySize - 1];
	int index = arraySize - 2;

	while (index >= 0 && vector[index] < key)
	{
		vector[index + 1] = vector[index];
		index--;
		count++;
	}
	vector[index + 1] = key;

}
// Precondition: Array is not empty
// Postcondition: Asks user to either choose to insertion sort the array in ascending or descending order
void performInsertionSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		int count = 0;
		cout << "\n\t\tInsertionSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A','D');
		if (toupper(sorting) == 'A')
		{
			insertionSort_Ascending(vector, vector.size(), count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		else
		{ 
			insertionSort_Descending(vector, vector.size(), count);
			cout << "\n\t\tDescending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}

}

// Precondition: low and high are within the range of the array
// Postcondition: Splits the array into a smaller partition, takes last element as pivot, places the pivot element at
//	its correct position in sorted array, and places all smaller to left of pivot and all greater elements to right of pivot
int partitionAscending(vector<double>& vector, int low, int high, int& count)
{
	double pivot = vector[high]; 
	int index = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (vector[j] < pivot)
		{
			index++;
			swap(vector[index], vector[j]);
			count++;
		}

	}
	swap(vector[index + 1], vector[high]);
	return (index + 1);
}


// Precondition: low and high are within the range of the array
// Postcondition: Splits the array into a smaller partition, takes last element as pivot, places the pivot element at
//	its correct position in sorted array, and places all greater to left of pivot and all smaller elements to right of pivot
int partitionDescending(vector<double>& vector, int low, int high, int& count)
{
	double pivot = vector[high]; 
	int index = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		// if current element is greater than pivot
		if (vector[j] > pivot)
		{
			index++;
			swap(vector[index], vector[j]);
			count++;
		}

	}
	swap(vector[index + 1], vector[high]);
	return (index + 1);
}


// Precondition: Array is not empty
// Postcondition: Quick sorts the dynamic array in ascending order
void quickSort_Ascending(vector<double>& vector, int low, int high, int& count)
{
	if (low < high)
	{
		int index = partitionAscending(vector, low, high, count);

		quickSort_Ascending(vector, low, index - 1, count);
		quickSort_Ascending(vector, index + 1, high, count);
	}
}


// Precondition: Array is not empty
// Postcondition: Quick sorts the dynamic array in descending order
void quickSort_Descending(vector<double>& vector, int low, int high, int& count)
{
	if (low < high)
	{
		int index = partitionDescending(vector, low, high, count);

		quickSort_Descending(vector, low, index - 1, count);
		quickSort_Descending(vector, index + 1, high, count);
	}
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to quick sort the array in ascending or descending order
void performQuickSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		int count = 0;
		cout << "\n\t\tQuickSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A', 'D');
		if (toupper(sorting) == 'A')
		{
			quickSort_Ascending(vector, 0, vector.size() - 1, count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		else
		{
			quickSort_Descending(vector, 0, vector.size() - 1, count);
			cout << "\n\t\tDescending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}
	
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
// Postcondition: Merge sorts the dynamic array in ascending order
void mergeSort_Ascending(vector<double>& vector, int left, int right, int& count)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort_Ascending(vector, left, mid, count);
	mergeSort_Ascending(vector, mid + 1, right, count);
	mergeAscending(vector, left, mid, right, count);
}

// Precondition: Array is not empty
// Postcondition: Merge sorts the dynamic array in descending order
void mergeSort_Descending(vector<double>& vector, int left, int right, int& count)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort_Descending(vector, left, mid, count);
	mergeSort_Descending(vector, mid + 1, right, count);
	mergeDescending(vector, left, mid, right, count);
}

// Precondition: Array is not empty
// Postcondition: Asks user to either choose to merge sort the array in ascending or descending order
void performMergeSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		int count = 0;
		cout << "\n\t\tMergeSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A', 'D');
		if (toupper(sorting) == 'A')
		{
			mergeSort_Ascending(vector, 0, vector.size() - 1, count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		else
		{
			mergeSort_Descending(vector, 0, vector.size() - 1, count);
			cout << "\n\t\tDescending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}
	
}

// Precondition: n is the size of the heap, i is an index in temp
// Postcondition: Swapping node i to the correct location, with smallest be the parent root
void heapifyDescending(vector<double>& vector, int n, int i, int& count)
{
	int smallest = i;
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < n && vector[left] < vector[smallest])
	{
		smallest = left;
	}

	if (right < n && vector[right] < vector[smallest])
	{
		smallest = right;
	}

	if (smallest != i)
	{
		swap(vector[i], vector[smallest]);
		count++;
		heapifyDescending(vector, n, smallest, count);
	}
}


// Precondition: n is the size of the heap, i is an index in temp
// Postcondition: Swapping node i to the correct location, with largest be the parent root
void heapifyAscending(vector<double>& vector, int n, int i, int& count)
{

	int largest = i;
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < n && vector[left] > vector[largest])
		largest = left;

	if (right < n && vector[right] > vector[largest])
		largest = right;

	if (largest != i)
	{
		swap(vector[i], vector[largest]);
		count++;
		heapifyAscending(vector, n, largest, count);
	}
}

// Precondition: Array is not empty
// Postcondition: Heap sorts the dynamic array in ascending order
void heapSort_Ascending(vector<double>& vector, int& count)
{
	int n = vector.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyAscending(vector, n, i, count);

	for (int i = n - 1; i > 0; i--)
	{
		swap(vector[0], vector[i]);
		count++;
		heapifyAscending(vector, i, 0, count);
	}
}

// Precondition: Array is not empty
// Postcondition: Heap sorts the dynamic array in descending order
void heapSort_Descending(vector<double>& vector, int& count)
{
	int n = vector.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapifyDescending(vector, n, i, count);

	for (int i = n - 1; i > 0; i--)
	{
		swap(vector[0], vector[i]);
		count++;
		heapifyDescending(vector, i, 0, count);
	}
}



// Precondition: Array is not empty
// Postcondition: Asks user to either choose to heap sort the array in ascending or descending order
void performHeapSort(vector<double> vector)
{
	if (vector.empty())
		cout << "\n\t\tThe dynamic array is empty." << endl;
	else
	{
		int count = 0;

		cout << "\n\t\tHeapSort:";
		char sorting = inputChar("\n\n\t\tChoose sort in (A)-ascending or (D)-descending order: ", 'A', 'D');
		if (toupper(sorting) == 'A')
		{
			heapSort_Ascending(vector, count);
			cout << "\n\t\tAscending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
		else
		{
			heapSort_Descending(vector, count);
			cout << "\n\t\tDescending:" << endl;
			displayArray(vector);
			cout << "\n\t\tNumber of swapping routines = " << count << endl;
		}
	}
	
}

