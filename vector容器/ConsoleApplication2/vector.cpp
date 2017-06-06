#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

//此函数可替代主函数中的排序代价
template<typename RandomIter>
void bubble_sort(RandomIter start, RandomIter last)
{
	cout << "Starting sort." << endl;
	bool out_of_order{ false };
	while (true)
	{
		for (auto first = start+1; first != last; ++first)
		{
			if (*(first -1) > *first)
			{
				swap(*first, *(first + 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)
		{
			break;
		}
		out_of_order = false;
	}
}

//int main()
//{
//
//	vector<double> values(20);
//	values[0] = 3.14159;//不能使用下标生成新元素，即超出下标范围
//	values[1] = 5.0;
//	values[2] = 2.0*values[0] * values[1];
//
//	for (size_t i = 0;
//		i < 10;
//		i++)//第一次执行时按顺序执行语句。在循环过程中，先执行i++这个语句段，再比较大小
//	{
//
//	}
//	cout << *values.data() << endl;
//
//	values.push_back(3.21221);//vector添加新元素
//
//	//vector插入元素
//	vector<string>words;
//	words.push_back(string("facetious"));
//	words.emplace_back("abstemious");
//	string str{ "asddfvv" };
//	words.emplace_back(str, 2, 3);
//	copy(begin(words), end(words), ostream_iterator<string>{cout, " "});
//	cout << endl;
//
//	vector<string> wordss{ "first","second" };
//	auto iter1 = wordss.emplace(++begin(wordss), 5, 'A');//emplace参数列表首个参数后跟尽可能多的参数，参数必须是被插入对象构造函数所需的..此函数更高效
//	wordss.emplace(++iter1, "$$$$");
//	copy(begin(wordss), end(wordss), ostream_iterator<string>{cout, "　"});
//	cout << endl;
//
//	vector<string> words1{ "one","three","eight" };
//	auto iter2 = words1.insert(++begin(words1), "two");
//	string more[]{ "five","six","seven" };
//	iter2 = words1.insert(--end(words1), begin(more), end(more));
//	words1.insert(begin(words1), begin(words1), end(words1));
//	copy(begin(words1), end(words1), ostream_iterator<string>{cout, " "});
//	cout << endl;
//	
//	words1.insert(cend(words1) , 2, "nine");//在位置插入两个nine
//	copy(begin(words1), end(words1), ostream_iterator<string>{cout, " "});
//	
//	auto riter = find(rbegin(words1), rend(words1), "one");//返回找到的第一个元素，找不到则返回首个元素之前的迭代器
//	words1.insert(riter.base(),"five");//指向序列结束方向后一个元素
//	//交换并删除尾部元素，实际删除第二个元素。（不考虑元素顺序)。需容器不为空
//	swap(begin(words1) + 1, end(words1) - 3);
//	words1.pop_back();
//
//	words1.shrink_to_fit();//去除多余容量，迭代器需要重新获取。需容器不为空
//
//	//words1.clear();//清空，但是容量不变
//	words1.pop_back();//删除尾部元素。对应push_back
//	
//	auto iter11 = words1.erase(begin(words1) + 1);//删除元素，容量不变，返回一个删除元素后一个元素的迭代器
//	auto iter22 = words1.erase(begin(words1), end(words1));//删除范围内的元素
//
//	vector <string> words2{ "one1","one", "one2","one", "one3", "one4", "one5" };
//	auto iter3 = remove(begin(words2), end(words2),"one");//从头到尾搜寻one并删除，返回最后一个元素之后的位置
//	words2.erase(iter3, end(words2));//删除元素，直到结束位置end(words2)
//	words2.erase(remove(begin(words2), end(words2), "one"), end(words));//同理。。
//
//
//
//
//	system("pause");
//	return 0;
//}