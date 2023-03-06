#include <iostream>
#include <cstring>
using namespace std;
class Queue {
public:
	Queue(int cap=10)
		:cap_(cap)
		, front_(0)
		, rear_(0)
		,size_(0)
	{
		pQue_ = new int[cap_];
	}
	~Queue()
	{
		delete []pQue_;
		pQue_ = nullptr;
	}

public:
	//增(入队)
	void push(int val)
	{
		if (((rear_ + 1) % cap_) == front_)
		{
			expand();
		}

		pQue_[(rear_ + 1) % cap_ - 1] = val;
		rear_ = (rear_ + 1) % cap_;
		size_++;
	}

	//删(出队)
	void pop()
	{
		if (front_ == rear_)
		{
			throw "队列已经是空的";
		}

		front_ = (front_ + 1) % cap_;
		size_--;
	}
	//判空
	bool empty()
	{
		return front_ == rear_;
	}
	//队头元素
	int front() const 
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[front_];
	}
	//队尾元素
	int back() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[rear_-1];
	}


	//扩容
// 	void expand()
// 	{
// 		int* p = new int[cap_*2];
// 		memcpy(p, pQue_, sizeof(int) * cap_);
// 		delete pQue_;
// 		pQue_ = p;
// 		p = nullptr;
// 	}

	void expand()
	{
		int* p = new int[cap_ * 2];
		int i = 0;
		int j = front_;
		for (; j != rear_; i++, j = (j + 1) % cap_)
		{
			p[i] = pQue_[j];
		}

		delete[]pQue_;
		pQue_ = p;
		cap_ *= 2;
		front_ = 0;
		rear_ = i;
	}


private:
	int* pQue_;
	int cap_;
	int front_;
	int rear_;
	int size_;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };

	Queue que;

	for (int v : arr)
	{
		que.push(v);
	}

	cout << que.front() << endl;
	cout << que.back() << endl;

	que.push(100);
	que.push(200);
	que.push(300);
	cout << que.front() << endl;
	cout << que.back() << endl;

	while (!que.empty())
	{
		cout << que.front() << " " << que.back() << endl;
		que.pop();
	}

	return 0;
}