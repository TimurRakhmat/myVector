#include <iostream>
#include <algorithm>
#include <vector>

#include "myvector.h"
#include "myiter.h"


using namespace std;


void printMyVec(const MyVector& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}


int main()
{
	int n = 200;
	/*MyVector v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		if (v.size() == v.capacity())
			cout << v[i] << " _ " << v.size() << " _ " << v.capacity() << "\n";
	}

	printMyVec(v);

	auto b = v.begin() + 1;
	b += 3;
	auto d = v.end();
	cout << *b;*/

	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		if (v.size() == v.capacity())
			cout << v[i] << " _ " << v.size() << " _ " << v.capacity() << "\n";
	}

	return 0;
}
