#include <iostream>
using namespace std;

struct Node
{
	Node(int data=0)
		:data_(data)
		, next_(nullptr)
		, pre_(nullptr)
	{}

	int data_;
	Node* next_;
	Node* pre_;
};

class DoubleLink {
public:
	DoubleLink() {
		head_ = new Node();
	}
	~DoubleLink(){
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		}
	}

public:
	//增
	//头插法
	void InsertHead(int val)
	{
		Node* p = new Node(val);
		p->next_ = head_->next_;
		p->pre_ = head_;
		head_->next_ = p;
	}
	// 尾插法
	void InsertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}

		Node* node = new Node(val);
		p->next_ = node;
		node->pre_ = p;
	}

	//删
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;
				if (p->next_ != nullptr)
				{
					p->next_->pre_ = p->pre_;
				}
				delete p;
				return;
			}

			else
			{
				p = p->next_;
			}
		}
	}
	//改

	//查
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
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


	void Show()
	{
		Node* p = head_->next_;
		while (p != nullptr)
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
	DoubleLink dlink;

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
	return 0;
}