#include <iostream>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

void RadixSort(int arr[], int size)
{
	int Max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (Max < arr[i])
		{
			Max = arr[i];
		}
	}

	int len = to_string(Max).size();

	vector<vector<int>> svec;

	int mod = 10;
	int dev = 1;
	for (int i = 0; i < len; mod *= 10, dev *= 10, i++)
	{
		svec.resize(10);
		for (int j = 0; j < size; j++)
		{
			int index = arr[j] % mod / dev;
			svec[index].push_back(arr[j]);
		}

		int idx = 0;
		for (auto vec : svec)
		{
			for (auto val : vec)
			{
				arr[idx++] = val;
			}
		}
		svec.clear();
	}
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

	RadixSort(arr, 10);

	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
	return 1;
}