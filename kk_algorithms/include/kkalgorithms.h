#pragma once
#include <string>

using namespace std;


typedef enum kerr_t
{
	ERR_NO_ERROR = 0,
	ERR_INVALID_INPUT = 1,
	ERR_FILE_NOT_OPEN = 2

};


struct k_result {
	string res_stringtype{""};
	int res_integer{0};
	double res_double{0};
	int resArr[100000];
};



