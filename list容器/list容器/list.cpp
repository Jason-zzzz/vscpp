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
	//����
	list<string> words;
	list<string> sayings{ 20 };
	list<string> values(30, "2.34445");
	copy(begin(sayings), end(sayings), ostream_iterator<string>{ cout," " });

	//��������
	list<string> save_values{ values };
	list<string> part_save{ ++begin(save_values),--end(save_values) };//ֻ���������Լ� 

	//���Ԫ��
	list<string> names{ "0","1", "2", "3", "4" };
	names.push_front("jan");
	names.push_back("jim");
	//better
	names.emplace_front("Ian");
	names.emplace_back("Tom");
	names.emplace(++begin(names), "BetterFuck");

	//����Ԫ��
	names.insert(++begin(names), "God");
	auto iter = begin(names);//��ȡ������
	advance(iter, 8);//��������ǰ�ƶ�
	names.insert(iter, 3, "123");//��iterλ�����3��"123"
	//����һ��Ԫ��
	vector<string> members{ "mm","mm", "mm", "mm", "mm" };
	vector<string> members1(4,"nn");
	names.insert(--(--end(names)), cbegin(members), cend(members));

	//�Ƴ�Ԫ��
	//names.remove("mm");
	names.unique();//ȥ�أ�����һ��
	names.remove_if([](string s) {const char *c = s.data(); return *c > 80 ? true : false; });

	//����Ԫ��
	names.sort(greater<>());//��������
	//�Լ�ʵ��һ������,��ͬ��ĸ��ͷ������˳����
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
	//��ͬ����ʹ��Lambda���ʽ
	names.sort([](const string& s1, const string& s2)
	{
		if (s1[0] == s2[0])
		{
			return s1.length() > s2.length();
		}
		return s1 > s2;
	});

	//�ϲ�Ԫ��
	list<int> my_values{ 2,3,4,6,9 };
	list<int> your_values{ -2,0,5,10 };
	my_values.merge(your_values);	//Ԫ����������,your_values���Ƶ�my_values;
	//�������򣬿ɱȽ�
	list<string> my_words{ "One","Five", "Nine" };
	list<string> your_words{ "Three", "Two","Twelve" };
	auto comp_str = [](const string& s1, const string& s2) {return s1[0] < s2[0]; };
	my_words.sort(comp_str);
	your_words.sort(comp_str);
	//my_words.merge(your_words, comp_str);

	//�ƶ�Ԫ�� 
	//����
	my_words.splice(++begin(my_words), your_words, ++begin(your_words));//Ŀ��������Ԫ����Դ��Ԫ�ص�����
	//һ��
	my_words.splice(++(++(++begin(my_words))), your_words, begin(your_words), end(your_words));
	//ȫ��
	your_words.splice(begin(your_words), my_words);

	//��Ա����
	for (const auto& name : names)
	{
		cout << name << endl;//name����ָ��ÿ��list������
	}



	system("pause");
	return 0;
}