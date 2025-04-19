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
		clear();
	}

	void clear() {
		delete[] array;

		array = NULL;
		current_size = 0;

		step = DEFAULT_STEP;
		max_size = DISABLE_MAX_SIZE;
	}


	bool add() {
		return add(NULL);
	}
	bool add(const T new_element) {
		return add(&new_element);
	}
	bool add(const T* new_element) {
		if (getMaxSize() && size() == getMaxSize()) {
			return false;
		}

		if (!(size() % getStep())) {
			T* new_pointer = (T*) new T[size() + 10];

			if (new_pointer == NULL) {
				return false;
			}

			for (uint32_t i = 0;i < size();i++) {
				if constexpr (std::is_array<T>::value) {
					memcpy(new_pointer[i], array[i], sizeof(T));
				}
				else {
					new_pointer[i] = array[i];
				}
			}

			delete[] array;
			array = new_pointer;
		}

		if (new_element != NULL) {
			if constexpr (std::is_array<T>::value) {
				memcpy(array[size()], *new_element, sizeof(T));
			}
			else {
				array[size()] = *new_element;
			}
		}
		else {
			memset((void*)(array + size()), 0, sizeof(T));
		}
		current_size++;

		return true;
	}

	bool del(uint32_t el_index) {
		if (el_index >= size() || array == NULL) {
			return false;
		}

		while (el_index < size() - 1) {
			if constexpr (std::is_array<T>::value) {
				memcpy(array[el_index], array[el_index + 1], sizeof(T));
			}
			else {
				array[el_index] = array[el_index + 1];
			}

			el_index++;
		}

		current_size--;

		if (!(size() % getStep())) {
			T* new_pointer = (T*) new T[size()];

			if (new_pointer == NULL) {
				return false;
			}

			for (uint32_t i = 0;i < size();i++) {
				if constexpr (std::is_array<T>::value) {
					memcpy(new_pointer[i], array[i], sizeof(T));
				}
				else {
					new_pointer[i] = array[i];
				}
			}

			delete[] array;

			if (!size()) {
				delete[] new_pointer;
				new_pointer = NULL;
			}
			array = new_pointer;
		}

		return true;
	}


	T& operator[] (const uint32_t el_index) {
		return array[el_index];
	}


	uint32_t size() {
		return current_size;
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
	uint32_t current_size = 0;

	uint8_t step = DEFAULT_STEP;
	uint32_t max_size = DISABLE_MAX_SIZE;

};

#endif
