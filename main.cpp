#include <iostream>
#include "kkdivideandconquer.h"


using namespace std;

int main() {
	string inp1{" "}, inp2{" "};
	k_result mainResult;
	k_error ret;

	
	DivConquer obj;
	ret = obj.karatsubaMultiplication(inp1, inp2, &mainResult);
	if(ret == err_no_error)
		cout << "no error \n";
	
	
	
	
	cout << "kkkk\n";

	return 0;

}