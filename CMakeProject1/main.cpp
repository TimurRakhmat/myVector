#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

#include "myvector.h"
#include "myiter.h"


using namespace std;

template<class T>
void printMyVec(const MyVector<T>& v) {

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}


int main()
{
	int n = 64;
	MyVector<string> v;
	for (int i = 0; i < n; i++) {
		v.push_back("abc" + to_string(i));
		if (v.size() == v.capacity())
			cout << v[i] << " _ " << v.size() << " _ " << v.capacity() << "\n";
	}

	for (int i = 0; i < (n >> 1); i ++) {
		v.erase(v.begin() + i);
	}
	printMyVec(v);

	auto b = v.begin() + 1;
	b += 3;
	auto d = v.end();
	cout << *b;


	/*char* r = "asdfghjkl";
	long long* t = new long long[10];


	for (int i = 0; i < 10; i++) {
		t[i] = i;
	}

	MyIter<char> g(r);

	MyIter<long long> gg(t);
	cout << *(g + 2) << endl;
	
	cout << *(gg + 2);*/

	return 0;
}
