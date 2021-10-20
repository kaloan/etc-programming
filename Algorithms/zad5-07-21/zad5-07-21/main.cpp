#include<iostream>
#include<vector>
#include<utility>

using namespace std;

// Find the start and end indexes of the subarray with largest sum
template<typename T=int>
pair<size_t, size_t> findMaxSumEnds(vector<T>& arr)
{
	// maxStart[i] is the starting index of the subarray with largest sum ending in i
	vector<size_t> maxStart(arr.size()); //O(n)
	// maxValue[i] sum of the elements in arr[maxStart[i], i]
	vector<T> maxValue(arr.size()); //O(n)
	for (size_t i = 0; i < arr.size(); i++) //O(n)
	{
		maxValue[i] = arr[i];
		maxStart[i] = i;
	}

	for (size_t i = 1; i < arr.size(); i++) //O(n)
	{
		if (maxValue[i - 1] + arr[i] > maxValue[i]) 
		{
			maxValue[i] = maxValue[i - 1] + arr[i];
			maxStart[i] = maxStart[i - 1];
		}
	}

	T max = T();
	size_t start;
	size_t end;
	for (size_t i = 1; i < arr.size(); i++) //O(n)
	{
		if (max < maxValue[i])
		{
			max = maxValue[i];
			start = maxStart[i];
			end = i;
		}
	}

	return make_pair(start, end);
}


int main() 
{
	vector<int> a({ 1,5,-12,2,8,19,-5,6 });
	auto res = findMaxSumEnds(a);

	cout << res.first << " " << res.second;

	return 0;
}