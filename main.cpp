#include <iostream>
#include "kkdivideandconquer.h"



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
	

	string filePath{"D:/Computer-Science/Algorithms/inputarr.txt"};
	ret = obj.divide_conquer_sorting_inversions(filePath, mainResult);
	
	if (ret != kerr_t::ERR_NO_ERROR) {
		cout << ret;
	}
	else {
		cout << mainResult.res_integer << endl;
	}
	
	
	
	cout << "kkkk\n";

	return 0;

}