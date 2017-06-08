#include <string>
#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

int main()
{

	//创建
	forward_list<string> my_words{ "one","two","three" };
	//统计大小容量
	auto count = distance(begin(my_words), end(my_words));
	//移动
	auto iter = begin(my_words);
	advance(iter, 2);//advance无返回值
	//插入元素
	forward_list<string> your_words{ "four","five","six" };
	my_words.splice_after(my_words.before_begin(), your_words, ++begin(your_words));//目标位置，元素来源，元素位置的前一个位置
	my_words.splice_after(my_words.before_begin(), your_words, begin(your_words), end(your_words));//,,元素来源开始位置，结束位置(移动除开始位置的其他元素)
	your_words.splice_after(your_words.begin(), my_words);//目标位置，容器


	system("pause");
	return 0;
}