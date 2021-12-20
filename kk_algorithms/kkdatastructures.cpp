#include "include\kkdatastructures.h"

bool Kkstack::push(int data)
{
	if (is_full()) {
		return false;
	}

	capacity++;
	arr[capacity] = data;
	return true;
}

int Kkstack::pop()
{
	if (is_empty()) {
		return -1;
	}
	capacity--;
	return arr[capacity+1];
}

int Kkstack::top_element()
{
	if (is_empty()) {
		return -1;
	}

	return arr[capacity];
}

int Kkstack::size()
{
	return capacity;
}

bool Kkstack::is_empty()
{
	if (capacity < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Kkstack::is_full()
{
	if (capacity == MAX_STACK_ELEMENTS-1) {
		return true;
	}
	else {
		return false;
	}
}
