#include <algorithm>
#include <iostream>
#include <forward_list>
#include <iterator>
#include "Box.h"

using namespace std;

template<typename Iter>
void list_elements(Iter begin, Iter end)
{
	size_t perline{ 6 };
	size_t count{};
	while (begin != end)
	{
		cout << *(begin++);
		if (++count % perline == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{

	forward_list<Box> boxes;
	copy(istream_iterator<Box>(cin), istream_iterator<Box>(), front_inserter(boxes));

	boxes.sort();
	cout << "\nAfter sorting the sequence is: \n";

	copy(begin(boxes), end(boxes), ostream_iterator<Box>{cout, " "});
	cout << endl;

	forward_list<Box> more_boxes{ Box{3,3,3},Box{ 5,5,5 }, Box{ 4,4,4 }, Box{ 2,2,2 } };
	boxes.insert_after(boxes.begin(), more_boxes.begin(), more_boxes.end());
	cout << "After insert more boxes the sequence is:\n";
	list_elements(boxes.begin(),boxes.end());

	boxes.sort();
	cout << endl;
	cout << "The sort sequence is now:\n";
	list_elements(begin(boxes),end(boxes));

	more_boxes.sort();
	boxes.merge(more_boxes);
	cout << "After mergin more_boxes the sequence is :\n";
	list_elements(begin(boxes), end(boxes));

	boxes.unique();
	cout << "After removing successive duplicates the sequence is:\n";
	list_elements(boxes.begin(), boxes.end());

	const double max_v{ 30.0 };
	boxes.remove_if([max_v](const Box& box) {return box.volume() < max_v; });
	cout << "After removing those with volume less than 30 the sorted sequence is :" << endl;
	list_elements(begin(boxes), end(boxes));

	system("pause");
	return 0;
}