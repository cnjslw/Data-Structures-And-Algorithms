#include <iostream>
#include <time.h>
using namespace std;

int Partation(int* arr, int l, int r)
{
	int val = arr[l];
	while (l < r)
	{
		while (1 < r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}

		while (l < r && arr[l] < val)
		{
			l++;
		}

		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = val;
	return l;
}
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int pos = Partation(arr, begin, end);
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos + 1, end);

}
void QuickSort(int* arr, int size)
{
	return QuickSort(arr, 0, size - 1);
}
int main()
{
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;

	QuickSort(arr, 10);

	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
	return 1;
}