#include <iostream>
#include <string>
#include <list>
#include <functional>

using namespace std;

//ѭ�����
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
//	while (getline(cin, proberb, '\n'), !proberb.empty()) //ѭ�����벢�Իس��ָ��ĳ��Ԫ��Ϊ��ʱ������
//		proverbs.push_front(proberb);//������Ԫ����ӵ�����
//
//	cout << "Go on, just one more:" << endl;
//	getline(cin, proberb, '\n');
//	proverbs.emplace_back(proberb);
//
//	cout << "The elements in the list in reverse order are:" << endl;
//	list_elements(rbegin(proverbs), rend(proverbs));//�������
//
//	proverbs.sort();
//	cout << "\n Your proverbs in ascending sequence are:" << endl;
//	list_elements(begin(proverbs), end(proverbs));//��������
//
//	proverbs.sort(greater<>());
//	cout << "\nYour proverbs in descending sequence:" << endl;
//	list_elements(begin(proverbs), end(proverbs));//������������
//
//
//	system("pause");
//	return 0;
//}