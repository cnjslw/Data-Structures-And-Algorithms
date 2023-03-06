#include <iostream>
#include <time.h>
using namespace std;

void Merge(int arr[], int l, int m, int r, int* p)
{
	int index = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[index++] = arr[i++];
		}
		else
		{
			p[index++] = arr[j++];
		}
	}

	while (i <= m)
	{
		p[index++] = arr[i++];
	}
	while (j <= r)
	{
		p[index++] = arr[j++];
	}

	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}
}
void MergeSort(int* arr, int begin, int end, int* p)
{
	if (begin >= end)
	{
		return;
	}

	int middle = (begin + end) / 2;

	MergeSort(arr, begin, middle, p);
	MergeSort(arr, middle + 1, end, p);
	Merge(arr, begin, middle, end, p);

}
void MergeSort(int* arr, int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
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

	MergeSort(arr, 10);

	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
	return 1;
}