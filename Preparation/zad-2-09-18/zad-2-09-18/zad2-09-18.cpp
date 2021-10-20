#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* far;
	Node(int data)
	{
		this->data = data;
		next = NULL;
		far = NULL;
	}
};

Node* readList(char* filename)
{
	ifstream numFile;
	numFile.open(filename, ios::in);

	if (numFile.get() == '\n') return NULL;
	numFile.seekg(-1, ios::cur);

	int n = 1;
	int f;
	numFile >> f;

	Node* start = new Node(f);
	Node* prev = start;
	while (!numFile.eof())
	{
		numFile >> f;
		Node* next = new Node(f);
		prev->next = next;
		prev = next;
		++n;
	}
	
	int k = ceil(sqrt(n));
	Node* curr = start;
	while (curr)
	{
		Node* temp = curr;
		bool finished;
		for (int i = 1; i <= k; i++)
		{
			if (temp) temp = temp->next;
			else
			{
				finished = true;
				break;
			}
		}
		if (finished) break;
		curr->far = temp;
		curr = curr->far;
	}
}

bool member(int &N, Node* start)
{
	Node* prev = NULL;
	Node* curr = start;
	bool isIn = false;

	if (N < start->data) return false;
	while (curr->data<N && curr->far)
	{
		prev = curr;
		curr = curr->far;
	}

	//Close to end of list
	if (!curr->far)
	{
		while (curr)
		{
			if (N == curr->data) return true;
			curr = curr->next;
		}
	}

	//Finished because curr->data >=N
	if (N == curr->data) return true;
	Node* c = prev;
	while (c != curr)
	{
		if (N == c->data) return true;
		c = c->next;
	}


	return false;
}