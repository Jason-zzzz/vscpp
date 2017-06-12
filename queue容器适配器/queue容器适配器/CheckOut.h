#pragma once
#include <queue>
#include "Customer.h"

using namespace std;

class Checkout
{
private:
	queue<Customer> customers;
public:
	void add(const Customer& customer) { customers.push(customer); }//��ӹ˿�
	size_t qlength() const { return customers.size(); }//�˿͸���
	void time_increment()
	{
		if (!customers.empty())
		{
			if (customers.front().time_decrement().done())
				customers.pop();
		}
	};
	bool operator<(const Checkout& other) const { return qlength() < other.qlength(); };
	bool operator>(const Checkout& other) const { return qlength() > other.qlength(); };
};