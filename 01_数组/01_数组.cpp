#include<iostream>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "vld.h"

class Array {
public:
	//Constructor
	Array(int size = 10) :
		mCap(size), mCur(0)
	{
		mpArr = new int[mCap]();
	}
	~Array() 
	{
		delete[]mpArr;
		mpArr = nullptr;
	}
public:
	//Member functions
	//insert
	// 1. insert the tail
	void push_back(int val)
	{
		if (mCur == mCap)
			expand();
		mpArr[mCur++] = val;
	}
	// 2. insert a non-trailing position
	void insert(int val, int pos)
	{
		if (pos<0 || pos>mCap)
			return;

		if (mCur == mCap)
			expand();

		for (int i = mCur ; i>pos ; i--)
		{
			mpArr[i] = mpArr[i - 1];
		}
		mpArr[pos] = val;
		mCur++;
	}

	//delete
	//1.erase by position
	void erase(int pos)
	{
		if (pos < 0 || pos >= mCur)
			return;

		for (int i = pos + 1; i < mCur; i++)
			mpArr[i - 1] = mpArr[i];

		mCur--;
	}


	//change

	//search
	int find(int val)
	{
		for (int i = 0; i < mCur; i++)
		{
			if (mpArr[i] == val)
				return i;
		}

		return -1;
	}


	//expand
	void expand()
	{
		int* p = new int[mCap*2];
		memcpy(p, mpArr, sizeof(int) * mCap);
		delete[]mpArr;
		mpArr = p;
		mCap *= 2;
		p = nullptr;
	}

	//show the array
	void show()const 
	{
		for (int i = 0; i < mCur; i++)
			std::cout << mpArr[i]<<" ";
		std::cout << std::endl;
		std::cout << "Capacity of the array: " << mCap << "  " << " valid elements: " << mCur;
		std::cout << std::endl;
	}

private:
	//Member variables
	int* mpArr = nullptr; //Points to an array
	int  mCap  = 0;  //Capacity of the array
	int  mCur  = 0;  //Number of valid elements of the array

};


//�����ַ���
void Reverse(char arr[] , int size)
{
	char* p = arr;
	char* q = arr + size - 1;
	while (p < q)
	{
		char ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}


//�������飬��ż���������������ߣ�������������������ұ�
void AdjustArray(int arr[], int size)
{
	int* p = arr;
	int* q = arr + size - 1;
	while (p <q)
	{
		while (p < q)
		{
			if ((*p & 0x01) == 1)  //���������һλ��1��˵���������������κε���
				break;
			p++;
		}

		while (p < q)
		{
			if ((*q & 0x01) == 0)  //ͬ�ϣ��ж���ż��
				break;
			q--;
		}

		if (p < q)
		{
			int temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}
	}
}


int main()
{
	Array TestArray(10);

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		TestArray.push_back(rand() % 100);
	}

	TestArray.show();

	TestArray.insert(999, 2);
	TestArray.show();

	int pos = TestArray.find(999);
	if (pos != -1)
	{
		TestArray.erase(pos);
		TestArray.show();
	}

	std::cout << "---------Algorithm:Reverse Array --------------" << std::endl;
	char arr[] = "Hello World";
	std::cout << "A string: " << arr << std::endl;
	Reverse(arr, strlen(arr));
	std::cout << "Reverse  a string (two pointers) : " << arr << std::endl;

	std::cout << "---------Algorithm:Adjust Array --------------" << std::endl;
	int intArr[10] = { 0 };
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		intArr[i] = rand() % 100;
	}

	for (int v : intArr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	AdjustArray(intArr, 10);
	for (int v : intArr)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;


	return 0;
}