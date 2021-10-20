#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	char text; 
	Node *left, *right;
	Node(char text)
	{
		this->text = text;
		left = right = NULL;
	}
};

bool lastRow(queue<Node*> q)
{
	for (int k = 1; k <= q.size(); k++)
	{
		if (q.front() != NULL) return false;
		Node* tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	return true;
}

void printText(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty() && !lastRow(q))
	{
		queue<Node*> next;
		while (!q.empty())
		{
			Node* curr = q.front();
			q.pop();
			if (curr)
			{
				std::cout << curr->text;
				next.push(curr->left);
				next.push(curr->right);
			}
			else std::cout << " ";
		}
		cout << endl;
		q = move(next);
	}
}


int main()
{
	Node* root = new Node('I');
	root->left = new Node('a');
	root->right = new Node('m');
	root->left->right = new Node('a');
	root->right->left = new Node('Q');
	root->right->right = new Node('!');

	printText(root);

	cin.get();
	return 0;
}