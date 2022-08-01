#include "include\kksortsearch.h"
#include <iostream>
#include <algorithm>


kerr_t Kksort::bubble_sort(vector<int>& inp)
{
	bool swapped = true;
	int size = inp.size();
	int i, j;
	for (i = 0; i < size && swapped; i++) {
		swapped = false;
		for (j = 0; j < size - i - 1; j++) {
			if (inp[j] > inp[j + 1]) {
				int temp = inp[j];
				inp[j] = inp[j + 1];
				inp[j + 1] = temp;
				swapped = true;
			}

		}

	}


	return ERR_NO_ERROR;
}

kerr_t Kksort::selection_sort(vector<int>& inp)
{
	int size = inp.size();
	int i, j, min;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) // No repeatition over mins
		{
			if (inp[j] < inp[min]) {
				min = j;
			}

		}

		int temp = inp[i];
		inp[i] = inp[min];
		inp[min] = temp;


	}

	return ERR_NO_ERROR;
}

kerr_t Kksort::insertion_sort(vector<int>& inp)
{
	int i, j, temp, size = inp.size();

	for (i = 1; i < size; i++) {
		j = i;
		temp = inp[i];
		while (inp[j - 1] > temp && j > 0) {
			inp[j] = inp[j - 1];
			j--;
		}
		inp[j] = temp;
	}


	return ERR_NO_ERROR;
}

kerr_t Kksort::shell_sort(vector<int>& inp)
{
	int size = inp.size();
	int gap, i, j, temp;


	// keep reducing set size by 2
	for (gap = size / 2; gap > 0; gap = gap / 2) {

		for (i = gap + 1; i < size; i++) {
			temp = inp[i];
			j = i;
			while (inp[j - 1] > temp && j > gap) {
				inp[j] = inp[j - 1];
				j--;

			}
			inp[j] = temp;

		}

	}


	return ERR_NO_ERROR;
}

//*********************//

kerr_t merge_internal(vector<int>& inp, const int start, const int mid, const int finish) {


	vector<int>* leftarr = new vector<int>(mid + 1 - start);
	vector<int>* rightarr = new vector<int>(finish - mid);

	for (int i = 0; i < mid + 1 - start; i++) {
		(*leftarr)[i] = inp[start + i];
	}

	for (int i = 0; i < finish - mid; i++) {
		(*rightarr)[i] = inp[mid + 1 + i];
	}

	int leftindex = 0, rightindex = 0, i = start;

	while (leftindex < mid + 1 - start && rightindex < finish - mid) {
		if ((*leftarr)[leftindex] < (*rightarr)[rightindex]) {
			inp[i] = (*leftarr)[leftindex];
			leftindex++;
			i++;
		}
		else {
			inp[i] = (*rightarr)[rightindex];
			rightindex++;
			i++;
		}
	}


	while (rightindex < finish - mid) {
		inp[i] = (*rightarr)[rightindex];
		i++;
		rightindex++;
	}


	while (leftindex < mid + 1 - start) {
		inp[i] = (*leftarr)[leftindex];
		leftindex++;
		i++;
	}

	delete leftarr, rightarr;

	return ERR_NO_ERROR;


}
kerr_t merge_sort_internal(vector<int>& inp, const int start, const int finish) {

	if (start >= finish) {
		return ERR_NO_ERROR;
	}

	int mid = start + (finish - start) / 2;

	merge_sort_internal(inp, start, mid);
	merge_sort_internal(inp, mid + 1, finish);
	merge_internal(inp, start, mid, finish);

	return ERR_NO_ERROR;

}



kerr_t Kksort::merge_sort(vector<int>& inp)
{

	merge_sort_internal(inp, 0, inp.size() - 1);


	return ERR_NO_ERROR;
}


//*********************//


kerr_t k_swap(int *a, int*b) {
	int t = *a;
	*a = *b;
	*b = t;
	return ERR_NO_ERROR;

}
kerr_t partition(vector<int>& inp, const int low, const int high, int &res) {

	int pivot = inp[high];
	int i = low - 1;
	for (int j = low; j <= high; j++) {

		if (inp[j] < pivot) {
			i++;
			k_swap(&inp[i], &inp[j]);
		}

	}
	
	k_swap(&inp[i + 1], &inp[high]); // swap with pivot
	res = i + 1;

	return ERR_NO_ERROR;
}


kerr_t quick_sort_internal(vector<int>& inp, int low, int high) {

	if (low < high) {
		int pi;
		partition(inp, low, high, pi);

		quick_sort_internal(inp, low, pi - 1);
		quick_sort_internal(inp, pi + 1, high);
	}

	return ERR_NO_ERROR;
}



kerr_t Kksort::quick_sort(vector<int>& inp)
{


	quick_sort_internal(inp, 0, inp.size() - 1);

	return ERR_NO_ERROR;
}


//*********************//
kerr_t Kksort::counting_sort(vector<int>& inp)
{
	int max = *std::max_element(inp.begin(), inp.end());
	int min = *std::min_element(inp.begin(), inp.end());
	int range = max - min + 1, i=0;

	vector<int> count(range), output(inp.size());

	// Count by adding the number of values

	for (i = 0; i < inp.size(); i++) {
		count[inp[i]-min]++;
	}

	// Perform addition

	for (i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	// 

	for (i = 0; i < inp.size(); i++) {
		output[count[inp[i] - min]-1] = inp[i];
		count[inp[i] - min]--;
	}

	for (i = 0; i < inp.size(); i++) {
		inp[i] = output[i];
	}

	return ERR_NO_ERROR;
}

//*********************//
kerr_t Kksort::bucket_sort(vector<float>& inp)
{
	if (*std::max_element(inp.begin(), inp.end()) > inp.size()) {
		return ERR_INVALID_INPUT;
	}


	vector<vector<float>> vec(inp.size());

	for (int i = 0; i < inp.size(); i++) {
		int bucket = inp[i];
		vec[bucket].push_back(inp[i]);
	}

	for (int i = 0; i < inp.size(); i++) {
		std::sort(vec[i].begin(), vec[i].end());
	}

	vector<float> vecs;

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			vecs.push_back(vec[i][j]);
		}
	}

	for (int i = 0; i < inp.size(); i++) {
		inp[i] = vecs[i];
	}


	return ERR_NO_ERROR;
}



kerr_t counting_radix_sort_internal(vector<int>& inp, const int exp) {
	
	int i;
	vector<int> count(10), output(inp.size()); // const int as there are only 10 digits
	for (i = 0; i < inp.size(); i++) {
		count[(inp[i]/exp)%10]++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	
	for (i = inp.size() -1; i > -1; i--) {
		output[count[(inp[i] / exp) % 10] - 1] = inp[i];
		count[(inp[i] / exp) % 10]--;
	}

	for (i = 0; i < inp.size(); i++) {
		inp[i] = output[i];
	}


	
	return ERR_NO_ERROR;
}

kerr_t Kksort::radix_sort(vector<int>& inp) {

	int max = *std::max_element(inp.begin(), inp.end());

	for (int exp = 1; max / exp > 0; exp *= 10) {

		counting_radix_sort_internal(inp, exp);

	}

	return ERR_NO_ERROR;
}



//SEARCHING

kerr_t Kksearch::linear_search(vector<int>& inp, const int val, k_result *res)
{
	int end = inp.size()-1;
	for (int start = 0; start <= end;) {
		if (inp[start] == val) {
			res->res_integer = start;
			return ERR_NO_ERROR;
		}

		if (inp[end] == val) {
			res->res_integer = end;
			return ERR_NO_ERROR;
		}

		start++;
		end--;
	}
	return ERR_INVALID_INPUT;
}

kerr_t Kksearch::binary_search(vector<int>& inp, const int val, k_result* res) {

	int left = 0;
	int right = inp.size() - 1;
	int mid;


	while (left <= right) {

		mid = left + (right - left) / 2;
		if (inp[mid] == val) {
			res->res_integer = mid;
			return ERR_NO_ERROR;
		}
		else if (inp[mid] < val) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	return ERR_INVALID_INPUT;


}

kerr_t Kksearch::interpolation_search(vector<int>& inp, const int val, k_result* res)
{
	return ERR_INVALID_INPUT;
}
