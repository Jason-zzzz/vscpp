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
using distribution = uniform_int_distribution<>;//�����ƽ���ֲ��ؼ���
using namespace std;

void histogram(const vector<int>& v, int min)
{
	string bar(60, '*');
	for (size_t i = {}; i < v.size(); i++)
	{
		//setw����������,substr:���ĳ��  ���������ʱ�估������
		cout << setw(3) << i + min << " " << setw(4) << v[i] << " " << bar.substr(0, v[i]) << (v[i] > static_cast<int>(bar.size()) ? "..." : "") << endl;
	}
}

int main()
{
	//����
	queue<string> words;
	queue<string, list<string>> words1;

	//Ԫ�ط���
	deque<double> values{ 1.5,2.5,3.5,4.5 };
	queue<double> numbers(values);
	while (!numbers.empty())
	{
		cout << numbers.front() << " ";
		numbers.pop();//�����ջ
	}
	cout << endl;

	/***********************ģ�����*****************************/

	random_device random_n;//�����������

	int service_t_min(2), service_t_max{ 15 };//ʱ��
	distribution service_t_d{ service_t_min,service_t_max };//���ɽ���ʱ�������

	int min_customers{ 15 }, max_customers{ 20 };
	distribution n_1st_customers_d { min_customers,max_customers };//����ʱ�ȴ��˿͸���

	int min_arr_interval{ 1 }, max_arr_interval{ 5 };
	distribution arrival_interval_d{ min_arr_interval,max_arr_interval };//�˿͵�����

	size_t n_checkouts{};//����̨����
	cout << "Enter the number of checkouts in the supermarket:";
	cin >> n_checkouts;

	if (!n_checkouts)
	{
		cout << "Number of checkouts must be greater than 0. Settin to 1." << endl;
		n_checkouts = 1;
	}


	vector<Checkout> checkouts{ n_checkouts };//��������̨
	vector<int> service_times(service_t_max - service_t_min + 1);//����ʱ���

	int count{ n_1st_customers_d(random_n) };//����n_1st_customers��Χ�������
	cout << "Customers waiting at store opening:" << count << endl;
	int added{};
	int service_t{};
	while (added++ < count)
	{
		service_t = service_t_d(random_n);//��������ʱ�������
		min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//�����ٵ�����̨������ӹ˿�
		++service_times[service_t - service_t_min];//��¼������ʱ�������
	}

	size_t time{};
	const size_t total_time{ 600 };
	size_t longest_q{};

	int new_cust_interval{ arrival_interval_d(random_n) };//�¹��ٵĹ˿͸���

	while (time < total_time)//Ӫҵ�ڼ�
	{
		++time;
		if (--new_cust_interval == 0)
		{
			service_t = service_t_d(random_n);
			min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));
			++service_times[service_t - service_t_min];//��¼�±�Ϊservice_t-service_t_min�ķ���ʱ�������

			for (auto& checkout : checkouts)
				longest_q = max(longest_q, checkout.qlength());//��¼���������

			new_cust_interval = arrival_interval_d(random_n);
		}

		for (auto & checkout : checkouts)
			checkout.time_increment();
	}

	cout << "Maximum queue lenght = " << longest_q << endl;
	cout << "\nHistogram of service times:" << endl;
	histogram(service_times, service_t_min);//��״ͼ

	cout << "\nTotal number of customers today:" << accumulate(begin(service_times), end(service_times), 0) << endl;



	system("pause");
	return 0;
}