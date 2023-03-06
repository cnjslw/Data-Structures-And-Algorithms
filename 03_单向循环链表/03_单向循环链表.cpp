#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Node
{
	Node(int data = 0)
		:data_(data), next_(nullptr)
	{}

	int data_;
	Node* next_;
};

class CircleLink
{
public:
	CircleLink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}

	~CircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			delete p;
			p = head_->next_;
		}
		delete head_;
	}
public:
	//增
	//尾插法
	void InsertTail(int val)
	{
		Node* p = new Node(val);
		tail_->next_ = p;
		tail_ = p;
		tail_->next_ = head_;
		p = nullptr;
	}
	//头插法
	void InsetHead(int val)
	{
		Node* p = new Node(val);
		p->next_ = head_->next_;
		head_->next_ = p;
		if (p->next_ == head_)
		{
			tail_ = p;
		}

		p = nullptr;
	}
	//删
	bool Remove(int val)
	{
		Node* q = head_;
		Node* p = head_->next_;
		
		while (p != head_)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;
				if (q->next_ == head_)
				{
					tail_ = q;
				}

				p = nullptr;
				return true;
			}
			else
			{
				q = p;
				p = p->next_;
			}
		}
		return false;
	}
	//改

	//查
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p->next_ != head_)
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

	//展示链表
	void Show()const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->data_ << " --> ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	Node* head_;
	Node* tail_;
};

void Joseph(Node* head , int k , int m)
{
	Node* p = head;
	Node* q = head;

	while (q->next_ != head)
	{
		q = q->next_;
	}

	for (int i = 1; i < k; i++)
	{
		q = p;
		p = p->next_;
	}

	for (;;)
	{
		for (int i = 1; i < m; i++)
		{
			q = p;
			p = p->next_;
		}

		cout << p->data_ << " ";

		if (p == q)
		{
			delete p;
			break;
		}

		q->next_ = p->next_;
		delete p;
		p = q->next_;

	}
}


int main()
{
	CircleLink clink;
	srand(time(NULL));
	clink.InsetHead(100);

	for (int i = 0; i < 10; i++)
	{
		clink.InsertTail(rand()%100);
	}

	clink.InsertTail(200);
	clink.Show();

	clink.InsertTail(300);
	clink.Show();
	
	cout << "-------------------------约瑟夫环问题----------------------------" << endl;

	Node* head = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);

	head->next_ = n2;
	n2->next_ = n3;
	n3->next_ = n4;
	n4->next_ = n5;
	n5->next_ = n6;
	n6->next_ = n7;
	n7->next_ = n8;
	n8->next_ = head;

	Joseph(head, 1, 5);

	return 0;
}
