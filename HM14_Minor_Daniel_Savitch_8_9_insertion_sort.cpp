//Name: Daniel Minor	
//Date: 2/10/2016
//Homework # 14
//Problem # (Savitch problem 8-9)
//Insertion Sort using vectors, rather than arrays.
//Students worked with: Jake Smith



#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

void swap(int& ken, int& takata);
void input(vector<int> &fill_w_num);
void output(vector<int> fill_w_num);
void insertion_sort(vector<int> &fill_w_num);

int main()
{
	vector<int> fill_w_num;

	input(fill_w_num);
	insertion_sort(fill_w_num);
	output(fill_w_num);

	char dummy;
	cout << "Enter any key to quit." << endl;
	cin >> dummy;
	return 0;
}

void swap(int& ken, int& takata)
{
	int temp;
	temp = ken;
	ken = takata;
	takata = temp;
	return;
}

void input(vector<int> &fill_w_num)
{
	ifstream incoming_data;
	incoming_data.open("input_enormous.txt");

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
		fill_w_num.push_back(temp);	
	}
	
	incoming_data.close();
	return;
}

void output(vector<int> fill_w_num)
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
	for (unsigned int i = 0; i < fill_w_num.size(); i++)
	{
		outgoing_data << fill_w_num[static_cast<int>(i)] << endl;
	}
	outgoing_data.close();
	return;
}

void insertion_sort(vector<int> &fill_w_num)
{
	for (unsigned int i = 1; i < fill_w_num.size(); i++)
	{
		static_cast<int>(i);
		int mover = i - 1;
		while ((mover >= 0) && (fill_w_num[mover] > fill_w_num[mover + 1]))
		{
			swap(fill_w_num[mover], fill_w_num[mover + 1]);
			mover--;
		}
	}
	return;
}

