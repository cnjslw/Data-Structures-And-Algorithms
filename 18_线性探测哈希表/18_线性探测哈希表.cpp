#include <iostream>
enum State
{
	STATE_UNUSE,
	STATE_USING,
	STATE_DEL,
};

struct Bucket {
	Bucket(int key = 0, State state = STATE_UNUSE)
		:key_(key)
		, state_(state)
	{}
	
	int key_;
	State state_;
};

class HashTable
{
public:
	HashTable(int size = primes_[0],double loadFactor =0.75)
		:useBucketNum_(0)
		,loadFactor_(loadFactor)
		,primeIdx_(0) 
	{
		if (size != primes_[0])
		{
			//�����û�������ȡ����һ���������������
			for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
			{
				if (primes_[primeIdx_] >= size)break;
			}
			if (primeIdx_ == PRIME_SIZE)primeIdx_--;
		}
		tableSize_ = primes_[primeIdx_];
		table_ = new Bucket[tableSize_];
	}


	~HashTable() 
	{
		delete[]table_;
		table_ = nullptr;
	}

public:
	//����Ԫ��
	bool insert(int val)
	{
		//��������
		//����װ������
		double factor = (1.0*useBucketNum_)/tableSize_;
		std::cout << "factor: " << factor << std::endl;
		if (factor>=loadFactor_)
		{
			expand();
		}

		int idx = val % tableSize_;
		
		int i = idx;
		do 
		{
			if (table_[i].state_ != STATE_USING)
			{
				table_[i].key_ = val;
				table_[i].state_ = STATE_USING;
				useBucketNum_++;
				return true;
			}
			i = (i + 1) % tableSize_;
		} while (i != idx);

		return false;
	}

	//ɾ��
	bool erase(int val)
	{
		int idx = val % tableSize_;
		int i = idx;
		do
		{
			if (table_[i].state_ == STATE_USING && table_[i].key_ == val)
			{
				table_[i].state_ = STATE_DEL;
				useBucketNum_--;
				return true;
			}

			i = (i + 1) % tableSize_;
		} while (table_[i].state_ != STATE_UNUSE && i != idx);

		return true;
	}

	//��
	bool find(int key)
	{
		int idx = key % tableSize_;

		int i = idx;
		do
		{
			if (table_[i].state_ == STATE_USING && table_[i].key_ == key)
			{
				return true;
			}
			i = (i + 1) % tableSize_;
		} while (table_[i].state_ != STATE_UNUSE && i != idx);

		return false;
	}
private:
	void expand()
	{
		primeIdx_++;
		if (primeIdx_ == PRIME_SIZE)
		{
			throw "Hash Table is too large , can not expand anymore";
		}

		Bucket* newTable = new Bucket[primes_[primeIdx_]];
		for (int i = 0; i < tableSize_; i++)
		{
			if (table_[i].state_ == STATE_USING)
			{
				int idx = table_[i].key_ % primes_[primeIdx_];
				int k = idx;
				do 
				{
					if (newTable[k].state_ != STATE_USING)
					{
						newTable[k].key_ = table_[i].key_;
						newTable[k].state_ = STATE_USING;
						break;
					}
					k = (k + 1) % primes_[primeIdx_];
				} while (k!=idx);
			}
		}

		delete[]table_;
		table_ = newTable;
		newTable = nullptr;
		tableSize_ = primes_[primeIdx_];
	}

private:
	Bucket* table_;    // ָ��̬���ٵĹ�ϣ��
	int tableSize_;    // ��ϣ��ǰ�ĳ���
	int useBucketNum_; // �Ѿ�ʹ�õ�Ͱ�ĸ���
	double loadFactor_;// ��ϣ���װ������

	static const int PRIME_SIZE = 10; // ������Ĵ�С
	static int primes_[PRIME_SIZE];   // ������
	int primeIdx_; // ��ǰʹ�õ������±�
};

int HashTable::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

int main()
{
	HashTable htable;
	htable.insert(21);
	htable.insert(32);
	htable.insert(14);
	htable.insert(15);

	htable.insert(22);

	std::cout << htable.find(21) << std::endl;
	htable.erase(21);
	std::cout << htable.find(21) << std::endl;
	return 0;
}