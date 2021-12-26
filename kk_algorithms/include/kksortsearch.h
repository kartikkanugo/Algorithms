#pragma

#include "kkalgorithms.h"
#include <vector>

class Kksort {
private:


public:

	/**
	* Bubble sort sorts and compares in every loop the next element
	* O(n2)
	*/
	kerr_t bubble_sort(vector<int> &inp);

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
	* Merge sort is the a divide and conquer algorithm
	* First divide it to a single value array then in the combine step compare and combine
	* O(nlogn) worst case
	*/
	kerr_t merge_sort(vector<int>& inp);





};