#include <functional>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

//多次输出priority_queue
template<typename T>
void list_pq(priority_queue<T> pq, size_t count = 5)
{
	size_t n{ count };
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
		if (--n) continue;
		cout << endl;//5个时换行
		n = count;
	}
	cout << endl;
}

int main()
{
	//创建一个优先队列
	//priority_queue<string> words;
	//初始化
	string wordss[]{ "one","two","three","four" };
	priority_queue<string> words{ begin(wordss),end(wordss) };//倒序

	//拷贝
	priority_queue<string> copy_words{ words };

	//自定义排序
	priority_queue<string, vector<string>, greater<string>> words1{ begin(wordss),end(wordss) };

	priority_queue<string, deque<string>> words2{ begin(wordss),end(wordss) };//用deque代替

	//生成deque或vector并用其初始化priority_queue
	vector<int> values{ 21,22,12,3,24,54,56 };
	priority_queue<int> numbers{ less<int>(),values };//参数：（排序函数对象，初始元素容器)

	//使用
	priority_queue<string> inWords;
	string word;
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
	while (true)
	{
		if ((cin >> word).eof())
			break;
		inWords.push(word);
	}
	//列出内容的同时不让内容丢失
	priority_queue<string> inWords_copy{ inWords };
	while (!inWords_copy.empty())
	{
		cout << inWords_copy.top() << endl;
		inWords_copy.pop();
	}
	cout << endl;

	list_pq(inWords);

	system("pause");
	return 0;
}