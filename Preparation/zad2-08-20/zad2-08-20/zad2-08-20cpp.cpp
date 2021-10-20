#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string text;
	Node* next;
};

void unite(Node* list)
{
	Node* curr = list;
	Node* prev = NULL;
	if (!(curr->next)) return;
	//curr = curr->next;
	do
	{
		
		Node* temp = curr->next;
		if (curr->text.back() == temp->text.front())
		{
			//temp = curr->next;
			//curr->text.pop_back();
			curr->text.push_back('-');
			curr->text += temp->text;

			curr->next = temp->next;

			if (temp == list)
			{
				prev->next = temp;
				temp->text = curr->text;
				delete curr;
				break;
			}
			delete temp;
		}
		//Not the one below!
		/*Node* temp;
		do
		{
			temp = curr->next;
			//curr->text.pop_back();
			curr->text.push_back('-');
			curr->text += temp->text;

			curr->next = temp->next;
			if (temp == list)
			{
				prev->next = temp;
				temp->text = curr->text;
				delete curr;
				break;
			}
			delete temp;
		} while (curr->text.back() == temp->text.front());*/
		

		prev = curr;
		curr = curr->next;
	} while (curr != list);
}


int main()
{
	string temp;
	Node* start = new Node;
	Node* curr = start;
	Node* prev = NULL;
	do
	{
		//cin >> temp;
		getline(cin, temp);
		curr->text = temp;
		if (prev) prev->next = curr;
		if (!temp.empty())
		{
			prev = curr;
			curr = new Node;
		}
	} while (!temp.empty());
	
	curr = prev;
	curr->next = start;
	
	unite(start);
	cout << start->text;
	Node* tmp = start->next;
	while (tmp != start)
	{
		cout << tmp->text << "\n";
		tmp = tmp->next;
	}

	cin.get();
	return 0;
}