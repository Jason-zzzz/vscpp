#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//�Ѵ���
	vector<double> numbers{ 2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0 };
	make_heap(begin(numbers), end(numbers));//make_heap��numbers����Ϊ��,���Һ��ٵ��ûỹԭ.Ĭ��Ϊ�󶥶�,p109
	make_heap(begin(numbers), end(numbers),greater<>());//�Զ�����������С����

	//�Ѳ���
	make_heap(begin(numbers), end(numbers));
	numbers.push_back(11);
	push_heap(begin(numbers), end(numbers));

	system("pause");
	return 0;
}