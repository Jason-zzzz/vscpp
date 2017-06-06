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
		vector<int> values(n_elements);//使用n_elements个大小来分配values的空间
		cout << "\nAppending to a vector with " << n_elements << " initial elemnts:\n" << endl;
		sizes.push_back(values.size());//记录大小
		size_t space{ values.capacity() };
		capacities.push_back(space);//记录容量
		
		size_t count{};
		size_t n_increases{ 10 };
		while (count < n_increases)
		{
			values.push_back(22);//增加一个元素
			if (space < values.capacity())//当记录容量小于现有容量时(即在容量范围内时为false,此判断使得函数跳过了为true的过程)
			{
				space = values.capacity();//记录容量
				capacities.push_back(space);
				sizes.push_back(values.size());//记录大小
				++count;//自增。即额外增加n_increases个元素
			}
		}

		cout << "Size/Capacity:";
		for (size_t i = 0; i < sizes.size(); i++)
		{
			cout << sizes.at(i) << "/" << capacities.at(i) << " ";//输出大小/容量
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
			junk.reserve(junk.size() * 13 / 10);//增量30%.（增量的作用是减少扩容次数）
		}
		junk.push_back(i);
	}

	system("pause");
	return 0;
}