#include <iostream>
#include "DynamicArray.h"

using namespace std;

struct struct_t {
	struct_t(uint8_t a, float b) {
		this->a = a;
		this->b = b;
	}

	uint16_t a;
	double b;
};

void main() {
	cout << "\\/Struct array\\/" << endl;
	DynamicArray<struct_t> array;

	array.add(struct_t(12, 2.3));
	array.add(struct_t(11, 3.1));
	array.add(struct_t(44, 7.3));

	cout << "Elements count: " << array.getSize() << endl;

	for (uint32_t i = 0;i < array.getSize();i++) {
		cout << "Index: " << i << " A = " << array[i].a << " B = " << array[i].b << endl;
	}

	cout << endl << "\\/Variable array\\/" << endl;
	DynamicArray<int> array1;

	array1.add(12);
	array1.add(11);
	array1.add(44);

	cout << "Elements count: " << array1.getSize() << endl;

	for (uint32_t i = 0;i < array1.getSize();i++) {
		cout << "Index: " << i << " Element = " << array1[i] << endl;
	}
}