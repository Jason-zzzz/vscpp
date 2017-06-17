#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//堆创建
	vector<double> numbers{ 2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0 };
	make_heap(begin(numbers), end(numbers));//make_heap将numbers处理为堆,打乱后再调用会还原.默认为大顶堆,p109
	make_heap(begin(numbers), end(numbers),greater<>());//自定义排序生成小顶堆

	//堆操作
	make_heap(begin(numbers), end(numbers));
	numbers.push_back(11);
	push_heap(begin(numbers), end(numbers));

	system("pause");
	return 0;
}