#include <iostream>
using namespace std;

struct Node
{
	Node(int data = 0)
		: data_(data)
		, pre_(nullptr)
		, next_(nullptr)
	{}

	int data_;
	Node* pre_;
	Node* next_;
};

class DoubleCircleLink {
public:
	DoubleCircleLink()
	{
		       head_  = new Node();
		head_->next_  = head_;
		 head_->pre_  = head_;
	}

	~DoubleCircleLink() 
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;
		}

		delete head_;
		head_ = nullptr;
	}

	//增
	// 头插法
	void InsertHead(int val)
	{
		Node* p = new Node(val);
		p->next_ = head_->next_;
		p->pre_ = head_;
		head_->next_->pre_ = p;
		head_->next_ = p;
	}
	// 尾插法
	void InsertTail(int val)
	{
		Node* p = new Node(val);
		Node* node = head_->pre_;
//		Node* node = head_;
// 		while (node->next_ != head_)
// 		{
// 			node = node->next_;
// 		}
		
		p->next_ = node->next_;
		p->pre_ = node;
		node->next_->pre_ = p;
		node->next_ = p;




	}

	//删
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				p->next_->pre_ = p->pre_;
				p->pre_->next_ = p->next_;
				delete p;
				return;
			}
			else
			{
				p = p->next_;
			}
		}
	}
	//查
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				return true;
			}
			else
			{
				p = p->next_;
			}
		}
		return false;
	}

	//Show
	void Show()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}

private:
	Node* head_;
};

int main()
{
	DoubleCircleLink dlink;

	dlink.InsertHead(100);

	dlink.InsertTail(20);
	dlink.InsertTail(12);
	dlink.InsertTail(78);
	dlink.InsertTail(32);
	dlink.InsertTail(7);
	dlink.InsertTail(90);
	dlink.Show();

	dlink.InsertHead(200);
	dlink.Show();

	dlink.Remove(200);
	dlink.Show();

	dlink.Remove(90);
	dlink.Show();

	dlink.Remove(78);
	dlink.Show();
}