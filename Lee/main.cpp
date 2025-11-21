#include <iostream>

#include "L22.h"
#include "L327.h"
#include "L4.h"
#include "LCR170.h"
#include "L34.h"
#include "L406.h"
#include "L42.h"
#include "L496.h"
#include "L218.h"
#include "L307.h"
#include "L493.h"
int main() {
	vector<int> x = { 1,3,2,3,1 };
	L493 l493;
	l493.reversePairs(x);

	/*
	vector<int> x = { 1,3,5 };
	NumArray arr(x);
	arr.sumRange(0, 2);
	arr.update(1, 2);
	arr.sumRange(0, 2);
	vector<vector<int>> buildings;
	
	buildings.push_back({ 2, 9, 10 });
	buildings.push_back({ 3, 7, 15 });
	buildings.push_back({ 5, 12, 12 });
	buildings.push_back({ 15, 20, 10 });
	buildings.push_back({ 19, 24, 8 });*/


	//buildings.push_back({ 0, 2, 3 });
	//buildings.push_back({ 2, 5, 3 });

	//buildings.push_back({ 1, 2, 1 });
	//buildings.push_back({ 1, 2, 2 });
	//buildings.push_back({ 1, 2, 3 });

	/*buildings.push_back({ 5, 15, 20 });
	buildings.push_back({ 10, 15, 20 });
	buildings.push_back({ 20, 25, 5 });*/


	L218 l218;/*
	l218.getSkyline(buildings);*/

	/*std::vector<int> nums1 = {-2,5,-1};

	L327 l327;
	l327.countRangeSum(nums1, -2, 2);

	L496 l496;
	vector<int> nums1 = { 1,3,5,2,4 };
	vector<int>nums2 = { 6,5,4,3,2,1,7 };
	l496.nextGreaterElement(nums1, nums2);*/

	//L42 l42;
	//vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	//l42.trap(height);

	//L406 l406;
	//// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
	//std::vector<std::vector<int>> data = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	//l406.reconstructQueue(data);
	

	//LCR170 lcr170;
	//lcr170.reversePairs(nums1);

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
