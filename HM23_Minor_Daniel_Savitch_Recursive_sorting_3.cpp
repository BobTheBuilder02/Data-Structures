
//Names: Daniel Minor
//Date: 4/25/2016
//Homework # 23
//Problem: Recursive sorting 3
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:                             


//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
//#include <ctime>
using namespace std;

//Function declarations
void input(vector<int> &arr);
void swap(int& ken, int& takata);
void quickSort(vector<int> &arr, int left, int right);
void output(vector<int>& arr);

int main()
{
	std::cout << "Enter any key to begin to program" << std::endl;
	//clocktime so you get an idea of the time it takes to sort. 
	//clock_t startTime = clock();
	
	vector<int> arr; 
	//fills vector with values, then gets the 
	input(arr);
	int begin = 0;
	int end = arr.size();
	quickSort(arr, begin, end);
	output(arr);

	char dummy;
	//std::cout <<"Sorting the file took: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << std::endl;
	std::cout << "Enter any key to quit." << std::endl;
	std::cin >> dummy;
	return 0;
}

//function definitions
void input(vector<int> &arr)
{
	ifstream incoming_data;
	incoming_data.open("input.txt");

	if (incoming_data.fail())
	{
		cout << "Error: Could not open file" << endl;
		char dummy;
		cout << "Enter any key to quit." << endl;
		cin >> dummy;
		exit(1);
	}
	
	while (!incoming_data.eof())
	{
		int temp;
		incoming_data >> temp;
		//can't do arr[temp] because the pushback function is the thing that creates more memory in the vector
		arr.push_back(temp);
	}
	incoming_data.close();
	return;
}

void swap(int& ken, int& takata)
{
	int temp = ken;
	ken = takata;
	takata = temp;
}

void quickSort(vector<int> &arr, int left, int right)
{
	int lefty = left;
	int righty = right;
	int pivot = arr[((left + right) / 2)];

	while (lefty <= righty)
	{
		while (arr[lefty] < pivot)
			lefty++;
		while (arr[righty] > pivot)
			righty--;
		if (lefty <= righty)
		{
			swap(arr[lefty], arr[righty]);
			lefty++;
			righty--;
		}
	}
	if (left < righty)
		quickSort(arr, left, righty);
	if (lefty < right)
		quickSort(arr, lefty, right);
}

void output(vector<int>& arr)
{
	ofstream outgoing_data;
	outgoing_data.open("output.txt");

	if (outgoing_data.fail())
	{
		cout << "Error: Could not open file" << endl;
		char dummy;
		cout << "Enter any key to quit." << endl;
		cin >> dummy;
		exit(1);
	}
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		outgoing_data << arr[static_cast<int>(i)] << endl;
	}
	outgoing_data.close();
	return;
}
