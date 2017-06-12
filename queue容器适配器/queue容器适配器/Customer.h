#pragma once
class Customer
{
private:
	size_t service_t{};//结账时间默认为10
public:
	explicit Customer(size_t st = 10):service_t{st}{}

	Customer & time_decrement()
	{
		if (service_t > 0)
			--service_t;
		return *this;
	}
	bool done() const { return service_t == 0; };
};