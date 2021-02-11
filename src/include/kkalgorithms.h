#pragma once
#include <string>

using namespace std;


typedef enum k_error
{
	err_no_error,
	err_invalid_input

};


struct k_result {
	string res_stringtype{""};
	int res_integer{0};
	double res_double{0};
};