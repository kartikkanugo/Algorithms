#include <iostream>
#include "kkdivideandconquer.h"
#include "kkdatastructures.h"
#include "kksortsearch.h"



using namespace std;

int main() {
	
	string inp1{"3141592653589793238462643383279502884197169399375105820974944592"}, inp2{"2718281828459045235360287471352662497757247093699959574966967627"};
	k_result mainResult;
	kerr_t ret;
	DivConquer obj;
	
	ret = obj.karatsuba_multiplication(inp1, inp2, mainResult);
	if (ret != kerr_t::ERR_NO_ERROR) {
		cout << ret;
	}
	else {
		cout << mainResult.res_stringtype << endl;
	}
	


	// Create own stack, linkedlist, queue, binary tree

	Kkstack obj2;
	obj2.push(1);
	obj2.push(3);

	cout << obj2.top_element() << obj2.is_empty() << obj2.is_full() << endl;
	obj2.pop();
	cout << obj2.top_element() << obj2.is_empty() << obj2.is_full() << endl;
	obj2.pop();
	cout << obj2.top_element() << obj2.is_empty() << obj2.is_full() << endl;
	
	cout << "kkkk\n";


	// sorting 

	vector<int> a = { 1, 9, 3,4,6};
	Kksort ob3;
	ob3.merge_sort(a);
	cout << a[0] << a[1] << a[2] << a[3] ;
	return 0;

}