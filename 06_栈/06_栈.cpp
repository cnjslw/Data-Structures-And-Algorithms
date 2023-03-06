#include <iostream>
using namespace std;

class SeqStack{
public:
	SeqStack(int size = 10)
		: mptop(0)
		, mcap(size)
	{
		mpStack = new int[size];
	}
	~SeqStack()
	{
		delete[]mpStack;
		mpStack = nullptr;
	}

public:
	//��
	void push(int val)
	{
		if (mptop == mcap)
		{
			expand();
		}
		mpStack[mptop++] = val;
	}
	//ɾ
	void pop()
	{
		if (mptop == 0)
		{
			throw "stack is empty!";
		}
		mptop--;
	}

	//ȡջ��Ԫ��
	int top()const
	{
		if(mptop ==0)
		{
			throw "stack is empty!";
		}
		return mpStack[mptop - 1];
			
	}
	//�п�
	bool isempty()const
	{
		return mptop == 0;
	}
	//��
	//��


//���ݳ�Ա
	//����
// 	void expand()
// 	{
// 		SeqStack p(mcap * 2);
// 		for (int i = mptop - 1; i >= 0; i--)
// 		{
// 			p.mpStack[p.mptop++] = mpStack[i];
// 		}
// 		delete[]mpStack;
// 		mpStack = p.mpStack;
// 	}

private:
	void expand()
	{
		int* p = new int[mcap * 2];
		memcpy(p, mpStack, mptop * sizeof(int));
		delete[]mpStack;
		mpStack = p;
		mcap *= 2;
	}
private:
	int* mpStack;
	int  mptop;
	int  mcap;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75,99,100,142,16 };
	SeqStack s;
	for (int val : arr)
	{
		s.push(val);
	}

	while (!s.isempty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}