#pragma once

#include "kkalgorithms.h"
#include <vector>

class Kksort {
private:


public:

	/**
	* Bubble sort sorts and compares in every loop the next element
	* O(n2)
	*/
	kerr_t bubble_sort(vector<int>& inp);

	/**
	* selection sort finds the min value in the loop
	* O(n2)
	*/
	kerr_t selection_sort(vector<int>& inp);
	/**
	* Insertion sorts as the data in inp it takes a value and inserts it in a sorted list
	* somecases it is better than bubble and selection as for a sorted list its performance is O(n)
	* O(n2) worst case
	*/
	kerr_t insertion_sort(vector<int>& inp);
	/**
	* Shell sort is the best O(n2) algorithm it works on top of insertion sort
	* It uses gap theory
	* O(n2) worst case
	*/
	kerr_t shell_sort(vector<int>& inp);
	/**
	* Merge sort is a divide and conquer algorithm
	* First divide it to a single value array then in the combine step compare and combine
	* O(nlogn) worst case
	*/
	kerr_t merge_sort(vector<int>& inp);
	/**
	* Quick sort is also a divide and conquer algorithm implementation
	* Divide the array from a pivot value with all values greater than one side and small the other side
	* This is better than mergesort in most of the cases
	* O(n2) worst case
	*/
	kerr_t quick_sort(vector<int>& inp);
	/**
	* Counting sort has a worst case of O(n)
	* Counting sort cannot be used for floats or indefinite range of the values
	*/
	kerr_t counting_sort(vector<int>& inp);
	/**
	* Bucket sort has a worst case of O(n), 
	* function is not complete cannot be used for anykind of input
	* Can be used for the floating points
	*/
	kerr_t bucket_sort(vector<float>& inp);
	/**
	* Radix sort has a worst case of O(n),
	* It is used by sorting units place, tens place and hundreds place
	* It is similar to counting sort
	*/
	kerr_t radix_sort(vector<int>& inp);




};


class Kksearch {

public:
	kerr_t linear_search(vector<int>& inp, const int val, k_result* res);


	/**
		Binary search can be done recursively or iteratively
		Iteratively is better as we use less memory
		Note: It only works for a sorted array
	*/
	kerr_t binary_search(vector<int>& inp, const int val, k_result* res);
	/**
		Interpolation search works only for a sorted array
	*/

	kerr_t interpolation_search(vector<int>& inp, const int val, k_result* res);


};