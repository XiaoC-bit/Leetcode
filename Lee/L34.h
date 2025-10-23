#pragma once
#include "common.h"


class L34
{
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0,r=nums.size()-1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums.at(mid) == target) {
                ans = mid;
            }
            if (nums.at(mid) >= target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }


    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums.at(mid) == target) {
                ans = mid;
            }
            if (nums.at(mid) <= target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        ans[0] = lower_bound(nums, target);
        ans[1] = upper_bound(nums, target);

        return ans;
    }
};

