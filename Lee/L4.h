#pragma once
#include "common.h"
class L4
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);


private:
    double func(size_t b1, size_t e1, vector<int>& nums1,
        size_t b2, size_t e2, vector<int>& nums2
    );
    double median(int x, int y);
};

