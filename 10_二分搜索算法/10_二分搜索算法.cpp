#include <iostream>
using namespace std;
int BinarySearch(int* arr , int size, int val)
{
	int first = 0, last = size;

	while (first <= last)
	{
		int middle = (first + last) / 2;
		if (arr[middle] == val)
		{
			return middle;
		}
		else if (arr[middle] > val)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}

	return -1;
}

int BinarySearch(int* arr, int i, int j, int val)
{

	if(i>j)return -1;

	int middle = (i + j) / 2;
	if (arr[middle] == val)
	{
		return middle;
	}
	else if (arr[middle] < val)
	{
		BinarySearch(arr, middle + 1, j, val);
	}
	else
	{
		BinarySearch(arr, i, middle - 1, val);
	}


}

int main()
{
	int arr[] = { 1,3,6,12,88,100 };
	int result = BinarySearch(arr, sizeof(arr) / sizeof(arr[0]), 88);
	if ( result>= 0)
	{
		cout<<"Find It !!!!"<< " At "<<result+1 <<"   ====·Çµİ¹éº¯Êı====  " << endl;
	}
	result = BinarySearch(arr, 0, 5, 77);
	if (result >= 0)
	{
		cout << "Find It !!!!" << " At " << result + 1 << "   ====µİ¹éº¯Êı====  " << endl;
	}
	else
	{
		cout << "Not Find It"<< "   ====µİ¹éº¯Êı====  " << endl;
	}
	
	return 0;
}
