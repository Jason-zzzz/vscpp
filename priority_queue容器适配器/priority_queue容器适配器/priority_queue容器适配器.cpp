#include <functional>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

//������priority_queue
template<typename T>
void list_pq(priority_queue<T> pq, size_t count = 5)
{
	size_t n{ count };
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
		if (--n) continue;
		cout << endl;//5��ʱ����
		n = count;
	}
	cout << endl;
}

int main()
{
	//����һ�����ȶ���
	//priority_queue<string> words;
	//��ʼ��
	string wordss[]{ "one","two","three","four" };
	priority_queue<string> words{ begin(wordss),end(wordss) };//����

	//����
	priority_queue<string> copy_words{ words };

	//�Զ�������
	priority_queue<string, vector<string>, greater<string>> words1{ begin(wordss),end(wordss) };

	priority_queue<string, deque<string>> words2{ begin(wordss),end(wordss) };//��deque����

	//����deque��vector�������ʼ��priority_queue
	vector<int> values{ 21,22,12,3,24,54,56 };
	priority_queue<int> numbers{ less<int>(),values };//�����������������󣬳�ʼԪ������)

	//ʹ��
	priority_queue<string> inWords;
	string word;
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
	while (true)
	{
		if ((cin >> word).eof())
			break;
		inWords.push(word);
	}
	//�г����ݵ�ͬʱ�������ݶ�ʧ
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