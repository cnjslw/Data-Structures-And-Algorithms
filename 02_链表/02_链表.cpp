#include <iostream>
using namespace std;
struct Node
{
	Node(int data = 0) :data_(data), next_(nullptr) {}
	int data_;
	Node* next_;
};

class Clink
{
public:
	Clink() {
		head_ = new Node();
	}
	~Clink() {
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		}
		head_ = nullptr;
	}

public:
	//1.增
	//1.1 头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
	}
	//1.2 尾插法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		p->next_ = node;
	}

	//删
	void Remove(int val)
	{
		Node* p = head_;
		Node* q = head_->next_;
		while (p != nullptr)
		{
			if (q->data_ != val)
			{
				p = q;
				q = q->next_;
			}
			else
			{
				p->next_ = q->next_;
				delete q;
				return;
			}
		}
		
	}
	//如果存在多个相同数据的节点
	void RemoveAll(int val)
	{
		Node* p = head_;
		Node* q = head_->next_;
		while (q != nullptr)
		{
			if (q->data_ != val)
			{
				p = q;
				q = q->next_;
			}
			else
			{
				p->next_ = q->next_;
				delete q;
				q = p->next_;
			}
		}
		
	}
	//查
	bool Find(int val)
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

	//打印
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

	friend void ReverseLink(Clink&);
	friend bool GetLastKNode(Clink&, int, int&);
	friend void MergeLink(Clink&, Clink&);
	bool IsLinkHasCircle(Node*, int&);
	bool IsLinkHasMerge(Node*, Node*, int&);



private:
	Node* head_;


};

void ReverseLink(Clink& link)
{
	Node* head = link.head_;
	Node* p = head->next_;
	if (p == nullptr)
	{
		return;
	}

	head->next_ = nullptr;
	while (p != nullptr)
	{
		Node* q = p->next_;
		//头插法
		p->next_ = head->next_;
		head->next_ = p;
		
		p = q;
	}
}

bool GetLastKNode(Clink& link, int k, int& val)
{
	Node* head = link.head_;
	Node* pre = head;
	Node* p = head;

	if (k < 1)
	{
		return false;
	}

	for (int i = 0; i < k; i++)
	{
		p = p->next_;
		if (p == nullptr)
		{
			return false;
		}
	}

	while (p != nullptr)
	{
		pre = pre->next_;
		p = p->next_;
	}

	val = pre->data_;
	return true;
}

void MergeLink(Clink& link1, Clink& link2)
{
	Node* p = link1.head_->next_;
	Node* q = link2.head_->next_;
	Node* last = link1.head_;
	link2.head_->next_ = nullptr;

	while (p != nullptr && q != nullptr)
	{
		if (p->data_ < q->data_)
		{
			last->next_ = p;
			p = p->next_;
			last = last->next_;
		}
		else
		{
			last->next_ = q;
			q = q->next_;
			last = last->next_;
		}
	}

	if (p != nullptr)
	{
		last->next_ = p;
	}
	else
	{
		last->next_ = q;
	}
	
}

bool IsLinkHasMerge(Node* head1, Node* head2, int& val)
{
	int cnt1 = 0, cnt2 = 0;
	Node* p = head1->next_;
	Node* q = head2->next_;

	while (p != nullptr)
	{
		cnt1++;
		p = p->next_;
	}
	while (q != nullptr)
	{
		cnt2++;
		q = q->next_;
	}

	p = head1;
	q = head2;
	if (cnt1 > cnt2)
	{
		int offset = cnt1 - cnt2;
		while (offset-- > 0)
		{
			p = p->next_;
		}
	}
	else
	{
		int offset = cnt1 - cnt2;
		while (offset-- > 0)
		{
			q = q->next_;
		}
	}

	while (p != nullptr && q != nullptr)
	{
		if (p == q)
		{
			val = p->data_;
			return true;
		}
		p = q->next_;
		q = q->next_;
	}

	return false;
}

bool IsLinkHasCircle(Node* head, int& val)
{
	Node* fast = head;
	Node* slow = head;
	while (fast != nullptr && fast->next_ != nullptr)
	{
		slow = slow->next_;
		fast = fast->next_->next_;

		if (slow == fast)
		{
			fast = head;
			while (fast != slow)
			{
				slow = slow->next_;
				fast = fast->next_;
			}
			val = slow->data_;
			return true;
		}
	}
	return false;
}

int main()
{
	Clink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertHead(val);
		cout << val << " ";
	}
	cout << endl;

	link.InsertTail(23);
	link.InsertHead(23);
	link.InsertHead(23);

	link.Show();

	link.RemoveAll(23);
	link.Show();

	cout << "-----------------逆序链表----------------" << endl;
	ReverseLink(link);
	link.Show();
	cout << "-----------------求倒数第k个节点----------------" << endl;
	int kval;
	int k = 6;
	if (GetLastKNode(link, k, kval))
	{
		cout << "倒数第" << k << "个节点的值:" << kval << endl;
	}
	else
	{
		cout << "倒数第" << k << "个节点不存在" << endl;
	}
	cout << "-----------------融合两个有序列表----------------" << endl;
	int arr[] = { 25, 37, 52, 78, 88, 92, 98, 108 };
	int brr[] = { 13, 23, 40, 56, 62, 77, 109 };

	Clink link1;
	Clink link2;

	for (int v : arr)
	{
		link1.InsertTail(v);
	}

	for (int v : brr)
	{
		link2.InsertTail(v);
	}

	link1.Show();
	link2.Show();

	MergeLink(link1, link2);
	link1.Show();

	

	Node head;
	Node n1(25), n2(67), n3(32), n4(18);
	head.next_ = &n1;
	n1.next_ = &n2;
	n2.next_ = &n3;
	n3.next_ = &n4;
	n4.next_ = &n4;

	int valIn;
	if (IsLinkHasCircle(&head, valIn))
	{
		cout << "链表存在环，环的入口节点是：" << valIn << endl;
	}

	cout << "-----------------判断是否相交----------------" << endl;
	Node head1;
	Node head2;
	Node t1(25), t2(67), t3(32), t4(18);
	Node m1(38), m2(96);
	head1.next_ = &t1;
	t1.next_ = &t2;
	t2.next_ = &t3;
	t3.next_ = &t4;

	head2.next_ = &m1;
	m1.next_ = &m2;
	m2.next_=  &t4;
	int valueMer = 0;
	if (IsLinkHasMerge(&head1, &head2, valueMer))
	{
		cout << "两个链表相交 , 相交于 : "<<valueMer<< endl;
	}
	else
	{
		cout << "两个链表不相交" << endl;
	}

	cout << "-----------------判断链表是否有环----------------" << endl;
	int val;
	if (IsLinkHasCircle(&head, val))
	{
		cout << "链表存在环，环的入口节点是：" << val << endl;
	}
	return 0;
}