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


//************TREE******************


TreeNode* Kktree::init_tree(int arr[MAX_STACK_ELEMENTS], int n) {

	TreeNode* tree = new TreeNode(arr[0]);

	TreeNode* temp = tree;
	TreeNode* tempr;
	int count = 0;
	for (int i = 1; i < n; i++) {
		
		if (i % 2 == 0) {
			temp->right = new TreeNode(arr[i]);
			count++;
		}
		else {
			temp->left = new TreeNode( arr[i]);
			count++;
		}

		if (count == 2) {
			tempr = temp->right;
			temp = temp->left;
		}
		if (count == 4) {
			temp = temp->right;
			count = 0;
		}

	}

	return tree;


}





kerr_t Kktree::in_order() {


	return ERR_NO_ERROR;
}
kerr_t Kktree::pre_order() {
	
	
	return ERR_NO_ERROR;

}
kerr_t Kktree::post_order() {


	return ERR_NO_ERROR;

}



//********************** Heap functions 

MinHeap::MinHeap(int capacity)
{
	this->capacity = capacity;
	this->heap_size = 0;
	this->hparr = new int[capacity];
}

kerr_t MinHeap::minHeapify(int i)
{ 
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && hparr[l] < hparr[smallest]) {
		smallest = l;
	}
	if (r < heap_size && hparr[r] < hparr[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		swapp(&hparr[smallest], &hparr[i]);
		minHeapify(smallest);
	}

	
	return kerr_t::ERR_NO_ERROR;
}

int MinHeap::parent(int i)
{
	return (i - 1) / 2;


	
}

int MinHeap::left(int i)
{
	return 2*i+1;
}

int MinHeap::right(int i)
{
	return 2*i+2;
}

kerr_t MinHeap::extractmin(int &out)
{
	if (heap_size <= 0) {
		return kerr_t::ERR_INVALID_INPUT;
	}

	if (heap_size == 1) {
		out = hparr[0];
		heap_size--;

		return kerr_t::ERR_NO_ERROR;
	}

	out = hparr[0];
	hparr[0] = hparr[heap_size - 1];
	heap_size--;
	minHeapify(0);




	return kerr_t::ERR_NO_ERROR;
}

kerr_t MinHeap::deleteKey(int i)
{
	int out;
	decreaseKey(i, INT_MIN);
	extractmin(out);
	return kerr_t::ERR_NO_ERROR;
}

void swapp(int *x, int *y) {
	int temp = *y;
	*y = *x;
	*x = temp;

}

kerr_t MinHeap::insertKey(int k)
{
	if (heap_size == capacity) {
		return kerr_t::ERR_CAPACITY_FULL;
	}

	heap_size++;
	hparr[heap_size - 1] = k;
	int i = heap_size - 1;

	// now should arrange the array to satisfy heap property

	while (i != 0 && hparr[parent(i)] > hparr[i]) {

		swapp(&hparr[i], &hparr[parent(i)]);
		i = parent(i);
		
	}

	return kerr_t::ERR_NO_ERROR;
}

kerr_t MinHeap::decreaseKey(int i, int new_val)
{
	hparr[i] = new_val;
	while (i != 0 && hparr[parent(i)] > hparr[i]) {

		swapp(&hparr[i], &hparr[parent(i)]);
		i = parent(i);

	}



	return kerr_t::ERR_NO_ERROR;
}

kerr_t MinHeap::getMin(int& out)
{
	out = hparr[0];


	return kerr_t::ERR_NO_ERROR;
}
