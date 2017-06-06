#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

//�˺���������������е��������
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
//	values[0] = 3.14159;//����ʹ���±�������Ԫ�أ��������±귶Χ
//	values[1] = 5.0;
//	values[2] = 2.0*values[0] * values[1];
//
//	for (size_t i = 0;
//		i < 10;
//		i++)//��һ��ִ��ʱ��˳��ִ����䡣��ѭ�������У���ִ��i++������Σ��ٱȽϴ�С
//	{
//
//	}
//	cout << *values.data() << endl;
//
//	values.push_back(3.21221);//vector�����Ԫ��
//
//	//vector����Ԫ��
//	vector<string>words;
//	words.push_back(string("facetious"));
//	words.emplace_back("abstemious");
//	string str{ "asddfvv" };
//	words.emplace_back(str, 2, 3);
//	copy(begin(words), end(words), ostream_iterator<string>{cout, " "});
//	cout << endl;
//
//	vector<string> wordss{ "first","second" };
//	auto iter1 = wordss.emplace(++begin(wordss), 5, 'A');//emplace�����б��׸�������������ܶ�Ĳ��������������Ǳ���������캯�������..�˺�������Ч
//	wordss.emplace(++iter1, "$$$$");
//	copy(begin(wordss), end(wordss), ostream_iterator<string>{cout, "��"});
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
//	words1.insert(cend(words1) , 2, "nine");//��λ�ò�������nine
//	copy(begin(words1), end(words1), ostream_iterator<string>{cout, " "});
//	
//	auto riter = find(rbegin(words1), rend(words1), "one");//�����ҵ��ĵ�һ��Ԫ�أ��Ҳ����򷵻��׸�Ԫ��֮ǰ�ĵ�����
//	words1.insert(riter.base(),"five");//ָ�����н��������һ��Ԫ��
//	//������ɾ��β��Ԫ�أ�ʵ��ɾ���ڶ���Ԫ�ء���������Ԫ��˳��)����������Ϊ��
//	swap(begin(words1) + 1, end(words1) - 3);
//	words1.pop_back();
//
//	words1.shrink_to_fit();//ȥ��������������������Ҫ���»�ȡ����������Ϊ��
//
//	//words1.clear();//��գ�������������
//	words1.pop_back();//ɾ��β��Ԫ�ء���Ӧpush_back
//	
//	auto iter11 = words1.erase(begin(words1) + 1);//ɾ��Ԫ�أ��������䣬����һ��ɾ��Ԫ�غ�һ��Ԫ�صĵ�����
//	auto iter22 = words1.erase(begin(words1), end(words1));//ɾ����Χ�ڵ�Ԫ��
//
//	vector <string> words2{ "one1","one", "one2","one", "one3", "one4", "one5" };
//	auto iter3 = remove(begin(words2), end(words2),"one");//��ͷ��β��Ѱone��ɾ�����������һ��Ԫ��֮���λ��
//	words2.erase(iter3, end(words2));//ɾ��Ԫ�أ�ֱ������λ��end(words2)
//	words2.erase(remove(begin(words2), end(words2), "one"), end(words));//ͬ����
//
//
//
//
//	system("pause");
//	return 0;
//}