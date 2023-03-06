#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Ã°ÅÝ
void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
	}
}

//Ñ¡ÔñÅÅÐòËã·¨
void ChoiceSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				k = j;
			}
		}
		if (k != i)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

//²åÈëÅÅÐò
void InsertSort(int* arr , int size)
{
// 	for (int i = 0; i < size; i++)
// 	{
// 		for (int j = i + 1; j > 0; j--)
// 		{
// 			if (arr[j] < arr[i])
// 			{
// 				int temp = arr[i];
// 				a[i] = a[j];
// 				a[j] = temp;
// 			}
// 			else
// 			{
// 				break;
// 			}
// 
// 		}
// 	}

	for (int i = 1; i < size; i++)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
				break;

			arr[j + 1] = arr[j];
		}

		arr[j + 1] = val;
	}
}
void ShellSort(int *arr , int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			int j = i - gap;
			int val = arr[i];
			for (; j >= 0; j-=gap)
			{
				if (arr[j] <= val)
					break;

				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}

	}
	
}

int main()
{
	cout << "=================Ã°ÅÝÅÅÐò====================" << endl;
	int arr1[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr1[i] = rand() % 100 + 1;
	}

	for (int val : arr1)
	{
		cout << val << " ";
	}
	cout << endl;

	BubbleSort(arr1, 10);

	for (int val : arr1)
	{
		cout << val<<" ";
	}
	cout << endl;

	cout << "=================Ã°ÅÝÅÅÐò====================" << endl;
	int arr2[10];

	for (int i = 0; i < 10; i++)
	{
		arr2[i] = rand() % 100 + 1;
	}

	for (int val : arr2)
	{
		cout << val << " ";
	}
	cout << endl;

	ChoiceSort(arr2, 10);

	for (int val : arr2)
	{
		cout << val << " ";
	}
	cout << endl;
	cout << "=================²åÈëÅÅÐò====================" << endl;
	int arr3[10];

	for (int i = 0; i < 10; i++)
	{
		arr3[i] = rand() % 100 + 1;
	}

	for (int val : arr3)
	{
		cout << val << " ";
	}
	cout << endl;

	InsertSort(arr3, 10);

	for (int val : arr3)
	{
		cout << val << " ";
	}
	cout << endl;
	cout << "=================Ï£¶ûÅÅÐò====================" << endl;
	int arr4[10];

	for (int i = 0; i < 10; i++)
	{
		arr4[i] = rand() % 100 + 1;
	}

	for (int val : arr4)
	{
		cout << val << " ";
	}
	cout << endl;

	ShellSort(arr4, 10);

	for (int val : arr4)
	{
		cout << val << " ";
	}
	cout << endl;

	cout << "=========================´óÊý¾Ý²âÐÔÄÜ==========================" << endl;
	
	const int COUNT = 100000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	int* crr = new int[COUNT];
	int* drr = new int[COUNT];


	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;
		arr[i] = val;
		brr[i] = val;
		crr[i] = val;
		drr[i] = val;
	}

	clock_t begin, end;

	begin = clock();
	BubbleSort(arr, COUNT);
	end = clock();
	cout << "BubbleSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ChoiceSort(brr, COUNT);
	end = clock();
	cout << "ChoiceSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	InsertSort(crr, COUNT);
	end = clock();
	cout << "InsertSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ShellSort(drr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
