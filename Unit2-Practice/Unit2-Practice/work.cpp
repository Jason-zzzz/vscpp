#include <iostream>
#include <array>
#include <iterator>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename Iter>
void list_elements(Iter begin, Iter end)
{
	size_t perline = 8;
	size_t count{};
	while (begin != end)
	{
		cout << *(begin++)<<" ";
		if (++count % perline == 0) cout << endl;
	}
	cout << endl;
}

void question1()
{
	array<size_t, 50> fib;
	auto iter = begin(fib);
	//递增赋值
	iota(begin(fib), end(fib), 0);
	//便利赋值
	generate(begin(fib) + 2, end(fib), [&iter]() {return *iter + *(++iter); });
	list_elements(begin(fib), end(fib));
}

void question2()
{
	vector<string> cityName;
	cout << "Enter some city's name, use Ctrl+Z to exit:" << endl;
	copy(istream_iterator<string>{cin}, istream_iterator<string>{},back_inserter(cityName));
	sort(cityName.begin(), cityName.end());
	auto iter = cityName.begin();
	size_t length{};
	for (size_t i = 0; i < cityName.size()-1; i++)
	{
		size_t len = (*(cityName.begin() + i)).size();
		length = length > len ? length : len;
	}
	char c{};
	while (iter != cityName.end())
	{
		auto& cString = *iter;

		if (cString[0] != c)
		{
			c = cString[0];
			cout << "\n" << endl;
		}
		cout << *iter << " ";
		for (size_t i = 0; i < length-(*iter).size(); i++)
		{
			cout << " ";
		}
		iter++;

	}
	cout << endl;
}

class City
{
public:
	string name;
	//输入，小于运算符重载
	bool operator<(const City& city) { return name < city.name; };
	friend istream& operator>>(istream& in, City& city);
};

inline istream& operator>>(istream& in, City& city)
{
	cout << "Enter some city name:";
	string name;
	in >> name;
	if (name == "\n") return in;
	city.name = name;
	return in;
}

void question3()
{
	list<City> cities;
	//list<string> cities;
	//copy(istream_iterator<City>(cin),istream_iterator<City>(),back_inserter(cities));
	string citysName;

	cout << "Enter some city name:";
	while (getline(cin, citysName, '\n'), !citysName.empty())
	{
		City c;
		cout << "Enter some city name:";
		c.name = citysName;
		cities.push_back(c);
	}
	cities.sort();
	size_t length{};
	auto iter = cities.begin();
	for (size_t i = 0; i < cities.size()-1; i++)
	{
		City c = *iter;
		length = c.name.size() > length ? c.name.size() : length;
		iter++;
	}

	iter = cities.begin();
	char cityFN{};
	while (iter != cities.end())
	{
		auto city = *iter;
		if (cityFN != city.name[0])
		{
			cityFN = city.name[0];
			cout << "\n" << endl;
		}
		cout << city.name;
		for (size_t i = 0; i < length-city.name.size(); i++)
		{
			cout << " ";
		}
		iter++;
	}
	cout << endl;
}

void question4()
{

}

int main()
{
	//question1();
	//question2();
	//question3();

	system("pause");
	return 0;
}
