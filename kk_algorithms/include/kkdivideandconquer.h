#pragma once


#include "kkalgorithms.h"
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
class DivConquer {
private:


public:
	kerr_t karatsuba_multiplication(string &inp1, string &inp2, k_result &result);
	kerr_t divide_conquer_sorting_inversions(string& inp1, k_result& result);
};