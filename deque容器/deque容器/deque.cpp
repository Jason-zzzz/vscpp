#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{

	deque<int> a_deque;//添加元素时分配内存
	deque<int> my_deque(10);//分配10个元素内存,默认值为0

	deque<string> words1{ "one","one", string("one"), "one", "one", "one" };
	deque<string> words1_copy{ words1 };//copy
	deque<string> words1_part{ begin(words1),begin(words1) + 3 };

	deque<int> numbers{ 2,3,4 };
	numbers.push_front(11);
	numbers.push_back(12);
	numbers.pop_front();
	numbers.emplace_front(12);//在开始位置生成元素

	auto init_list = { string{"seven"},string{"eight"},string{"nine"} };//auto推断的类型需一致。
	words1.assign(init_list);//替换所有元素为init_list
	words1.assign({ "onfds", "onfds1", "onfds2" });//同理

	vector<string> words1et{ "this","that", "these", "those" };
	words1.assign(begin(words1et) + 1, --end(words1et));//迭代器范围的元素

	words1.assign(8, "321");//用重复内容替换

	//用deque给deque赋值，他们的容量和大小随实际元素个数改变
	deque<string> words{ "one","one", "one", "one" };
	deque<string> other_words;
	other_words = words;
	words = { "第三方","dff","sdss22" };

	/****************************demo****************************/
	deque<string> names;
	cout << "Enter first names separated by spaces. Enter Ctrl+Z on new line to end:\n";
	copy(istream_iterator<string>{cin}, istream_iterator<string>{}, front_inserter(names));
	cout << "\nIn reverse order, the names you entered are:\n";
	copy(begin(names), end(names), ostream_iterator<string>{cout, " "});

	cout << endl;


	system("pause");
	return 0;
}