#include <numeric>
#include <iomanip>
#include <deque>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <random>
#include "CheckOut.h"

using uint = unsigned int;
using distribution = uniform_int_distribution<>;//随机数平均分布关键词
using namespace std;

void histogram(const vector<int>& v, int min)
{
	string bar(60, '*');
	for (size_t i = {}; i < v.size(); i++)
	{
		//setw控制输出间隔,substr:输出某段  输出各服务时间及其人数
		cout << setw(3) << i + min << " " << setw(4) << v[i] << " " << bar.substr(0, v[i]) << (v[i] > static_cast<int>(bar.size()) ? "..." : "") << endl;
	}
}

int main()
{
	//创建
	queue<string> words;
	queue<string, list<string>> words1;

	//元素访问
	deque<double> values{ 1.5,2.5,3.5,4.5 };
	queue<double> numbers(values);
	while (!numbers.empty())
	{
		cout << numbers.front() << " ";
		numbers.pop();//必须出栈
	}
	cout << endl;

	/***********************模拟结账*****************************/

	random_device random_n;//随机数生成器

	int service_t_min(2), service_t_max{ 15 };//时间
	distribution service_t_d{ service_t_min,service_t_max };//生成结账时间随机数

	int min_customers{ 15 }, max_customers{ 20 };
	distribution n_1st_customers_d { min_customers,max_customers };//开门时等待顾客个数

	int min_arr_interval{ 1 }, max_arr_interval{ 5 };
	distribution arrival_interval_d{ min_arr_interval,max_arr_interval };//顾客到达间隔

	size_t n_checkouts{};//结账台个数
	cout << "Enter the number of checkouts in the supermarket:";
	cin >> n_checkouts;

	if (!n_checkouts)
	{
		cout << "Number of checkouts must be greater than 0. Settin to 1." << endl;
		n_checkouts = 1;
	}


	vector<Checkout> checkouts{ n_checkouts };//创建收银台
	vector<int> service_times(service_t_max - service_t_min + 1);//收银时间段

	int count{ n_1st_customers_d(random_n) };//生成n_1st_customers范围的随机数
	cout << "Customers waiting at store opening:" << count << endl;
	int added{};
	int service_t{};
	while (added++ < count)
	{
		service_t = service_t_d(random_n);//生成收银时间随机数
		min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//从最少的收银台后面添加顾客
		++service_times[service_t - service_t_min];//记录各收银时间段人数
	}

	size_t time{};
	const size_t total_time{ 600 };
	size_t longest_q{};

	int new_cust_interval{ arrival_interval_d(random_n) };//新光临的顾客个数

	while (time < total_time)//营业期间
	{
		++time;
		if (--new_cust_interval == 0)
		{
			service_t = service_t_d(random_n);
			min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));
			++service_times[service_t - service_t_min];//记录下标为service_t-service_t_min的服务时间的人数

			for (auto& checkout : checkouts)
				longest_q = max(longest_q, checkout.qlength());//记录最长队列人数

			new_cust_interval = arrival_interval_d(random_n);
		}

		for (auto & checkout : checkouts)
			checkout.time_increment();
	}

	cout << "Maximum queue lenght = " << longest_q << endl;
	cout << "\nHistogram of service times:" << endl;
	histogram(service_times, service_t_min);//柱状图

	cout << "\nTotal number of customers today:" << accumulate(begin(service_times), end(service_times), 0) << endl;



	system("pause");
	return 0;
}