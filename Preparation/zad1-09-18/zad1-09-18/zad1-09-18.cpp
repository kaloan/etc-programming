#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int retSize = 0;
int* revealPassword(char*** &a, const int &m, const int &n)
{
	int M = m * 100 + m + 1;
	char* allMiddleWords = new char[m * 100 + m + 1];
	allMiddleWords[0] = '\0';
	for (int i = 0; i < m; i++)
	{
		bool isOrdered = true;
		for (int j = 0; j < n - 1; j++)
		{
			//printf("%s\n", a[i][j]);
			if (strcmp(a[i][j], a[i][j + 1]) > 0)
			{
				isOrdered = false;
				break;
			}
		}
		if (isOrdered)
		{
			int middle = (n % 2 == 0) ? n / 2 - 1 : n / 2;
			//strcat(allMiddleWords, a[i][middle]);
			//strcat(allMiddleWords, " ");
			//printf("%s\n", a[i][middle]);
			strcat_s(allMiddleWords, M, a[i][middle]);
			strcat_s(allMiddleWords, M, " ");
		}
	}
	int countOfWords = 0;
	allMiddleWords[strlen(allMiddleWords) - 1] = '\0';
	if (allMiddleWords[0] != '\0') ++countOfWords;
	else return NULL;
	for (int i = 0; i < strlen(allMiddleWords); i++)
	{
		if (allMiddleWords[i] == ' ') ++countOfWords;
	}
	int* res = new int[countOfWords];
	int wordsPos = 0;
	for (int i = 0; i < countOfWords; i++)
	{
		int cNum = 0;
		while (allMiddleWords[wordsPos] != ' ' && allMiddleWords[wordsPos] != '\0')
		{
			++cNum;
			++wordsPos;
		}
		++wordsPos;
		res[i] = cNum;
	}
	retSize = countOfWords;
	return res;
}

int main()
{
	char a1[] = "aaa";
	char a2[] = "bbb";
	char a3[] = "ccc";
	char b1[] = "aaa";
	char b2[] = "ncvjnajuwiuea";
	char b3[] = "z";
	char c1[] = "aaa";
	char c2[] = "aaaa";
	char c3[] = "aaaaa";
	char*** arr = new char**[3];
	arr[0] = new char*[3];
	arr[1] = new char*[3];
	arr[2] = new char*[3];
	arr[0][0] = a1;
	arr[0][1] = a2;
	arr[0][2] = a3;
	arr[1][0] = b1;
	arr[1][1] = b2;
	arr[1][2] = b3;
	arr[2][0] = c1;
	arr[2][1] = c2;
	arr[2][2] = c3;
	
	int* res = revealPassword(arr, 3, 3);
	for (int i = 0; i < retSize; i++)
	{
		cout << res[i] << " ";
	}

	cin.get();
	return 0;
}