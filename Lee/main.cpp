#include <iostream>

#include "L22.h"



int main() {

	L22 solution22;
	for (int i = 0; i < 9; i++) {
		auto res = solution22.generateParenthesis(i);
		std::cout << "Parenthesis " << i << std::endl;
		for (auto& it : res) {
			std::cout << it;
		}
		std::cout << "----------------" << std::endl;

	}
	

	return 0;
}
