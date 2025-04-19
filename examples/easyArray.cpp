#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray<int[10]> dynamic_array_1;
DynamicArray<double> dynamic_array_2;

void main() {
	/* --- Arrays --- */
	int array1[10] = { 1, 2, 3, 4, 5 };
	int array2[10] = { -1, -2, -3, -4, -5 };
	int array3[10] = { 15, 24, 33, 42, 51 };
	int array4[10] = { -51, -42, -33, -24, -15 };

	dynamic_array_1.add(&array1);
	dynamic_array_1.add(&array2);
	dynamic_array_1.add(&array3);
	dynamic_array_1.add(&array4);

	cout << "Arrays" << endl;

	for (uint8_t i = 0;i < dynamic_array_1.size();i++) {
		cout << "\tArray " << (i + 1) << ": ";

		for (uint8_t j = 0;j < 10;j++) {
			cout << dynamic_array_1[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
	dynamic_array_1.del(2);

	for (uint8_t i = 0;i < dynamic_array_1.size();i++) {
		cout << "\tArray " << (i + 1) << ": ";

		for (uint8_t j = 0;j < 10;j++) {
			cout << dynamic_array_1[i][j] << " ";
		}

		cout << endl;
	}

	/* --- Numbers --- */
	dynamic_array_2.add(1.3);
	dynamic_array_2.add(-4.1);
	dynamic_array_2.add(19.2);
	dynamic_array_2.add(-9.4);

	cout << "Numbers" << endl;

	for (uint8_t i = 0;i < dynamic_array_2.size();i++) {
		cout << "\tNumber " << (i + 1) << ": ";

		cout << dynamic_array_2[i] << endl;
	}

	cout << endl;
	dynamic_array_2.del(2);
	dynamic_array_2[0] = dynamic_array_2[1];

	for (uint8_t i = 0;i < dynamic_array_2.size();i++) {
		cout << "\tNumber " << (i + 1) << ": ";

		cout << dynamic_array_2[i] << endl;
	}
}