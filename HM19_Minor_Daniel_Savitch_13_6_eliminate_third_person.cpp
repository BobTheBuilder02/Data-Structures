//Names:Daniel Minor	
//Date: 3/12/16
//Homework # 19
//Problem # (Savitch problem 13-6)
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;

class Node
{
public:
	Node(); //default constructor
	Node(int value); //constructor to initialize nodes
	int getData() const; //gets value of node w/o changing it
	Node *getLink() const; //gets the  node that is next  in the list w/o changing it
	void setData(int value); //use to modify the values stored in the list
	void setLink(Node *next); // use to chnage the reference to the next node 
							  /*void head_insert(Nodeptr& head, int seats);
							  void Delete3rdNode(Nodeptr head, int target);*/
	int data;
	Node *link;
};
typedef Node* Nodeptr;

int main()
{

	int num_nodes;

	//Code from Takata
	cout << "Input the number of people (the number of suitors in Savitch’s description)." << endl;
	cin >> num_nodes;

	Nodeptr  t, p, head, tmp;
	p = head = new Node(1);
	for (int i = 2; i <= num_nodes; i++)
	{
		t = new Node(i);
		p->link = t;
		p = t;
	}
	p->link = head; //links last node in the list to the first node in the list.
	while (head != head->link) //as long as head doesn't point to itself (pointing to itself implies it is the last thing in the list)
	{
		head = head->link; // move the head to the next node once
		p = head->link; //put what the 2nd node is linked to into P
		head->link = p->link; // put the link of P (3rd node's link) into the 2nd Node's link
		delete p; // delete the third node
		head = head->link; // moves the head one more spot for the next iteration to start on. (makes the head become the 4th node)
	}

	cout << "The number of the last person is: " << head->data << endl;


	//Deletes all the nodes before exiting for good computer memory allocation
	
#ifdef MYTHING
	tmp = head;
	while (tmp != NULL)
{	
		Nodeptr nodeToDelete = tmp;
		tmp = tmp->getLink();
		delete nodeToDelete;
	}
#endif // MYTHING


	char dummy;
	cout << "enter any key to quit." << endl;
	cin >> dummy;
	return 0;
}

Node::Node() : data(0), link(NULL)
{
	//deliberately empty
}

Node::Node(int value) : data(value)
{
	//Deliberately empty
}

int Node::getData() const
{
	return data;
}

Node* Node::getLink() const
{
	return link;
}

void Node::setData(int value)
{
	data = value;
}

void Node::setLink(Node *next)
{
	link = next;
}
/*
void Node::head_insert(Nodeptr& head, int seats)
{
Nodeptr temp_ptr;
temp_ptr = new Node(seats, head);
head = temp_ptr;
}
*/
/*
void Node::Delete3rdNode(Nodeptr head, int target)
{
Nodeptr tmp = head;
Nodeptr here = head;
if (here == NULL)
{
return NULL;
}
else
{
for (int i = 0; i < num_nodes; i++)
{
while (here != here->link)
{
here = here->link;
Nodeptr nodeToDelete = here->link;
here->link = nodeToDelete->link;
delete nodeToDelete;
here = here->link;
}
}
}
}

*/
