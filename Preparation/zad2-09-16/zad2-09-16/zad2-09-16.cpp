#include <iostream>

using namespace std;

struct Node
{
	int data;
	int K;
	Node** children;
	Node(int K, int data)
	{
		this->K = K;
		this->data = data;
		children = new Node*[K];
		for (int i = 0; i < K; i++)
		{
			children[i] = NULL;
		}
	}
};


struct LNodes
{
	Node* vertex;
	LNodes* next;
};


Node* makeTreeHelper(int K, int* arr, int left, int right)
{
	if (left > right) return NULL;

	Node* res = new Node(K, arr[left]);
	//if (left == right) return res;
	Node* curr = res;
	for (int i = left; i < right; i *= K)
	{
		int M = i * K > right ? right : i * K;
		res->children[i] = makeTreeHelper(K, arr, i, M);
	}
	return res;
}
Node* makeTree(int K, int* arr, int n)
{
	if (!arr) return NULL;
	Node* start = new Node(K, arr[0]);
	for (int i = 1; i < n; i *= K)
	{
		int M = i * K > n ? n : i * K;
		start->children[i] = makeTreeHelper(K, arr, i, M);
	}
	return start;
	//return makeTreeHelper(K, arr, 1, n);
}
/*Node* makeTree(int K, int* arr, int n)
{
	//int* sorted = new int[n];
	
	/*for (int i = 0; i < n; i++)
	{
		int cMin = arr[i];
		for (int j = i + 1; j < n; j++)
		{
			if(arr[j]>cMin)
		}
	}

	if (n == 0) return NULL;
	Node* res = new Node(K, arr[0]);
	Node* curr = res;
	LNodes* list;
	list->vertex = curr;
	list->next = NULL;
	LNodes* lastL;
	for (int i = 1; i < n; i *= K)
	{
		for (int j = i; j < i + K; j++)
		{

		}
	}

	return res;
}*/

void printNodes(Node* n)
{
	if (!n) return;
	cout << n->data;
	for (int i = 0; i < n->K; i++)
	{
		cout << "|" << i << "|";
		printNodes(n->children[i]);	
		cout << "|";
	}
}

int main()
{
	int arr[] = {1,2,3,5,6,7,8,9,10};

	Node* res = makeTree(3, arr, 10);

	printNodes(res);
	return 0;
}