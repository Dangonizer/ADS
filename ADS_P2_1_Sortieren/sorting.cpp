#include "sorting.h"
#include <cmath>

namespace sorting
{

	void InsertionSort(vector<int> &arr, int left, int right)
	{
		int i, key, j;
		for (i = left + 1; i <= right; i++)
		{
			key = arr[i];
			j = i - 1;

			while (j >= left && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	int medianOfThree(const vector<int> &arr, int left, int right)
	{
		int center = (left + right) / 2;

		if (arr[center] < arr[left])
		{
			if (arr[right] < arr[center])
				return center;
			else if (arr[right] < arr[left])
				return right;
			else
				return left;
		}
		else
		{
			if (arr[right] < arr[left])
				return left;
			else if (arr[right] < arr[center])
				return right;
			else
				return center;
		}
	}
	//************
	// QuickSort *
	//************
	void partition(vector<int> &arr, int left, int right, int &i, int &j)
	{
		i = left, j = right;

		int pivot = arr[medianOfThree(arr, left, right)];

		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;
			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
	}

	void QuickSort(vector<int> &arr, int left, int right)
	{
		if (left < right)
		{
			int i, j;
			partition(arr, left, right, i, j);
			QuickSort(arr, left, j);
			QuickSort(arr, i, right);
		}
	}

	void HybridSort(vector<int> &arr, int left, int right)
	{
		const int threshold = 10;

		if (left < right)
		{
			if (right - left <= threshold)
			{
				InsertionSort(arr, left, right);
			}
			else
			{
				int i, j;
				partition(arr, left, right, i, j);
				HybridSort(arr, left, j);
				HybridSort(arr, i, right);
			}
		}
	}

	//************
	// MergeSort *
	//************
	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high)
	{
		int LeftPos, TempPos, RightPos;
		LeftPos = low;
		TempPos = low;
		RightPos = pivot;

		while ((LeftPos < pivot) && (RightPos <= high))
		{
			if (a[LeftPos] <= a[RightPos])
			{
				b[TempPos] = a[LeftPos];
				LeftPos++;
			}
			else
			{
				b[TempPos] = a[RightPos];
				RightPos++;
			}
			TempPos++;
		}

		while (LeftPos < pivot)
		{
			b[TempPos] = a[LeftPos];
			LeftPos++;
			TempPos++;
		}

		while (RightPos <= high)
		{
			b[TempPos] = a[RightPos];
			RightPos++;
			TempPos++;
		}

		for (int k = low; k <= high; k++)
			a[k] = b[k];
	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high)
	{
		if (low < high)
		{
			int middle = (low + high) / 2;
			MergeSort(a, b, low, middle);
			MergeSort(a, b, middle + 1, high);
			Merge(a, b, low, middle + 1, high);
		}
	}

	void natMerge(vector<int> &a, vector<int> &b, int left, int middle, int right)
	{
		Merge(a, b, left, middle, right);
	}

	void natMergeSort(vector<int> &a, vector<int> &b)
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			int left = 0;

			int middle = left;
			while (middle < a.size() - 1 && a[middle] <= a[middle + 1])
				middle++;
			int right = middle + 1;
			while (right < a.size() - 1 && a[right] <= a[right + 1])
				right++;
			if (middle < a.size() - 1)
			{
				natMerge(a, b, left, middle + 1, right);
				sorted = false;
			}
		}
	}

	//************
	// Heapsort  *
	//************
	int leftChild(int i)
	{
		return 2 * i + 1;
	}

	void heapify(vector<int> &a, int n, int i)
	{
		int child = i;
		int tmp = a[i];
		int j = i;

		// solange child existiert do:
		while (leftChild(j) < n)
		{
			child = leftChild(j);
			// pick biggest child
			if (child + 1 < n && a[child] < a[child + 1])
				child = child + 1;
			// if parent is smaller than child, swap
			if (tmp < a[child])
			{
				swap(a[j], a[child]);
				j = child;
			}
			else
				break;
		}
		a[j] = tmp;
	}

	void HeapSort(vector<int> &a, int n)
	{
		// build heap
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(a, n, i);

		// sort
		for (int i = n - 1; i > 0; i--)
		{
			swap(a[0], a[i]);
			heapify(a, i, 0);
		}
	}

	//************
	// Shellsort *
	//************
	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int> &a, int n)
	{
		int h = 1;
		// calculate h_max+1
		while (h < n)
			h = 2 * h + 1;
		// calculate h_max by going 1 step back
		h = (h - 1) / 2;

		while (h > 0)
		{
			// sort from h(first unsorted element in gapped insertion sort) to n
			for (int i = h; i < n; i++)
			{
				int tmp = a[i];
				int j = i;
				// instert into sorted sequence
				while (j >= h && a[j - h] > tmp)
				{
					a[j] = a[j - h];
					j = j - h;
				}
				a[j] = tmp;
			}
			// get next h
			h = (h - 1) / 2;
		}
	}

	void ShellSort_3n(vector<int> &a, int n)
	{
		int h = 1;
		// calculate h_max+1
		while (h < n)
			h = 3 * h + 1;
		// calculate h_max by going 1 step back
		h = (h - 1) / 3;

		while (h > 0)
		{
			// sort from h(first unsorted element in gapped insertion sort) to n
			for (int i = h; i < n; i++)
			{
				int tmp = a[i];
				int j = i;
				while (j >= h && a[j - h] > tmp)
				{
					a[j] = a[j - h];
					j = j - h;
				}
				a[j] = tmp;
			}
			// get next h
			h = (h - 1) / 3;
		}
	}

	void randomizeVector(vector<int> &array, int n)
	{
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}

}
