#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
class LinkHash {
public:
	LinkHash(int size = primes_[0], double loadFactor = 0.75)
		:useBucketNum_(0)
		, loadFactor_(loadFactor)
		, primeIdx_(0)
	{
		if (size != primes_[0])
		{
			for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
			{
				if (primes_[primeIdx_] >= size)break;
			}

			if (primeIdx_ == PRIME_SIZE)
				primeIdx_--;
		}

		table_.resize(primes_[primeIdx_]);
	}

public:
	//Ôö
	void insert(int val)
	{
		double factor = useBucketNum_ * 1.0 / table_.size();
		std::cout << "factor: " << factor << std::endl;
		if (factor >= loadFactor_)
		{
			expand();
		}

		int idx = val % table_.size();
		if (table_[idx].empty())
		{
			useBucketNum_++;
			table_[idx].emplace_front(val);
		}
		else
		{
			auto it = std::find(table_[idx].begin(), table_[idx].end(), val);
			if (it == table_[idx].end())
			{
				table_[idx].emplace_front(val);
			}
		}
	}
	//É¾
	void erase(int val)
	{
		int idx = val % table_.size();
		auto it = std::find(table_[idx].begin(), table_[idx].end(), val);
		if (it != table_[idx].end())
		{
			table_[idx].erase(it);
			if (table_[idx].empty())
				useBucketNum_--;
		}
	}
	//²é
	bool find(int val)
	{
		int idx = val % table_.size();  
		auto it = std::find(table_[idx].begin(), table_[idx].end(), val); 
		return it != table_[idx].end();
	}
private:
	void expand()
	{
		if (primeIdx_ + 1 == PRIME_SIZE)
		{
			throw "hashtable can not expand anymore!";
		}

		primeIdx_++;
		useBucketNum_ = 0;

		std::vector<std::list<int>> oldTable;
		table_.swap(oldTable);
		table_.resize(primes_[primeIdx_]);

		for (auto lists : oldTable)
		{
			for (auto keys : lists)
			{
				int idx = keys % table_.size();
				if (table_[idx].empty())
					useBucketNum_++;

				table_[idx].emplace_front(keys);
			}			
		}
	}
private:
	std::vector<std::list<int>> table_;
	int useBucketNum_;
	double loadFactor_;

	static const int PRIME_SIZE = 10;
	static int primes_[PRIME_SIZE];
	int primeIdx_;
};
int LinkHash::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

int main()
{
	LinkHash htable;
	htable.insert(21);
	htable.insert(32);
	htable.insert(14);
	htable.insert(15);

	htable.insert(22);

	htable.insert(67);

	std::cout << htable.find(67) << std::endl;
	htable.erase(67);
	std::cout << htable.find(67) << std::endl;

	return 0;
	return 0;
}