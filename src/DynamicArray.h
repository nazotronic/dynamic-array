#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define DISABLE_MAX_SIZE 0
#define DEFAULT_STEP 10

template <typename T>
class DynamicArray {
public:
	~DynamicArray() {
		free(array);
	}

	bool add() {
		return add(NULL);
	}
	bool add(T new_element) {
		return add(&new_element);
	}
	bool add(T* new_element) {
		if (getMaxSize() && getSize() == getMaxSize()) {
			return false;
		}

		if (!(getSize() % getStep()) ) {
			T* new_pointer = (T*) realloc(array, (getSize() + 10) * sizeof(T));

			if (new_pointer == NULL) {
				return false;
			}

			array = new_pointer;
		}

		if (new_element != NULL) {
			memcpy(array + getSize(), new_element, sizeof(T));
		}
		else {
			memset(array + getSize(), 0, sizeof(T));
		}
		size++;

		return true;
	}

	bool del(uint32_t el_index) {
		if (el_index >= getSize() || array == NULL) {
			return false;
		}

		while (el_index < getSize() - 1) {
			array[el_index] = array[el_index + 1];
			el_index++;
		}

		size--;

		if (!(getSize() % getStep()) ) {
			array = (T*) realloc(array, getSize() * sizeof(T));

			if (!getSize()) {
				free(array);
				array = NULL;
			}
		}

		return true;
	}

	bool modifyElement(uint32_t el_index, T element) {
		return modifyElement(el_index, &element);
	}
	bool modifyElement(uint32_t el_index, T* element) {
		if (el_index >= getSize() || array == NULL) {
			return false;
		}

		memcpy(array + el_index, element, sizeof(T));

		return true;
	}


	T& operator[] (const uint32_t el_index) {
		return array[el_index];
	}


	uint32_t getSize() {
		return size;
	}

	uint8_t getStep() {
		return step;
	}

	uint32_t getMaxSize() {
		return max_size;
	}


	void setStep(uint8_t step) {
		this->step = (!step) ? 1 : step;
	}

	void setMaxSize(uint32_t max_size) {
		this->max_size = max_size;
	}

private:
	T* array = NULL;
	uint32_t size = 0;

	uint8_t step = DEFAULT_STEP;
	uint32_t max_size = DISABLE_MAX_SIZE;

};

#endif
