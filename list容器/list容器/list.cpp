#include <iostream>
#include <list>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	//创建
	list<string> words;
	list<string> sayings{ 20 };
	list<string> values(30, "2.34445");
	copy(begin(sayings), end(sayings), ostream_iterator<string>{ cout," " });

	//拷贝复制
	list<string> save_values{ values };
	list<string> part_save{ ++begin(save_values),--end(save_values) };//只能自增或自减 

	//添加元素
	list<string> names{ "0","1", "2", "3", "4" };
	names.push_front("jan");
	names.push_back("jim");
	//better
	names.emplace_front("Ian");
	names.emplace_back("Tom");
	names.emplace(++begin(names), "BetterFuck");

	//插入元素
	names.insert(++begin(names), "God");
	auto iter = begin(names);//获取迭代器
	advance(iter, 8);//迭代器向前移动
	names.insert(iter, 3, "123");//在iter位置添加3个"123"
	//插入一段元素
	vector<string> members{ "mm","mm", "mm", "mm", "mm" };
	vector<string> members1(4,"nn");
	names.insert(--(--end(names)), cbegin(members), cend(members));

	//移除元素
	//names.remove("mm");
	names.unique();//去重，留第一个
	names.remove_if([](string s) {const char *c = s.data(); return *c > 80 ? true : false; });

	//排序元素
	names.sort(greater<>());//降序排序
	//自己实现一个排序,相同字母打头按长短顺序排
	class my_greater
	{
	public:
		bool operator()(const string& s1, const string& s2)
		{
			if (s1[0] == s2[0])
			{
				return s1.length() > s2.length();
			}
			return s1 > s2;
		}
	};
	vector<string> newNames{ "Iron", "Bitch", "", "Bob" };
	names.insert(begin(names), begin(newNames), end(newNames));
	names.sort(my_greater());
	//相同排序使用Lambda表达式
	names.sort([](const string& s1, const string& s2)
	{
		if (s1[0] == s2[0])
		{
			return s1.length() > s2.length();
		}
		return s1 > s2;
	});

	//合并元素
	list<int> my_values{ 2,3,4,6,9 };
	list<int> your_values{ -2,0,5,10 };
	my_values.merge(your_values);	//元素需是升序,your_values被移到my_values;
	//需是升序，可比较
	list<string> my_words{ "One","Five", "Nine" };
	list<string> your_words{ "Three", "Two","Twelve" };
	auto comp_str = [](const string& s1, const string& s2) {return s1[0] < s2[0]; };
	my_words.sort(comp_str);
	your_words.sort(comp_str);
	//my_words.merge(your_words, comp_str);

	//移动元素 
	//单个
	my_words.splice(++begin(my_words), your_words, ++begin(your_words));//目标容器，元素来源，元素迭代器
	//一段
	my_words.splice(++(++(++begin(my_words))), your_words, begin(your_words), end(your_words));
	//全部
	your_words.splice(begin(your_words), my_words);

	//成员访问
	for (const auto& name : names)
	{
		cout << name << endl;//name依次指向每个list的引用
	}



	system("pause");
	return 0;
}