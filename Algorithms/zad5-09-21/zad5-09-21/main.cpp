#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<algorithm>

using namespace std;

template<typename T = int>
size_t modifiedBinarySearch(vector<pair<T, size_t>>& arr, T& lookup)
{
	size_t lower = 0;
	size_t upper = arr.size() - 1;
	while(upper > lower)
	{
		size_t middle = (upper - lower) / 2;
		if (lookup == arr[middle].first) return middle;
		else if (lookup > arr[middle].first) lower = middle + 1;
		else upper = middle - 1;
	}

	return arr.size();
}

// Find whether two different elements in an array sum to a given integer
template<typename T = int>
bool checkForElementsSum(vector<T>& arr, T& m)
{
	// Contains pairs of the complement of arr[i] and i, necessary complication because m may be even
	vector<pair<T, size_t>> complement(arr.size()); //O(n)
	for (size_t i = 0; i < arr.size(); i++) //O(n)
	{
		complement[i] = make_pair(m - arr[i], i);
	}
	// Sorts the complements by the first argument
	std::sort(complement.begin(), complement.end());

	// By searching for the value in the complements we ensure there is an element
	// (not necessarily different) that completes the current one to m
	for (size_t i = 1; i < arr.size(); i++) //O(n)
	{
		auto complementIndex = modifiedBinarySearch(complement, arr[i]); //O(log n)
		if (complementIndex < arr.size()) 
		{
			if (complementIndex != i) return true;
			else if 
			(
				(complementIndex - 1 >= 0 && complement[complementIndex - 1].first + arr[i] == m) ||
				(complementIndex + 1 < arr.size() && complement[complementIndex + 1].first + arr[i] == m)
			) return true;
		}
	}

	return false;
}

template<typename T = int>
bool checkForElementsSumHash(vector<T>& arr, T& m)
{
	// Contains pairs of the complement of arr[i] and arr[i] itself
	unordered_multimap<T, T> complement; //O(1)
	for (size_t i = 0; i < arr.size(); i++) //O(n)
	{
		complement.insert(make_pair(m - arr[i], arr[i]));
	}

	for (auto& el : arr) //O(n)
	{
		auto complementIterator = complement.find(el);
		if (complementIterator != complement.end())
		{
			T complementToEl = complementIterator->second;
			if (complementToEl != el || complement.count(el) > 1) return true;
		}
	}

	return false;
}

int main()
{
	vector<int> a({ 1,5,-12,2,8,19,-5,6 });
	int M = 10;
	auto res1 = checkForElementsSum(a, M);
	auto res2 = checkForElementsSumHash(a, M);

	cout << res1 << " " << res2;

	return 0;
}