#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

void sortList(Node* start)
{
	if (!start || !(start->next)) return;
	Node* curr = start;

	while (curr)
	{
		int cMin = curr->data;
		Node* cMinNode = curr;
		Node* mover = curr->next;
		if (!mover) break;
		while (mover)
		{
			if (mover->data < cMin)
			{
				cMin = mover->data;
				cMinNode = mover;
			}
			mover = mover->next;
		}
		int temp = cMinNode->data;
		cMinNode->data = curr->data;
		curr->data = temp;

		curr = curr->next;
	}
}

int main()
{
	Node* st = new Node(5);
	Node* one = new Node(4);
	Node* two = new Node(10);
	Node* three = new Node(1);
	st->next = one;
	one->next = two;
	two->next = three;

	sortList(st);

	Node* curr = st;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}

	cin.get();
	return 0;
}