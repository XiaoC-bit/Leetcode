#include <iostream>

#include "L22.h"

#include "L4.h"
#include "LCR170.h"
#include "L34.h"

int main() {

	L34 l34;
	std::vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
	auto ans = l34.searchRange(nums1, 8);

	std::cout << ans[0] << "," << ans[1];

	/*
	std::vector<int> nums1 = {1,2,3,4};
	LCR170 lcr170;
	lcr170.reversePairs(nums1);
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

	}*/
	

	return 0;
}
