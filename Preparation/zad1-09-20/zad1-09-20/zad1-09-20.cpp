#include <iostream>
#include <queue>

using namespace std;

bool is_subordinate(const char* employee, const char* manager, const char* leaders[][2], size_t n)
{
	const char* curr = employee;
	while (curr)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(leaders[i][0], curr) == 0)
			{
				if (leaders[i][1] && strcmp(leaders[i][1], manager) == 0) return true;
				curr = leaders[i][1];
				break;
			}
		}
	}
	return false;
}
const char* the_big_boss(const char* leaders[][2], size_t n)
{
	for (int i = 0; i < n; i++)
	{
		if (leaders[i][1] == NULL) return leaders[i][0];
	}
}
int main()
{
	const char* leaders[][2] = { {"penka", "koce"}, {"koce", "boce"}, {"boce", NULL}, {"gosho", "penka"} };
	cout << the_big_boss(leaders, 4) << endl;
	cout << "Penka sub to gosho?" << endl;
	cout << is_subordinate("penka", "gosho", leaders, 4);
	cin.get();
	return 0;
}