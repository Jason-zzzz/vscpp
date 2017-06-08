#include <iostream>
#include <string>
#include <list>
#include <functional>

using namespace std;

//循环输出
template<typename Iter>
void list_elements(Iter begin, Iter end)
{
	while (begin != end)
	{
		cout << *begin++ << endl;
	}
}

//int main()
//{
//
//	list<string> proverbs;
//	cout << "Enter a few proverbs and enter an empty line to end:" << endl;
//
//	string proberb;
//	while (getline(cin, proberb, '\n'), !proberb.empty()) //循环读入并以回车分割，当某个元素为空时跳出。
//		proverbs.push_front(proberb);//将输入元素添加到容器
//
//	cout << "Go on, just one more:" << endl;
//	getline(cin, proberb, '\n');
//	proverbs.emplace_back(proberb);
//
//	cout << "The elements in the list in reverse order are:" << endl;
//	list_elements(rbegin(proverbs), rend(proverbs));//倒序输出
//
//	proverbs.sort();
//	cout << "\n Your proverbs in ascending sequence are:" << endl;
//	list_elements(begin(proverbs), end(proverbs));//排序后输出
//
//	proverbs.sort(greater<>());
//	cout << "\nYour proverbs in descending sequence:" << endl;
//	list_elements(begin(proverbs), end(proverbs));//倒序排序后输出
//
//
//	system("pause");
//	return 0;
//}