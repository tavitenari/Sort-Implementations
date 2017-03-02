/*
Tavi Ioane Tenari
CSS342 
Lab4
SortImpls.h
*/

#pragma once
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int fist, int last);
void InsertionSort(vector<int> &arr, int first, int last);
void Merge(vector<int> &arr, int first, int mid, int last);
void MergeSort(vector<int> &arr, int first, int last);
void QuickSort(vector<int> &arr, int first, int last);
void IterativeMergeSort(vector<int> &arr, int first, int last);
void ShellSort(vector<int> &arr, int first, int last);

void BubbleSort(vector<int> &arr, int first, int last)
{
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < (last + 1)))
	{
		sorted = true;
		for (int index = first; index < ((last + 1) - pass); index++)
		{
			int nextIndex = (index + 1);
			if (arr[index] > arr[nextIndex])
			{
				swap(arr[index], arr[nextIndex]);
				sorted = false;
			}
		}
		pass++;
	}
}

void InsertionSort(vector<int> &arr, int first, int last)//
{
	for (int unsorted = first; unsorted < last + 1; unsorted++)
	{
		int nextInt = arr[unsorted];
		int loc = unsorted;
		while ((loc > first) && (arr[loc - 1] > nextInt))
		{
			arr[loc] = arr[loc - 1];
			loc--;
		}
		arr[loc] = nextInt;
	}
}

void Merge(vector<int> &arr, int first, int mid, int last)
{
	int *tempArr = new int[last];
	int first1 = first;
	int last1 = mid;
	int first2 = (mid + 1);
	int last2 = last;
	int index = first1;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			tempArr[index] = arr[first1];
			first1++;
		}
		else
		{
			tempArr[index] = arr[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1)
	{
		tempArr[index] = arr[first1];
		first1++;
		index++;
	}
	while (first2 <= last2)
	{
		tempArr[index] = arr[first2];
		first2++;
		index++;
	}
	for (index = first; index <= last; index++)
	{
		arr[index] = tempArr[index];
	}
}

void MergeSort(vector<int> &arr, int first, int last)
{
	if (first < last)
	{
		int mid = first + ((last - first) / 2);
		MergeSort(arr, first, mid);
		MergeSort(arr, (mid + 1), last);
		Merge(arr, first, mid, last);
	}
}

void QuickSort(vector<int> &itemVector, int first, int last)
{
	if (last - first < 4)
	{
		InsertionSort(itemVector, first, last);
		return;
	}
	int mid = (first + last) / 2;
	if (itemVector[first] > itemVector[last])
	{
		swap(itemVector[first], itemVector[last]);
	}
	if (itemVector[first] > itemVector[mid])
	{
		swap(itemVector[first], itemVector[mid]);
	}
	else if (itemVector[mid] > itemVector[last])
	{
		swap(itemVector[mid], itemVector[last]);
	}
	int pivot = itemVector[mid];
	swap(itemVector[mid], itemVector[last - 1]);
	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done)
	{
		while (itemVector[left] < pivot)
		{
			left++;
		}
		while (itemVector[right] > pivot)
		{
			right--;
		}
		if (right > left)
		{
			swap(itemVector[left], itemVector[right]);
			right--;
			left++;
		}
		else
		{
			done = true;
		}
	}
	swap(itemVector[left], itemVector[last - 1]);
	QuickSort(itemVector, first, left - 1);
	QuickSort(itemVector, left + 1, last);
}

void IterativeMergeSort(vector<int> &arr, int first, int last)
{
	int size = (last - first) + 1;
	
	int *tempArr = new int[(last - first) + 1];
	for (int i = 0; i < first; i++)
	{
		tempArr[i] = arr[i];
	}
			
	int gap = 1;	
	while (gap < size)
	{
		int current = first;
		int first1 = first;
		int index1;
		int	index2;
		while ((first1 + gap) < (last + 1))
		{
			int first2 = (first1 + gap);
			int last1 = (first2 - 1);
			int last2;
			if (!((first2 + (gap - 1)) < (last + 1)))
			{
				last2 = last;
			}
			else
			{
				last2 = ((first2 + gap) - 1);
			}
			index1 = first1;
			index2 = first2;
			while ((index1 <= last1) && (index2 <= last2))
			{
				if (arr[index1] >= arr[index2])
				{
					tempArr[current] = arr[index2];
					index2++;
				}
				else
				{
					tempArr[current] = arr[index1];
					index1++;
				}
				current++;
			}
			while (index1 <= last1)
			{
				tempArr[current] = arr[index1];
				index1++;
				current++;
			}

			while (index2 <= last2)
			{
				tempArr[current] = arr[index2];
				current++;
				index2++;
			}

			first1 = last2 + 1;
		}
		
		index1 = first1;
		while (current < (last + 1))
		{
			tempArr[current] = arr[index1];
			current++;
			index1++;
		}

		for (int i = first; i < (last + 1); i++)
		{
			arr[i] = tempArr[i];
		}
		
		gap *= 2;
	}
}

void ShellSort(vector<int> &arr, int first, int last)
{
	int size = (last - first + 1);
	for (int gap = (size / 2); gap > 0; gap = (gap == 2) ? 1 + first : int(gap / 2.2 ))
	{
		for (int i = gap; i < size; i++)
		{
			int tmp = arr[i];
			int j = i;
			for (; (j >= gap) && (tmp < arr[j - gap]); j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = tmp;
		}
	}
}