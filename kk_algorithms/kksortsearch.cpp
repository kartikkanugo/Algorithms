#include "include\kksortsearch.h"

kerr_t Kksort::bubble_sort(vector<int> &inp)
{
	bool swapped = true;
	int size = inp.size();
	int i, j;
	for (i = 0; i < size && swapped; i++) {
		swapped = false;
		for (j = 0; j < size - i-1; j++) {
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
	for (i = 0; i < size -1; i++) {
		min = i;
		for (j = i+1; j < size; j++) // No repeatition over mins
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
		while (inp[j - 1] > temp && j>0) {
			inp[j] = inp[j - 1];
			j--;
		}
		inp[j] = temp;
	}


	return ERR_NO_ERROR;
}
