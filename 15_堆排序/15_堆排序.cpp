#include <iostream>

void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < size / 2)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child += 1;
		}
		if (arr[child] > val)
		{
			arr[i] = arr[child];
			i = child;
		}
		else
		{
			break;
		}
		
	}
	arr[i] = val;
}

void HeapSort(int arr[], int size)
{
	int n = size - 1;
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}

	for (int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		siftDown(arr, 0, i);
	}

}

int main()
{
	int arr[10] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	for (int v : arr)
	{
		std::cout<<v<<" ";
	}
	std::cout << std::endl;

	HeapSort(arr, 10);

	for (int v : arr)
	{
		std::cout << v << " ";
	}

	return 0;
}