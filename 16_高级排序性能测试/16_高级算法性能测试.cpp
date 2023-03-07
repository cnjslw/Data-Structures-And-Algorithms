// 16_�߼��������ܲ���.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <algorithm>
using namespace std;

// �ѵ��³�����
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < size / 2)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child = child + 1;
		}

		if (arr[child] > val)
		{
			arr[i] = arr[child];
			i = child;  // i����ָ�����ĺ��ӣ���������
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}

// ������
void HeapSort(int arr[], int size)
{
	int n = size - 1;
	// �ӵ�һ����Ҷ�ӽڵ�
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}

	// �ѶѶ�Ԫ�غ�ĩβԪ�ؽ��н������ӶѶ���ʼ�����³�����
	for (int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		siftDown(arr, 0, i); // ���������������������Ԫ�صĸ���
	}
}

// �鲢���̺���  O(n)
void Merge(int arr[], int l, int m, int r, int* p)
{
	int idx = 0;
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}

	while (i <= m)
	{
		p[idx++] = arr[i++];
	}

	while (j <= r)
	{
		p[idx++] = arr[j++];
	}

	// �ٰѺϲ��õĴ������Ľ����������ԭʼarr����[l,r]������
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}
}

// �鲢����ݹ�ӿ�
void MergeSort(int arr[], int begin, int end, int* p)
{
	// �ݹ����������
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	// �ȵ�
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	// �ٹ鲢  [begin, mid]  [mid+1, end] ������С����������У��ϲ��ɴ�����������
	Merge(arr, begin, mid, end, p);
}

// �鲢����
void MergeSort(int arr[], int size)
{
	int* p = new int[size];  // O(n)
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
}

// ���ŷָ����
int Partation(int arr[], int l, int r)
{
	// ѡ���׼�����Ż���������ȡ�С���   arr[l]   arr[r]   arr[(l+r)/2]  
	// ��¼��׼��
	int val = arr[l];

	// һ�ο��Ŵ���   ʱ�䣺O(n) * O(logn) = O(nlogn)    �ռ䣺O(logn) �ݹ�������ռ�õ�ջ�ڴ�
	while (l < r)
	{
		while (l < r && arr[r] > val)
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

	// l == r��λ�ã����ǷŻ�׼����λ��
	arr[l] = val;
	return l;
}

// ���ŵĵݹ�ӿ�
void QuickSort(int arr[], int begin, int end)
{
	if (begin >= end) // ���ŵݹ����������
	{
		return;
	}

	// �Ż�һ����[begin, end]���е�Ԫ�ظ���С��ָ�����������ò�������
	//if (end - begin <= 50)
	//{
		// InsertSort(arr, begin, end);
		//return;
	//}

	// ��[begin, end]�����Ԫ����һ�ο��ŷָ��
	int pos = Partation(arr, begin, end);

	// �Ի�׼������ߺ��ұߵ����У��ٷֱ���п���
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos + 1, end);
}

// ��������
void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
}

// ϣ������
void ShellSort(int arr[], int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2) // 100W 19 1000W 24
	{
		for (int i = gap; i < size; i++) // O(n)
		{
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap) // O(n)
			{
				if (arr[j] <= val)
				{
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}
	}
}

int main()
{
	cout << RAND_MAX << endl;

	const int COUNT = 100000000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	/*int* crr = new int[COUNT];
	int* drr = new int[COUNT];*/

	srand(time(NULL));

	// 0 - 32767    32768 - 32768+32767 
	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;  // 0 - 32767
		arr[i] = val;
	}

	clock_t begin, end;

	memcpy(brr, arr, COUNT * sizeof(int));

	begin = clock();
	QuickSort(brr, COUNT);
	end = clock();
	cout << "QuickSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	memcpy(brr, arr, COUNT * sizeof(int));

	begin = clock();
	MergeSort(brr, COUNT);
	end = clock();
	cout << "MergeSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	memcpy(brr, arr, COUNT * sizeof(int));

	begin = clock();
	ShellSort(brr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	memcpy(brr, arr, COUNT * sizeof(int));

	begin = clock();
	HeapSort(brr, COUNT);
	end = clock();
	cout << "HeapSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
}