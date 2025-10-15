#include <iostream>

#include "L22.h"

#include "L4.h"


int main() {

	L4 solution4;
	std::vector<int> nums1 = { 1,1 };
	std::vector<int> nums2 = { 1 };
	auto res = solution4.findMedianSortedArrays(nums1, nums2);

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
