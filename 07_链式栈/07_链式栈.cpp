
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Priority(char ch, char topch)
{
	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
	{
		return true;
	}
	if (topch == '(' && ch != ')')
	{
		return true;
	}

	return false;
}

string MiddleToEnd(string expr)
{
	string result;
	stack<char> s;
	for (char ch : expr)
	{
		if (ch >= '0' && ch <= '9')
		{
			result.push_back(ch);
		}
		else
		{
			for (;;)
			{
				if (s.empty() || ch == '(')
				{
					s.push(ch);
					break;
				}

				char topch = s.top();

				if (Priority(ch, topch))
				{
					s.push(ch);
					break;
				}
				else
				{
					s.pop();
					if (topch == '(')
						break;
					result.push_back(topch);
				}
			}
		}
	}

	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}
	return result;
}

class LinkStack {

public:
	LinkStack(int size = 10)
		:size_(size)
	{
		head_ = new Node[size];
	}

	~LinkStack()
	{
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = p->next_;
			delete p;
			p = head_;
		}
	}

public:
	void push(int val)
	{
		Node* p = new Node(val);
		p->next_ = head_->next_;
		head_->next_ = p;
		size_++;
	}

	void pop()
	{
		if (head_->next_ == nullptr)
		{
			throw "Stack is Empty!";
		}

		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
		size_--;
	}

	int top()
	{
		if (head_->next_ == nullptr)
		{
			throw "Stack is Empty!";
		}

		return head_->next_->data_;
	}

	bool isempty()const
	{
		return head_->next_ == nullptr;
	}

	int size() const
	{
		return size_;
	}

private:
	struct Node
	{
		Node(int data = 0)
			:data_(data)
			, next_(nullptr)
		{}

		int data_;
		Node* next_;
	};

	Node* head_;
	int size_;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkStack s;

	for (int v : arr)
	{
		s.push(v);
	}

	cout << s.size() << endl;

	while (!s.isempty())
	{
		cout<<s.top() << " ";
		s.pop();
	}
	cout << endl;

	cout << s.size() << endl;

	cout << "-----------------中缀表达式转后缀表达式(逆波兰表达式)---------------------" << endl;
	cout <<"(1+2)*(3+4)" << "  -> " <<MiddleToEnd("(1+2)*(3+4)") << endl;
	cout << "2+(4+6)/2+6/3" << "  -> " <<MiddleToEnd("2+(4+6)/2+6/3") << endl;
	cout << "2+6/(4-2)+(4+6)/2" <<"  -> " << MiddleToEnd("2+6/(4-2)+(4+6)/2") << endl;
}
