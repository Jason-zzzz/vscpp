#include <string>
#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

int main()
{

	//����
	forward_list<string> my_words{ "one","two","three" };
	//ͳ�ƴ�С����
	auto count = distance(begin(my_words), end(my_words));
	//�ƶ�
	auto iter = begin(my_words);
	advance(iter, 2);//advance�޷���ֵ
	//����Ԫ��
	forward_list<string> your_words{ "four","five","six" };
	my_words.splice_after(my_words.before_begin(), your_words, ++begin(your_words));//Ŀ��λ�ã�Ԫ����Դ��Ԫ��λ�õ�ǰһ��λ��
	my_words.splice_after(my_words.before_begin(), your_words, begin(your_words), end(your_words));//,,Ԫ����Դ��ʼλ�ã�����λ��(�ƶ�����ʼλ�õ�����Ԫ��)
	your_words.splice_after(your_words.begin(), my_words);//Ŀ��λ�ã�����


	system("pause");
	return 0;
}