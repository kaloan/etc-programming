#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int* farthestPair(char* st)
{
	int* res = new int[2];
	res[0] = res[1] = 0;
	int n = strlen(st);
	int cMax = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j >= i + 1; j--)
		{
			if (st[i] == st[j])
			{
				if (j - i > cMax)
				{
					cMax = j - i;
					res[0] = i;
					res[1] = j;
				}
			}
		}
	}

	return res;
}

int main()
{
	char st[40];
	//strcpy(st, "this is just a simple example");
	strcpy_s(st, 40, "this is just a simple example");
	int* res = farthestPair(st);
	cout << res[0] << " " << res[1];

	cin.get();
	return 0;
}