#pragma once
#include "common.h"

class L673
{
public:
    /*
    给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。

 

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 

提示: 

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
    
    */
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0;
        int max = 0;
        //1,2,4,3,5,4,7,2
        /*
        key:nums[i]

        first:length
        second:count
        */
        map<int, pair<int, int>> dicts;

        for (size_t i = 0; i < nums.size(); i++) {
            auto p = nums.at(i);

            int length = 0;
            int count = 0;
            bool find = false;

            for (auto it = dicts.begin(); it != dicts.end(); it++) {

                if (it->first >= p) {
                    break;
                }

                //数值更大，可以组成新的序列
                find = true;

                if (length > it->second.first) {
                    continue;
                }

                if (it->second.first == length) {
                    count += it->second.second;
                }
                else if (it->second.first > length) {
                    count = it->second.second;
                }
                length = it->second.first;
            }


            length++;

            if (!find) {
                count = 1;
            }

            auto it = dicts.find(p);
            if (it == dicts.end()) {
                dicts[p] = make_pair(length, count);
            }
            else {
                if (it->second.first < length) {
                    it->second.first = length;
                    it->second.second = count;
                }
                else if (it->second.first == length) {
                    it->second.second += count;
                }
            }

            if (max < length) {
                max = length;
                res = count;
            }
            else if (max == length) {
                res += count;
            }

        }

        return res;
    }
};

