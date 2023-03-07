#include <iostream>
#include <functional>
#include <cstring>
#include <time.h>
class PriorityQueue
{
public:
	using Comp = std::function<bool(int, int)>;
	PriorityQueue(int cap=20,Comp comp = std::greater<int>())
		:size_(0)
		,cap_(cap)
		,comp_(comp)
	{
		que_ = new int[cap_];
	}

	PriorityQueue(Comp comp)
		: size_(0)
		, cap_(20)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue()
	{
		delete[]que_;
		que_ = nullptr;
	}

public:
	//���
	void push(int val)
	{
		if (size_ == cap_)
		{
			int* p = new int[cap_ * 2];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[]que_;
			que_ = p;
			p = nullptr;
			cap_ *= 2;
		}
		if (size_ == 0)
		{
			que_[size_] = val;
		}
		else
		{
			siftUp(size_,val);
		}
		size_++;
	}
	//����
	void pop()
	{
		if (size_ == 0)
			throw "container is empty";
		size_--;
		if (size_ > 0)
		{
			siftDown(0,que_[size_]);
		}
	}

	//�п�
	bool isempty()const { return size_ == 0; }
	//��ȡ��С
	bool size()const { return size_; }
	//��ȡ����Ԫ��
	int top()const
	{
		if (size_ == 0)
			throw "container is empty";
		return que_[0];
	}

private:
	void siftUp(int i , int val)
	{
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (comp_(val, que_[father]))
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}
	void siftDown(int i , int val)
	{
		while (i<size_/2)
		{
			int child = 2 * i + 1;
			if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))
			{
				child += 1;
			}

			if (comp_(que_[child], val))
			{
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}
private:
	int* que_;
	int size_;
	int cap_;
	Comp comp_;

};
int main()
{
	// PriorityQueue que; // ���ڴ����ʵ�ֵ����ȼ�����
	// ����С����ʵ�ֵ����ȼ�����
	PriorityQueue que([](int a, int b) {return a < b; });
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		que.push(rand() % 100);
	}

	while (!que.isempty())
	{
		std::cout << que.top() << " ";
		que.pop();
	}
	std::cout << std::endl;
	return 0;
}