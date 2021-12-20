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