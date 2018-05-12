#include "stdafx.h"
#include "SharedPointer.h"
#include <iostream>

using namespace std;


class TestClass {
public:
	int intField;
	explicit TestClass(int _intField) : intField(_intField) {}
	~TestClass() {
		cout << "deleting TestClass" << endl;
	}
};

SharedPointer<TestClass> MakeTestClass() {
	SharedPointer<TestClass> a(new TestClass(5));
	return a;
}

int main() {
	SharedPointer<TestClass> first = MakeTestClass();
	SharedPointer<TestClass> second = first;
	SharedPointer<TestClass> third = first;

	cout << first.UseCount() << " " << second.UseCount() << " " << third.UseCount() << endl;

	third.Reset();

	cout << first.UseCount() << " " << second.UseCount() << " " << third.UseCount() << endl;
	cout << first->intField << endl;
}