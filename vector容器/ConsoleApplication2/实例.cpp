#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<size_t> sizes;
	vector<size_t> capacities;

	size_t el_incr{ 10 };
	size_t incr_count{ 4 * el_incr };

	for (size_t n_elements{}; n_elements < incr_count; n_elements += el_incr)
	{
		vector<int> values(n_elements);//ʹ��n_elements����С������values�Ŀռ�
		cout << "\nAppending to a vector with " << n_elements << " initial elemnts:\n" << endl;
		sizes.push_back(values.size());//��¼��С
		size_t space{ values.capacity() };
		capacities.push_back(space);//��¼����
		
		size_t count{};
		size_t n_increases{ 10 };
		while (count < n_increases)
		{
			values.push_back(22);//����һ��Ԫ��
			if (space < values.capacity())//����¼����С����������ʱ(����������Χ��ʱΪfalse,���ж�ʹ�ú���������Ϊtrue�Ĺ���)
			{
				space = values.capacity();//��¼����
				capacities.push_back(space);
				sizes.push_back(values.size());//��¼��С
				++count;//����������������n_increases��Ԫ��
			}
		}

		cout << "Size/Capacity:";
		for (size_t i = 0; i < sizes.size(); i++)
		{
			cout << sizes.at(i) << "/" << capacities.at(i) << " ";//�����С/����
		}
		cout << endl;

		sizes.clear();
		capacities.clear();

	}

	vector<size_t> junk{ 1,2,3 };
	for (size_t i = 0; i < 1000; i++)
	{
		if (junk.size() == junk.capacity())
		{
			junk.reserve(junk.size() * 13 / 10);//����30%.�������������Ǽ������ݴ�����
		}
		junk.push_back(i);
	}

	system("pause");
	return 0;
}