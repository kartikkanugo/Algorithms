#include "include\kksortsearch.h"
#include <iostream>



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
