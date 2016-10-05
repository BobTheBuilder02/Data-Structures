//Daniel Minor
//Binary Tree Sorting

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tree {
public:
	int val;
	Tree* left;
	Tree* right;
};
typedef Tree* treeptr;

void input(vector<int> &arr);
treeptr makenode(int val);
void setLeft(treeptr aTree, int val);
void setright(treeptr aTree, int val);
void Insert(treeptr aTree, int val);
vector<int> inTrav(treeptr aTree);
void output(vector<int>& arr);


int main()
{
	char dummy;
	vector<int> arr;
	treeptr myTree = makenode(65); // only freaking way to get anything to output, which then means my intrav function thinks the only thing in the tree is a 65 outside of it.
	std::cout << "Enter any key to begin to program" << std::endl;
	cin >> dummy;
	clock_t startTime = clock();
	input(arr);
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		Insert(myTree, arr[i]);
	}

	arr = inTrav(myTree); //inTrav should return the vector arr and then update the arr now, but it isn't. Stepping through intrav you can see it is 
	//creating a new vector everytime, so to get it to actually work, would need to have values pushed back to an array outside of function without messing up recursion
	//which my notes aren't helping me, or the answer is easy and I've been looking at this too long. 
	output(arr);

	std::cout << "Sorting the file took: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << std::endl;
	cout << "Press any key to quit" << endl;
	cin >> dummy;
	return 0;
}

void input(vector<int> &arr)
{
	ifstream incoming_data;
	incoming_data.open("inpu.txt");

	if (incoming_data.fail())
	{
		cout << "error: could not open file" << endl;
		char dummy;
		cout << "enter any key to quit." << endl;
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

treeptr makenode(int val)
{
	treeptr tempTree = new Tree;
	tempTree->left = tempTree->right = NULL;
	tempTree->val = val;
	return tempTree;
}

void setLeft(treeptr aTree, int val)
{
	aTree->left = makenode(val);
}

void setright(treeptr aTree, int val)
{
	aTree->right = makenode(val);
}

void Insert(treeptr aTree, int val)
{
	while (1)
	{
		if (val <= aTree->val)
		{
			if (aTree->left != NULL)
			{
				aTree = aTree->left;
			}
			else
			{
				setLeft(aTree, val);
				break;
			}
		}
		else
		{
			if (aTree->right != NULL)
			{
				aTree = aTree->right;
			}
			else
			{
				setright(aTree, val);
				break;
			}
		}
	}
}

vector<int> inTrav(treeptr aTree)
{
	vector<int> arr;
	if (aTree->left != NULL)
	{
		inTrav(aTree->left);
	}
	cout << "The Value is:" << aTree->val << endl;
	arr.push_back(aTree->val); //WHY DOES IT NOT OUTPUT THESE VALUES TO THE VECTOR DAMMIT, not sure how to get it to out the vector without messing up my recusion. 
	if (aTree->right != NULL)
	{
		inTrav(aTree->right);
	}
	return arr;
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