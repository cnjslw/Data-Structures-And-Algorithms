#include <iostream>
using namespace std;
// 基于单向循环链表
// struct Node {
// 
// 	Node(int data =0)
// 		:data_(data) 
// 		, next_(nullptr)
// 	{}
// 
// 	int data_;
// 	Node* next_;
// };
// 
// class CircleLine {
// 
// public:
// 
// //  这个方法不能为每一个node赋值
// // 	CircleLine(int size = 10)
// // 		:size_(size)
// // 	{
// // 		head_ = new Node;
// // 		for (int i = size_; i > 0; i++)
// // 		{
// // 			
// // 		}
// // 		
// // 	}
// 
// 	CircleLine()
// 	{
// 		head_ = new Node();
// 		tail_ = head_;
// 		head_->next_ = head_;
// 	}
// 	~CircleLine()
// 	{
// 		Node* p = head_;
// 		while (p != tail_)
// 		{
// 			head_ = p->next_;
// 			delete  p;
// 			p = head;
// 		}
// 	}
// 
// private:
// 	Node* head_;
// 	Node* tail_;
// //	int size_;
// };

//基于双向循环链表
struct Node {
	Node(int data=0)
		:data_(data)
		,pre_(nullptr)
		,next_(nullptr)
	{}

	int data_;
	Node* pre_;
	Node* next_;
};


class LinkQueue
{
public:
	LinkQueue()
	{
		head_ = new Node;
		head_->next_ = head_;
		head_->pre_ = head_;
	}

	~LinkQueue()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;
		}
		delete head_;
		head_ = nullptr;
	}

public:
	//出队
	void push(int val)
	{
		Node* p = new Node(val);
		p->next_ = head_;
		p->pre_ = head_->pre_;
		head_->pre_->next_ = p;
		head_->pre_ = p;
	}
	//入队
	void pop()
	{
		Node* p = head_->next_;
		head_->next_ = p->next_;
		p->next_->pre_ = head_;
		delete p;
	}

	int front()const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->next_->data_;
	}
	int back() const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->pre_->data_;
	}
	// 判空
	bool empty() const
	{
		return head_->next_ == head_;
	}
private:
	Node* head_;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkQueue que;

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
}