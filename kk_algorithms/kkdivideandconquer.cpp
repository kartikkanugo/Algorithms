#pragma once

#include "kkdivideandconquer.h"





void breakdown_number(string &inp, string &out1, string &out2) {
	int n = inp.size();
	if (n % 2 == 0 && n > 2) {
		out1 = inp.substr(0, n / 2);
		out2 = inp.substr(n / 2, n);
		
	}


}

int makeEqualLength(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
			str2 = '0' + str2;
	}
	return len1; // If len1 >= len2
}

string ten_multiply(int n, string &inp) {
	
		inp.append(n,'0');

		return inp;

}

string add_strings(string& inp1, string& inp2) {

	int carry = 0; string res;
	int maxlength = makeEqualLength(inp1,inp2);


	for (int i = maxlength-1; i >= 0; i--) {

		int num1 = inp1.at(i) - '0';
		int num2 = inp2.at(i) - '0';
		int sum = num1 + num2 + carry;
		
		if (sum > 9) {
			carry = sum/10;
			
			
			if (sum == 10) {
				carry = 1;
			}
			sum = sum % 10;
		}
		else {
			carry = 0;
		}

		res = to_string(sum) + res;
	}

	if (carry != 0) {
		res = to_string(carry) + res;
	}

	//cout << res<<endl;
	return res;



}


string karatsuba_multiplication_internal(string &inp1, string &inp2) {
	int n = inp1.size();
	string res; kerr_t ret;

	if (inp1.size() <= 2 && inp2.size() <= 2) {
		
		res = to_string(std::stoi(inp1) * std::stoi(inp2));
		
		return res;
	}
	else {

		// break down number larger than 2
		string a, b, c, d, ac, ad,bc,bd, first, second, third, addstr;

		breakdown_number(inp1, a, b);

		breakdown_number(inp2, c, d);

		// add strings

		ac = karatsuba_multiplication_internal(a, c);
		ad = karatsuba_multiplication_internal(a, d);
		bc = karatsuba_multiplication_internal(b, c);
		bd = karatsuba_multiplication_internal(b, d);

		first = ten_multiply(n, ac);
		addstr = add_strings(ad, bc);
		second = ten_multiply(n / 2, addstr);
		
		return add_strings(add_strings(first, second), bd);
		

	}






}



kerr_t DivConquer::karatsuba_multiplication(string &inp1, string &inp2, k_result &result) {


	if (inp1.size() != inp2.size()) {
		return kerr_t::ERR_INVALID_INPUT;
	}
	else {
		result.res_stringtype = karatsuba_multiplication_internal(inp1, inp2);
		return  kerr_t::ERR_NO_ERROR;;
	}



}



