#include <iostream>
#include <queue>

using namespace std;

char calcWithNeighbours(char** &terrain, const int &m, const int &n, const int &I, const int &J)
{
	int countOfFours=0;
	for (int i = -1; i < 1; i++)
	{
		for (int j = -1; j < 1; j++)
		{
			if ((i != 0 || j != 0) && (I + i >= 0 && I + i < m && J + j >= 0 && J + j < n))
			{
				if (terrain[I + i][J + j] == '4') ++countOfFours;
			}
		}
	}
	if (countOfFours >= 3) return '3';
	return '4';
}

char** copyArr(char** &terrainGiven, const int &m, const int &n)
{
	char** terr = new char*[m];
	terr[0] = new char[m*n];
	for (int i = 1; i < m; i++)
	{
		terr[i] = terr[i - 1] + n;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			terr[i][j] = terrainGiven[i][j];
		}
	}

	return terr;
}
char** age(char** &terrainGiven, const int &m, const int &n)
{
	char** terr = copyArr(terrainGiven, m ,n);
	char** newTerr = copyArr(terr, m, n);
	for (int k = 0; k < 100; k += 10)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << terr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (terr[i][j] >= '1' && terr[i][j] <= '3')
				{
					++newTerr[i][j];
				}
				else if (terr[i][j] == '4')
				{
					newTerr[i][j] = calcWithNeighbours(terr, m ,n, i ,j);
				}
			}

			
		}
		delete[] terr[0];
		delete terr;
		terr = newTerr;
		newTerr = copyArr(terr, m, n);
	}

	return terr;
}

int main()
{
	int m = 4, n = 6;
	char terrain[4][6] = { 
		{'R', 'R', '1', '1', '2','2' },
		{'1', 'R', 'R', 'R', '1','2' }, 
		{'S', '1', 'R', 'R', '2','3' }, 
		{'4', '4', 'S', 'S', 'R','R' } };
	char** p = new char*[4];
	p[0] = new char[24];
	for (int i = 1; i < m; i++)
	{
		p[i] = p[i - 1] + n;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = terrain[i][j];
		}
	}

	char** hundred = age(p, 4, 6);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << hundred[i][j] << " ";
		}
		cout << endl;
	}
	cin.ignore();
	return 0;
}