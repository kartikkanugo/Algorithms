#pragma once

#include "kkalgorithms.h"

#define MAX_STACK_ELEMENTS 500


class Kkstack {
private:

	int capacity;


public:
	int arr[MAX_STACK_ELEMENTS];
	// stack functions 
	Kkstack()
	{
		capacity = -1;
	}
	bool push(int data);
	int pop();
	int top_element();
	int size();
	bool is_empty();
	bool is_full();
};



// Linked list stack
class Kkstackll {
private:

	int capacity;


public:
	int arr[MAX_STACK_ELEMENTS];
	// stack functions 
	Kkstackll()
	{
		capacity = -1;
	}
	bool push(int data);
	int pop();
	int top_element();
	int size();
	bool is_empty();
	bool is_full();
};


struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->data = data;
		left = right = nullptr;
	}
};


class Kktree {


public:
	TreeNode* init_tree(int arr[MAX_STACK_ELEMENTS], int n);
	TreeNode* insert_node();
	kerr_t in_order();
	kerr_t pre_order();
	kerr_t post_order();

	kerr_t in_order_non_recursive();
	kerr_t pre_order_non_recursive();
	kerr_t post_order_non_recursive();

};


class MinHeap {
	int* hparr;
	int capacity;
	int heap_size;

public:


	/**
	* Creates the minheap obj
	*/
	MinHeap(int capacity);
	/**
	* heapify the sub tree with the int has a root
	*/
	kerr_t minHeapify(int);
	/**
	* Determines the parent of the child node
	*/
	int parent(int i);
	/**
	* Determines the left child
	*/
	int left(int i);
	/**
	* Determines the right child
	*/
	int right(int i);
	/**
	* extracts the minimum value in the heap
	*/
	kerr_t extractmin(int &out);
	/**
	* deletes a key stored at index i
	*/
	kerr_t deleteKey(int i);
	/**
	* inserts a new key k
	*/
	kerr_t insertKey(int k);
	/**
	* decreases key at index i to new val
	*/
	kerr_t decreaseKey(int i, int new_val);
	/**
* gets minimum value
*/
	kerr_t getMin(int &out);



};