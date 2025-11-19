#include <iostream>

#include "L22.h"
#include "L327.h"
#include "L4.h"
#include "LCR170.h"
#include "L34.h"
#include "L406.h"
#include "L42.h"

int main() {
	L42 l42;
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	l42.trap(height);

	L406 l406;
	// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
	std::vector<std::vector<int>> data = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	l406.reconstructQueue(data);
	std::vector<int> nums1 = { -2,5,-1 };

	L327 l327;
	l327.countRangeSum(nums1, -2, 2);

	LCR170 lcr170;
	lcr170.reversePairs(nums1);

	/*
	L34 l34;
	std::vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
	auto ans = l34.searchRange(nums1, 8);

	std::cout << ans[0] << "," << ans[1];

	
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
